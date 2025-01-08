#include "firstwindow.h"
#include "ui_firstwindow.h"
#include "loginwindow.h"
#include "createdatabaseconnection.h"

FirstWindow::FirstWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FirstWindow)
{
    ui->setupUi(this);

    connect(ui->databaseWizard, &QPushButton::clicked, this, &FirstWindow::openDatabaseWizard);


}

FirstWindow::~FirstWindow()
{
    delete ui;
}


void FirstWindow::openDatabaseWizard() {

    CreateDatabaseConnection *DatabaseWizardWindow = new CreateDatabaseConnection;

    DatabaseWizardWindow->show();
    DatabaseWizardWindow->raise();
    DatabaseWizardWindow->activateWindow();


};
