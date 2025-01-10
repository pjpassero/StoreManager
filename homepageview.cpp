#include "homepageview.h"
#include "ui_homepageview.h"

HomePageView::HomePageView(QWidget *parent, pqxx::connection &conn)
    : QMainWindow(parent)
    , ui(new Ui::HomePageView), C(conn)
{
    ui->setupUi(this);

    this->setWindowTitle("Store Manager Pro: V1.0");

    connect(ui->inventory, &QPushButton::clicked, this, &HomePageView::LoadInventoryView);
    connect(ui->employees, &QPushButton::clicked,this, &HomePageView::LoadEmployeeView);

}

HomePageView::~HomePageView()
{
    delete ui;
}



void HomePageView::LoadInventoryView() {

    inventory = new InventoryView(nullptr, C);

    inventory->activateWindow();
    inventory->raise();
    inventory->show();



};


void HomePageView::LoadEmployeeView() {

    employees = new EmployeeListView(nullptr, C);

    employees->activateWindow();
    employees->raise();
    employees->show();

}
