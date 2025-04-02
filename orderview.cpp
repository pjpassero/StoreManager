#include "orderview.h"
#include "ui_orderview.h"
#include <iostream>
OrderView::OrderView(QWidget *parent, pqxx::connection &conn)
    : QMainWindow(parent)
    , C(conn), ui(new Ui::OrderView)
{
    ui->setupUi(this);
    ui->connect(send, this, &QPushButton::click, &OrderView::SendOrder);
    PopulateProductsFromFile();
}

OrderView::~OrderView()
{
    delete ui;
}

void OrderView::PopulateProductsFromFile() {
    try {
        pqxx::work txn(C);
        std::string query = "SELECT sku, productName, productCost, productInventory FROM product as pro, vendor as ven WHERE pro.vendorid = ven.vendorid";
        pqxx::result result = txn.exec(query);

        ui->orderDocket->setRowCount(result.size());  // Set the number of rows in the table widget

        int row = 0;
        for (auto r : result) {
            QString qSKU = QString::fromStdString(r["sku"].c_str());
            QString qName = QString::fromStdString(r["productName"].c_str());
            QString qCost = QString::fromStdString(r["productCost"].c_str());
            QString qInventory = QString::fromStdString(r["productInventory"].c_str());

            ui->orderDocket->setItem(row, 0, new QTableWidgetItem(qSKU));            // SKU
            ui->orderDocket->setItem(row, 1, new QTableWidgetItem(qName));           // Name
            ui->orderDocket->setItem(row, 2, new QTableWidgetItem(qCost));           // Cost
            ui->orderDocket->setItem(row, 3, new QTableWidgetItem(qInventory));      // Inventory
            ui->orderDocket->setItem(row, 4, new QTableWidgetItem("0"));      // Inventory


            row++;
        }

    } catch (const std::exception& e) {
        std::cerr << "Error fetching data: " << e.what() << std::endl;
    }
}


void OrderView::SendOrder() {
    int rowCount = ui->orderDocket->rowCount();

    for(int i = 0; i < rowCount; i++) {
    }

}
