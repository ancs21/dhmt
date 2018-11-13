#include "graphics.h"
#include <QPainter>
#include <QPixmap>
#include <QRect>

graphics::graphics(QWidget *parent) :
    QWidget(parent)
{
    position = 0;
    hinh = 0;
    timerId = startTimer(100);
}
void graphics::timerEvent(QTimerEvent *) {
    position += 1;
    hinh += 1;
//    if (hinh == 10) hinh = 0;
//     if (hinh == 112) hinh = 0;

    // walkman
    hinh1 += 1;
    if (hinh1 == 8) hinh1 = 0;
    if (hinh == 4) hinh = 0;
    repaint();
}

void graphics::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 5, Qt::SolidLine));
    drawMegaman(painter);
}

void graphics::drawMegaman(QPainter &painter) {
    // megaman
//    QPixmap spritesheet("D://b5/b5/Megaman.png");
//    double wHinh = spritesheet.width()/10;
//    double hHinh = spritesheet.height();
//    int r = 5;
//    QRect displaywindow(wHinh*hinh,0,wHinh, hHinh);
//    QRect pos(200, height()/2, wHinh*2, hHinh*2);
//    painter.drawPixmap(pos, spritesheet, displaywindow);

//    // baymax
//    QPixmap spritesheet("D://b5/b5/baymax.png");
//    double wHinh = spritesheet.width()/112;
//    double hHinh = spritesheet.height();
//    QRect displaywindow(wHinh*hinh,0,wHinh, hHinh);
//    QRect pos(100, height()/2, wHinh, hHinh);
//    painter.drawPixmap(pos, spritesheet, displaywindow);

    // walkman
    QPixmap spritesheet1("D://b5/b5/walkman.png");
    double wHinh1 = spritesheet1.width()/8;
    double hHinh1 = spritesheet1.height();
    QRect displaywindow1(wHinh1*hinh1,0,wHinh1, hHinh1);
    QRect pos1(5*position, height()/2, wHinh1/2, hHinh1/2);
    painter.drawPixmap(pos1, spritesheet1, displaywindow1);

    // walking girl
//    QPixmap spritesheet("D://b5/b5/walking-girl.png");
//    double wHinh = spritesheet.width()/4;
//    double hHinh = spritesheet.height();
//    QRect displaywindow(wHinh*hinh,0,wHinh, hHinh);
//    QRect pos(200, height()/4, wHinh/4, hHinh/4);
//    painter.drawPixmap(pos, spritesheet, displaywindow);
}


