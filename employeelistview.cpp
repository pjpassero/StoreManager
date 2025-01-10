#include "employeelistview.h"
#include "ui_employeelistview.h"
#include <pqxx/pqxx>
#include <StoreManager/StoreManager/Employee.h>
#include <iostream>
EmployeeListView::EmployeeListView(QWidget *parent,pqxx::connection &conn)
    : QMainWindow(parent)
    , ui(new Ui::EmployeeListView), C(conn)
{
    ui->setupUi(this);
    populateEmployeeTable();


    connect(ui->pushButton, &QPushButton::clicked, this, &EmployeeListView::AddEmployee);
}

EmployeeListView::~EmployeeListView()
{
    delete ui;
}



void EmployeeListView::populateEmployeeTable() {

    try {
        pqxx::work txn(C);
        std::string queryEmployees = "SELECT employeeid, fullname, username, password, permissionlevel, personalemail FROM employee";
        pqxx::result result = txn.exec(queryEmployees);
        ui->tableWidget->setRowCount(result.size());

        int row = 0;
        for(auto r : result) {
            QString employeeId = QString::fromStdString(r["employeeId"].c_str());
            QString name = QString::fromStdString(r["fullname"].c_str());
            QString username = QString::fromStdString(r["username"].c_str());
            QString password = QString::fromStdString(r["password"].c_str());
            QString permission = QString::fromStdString(r["permissionLevel"].c_str());
            QString pEmail = QString::fromStdString(r["personalEmail"].c_str());

            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(employeeId));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(name));
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(username));
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(password));
            ui->tableWidget->setItem(row, 4, new QTableWidgetItem(permission));
            ui->tableWidget->setItem(row, 5, new QTableWidgetItem(pEmail));

            row++;
        }
    }catch (const std::exception& e) {
        std::cerr << "Error fetching data: " << e.what() << std::endl;
    }




}


void EmployeeListView::AddEmployee() {

    newEmployee = new AddEmployeeView();
    newEmployee->show();
    newEmployee->raise();
    newEmployee->activateWindow();



}
