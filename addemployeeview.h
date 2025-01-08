#ifndef ADDEMPLOYEEVIEW_H
#define ADDEMPLOYEEVIEW_H

#include <QMainWindow>

namespace Ui {
class AddEmployeeView;
}

class AddEmployeeView : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddEmployeeView(QWidget *parent = nullptr);
    ~AddEmployeeView();

private:
    Ui::AddEmployeeView *ui;
};

#endif // ADDEMPLOYEEVIEW_H
