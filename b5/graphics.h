#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>

class graphics : public QWidget
{
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = 0);
    void timerEvent(QTimerEvent *);
    void paintEvent(QPaintEvent *);

    double timerId;
    double position;
    double hinh, hinh1;
    QPixmap spritesheet;

    void drawMegaman(QPainter& painter);

signals:

public slots:

};

#endif // GRAPHICS_H
