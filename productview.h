/*
 * Philip J. Passero IV
 * productview.h
 *
 *Creates the product view for the application
 */


#ifndef PRODUCTVIEW_H
#define PRODUCTVIEW_H

#include <QDialog>

namespace Ui {
class ProductView;
}

class ProductView : public QDialog
{
    Q_OBJECT

public:
    explicit ProductView(QWidget *parent = nullptr);
    ~ProductView();

private:
    Ui::ProductView *ui;
};

#endif // PRODUCTVIEW_H
