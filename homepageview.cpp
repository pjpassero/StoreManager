#include "homepageview.h"
#include "ui_homepageview.h"

HomePageView::HomePageView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomePageView)
{
    ui->setupUi(this);


    connect(ui->inventory, &QPushButton::clicked, this, &HomePageView::LoadInventoryView);


}

HomePageView::~HomePageView()
{
    delete ui;
}



void HomePageView::LoadInventoryView() {

    inventory = new InventoryView();

    inventory->activateWindow();
    inventory->raise();
    inventory->show();



};
