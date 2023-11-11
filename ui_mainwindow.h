/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <my_label.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    my_label *frame;
    QLabel *mouse_movement;
    QLabel *label_3;
    QLabel *mouse_pressed;
    QLabel *label_5;
    QFrame *x_axis;
    QFrame *y_axis;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(713, 743);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        frame = new my_label(centralWidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 9, 711, 691));
        frame->setCursor(QCursor(Qt::CrossCursor));
        frame->setMouseTracking(true);
        frame->setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 0), stop:0.52 rgba(0, 0, 0, 0), stop:0.565 rgba(82, 121, 76, 33), stop:0.65 rgba(159, 235, 148, 64), stop:0.721925 rgba(255, 238, 150, 129), stop:0.77 rgba(255, 128, 128, 204), stop:0.89 rgba(191, 128, 255, 64), stop:1 rgba(0, 0, 0, 0));"));
        frame->setFrameShape(QFrame::Box);
        frame->setLineWidth(1);
        mouse_movement = new QLabel(centralWidget);
        mouse_movement->setObjectName("mouse_movement");
        mouse_movement->setGeometry(QRect(720, 70, 111, 31));
        mouse_movement->setFrameShape(QFrame::Panel);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(720, 50, 111, 20));
        mouse_pressed = new QLabel(centralWidget);
        mouse_pressed->setObjectName("mouse_pressed");
        mouse_pressed->setGeometry(QRect(720, 140, 111, 31));
        mouse_pressed->setFrameShape(QFrame::Panel);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(730, 120, 81, 20));
        x_axis = new QFrame(centralWidget);
        x_axis->setObjectName("x_axis");
        x_axis->setGeometry(QRect(0, 225, 700, 1));
        x_axis->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 255);"));
        x_axis->setFrameShape(QFrame::HLine);
        x_axis->setFrameShadow(QFrame::Sunken);
        y_axis = new QFrame(centralWidget);
        y_axis->setObjectName("y_axis");
        y_axis->setGeometry(QRect(225, 0, 1, 700));
        y_axis->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(85, 255, 255);"));
        y_axis->setFrameShape(QFrame::VLine);
        y_axis->setFrameShadow(QFrame::Sunken);
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(320, 100, 63, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe Script")});
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(13, 116, 147);"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(320, 580, 63, 31));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(13, 116, 147);"));
        label_2->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(90, 340, 63, 31));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(13, 116, 147);"));
        label_4->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(550, 340, 63, 31));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(13, 116, 147);"));
        label_6->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 713, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        frame->setText(QString());
        mouse_movement->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "    Mouse Movement", nullptr));
        mouse_pressed->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Mouse Pressed", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "12", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
