#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addemployeeview.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), employeeCreate(nullptr) // Initialize to nullptr
{
    ui->setupUi(this);

    // Connection to combine store name, owner, and address into CSV format
    /*
    connect(ui->pushButton, &QPushButton::clicked, this, [this]() {
        QString storeName = ui->storeName->toPlainText();
        QString ownerName = ui->ownerName->toPlainText();
        QString address = ui->address->toPlainText();

        ui->csvDataLine->setText(storeName + "," + ownerName + "," + address);
    });

    // Open the second window on button click
*/

}

MainWindow::~MainWindow()
{
    delete ui;
    if(employeeCreate) {
        delete employeeCreate;
    }
}
