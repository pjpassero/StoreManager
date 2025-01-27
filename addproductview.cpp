/*
 * Philip J. Passero IV
 * addproductview.cpp
 *
 * Add Product View Implementation File
 *
 *
 * Implements the add product view class which creates a new window to add a new product to the database
 *
 */

#include "addproductview.h"
#include "ui_addproductview.h"
#include <pqxx/pqxx>
#include "StoreManager/StoreManager/Product.h"
#include "inventoryview.h"

/*
 * Add Product View Constructor
 * @param parent: parent window pointer
 * @param conn: reference to the database conneciton class object
 *
 * Creates a new QDialog Window that displays a form to add a new product
 */

AddProductView::AddProductView(QWidget *parent, pqxx::connection &conn)
    : QDialog(parent)
    , ui(new Ui::AddProductView), C(conn)
{
    ui->setupUi(this);
    this->setWindowTitle("Add a New Product");
    populateVendorList();


    //Registers the button click of addProduct
    connect(ui->addProduct, &QPushButton::clicked, this, &AddProductView::CreateNewProduct);


}

AddProductView::~AddProductView()
{


    delete ui;
}

/*
 * Determines the approprite active level of the product based on string input.
 * @param level: reference to the active level stored in the database
 *
 * @return: integer that will be used in the GUI for the inventory information
 */

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

/*
 *New Product button event handler
 *Takes all the data from the form and stores then in QStrings
 *Determine Level will get the appropriate level for the selection
 *
 *Connects to the database and finds the venderid that matches the user selection
 *If found, then a new product object is created and the product object SaveToInventoryFile() is called to save to the database
 *Once the work is done, the window is closed and deconstructed.
 */

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

/*
 *Populate the vendor list for the user to select from when creating a new product
 *Select all the vendors from vendor table and place then in the list on the GUI
 *
 */


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

