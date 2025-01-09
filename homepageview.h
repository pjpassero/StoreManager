#ifndef HOMEPAGEVIEW_H
#define HOMEPAGEVIEW_H
#include <inventoryview.h>
#include <QMainWindow>

namespace Ui {
class HomePageView;
}

class HomePageView : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomePageView(QWidget *parent = nullptr);
    ~HomePageView();

private:
    Ui::HomePageView *ui;
    InventoryView *inventory;
    void LoadInventoryView();

};

#endif // HOMEPAGEVIEW_H
