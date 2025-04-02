#include "pointofsaleview.h"
#include "ui_pointofsaleview.h"
#include "loginwindow.h"
#include "pqxx/pqxx"
PointOfSaleView::PointOfSaleView(QWidget *parent, pqxx::connection &conn)
    : QMainWindow(parent), C(conn)
    , ui(new Ui::PointOfSaleView)
{
    ui->setupUi(this);

    connect(ui->addToList, &QPushButton::clicked, this, &PointOfSaleView::AddToList);
    this->setWindowTitle("Point of Sale");
    Login();

}

PointOfSaleView::~PointOfSaleView()
{
    delete ui;
}


void PointOfSaleView::Login() {
    if(!loggedIn) {

        LoginWindow* loginWin = new LoginWindow(this, C, POINT_OF_SALE);
        loginWin->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);
        loginWin->show();
        loginWin->activateWindow();
        loginWin->raise();

    }
    //std::string employeeName = session->getCurentEmployee().getName();
    //QString eName = QString::fromStdString(employeeName);

}

void PointOfSaleView::setSession(UserSession* us){
    session = us;
}

void PointOfSaleView::updateWinData() {
    Employee employ = session->getCurentEmployee();
    std::cout << employ.getName();
    ui->user->setText(QString::fromStdString(employ.getName()));
}


void PointOfSaleView::AddToList()  {

    std::string item = ui->productLine->toPlainText().toStdString();


}
