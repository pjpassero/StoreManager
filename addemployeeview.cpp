#include "addemployeeview.h"
#include "ui_addemployeeview.h"
#include "StoreManager/StoreManager/Employee.h"

//#include <string>


AddEmployeeView::AddEmployeeView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AddEmployeeView)
{
    ui->setupUi(this);


    this->setWindowTitle("Add Employee");

    connect(ui->addEmployee, &QPushButton::clicked, this, [this]() {
    /*
        QString employeeName = ui->firstname->toPlainText() + " " + ui->lastname->toPlainText();
        QString employeeUserName = ui->username->toPlainText();
        QString employeePassword = ui->password->toPlainText();
        QString employeePayRate = ui->payRate->toPlainText();
        QString employeeIsActive = ui->isActive->currentText();
        QString employeePrivledgeLevel = ui->privledgeLevel->currentText();
        QString employeeAddress = ui->address->toPlainText();

        QString finalString = employeeName + "," + employeeUserName + "," + employeePassword + "," + employeePayRate + "," +
            employeeIsActive + "," + employeePrivledgeLevel;

        ui->label->setText(finalString);
        double employeePay = employeePayRate.toDouble();

        Employee newEmployee(employeeName.toStdString(),employeePay, employeePrivledgeLevel.toStdString(), employeeUserName.toStdString(), employeePassword.toStdString(), employeeAddress.toStdString());

        newEmployee.AddNewEmployeeDriver(newEmployee, storePath);

*/
    });

}

AddEmployeeView::~AddEmployeeView()
{
    delete ui;
}
