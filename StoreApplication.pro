QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    StoreManager/StoreManager/BalanceSheet.cpp \
    StoreManager/StoreManager/DataBaseManager.cpp \
    StoreManager/StoreManager/Employee.cpp \
    StoreManager/StoreManager/Product.cpp \
    StoreManager/StoreManager/UserSession.cpp \
    StoreManager/StoreManager/mainStoreManager.cpp \
    StoreManager/StoreManager/store.cpp \
    addemployeeview.cpp \
    addproductview.cpp \
    addvendorview.cpp \
    createdatabaseconnection.cpp \
    employeelistview.cpp \
    firstwindow.cpp \
    homepageview.cpp \
    inventoryview.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    pointofsaleview.cpp \
    productview.cpp

HEADERS += \
    StoreManager/StoreManager/BalanceSheet.h \
    StoreManager/StoreManager/DataBaseManager.h \
    StoreManager/StoreManager/Employee.h \
    StoreManager/StoreManager/Product.h \
    StoreManager/StoreManager/UID.h \
    StoreManager/StoreManager/UserSession.h \
    StoreManager/StoreManager/store.h \
    addemployeeview.h \
    addproductview.h \
    addvendorview.h \
    createdatabaseconnection.h \
    employeelistview.h \
    firstwindow.h \
    homepageview.h \
    inventoryview.h \
    loginwindow.h \
    mainwindow.h \
    pointofsaleview.h \
    productview.h

FORMS += \
    addemployeeview.ui \
    addproductview.ui \
    addvendorview.ui \
    createdatabaseconnection.ui \
    employeelistview.ui \
    firstwindow.ui \
    homepageview.ui \
    inventoryview.ui \
    loginwindow.ui \
    mainwindow.ui \
    pointofsaleview.ui \
    productview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    StoreManager/StoreManager.xcodeproj/project.pbxproj \
    StoreManager/StoreManager.xcodeproj/project.xcworkspace/contents.xcworkspacedata \
    StoreManager/StoreManager.xcodeproj/project.xcworkspace/xcuserdata/pjpassero.xcuserdatad/UserInterfaceState.xcuserstate \
    StoreManager/StoreManager.xcodeproj/xcuserdata/pjpassero.xcuserdatad/xcschemes/xcschememanagement.plist \
    StoreManager/StoreManager/StoreDataFiles/LumberCo/LumberCo.txt \
    StoreManager/StoreManager/StoreDataFiles/LumberCo/employee/employee.txt \
    StoreManager/StoreManager/StoreDataFiles/LumberCo/inventory/inventory.csv \
    StoreManager/StoreManager/StoreDataFiles/LumberCo/inventory/inventory.txt


# Include directories for libpq and libpqxx
INCLUDEPATH += /opt/homebrew/include /opt/homebrew/opt/libpq/include

# Link libraries for libpqxx and libpq
LIBS += -L/opt/homebrew/lib -L/opt/homebrew/opt/libpq/lib -lpqxx -lpq
