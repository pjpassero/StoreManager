#include "homepageview.h"
#include "ui_homepageview.h"

HomePageView::HomePageView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomePageView)
{
    ui->setupUi(this);
}

HomePageView::~HomePageView()
{
    delete ui;
}
