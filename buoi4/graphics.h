#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>

class graphics : public QWidget
{
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = 0);
    void timerEvent(QTimerEvent *);
    double position;
    double timerId;

    void paintEvent(QPaintEvent *);
    double w = width();
    double h = height();
    void drawExample(QPainter& painter);

    // quay
//    QPointF pstart, pcenter, pnew;
    int angle;
    QPointF quay(QPointF p, QPointF c, int deta);
    void animationCircle(QPainter& painter);

    void hemattroi(QPainter& painter);

    int random(int n);
    void ngansao(QPainter &painters);


signals:

public slots:

};

#endif // GRAPHICS_H
