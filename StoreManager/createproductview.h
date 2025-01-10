#ifndef CREATEPRODUCTVIEW_H
#define CREATEPRODUCTVIEW_H

#include <QDialog>

namespace Ui {
class CreateProductView;
}

class CreateProductView : public QDialog
{
    Q_OBJECT

public:
    explicit CreateProductView(QWidget *parent = nullptr);
    ~CreateProductView();

private:
    Ui::CreateProductView *ui;
};

#endif // CREATEPRODUCTVIEW_H
