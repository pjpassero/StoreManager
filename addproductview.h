#ifndef ADDPRODUCTVIEW_H
#define ADDPRODUCTVIEW_H

#include <QDialog>

namespace Ui {
class AddProductView;
}

class AddProductView : public QDialog
{
    Q_OBJECT

public:
    explicit AddProductView(QWidget *parent = nullptr);
    ~AddProductView();


private:
    Ui::AddProductView *ui;
    void CreateNewProduct();
};

#endif // ADDPRODUCTVIEW_H
