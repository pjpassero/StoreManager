#ifndef EMPLOYEECREATORVIEW_H
#define EMPLOYEECREATORVIEW_H

#include <QMainWindow>            // Include QMainWindow
#include "ui_EmployeeCreatorView.h" // Include the generated UI header file

namespace Ui {
class EmployeeCreatorView;
}

class EmployeeCreatorView : public QMainWindow {
    Q_OBJECT

public:
    explicit EmployeeCreatorView(QWidget *parent = nullptr);
    ~EmployeeCreatorView();

private:
    Ui::EmployeeCreatorView *ui;  // Pointer to the UI
};

#endif // EMPLOYEECREATORVIEW_H
