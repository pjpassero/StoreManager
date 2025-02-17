#include "homepageview.h"
#include "ui_homepageview.h"
#include "StoreManager/StoreManager/UserSession.h"


HomePageView::HomePageView(QWidget *parent, pqxx::connection &con, UserSession &newSession)
    : QMainWindow(parent)
    , ui(new Ui::HomePageView),session(newSession),C(con)
{
    ui->setupUi(this);

    QString titleString = "Store Manager Pro: V1.0, User: " + QString::fromStdString(session.getCurentEmployee().getName());

    this->setWindowTitle(titleString);

    connect(ui->inventory, &QPushButton::clicked, this, &HomePageView::LoadInventoryView);
    connect(ui->employees, &QPushButton::clicked,this, &HomePageView::LoadEmployeeView);

    if(session.getCurentEmployee().getPermissionLevel() != "Owner") {
        ui->employees->setEnabled(false);
        ui->balancesheet->setEnabled(false);
        ui->storeData->setEnabled(false);
    }

    ui->inventory->setToolTip("Inventory");
    //employees->setToolTip("Employees");


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
