#include "homepageview.h"
#include "ui_homepageview.h"

HomePageView::HomePageView(QWidget *parent, pqxx::connection &conn)
    : QMainWindow(parent)
    , ui(new Ui::HomePageView), C(conn)
{
    ui->setupUi(this);


    connect(ui->inventory, &QPushButton::clicked, this, &HomePageView::LoadInventoryView);


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
