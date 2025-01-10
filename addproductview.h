#ifndef ADDPRODUCTVIEW_H
#define ADDPRODUCTVIEW_H
#include <pqxx/pqxx>
#include <QDialog>

namespace Ui {
class AddProductView;
}

class AddProductView : public QDialog
{
    Q_OBJECT

public:
    explicit AddProductView(QWidget *parent, pqxx::connection &conn);
    ~AddProductView();


private:
    Ui::AddProductView *ui;
    pqxx::connection &C;
    void CreateNewProduct();
    void populateVendorList();


};

#endif // ADDPRODUCTVIEW_H
