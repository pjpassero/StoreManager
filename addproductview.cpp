#include "addproductview.h"
#include "ui_addproductview.h"
#include <pqxx/pqxx>
#include "StoreManager/StoreManager/Product.h"

AddProductView::AddProductView(QWidget *parent, pqxx::connection &conn)
    : QDialog(parent)
    , ui(new Ui::AddProductView), C(conn)
{
    ui->setupUi(this);


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

    Product newProduct(pName.toStdString(), cost.toDouble(),price.toDouble(),0,lSupplier.toStdString(),upc.toInt());

    newProduct.SaveToInventoryFile(newProduct);


}
