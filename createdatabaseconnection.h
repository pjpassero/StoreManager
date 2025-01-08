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
    void CreateStoreDatabaseCredentialFile(const std::string& db, const std::string& uname, const std::string& password, const std::string& host, const std::string& port);



};

#endif // CREATEDATABASECONNECTION_H
