#include "graphics.h"
#include <QPainter>
#include <QString>
#include <math.h>

graphics::graphics(QWidget *parent) :
    QWidget(parent)
{
    position = 50;
    timerId = startTimer(100);
    angle = 1;
}

void graphics::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
//    drawExample(painter);
//    animationCircle(painter);
    hemattroi(painter);
//    ngansao(painter);
}

void graphics::timerEvent(QTimerEvent *) {
    if (position == 0) {
        position = 50;
    }
    position -= 1;

    angle += 30;
    repaint();
}

void graphics::drawExample(QPainter& painter) {
    painter.setBrush(QBrush("#b40000"));

    QString fileImg = "D://buoi4//buoi4//oto.png";
    painter.drawPixmap(position, h/2, 382, 215, QPixmap(fileImg));

}

// ham quay
QPointF graphics::quay(QPointF p, QPointF c, int deta) {
    QPointF pnew;
    double goc = deta*3.14/180;
    pnew.setX(c.x() + (p.x() - c.x())*cos(goc) - (p.y() - c.y())*sin(goc));
    pnew.setY(c.y() + (p.x() - c.x())*sin(goc) + (p.y() - c.y())*cos(goc));
    return pnew;
}

void graphics::animationCircle(QPainter &painter) {
    double w = width();
    double h = height();
    painter.setPen(Qt::red);
    painter.drawEllipse(w/2, h/2, 10, 10);
    QPointF pQuay = quay(QPointF(w/2, h/2-100), QPointF(w/2, h/2), angle);
    painter.drawEllipse(pQuay, 20, 20);
}

void graphics::hemattroi(QPainter &painter) {
    double w = width();
    double h = height();

    QString sun = "D://buoi4//buoi4//sun.png";
    QString moon = "D://buoi4//buoi4//moon.png";
    QString earth = "D://buoi4//buoi4//earth.png";

    //sun in center
    painter.drawPixmap(w/2-40, h/2-40, 80, 80, QPixmap(sun));

    QPointF pQuay = quay(QPointF(w/2, h/2-200), QPointF(w/2, h/2), angle/4);
    painter.drawPixmap(pQuay.x()-25, pQuay.y()-25, 50, 50, QPixmap(earth));

    QPointF pQuay1 = quay(QPointF(pQuay.x(), pQuay.y()+75), pQuay, angle);
    painter.drawPixmap(pQuay1.x()-15, pQuay1.y()-15, 30, 30, QPixmap(moon));
}

int graphics::random(int n) {
    return rand() % n;
}

void graphics::ngansao(QPainter &painters) {
    for (int i = 0; i<1000;i++) {
        painters.setPen(Qt::NoPen);
        painters.setBrush(QColor(random(255), random(255), random(255)));
        painters.drawEllipse(random(1000), random(1000), position, position);
    }
}
