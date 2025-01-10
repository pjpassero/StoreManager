#include "employeelistview.h"
#include "ui_employeelistview.h"

EmployeeListView::EmployeeListView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EmployeeListView)
{
    ui->setupUi(this);
}

EmployeeListView::~EmployeeListView()
{
    delete ui;
}
