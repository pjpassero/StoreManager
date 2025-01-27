/*
 *Philip J. Passero IV
 *employeelistview.h
 *
 *Employee List View Class declaration
 */

#ifndef EMPLOYEELISTVIEW_H
#define EMPLOYEELISTVIEW_H
#include <pqxx/pqxx>
#include <addemployeeview.h>
#include <QMainWindow>

namespace Ui {
class EmployeeListView;
}

class EmployeeListView : public QMainWindow
{
    Q_OBJECT

public:
    explicit EmployeeListView(QWidget *parent, pqxx::connection &conn);
    ~EmployeeListView();

private:
    Ui::EmployeeListView *ui;
    pqxx::connection &C;
    AddEmployeeView *newEmployee;

    void populateEmployeeTable();
    void AddEmployee();

};

#endif // EMPLOYEELISTVIEW_H
