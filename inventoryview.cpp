#include "inventoryview.h"
#include "ui_inventoryview.h"
#include "productview.h"
#include "addproductview.h"
#include "StoreManager/StoreManager/Product.h"
#include "StoreManager/StoreManager/store.h"
#include <fstream>
#include <pqxx/pqxx>
#include <string>


InventoryView::InventoryView(QWidget *parent, pqxx::connection &conn)
    : QMainWindow(parent)
    , ui(new Ui::InventoryView), newProduct(nullptr), C(conn)
{
    ui->setupUi(this);

    //Store myStore("LumberCo");

    this->setWindowTitle("Inventory View");
    this->PopulateInventoryViewFromFile();

    ui->tableWidget->setColumnCount(6);
    connect(ui->newItem, &QPushButton::clicked, this, [this]() {
        if(!newProduct) {
            newProduct = new AddProductView(this, C);
        }

        newProduct->show();
        newProduct->raise();
        newProduct->activateWindow();

    });
}

InventoryView::~InventoryView()
{
    delete ui;
}

void InventoryView::PopulateInventoryViewFromFile() {
    try {
        pqxx::work txn(C);
        std::string query = "SELECT sku, productName, productCost, productPrice, productInventory, supplierId, UPC FROM product";
        pqxx::result result = txn.exec(query);

        ui->tableWidget->setRowCount(result.size());  // Set the number of rows in the table widget

        int row = 0;
        for (auto r : result) {
            QString qSKU = QString::fromStdString(r["sku"].c_str());
            QString qName = QString::fromStdString(r["productName"].c_str());
            QString qCost = QString::fromStdString(r["productCost"].c_str());
            QString qPrice = QString::fromStdString(r["productPrice"].c_str());
            QString qInventory = QString::fromStdString(r["productInventory"].c_str());
            QString qSupplierId = QString::fromStdString(r["supplierId"].c_str());
            QString qUPC = QString::fromStdString(r["UPC"].c_str());


            std::string queryForSupplier = "SELECT suppliername FROM supplier WHERE supplierId = $1";
            pqxx::result supplierResult = txn.exec_params(queryForSupplier, qSupplierId.toInt());

            if(supplierResult.empty()) {
                std::cerr << "No data found for supplier id!" << std::endl;
            } else {
                //std::cout << "Found" << std::endl;
            }
            QString supplierName = QString::fromStdString(supplierResult[0]["supplierName"].c_str());


            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(qSKU));            // SKU
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(qName));           // Name
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(qCost));           // Cost
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(qPrice));          // Price
            ui->tableWidget->setItem(row, 4, new QTableWidgetItem(qInventory));      // Inventory
            ui->tableWidget->setItem(row, 5, new QTableWidgetItem(supplierName));     // Supplier ID
            ui->tableWidget->setItem(row, 6, new QTableWidgetItem(qUPC));            // UPC

            row++;
        }

    } catch (const std::exception& e) {
        std::cerr << "Error fetching data: " << e.what() << std::endl;
    }
}




