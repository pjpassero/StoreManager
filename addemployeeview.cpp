/*
 * Philip J. Passero IV
 * addemployeeview.cpp
 *
 * Employee View Implementation
 *
 * Implements the employee view and related functions of the view
 *
 */

#include "addemployeeview.h"
#include "employeelistview.h"
#include "ui_addemployeeview.h"
#include "StoreManager/StoreManager/Employee.h"
#include <pqxx/pqxx>


/*
 * Add employee view constructor
 * @param parent: pointer to the parent window
 * @param conn: reference to the conenction class object for the database
 *
 *Creates a QMainWindow object based on the params. Will initalize the database connection to this particular window.
 *Houses the handler for the addEmployee push button onclick event - THIS WILL BE CHANGED TO A SEPERATE FUNCTION
 */

AddEmployeeView::AddEmployeeView(QWidget *parent, pqxx::connection &conn)
    : QMainWindow(parent)
    , ui(new Ui::AddEmployeeView), C(conn)
{
    ui->setupUi(this);


    this->setWindowTitle("Add New Employee");



    //Registers the button click event to a function and creates new employee details based on that
    //WILL CONVERT THIS TO ITS OWN FUNCTION
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
