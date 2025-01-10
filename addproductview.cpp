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
    populateVendorList();

    connect(ui->addProduct, &QPushButton::clicked, this, &AddProductView::CreateNewProduct);


}

AddProductView::~AddProductView()
{
    delete ui;
}

void AddProductView::CreateNewProduct() {

    QString pName  = ui->productName->text();
    QString lSupplier = ui->preferredVendor->currentText();
    QString cost = ui->productLastCost->text();
    QString price = ui->productPrice->text();
    QString upc = ui->productUPC->text();

    pqxx::work txn(C);
    std::string getSupplierId = "SELECT supplierid FROM supplier WHERE suppliername=$1";
    pqxx::result result = txn.exec_params(getSupplierId, lSupplier.toStdString());

    QString supplierId = QString::fromStdString(result[0]["supplierId"].c_str());


    txn.commit();

    Product newProduct(pName.toStdString(), cost.toDouble(),price.toDouble(),0,supplierId.toInt(),upc.toInt(), C);

    newProduct.SaveToInventoryFile(newProduct);




    this->close();

    InventoryView *parentWindow = qobject_cast<InventoryView *>(parent());
    if (parentWindow) {
        parentWindow->reloadDataTable();
    }
}


void AddProductView::populateVendorList() {

    pqxx::work txn(C);
    std::string query = "SELECT suppliername FROM supplier";
    pqxx::result result = txn.exec(query);

    ui->preferredVendor->clear(); // Clear existing items to avoid duplicates


    if(result.empty()) {
        std::cerr << "Result is empty!" << std::endl;
    }

    for(auto r : result) {
        QString qSupplierName = QString::fromStdString(r["supplierName"].c_str());
        ui->preferredVendor->addItem(qSupplierName);

    }



}

