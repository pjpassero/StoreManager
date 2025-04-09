#ifndef SALESVIEW_H
#define SALESVIEW_H

#include <QMainWindow>

namespace Ui {
class SalesView;
}

class SalesView : public QMainWindow
{
    Q_OBJECT

public:
    explicit SalesView(QWidget *parent = nullptr);
    ~SalesView();

private:
    Ui::SalesView *ui;
};

#endif // SALESVIEW_H
