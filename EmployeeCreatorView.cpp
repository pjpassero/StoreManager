#include "EmployeeCreatorView.h"
#include "ui_EmployeeCreatorView.h"

EmployeeCreatorView::EmployeeCreatorView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EmployeeCreatorView)
{
    ui->setupUi(this);
}

EmployeeCreatorView::~EmployeeCreatorView()
{
    delete ui;
}
