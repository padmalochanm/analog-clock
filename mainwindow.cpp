#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QImage>
#include <iostream>
#include<vector>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintDevice>
#include <QPoint>
#include <cmath>
#include <ctime>
#include<utility>
using namespace std;

vector<pair<int,int>>p;
vector<pair<int,int>>v1;
vector<pair<int,int>>v2;
vector<pair<int,int>>v3;
vector<pair<int,pair<int,int>>>bresh_circle;
int gSize=5;
class Color{
public:
    int r;
    int g;
    int b;
    Color() {
        r = g = b = 0;
    }

    Color(int r, int g, int b) {
        this->r = r;
        this->g = g;
        this->b = b;
    }

    Color(Color &c) {
        this->r = c.r;
        this->g = c.g;
        this->b = c.b;
    }

    void setColor(int r, int g, int b) {
        this->r = r;
        this->g = g;
        this->b = b;
    }
};

Color clicked[700][700];
QImage img=QImage(700,700,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    p1.setX(0);
    p1.setY(0);
    p2.setX(0);
    p2.setY(0);

    ui->setupUi(this);
    ui->x_axis->hide();
    ui->y_axis->hide();
    connect(ui->frame,SIGNAL(Mouse_Pos()),this,SLOT(Mouse_Pressed()));
    connect(ui->frame,SIGNAL(sendMousePosition(QPoint&)),this,SLOT(showMousePosition(QPoint&)));
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(drawClockHands()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::point(int x,int y){

    int n = gSize, x_mid = img.width() / 2 - (img.width() / 2) % n, y_mid = img.height() / 2 - (img.height() / 2) % n;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if ((x_mid + i + x * n) < img.width() && x_mid + i + x * n >= 0 && y_mid - (j + (y - 1) * n) < img.height() && y_mid - (j + (y - 1) * n) >= 0) {
                img.setPixel(x_mid + i + x * n, y_mid - (j + (y - 1) * n),qRgb(255,255,0));
            }
        }
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::pointColor(int x,int y, int r, int g, int b)
{
    int n = gSize, x_mid = img.width() / 2 - (img.width() / 2) % n, y_mid = img.height() / 2 - (img.height() / 2) % n;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (x_mid + i + x * n < img.height() && x_mid + i + x * n >= 0 && y_mid - (j + (y - 1) * n) < img.height() && y_mid - (j + (y - 1) * n) >= 0) {
                img.setPixel(x_mid + i + x * n, y_mid - (j + (y - 1) * n),qRgb(r, g, b));
            }
        }
    }

    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::showMousePosition(QPoint &pos){
    int x = pos.x(), y = pos.y();
    x =  x / gSize - (img.width() / 2) / gSize;
    y =  (img.height() / 2) / gSize - y / gSize;
    ui->mouse_movement->setText(" X : " + QString::number(x) + ", Y : " + QString::number(y));
}

void MainWindow::Mouse_Pressed(){
    int x = ui->frame->x, y = ui->frame->y;
    x =  x / gSize - (img.width() / 2) / gSize;
    y =  (img.height() / 2) / gSize - y / gSize;
    p.push_back({x,y});
    ui->mouse_pressed->setText(" X : "+QString::number(x)+", Y : "+QString::number(y));
    p2.setX(p1.x());
    p2.setY(p1.y());
    p1.setX(x);
    p1.setY(y);
    pointColor(x,y,0,255,0);
}

void MainWindow::startTimer(QTimer *timer){
    timer->start(1000); // Start the timer with a 1000ms interval (1 second).
}

void MainWindow::on_BresenhamCircle_clicked1(int r){
    int dx = 0;
    int dy = 0;
    bresh_circle.push_back({r,{dx,dy}});
    int x = 0, y = r;
    int P = 1 - r;
    while(x<=y){
        pointColor(x+dx, y+dy, 255, 255, 0);
        pointColor(-x+dx, y+dy, 255, 255, 0);
        pointColor(x+dx, -y+dy, 255, 255, 0);
        pointColor(-x+dx, -y+dy, 255, 255, 0);
        pointColor(y+dx, x+dy, 255, 111, 0);
        pointColor(-y+dx, x+dy, 255, 111, 0);
        pointColor(y+dx, -x+dy, 255, 111, 0);
        pointColor(-y+dx, -x+dy, 255, 111, 0);
        x++;

        if (P < 0) {
            P += 2 * x + 1;
        }
        else{
            y--;
            P += 2 * (x - y) + 1;
        }
    }
    pointColor(0,0,255,255,255);

    pointColor(0,17,255, 255, 255);
    pointColor(17,0,255, 255, 255);
    pointColor(0,-17,255, 255, 255);
    pointColor(-17,0,255, 255, 255);

    pointColor(0,52,255, 255, 255);
    pointColor(52,0,255, 255, 255);
    pointColor(0,-52,255, 255, 255);
    pointColor(-52,0,255, 255, 255);
    pointColor(0,53,255, 255, 255);
    pointColor(53,0,255, 255, 255);
    pointColor(0,-53,255, 255, 255);
    pointColor(-53,0,255, 255, 255);
    pointColor(0,54,255, 255, 255);
    pointColor(54,0,255, 255, 255);
    pointColor(0,-54,255, 255, 255);
    pointColor(-54,0,255, 255, 255);
    pointColor(0,55,255, 255, 255);
    pointColor(55,0,255, 255, 255);
    pointColor(0,-55,255, 255, 255);
    pointColor(-55,0,255, 255, 255);
    pointColor(0,56,255, 255, 255);
    pointColor(56,0,255, 255, 255);
    pointColor(0,-56,255, 255, 255);
    pointColor(-56,0,255, 255, 255);

    pointColor(8, 15, 255, 255, 255);
    pointColor(15, 8, 255, 255, 255);
    pointColor(-15, 8, 255, 255, 255);
    pointColor(-8, 15, 255, 255, 255);
    pointColor(15, -8, 255, 255, 255);
    pointColor(8, -15, 255, 255, 255);
    pointColor(-8, -15, 255, 255, 255);
    pointColor(-15, -8, 255, 255, 255);

    ui->frame->setPixmap(QPixmap::fromImage(img));
}

vector<pair<int,int>> vcl;
void MainWindow::on_pushButton_5_clicked1(int x1, int y1, int x2, int y2, int r, int g, int b){
    vcl.push_back({x1,y1});
    vcl.push_back({x2,y2});
    pointColor(x1, y1, r, g, b);
    pointColor(x2, y2, r, g, b);

    int dx = x1-x2;
    int dy = y1-y2;
    if (dy == 0) {
        for (int x = fmin(x1, x2); x <=fmax(x1, x2); x++) {
            vcl.push_back({x,y1});
            pointColor(x, y1, r, g, b);
        }
    } else if (dx * dy > 0) {
        // positive slope
        dy = abs(dy);
        dx = abs(dx);
        if (dx > dy) {
            // slope < 1
            int p = 2 * dy - dx;
            int k = 0;
            int x, y;
            if (x1<=x2) {
                x = x1;
                y = y1;
            } else {
                x = x2;
                y = y2;
            }
            while (k <= dx) {
                if (x != x1 && x != x2) {
                    vcl.push_back({x,y});
                    pointColor(x, y, r, g, b);
                }
                x = x + 1;
                if (p < 0) {
                    p = p + 2 * dy;
                } else {
                    y = y + 1;
                    p = p + 2 * (dy - dx);
                }
                k++;
            }
        } else {
            // slope > 1
            int p = 2 * dx - dy;
            int k = 0;
            int x, y;
            if (y1<=y2) {
                x = x1;
                y = y1;
            } else {
                x = x2;
                y = y2;
            }
            while (k <= dy) {
                if (y != y1 && y != y2) {
                    vcl.push_back({x,y});
                    pointColor(x, y, r, g, b);
                }
                y = y + 1;
                if (p < 0) {
                    p = p + 2 * dx;
                } else {
                    x = x + 1;
                    p = p + 2 * (dx - dy);
                }
                k++;
            }
        }
    } else if (dx * dy < 0) {
        // positive slope
        dy = abs(dy);
        dx = abs(dx);
        if (dx > dy) {
            // slope < 1
            int p = 2 * dy - dx;
            int k = 0;
            int x, y;
            if (x1<=x2) {
                x = x1;
                y = y1;
            } else {
                x = x2;
                y = y2;
            }
            while (k <= dx) {
                if (x != x1 && x != x2) {
                    vcl.push_back({x,y});
                    pointColor(x, y, r, g, b);
                }
                x = x + 1;
                if (p < 0) {
                    p = p + 2 * dy;
                } else {
                    y = y - 1;
                    p = p + 2 * (dy - dx);
                }
                k++;
            }
        } else {
            // slope > 1
            int p = 2 * dx - dy;
            int k = 0;
            int x, y;
            if (y1 <= y2) {
                x = x1;
                y = y1;
            } else {
                x = x2;
                y = y2;
            }
            while (k <= dy) {
                if (y != y1 && y != y2) {
                    vcl.push_back({x,y});
                    pointColor(x, y, r, g, b);
                }
                y = y + 1;
                if (p < 0) {
                    p = p + 2 * dx;
                } else {
                    x = x - 1;
                    p = p + 2 * (dx - dy);
                }
                k++;
            }
        }
    } else {
        for (int y = fmin(y1, y2); y <=fmax(y1, y2); y++) {
            vcl.push_back({p1.x(),y});
            pointColor(p1.x(), y, r, g, b);
        }
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::drawClockHands() {
    for(int i = 0;i<vcl.size();i++){
        pointColor(vcl[i].first,vcl[i].second,0,0,0);
    }
    vcl.clear();
    QTime currentTime = QTime::currentTime();

    on_BresenhamCircle_clicked1(54);
    on_BresenhamCircle_clicked1(53);
    int hour = currentTime.hour();
    int minute = currentTime.minute();
    int second = currentTime.second();


    // Draw the hour hand
    int hourLength = 15;
    int hourAngle = 90 - (30 * (hour + (float)minute / 60));
    cout<< hour<<"  "<< hourAngle<<endl;
    drawHand(hourAngle, hourLength, 255, 255, 255);

    // Draw the minute hand
    int minuteLength = 30;
    int minuteAngle = 90 - (6 * minute);
    cout<< minute<<" "<<minuteAngle<<endl;
    drawHand(minuteAngle, minuteLength, 0, 255, 255);

    // Draw the second hand
    int secondLength = 45;
    int secondAngle = 90 - 6 * second;
    cout<< second<<" "<<secondAngle<<endl;
    drawHand(secondAngle, secondLength, 0, 102, 255);
    pointColor(0, 0, 255, 255, 255);
}

void MainWindow::drawHand(int angle, int length, int r, int g, int b) {
    int x1 = 0;
    int y1 = 0;
    int x2 = length * cos(qDegreesToRadians(angle));
    int y2 = (length) * sin(qDegreesToRadians(angle));
    on_pushButton_5_clicked1(x1, y1, x2, y2, r, g, b);
}



