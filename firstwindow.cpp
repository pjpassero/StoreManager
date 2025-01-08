#include "firstwindow.h"
#include "ui_firstwindow.h"
#include "loginwindow.h"

FirstWindow::FirstWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FirstWindow)
{
    ui->setupUi(this);


}

FirstWindow::~FirstWindow()
{
    delete ui;
}
