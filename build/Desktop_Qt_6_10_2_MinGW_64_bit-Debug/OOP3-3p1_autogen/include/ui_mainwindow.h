/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *btnCircle;
    QPushButton *btnSquare;
    QPushButton *btnLine;
    QPushButton *btnSelect;
    QSpacerItem *verticalSpacer;
    QWidget *drawingContainer;
    QMenuBar *menubar;
    QMenu *menuBETTERPAINT;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, -1, 471, 361));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        btnCircle = new QPushButton(widget);
        btnCircle->setObjectName("btnCircle");

        verticalLayout->addWidget(btnCircle);

        btnSquare = new QPushButton(widget);
        btnSquare->setObjectName("btnSquare");

        verticalLayout->addWidget(btnSquare);

        btnLine = new QPushButton(widget);
        btnLine->setObjectName("btnLine");

        verticalLayout->addWidget(btnLine);

        btnSelect = new QPushButton(widget);
        btnSelect->setObjectName("btnSelect");

        verticalLayout->addWidget(btnSelect);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        drawingContainer = new QWidget(widget);
        drawingContainer->setObjectName("drawingContainer");
        drawingContainer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(drawingContainer, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menuBETTERPAINT = new QMenu(menubar);
        menuBETTERPAINT->setObjectName("menuBETTERPAINT");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuBETTERPAINT->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnCircle->setText(QCoreApplication::translate("MainWindow", "Circle", nullptr));
        btnSquare->setText(QCoreApplication::translate("MainWindow", "Square", nullptr));
        btnLine->setText(QCoreApplication::translate("MainWindow", "Line", nullptr));
        btnSelect->setText(QCoreApplication::translate("MainWindow", "Select", nullptr));
        menuBETTERPAINT->setTitle(QCoreApplication::translate("MainWindow", "BETTERPAINT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
