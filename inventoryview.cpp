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
            newProduct = new AddProductView(this);
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

            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(qSKU));            // SKU
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(qName));           // Name
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(qCost));           // Cost
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(qPrice));          // Price
            ui->tableWidget->setItem(row, 4, new QTableWidgetItem(qInventory));      // Inventory
            ui->tableWidget->setItem(row, 5, new QTableWidgetItem(qSupplierId));     // Supplier ID
            ui->tableWidget->setItem(row, 6, new QTableWidgetItem(qUPC));            // UPC

            row++;
        }

    } catch (const std::exception& e) {
        std::cerr << "Error fetching data: " << e.what() << std::endl;
    }
}



/*
void InventoryView::PopulateInventoryViewFromFile() {
    string filePath = "/Users/pjpassero/Documents/StoreApplication/StoreManager/StoreManager/StoreDataFiles/LumberCo/inventory/inventory.txt";

    ifstream testFile(filePath);
    if (!testFile) {
        cerr << "File not found at path: " << filePath << endl;
        return;
    }
    testFile.close();

    ifstream companyInventoryFile;
    companyInventoryFile.open(filePath);
    if (!companyInventoryFile.is_open()) {
        cerr << "Cannot open the file" << endl;
        return;
    }

    ui->tableWidget->setRowCount(0);

    string currentFileLine;
    int row = 0;

    try {
        while (getline(companyInventoryFile, currentFileLine)) {
            size_t pos1 = currentFileLine.find(',');
            size_t pos2 = currentFileLine.find(',', pos1 + 1);
            size_t pos3 = currentFileLine.find(',', pos2 + 1);
            size_t pos4 = currentFileLine.find(',', pos3 + 1);
            size_t pos5 = currentFileLine.find(',', pos4 + 1);
            size_t pos6 = currentFileLine.find(',', pos5 + 1);

            if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos || pos4 == string::npos || pos5 == string::npos || pos6 == string::npos) {
                continue;
            }

            string SKU = currentFileLine.substr(0, pos1);
            string Name = currentFileLine.substr(pos1 + 1, pos2 - pos1 - 1);
            string Price = currentFileLine.substr(pos2 + 1, pos3 - pos2 - 1);
            string InventoryCount = currentFileLine.substr(pos3 + 1, pos4 - pos3 - 1);
            string Manufacturer = currentFileLine.substr(pos4 + 1, pos5 - pos4 - 1);
            string UPC = currentFileLine.substr(pos5 + 1, pos6 - pos5 - 1);

            QString qSKU = QString::fromStdString(SKU);
            QString qName = QString::fromStdString(Name);
            QString qPrice = QString::fromStdString(Price);
            QString qInventoryCount = QString::fromStdString(InventoryCount);
            QString qManufacturer = QString::fromStdString(Manufacturer);
            QString qUPC = QString::fromStdString(UPC);

            ui->tableWidget->insertRow(row);
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(qSKU));           // SKU
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(qName));          // Name
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(qPrice));         // Price
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(qInventoryCount)); // Inventory Count
            ui->tableWidget->setItem(row, 4, new QTableWidgetItem(qManufacturer));  // Manufacturer
            ui->tableWidget->setItem(row, 5, new QTableWidgetItem(qUPC));           // UPC

            row++;
        }

    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    companyInventoryFile.close();
}
*/
