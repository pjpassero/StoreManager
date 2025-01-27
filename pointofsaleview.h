/*
 * Philip J. Passero IV
 * pointofsaleview.h
 *
 *
 * In development
 *
 * This will eventually be the home of the Point of Sale window for the application
 */

#ifndef POINTOFSALEVIEW_H
#define POINTOFSALEVIEW_H

#include <QMainWindow>

namespace Ui {
class PointOfSaleView;
}

class PointOfSaleView : public QMainWindow
{
    Q_OBJECT

public:
    explicit PointOfSaleView(QWidget *parent = nullptr);
    ~PointOfSaleView();

private:
    Ui::PointOfSaleView *ui;
};

#endif // POINTOFSALEVIEW_H
