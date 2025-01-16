#ifndef ADDVENDORVIEW_H
#define ADDVENDORVIEW_H
#include <pqxx/pqxx>
#include <QDialog>

namespace Ui {
class AddVendorView;
}

class AddVendorView : public QDialog
{
    Q_OBJECT

public:
    explicit AddVendorView(QWidget *parent, pqxx::connection &conn);
    ~AddVendorView();

private:
    Ui::AddVendorView *ui;
    pqxx::connection &C;
};

#endif // ADDVENDORVIEW_H
