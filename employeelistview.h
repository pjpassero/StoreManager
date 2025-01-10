#ifndef EMPLOYEELISTVIEW_H
#define EMPLOYEELISTVIEW_H

#include <QMainWindow>

namespace Ui {
class EmployeeListView;
}

class EmployeeListView : public QMainWindow
{
    Q_OBJECT

public:
    explicit EmployeeListView(QWidget *parent = nullptr);
    ~EmployeeListView();

private:
    Ui::EmployeeListView *ui;
};

#endif // EMPLOYEELISTVIEW_H
