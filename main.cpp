
#include "mainwindow.h"
//#include "firstwindow.h"
#include <QApplication>
#include "inventoryview.h"
#include "productview.h"
#include "loginwindow.h"
#include "firstwindow.h"
#include <pqxx/pqxx>
#include <iostream>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    /*
    //LoginWindow loginWin;
    AddEmployeeView newEmployee;
    //loginWin.show();

    newEmployee.show();

*/
    //Hello World!
    FirstWindow startUpWindow;

    startUpWindow.show();

    return a.exec();
}
