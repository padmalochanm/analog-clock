#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void Mouse_Pressed();
    void showMousePosition(QPoint& pos);
    void drawClockHands();
    void startTimer(QTimer *timer);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;
    QPoint p1,p2;
    void point(int,int);
    void pointColor(int,int,int,int,int);
    void on_BresenhamCircle_clicked1(int r);
    void on_pushButton_5_clicked1(int x1, int y1, int x2, int y2, int r, int g, int b);
    void drawHand(int angle, int length, int r, int g, int b);
};

#endif // MAINWINDOW_H
