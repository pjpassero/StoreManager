#include "addemployeeview.h"
#include "employeelistview.h"
#include "ui_addemployeeview.h"
#include "StoreManager/StoreManager/Employee.h"
#include <pqxx/pqxx>


AddEmployeeView::AddEmployeeView(QWidget *parent, pqxx::connection &conn)
    : QMainWindow(parent)
    , ui(new Ui::AddEmployeeView), C(conn)
{
    ui->setupUi(this);


    this->setWindowTitle("Add New Employee");




    connect(ui->addEmployee, &QPushButton::clicked, this, [this]() {
        QString employeeName = ui->firstname->toPlainText() + " " + ui->lastname->toPlainText();
        QString employeeUserName = ui->username->toPlainText();
        QString email = ui->email->toPlainText();
        QString employeePassword = ui->password->toPlainText();
        QString employeePayRate = ui->payRate->toPlainText();
        QString employeeIsActive = ui->isActive->currentText();
        QString employeePrivledgeLevel = ui->privledgeLevel->currentText();
        QString employeeAddress = ui->address->toPlainText();
        QString phoneNum = ui->phoneNumber->toPlainText();

        string activeL = "N";

        if(employeeIsActive == "Active") {
            activeL = "Y";
        }

        double employeePay = employeePayRate.toDouble();

        Employee newEmployee(employeeName.toStdString(),employeePay, email.toStdString(), phoneNum.toStdString(), activeL, employeePrivledgeLevel.toStdString(), employeeUserName.toStdString(), employeePassword.toStdString(), employeeAddress.toStdString(), C);

        newEmployee.AddNewEmployeeDriver(newEmployee);

        this->close();


    });

}

AddEmployeeView::~AddEmployeeView()
{
    delete ui;
}
