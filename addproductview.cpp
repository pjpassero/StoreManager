#include "addproductview.h"
#include "ui_addproductview.h"
#include <pqxx/pqxx>
#include "StoreManager/StoreManager/Product.h"
#include "inventoryview.h"
AddProductView::AddProductView(QWidget *parent, pqxx::connection &conn)
    : QDialog(parent)
    , ui(new Ui::AddProductView), C(conn)
{
    ui->setupUi(this);
    this->setWindowTitle("Add a New Product");
    populateVendorList();

    connect(ui->addProduct, &QPushButton::clicked, this, &AddProductView::CreateNewProduct);


}

AddProductView::~AddProductView()
{


    delete ui;
}

int determineLevel(const std::string& level) {
    if (level == "Active") {
        return 0;
    } else if (level == "Inactive") {
        return 1;
    } else if (level == "Discontinued") {
        return 2;
    } else if (level == "Out of Stock") {
        return 3;
    } else {
        throw std::invalid_argument("Invalid level");
    }
}

void AddProductView::CreateNewProduct() {

    QString pName  = ui->productName->text();
    QString lSupplier = ui->preferredVendor->currentText();
    QString cost = ui->productLastCost->text();
    QString price = ui->productPrice->text();
    QString activeLevel = ui->activeLevel->currentText();
    QString upc = ui->productUPC->text();

    int getActiveLevel = determineLevel(activeLevel.toStdString());

    pqxx::work txn(C);
    std::string getSupplierId = "SELECT vendorid FROM vendor WHERE vendorname=$1";
    pqxx::result result = txn.exec_params(getSupplierId, lSupplier.toStdString());

    QString supplierId = QString::fromStdString(result[0]["vendorid"].c_str());


    txn.commit();

    Product newProduct(pName.toStdString(), cost.toDouble(),price.toDouble(),0,supplierId.toInt(),upc.toULongLong(), getActiveLevel, C);

    newProduct.SaveToInventoryFile(newProduct);




    this->close();

    InventoryView *parentWindow = qobject_cast<InventoryView *>(parent());
    if (parentWindow) {
        parentWindow->reloadDataTable();
    }
}


void AddProductView::populateVendorList() {

    pqxx::work txn(C);
    std::string query = "SELECT vendorname FROM vendor";
    pqxx::result result = txn.exec(query);

    ui->preferredVendor->clear(); // Clear existing items to avoid duplicates


    if(result.empty()) {
        std::cerr << "Result is empty!" << std::endl;
    }

    for(auto r : result) {
        QString qSupplierName = QString::fromStdString(r["vendorname"].c_str());
        ui->preferredVendor->addItem(qSupplierName);

    }



}

