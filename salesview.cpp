#include "salesview.h"
#include "ui_salesview.h"
#include <iostream>
#include "pqxx/pqxx"
SalesView::SalesView(QWidget *parent,pqxx::connection &conn)
    : QMainWindow(parent), C(conn)
    , ui(new Ui::SalesView)
{
    ui->setupUi(this);
    this->setWindowTitle("Sales Data");
    LoadTable();
}

SalesView::~SalesView()
{
    delete ui;
}



void SalesView::LoadTable() {
    try {
        pqxx::work txn(C);
        std::string query =
            "SELECT timestamp, customerincrement, customer_name, "
            "transaction_amount, numberofitems, payment_method "
            "FROM sale, customer WHERE customer.customerid = sale.customerid";

        pqxx::result result = txn.exec(query);

        ui->salesWindow->setRowCount(result.size());

        if (result.size() == 0) {
            std::cerr << "No results!";
            return;
        }

        int row = 0;
        for (auto r : result) {
            QString timestamp = QString::fromStdString(r["timestamp"].c_str());
            QString customerIncrement = QString::fromStdString(r["customerincrement"].c_str());
            QString customerName = QString::fromStdString(r["customer_name"].c_str());
            QString transactionAmount = QString::fromStdString(r["transaction_amount"].c_str());
            QString numberOfItems = QString::fromStdString(r["numberofitems"].c_str());
            QString paymentMethod = QString::fromStdString(r["payment_method"].c_str());

            ui->salesWindow->setItem(row, 0, new QTableWidgetItem(timestamp));
            ui->salesWindow->setItem(row, 1, new QTableWidgetItem(customerIncrement));
            ui->salesWindow->setItem(row, 2, new QTableWidgetItem(customerName));
            ui->salesWindow->setItem(row, 3, new QTableWidgetItem(transactionAmount));
            ui->salesWindow->setItem(row, 4, new QTableWidgetItem(numberOfItems));
            ui->salesWindow->setItem(row, 5, new QTableWidgetItem(paymentMethod));

            row++;
        }

    } catch (std::exception &e) {
        std::cerr << "Error loading table: " << e.what() << std::endl;
    }
}

