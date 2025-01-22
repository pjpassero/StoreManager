/*
 * Philip J. Passero IV
 * addemployeeview.h
 *
 * Add Employee View class declaration file
 *
 */

#ifndef ADDEMPLOYEEVIEW_H
#define ADDEMPLOYEEVIEW_H
#include <pqxx/pqxx>
#include <QMainWindow>

namespace Ui {
class AddEmployeeView;
}

class AddEmployeeView : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddEmployeeView(QWidget *parent, pqxx::connection &conn);
    ~AddEmployeeView();

private:
    Ui::AddEmployeeView *ui;
    pqxx::connection &C;

};

#endif // ADDEMPLOYEEVIEW_H
