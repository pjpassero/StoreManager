#ifndef CREATEDATABASECONNECTION_H
#define CREATEDATABASECONNECTION_H

#include <QWidget>

namespace Ui {
class CreateDatabaseConnection;
}

class CreateDatabaseConnection : public QWidget
{
    Q_OBJECT

public:
    explicit CreateDatabaseConnection(QWidget *parent = nullptr);
    ~CreateDatabaseConnection();

private:
    Ui::CreateDatabaseConnection *ui;

    void CreateConn();

};

#endif // CREATEDATABASECONNECTION_H
