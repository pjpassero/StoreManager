#ifndef HOMEPAGEVIEW_H
#define HOMEPAGEVIEW_H

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
};

#endif // HOMEPAGEVIEW_H
