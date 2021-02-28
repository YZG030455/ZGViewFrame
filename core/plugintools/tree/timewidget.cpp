#include "timewidget.h"

#include "math.h"
#include <QTimer>
#include <QPainter>
#include <QtWidgets>


TimeWidget::TimeWidget(QWidget *parent)
    : QWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerOut()));
    timer->start(1000);

    setWindowTitle(tr("Analog Clock"));
//    resize(400, 400);
}

void TimeWidget::slotTimerOut()
{
    this->update();
}

QRectF TimeWidget::textRectF(double radius, int pointSize, double angle)
{
    QRectF rectF;
    rectF.setX(radius * qCos(angle * M_PI/ 180) - pointSize *2);
    rectF.setY(radius * qSin(angle * M_PI/ 180) - pointSize *2);
    rectF.setWidth(pointSize *4);
    rectF.setHeight(pointSize);

    return rectF;
}

void TimeWidget::paintEvent(QPaintEvent *event)
{
    static const QPoint hourHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -40)
    };
    static const QPoint minuteHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -60)
    };

    static const QPoint secondHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -80)
    };

    QColor hourColor(127, 0, 127);
    QColor minuteColor(0, 127, 127, 191);
    QColor secondColor(0, 127, 127, 191);

    int side = qMin(width(), height());
    QTime time = QTime::currentTime();


    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    //平移坐标系原点至中心
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 200.0, side / 200.0);   // 缩放

    // 绘制时针
    painter.setPen(Qt::NoPen);
    painter.setBrush(hourColor);
    painter.save();
    //每圈 360 = 12h  即：旋转角度 = 小时 * 30
    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    painter.drawConvexPolygon(hourHand ,2);
    //    QPen pen;
    //    pen.setColor(Qt::red);
    //    pen.setWidth(2);
    //    painter.setPen(pen);
    //    painter.drawLine(QPoint(0, 0) ,QPoint(60, 60));
    painter.restore();


    painter.setPen(hourColor);

    // 绘制小时线 （360/ 12 = 30）
    for (int i = 0; i < 12; ++i) {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }

    int radius = 100;
    QFont font = painter.font();
    font.setBold(true);
    painter.setFont(font);
    int pointSize = font.pointSize();

    //绘制小时文本
    int nHour = 0;
    for(int i = 0; i< 12; ++i)
    {
        nHour = i*3;
        if(nHour > 12)
        {
            nHour -=12;
        }
        painter.drawText(textRectF(radius *0.8,pointSize, i* 30), Qt::AlignCenter, QString::number(nHour));
    }

    // 绘制分针
    painter.setPen(Qt::NoPen);
    painter.setBrush(minuteColor);
    painter.save();
    //每圈 360 = 12h  即：旋转角度 = 小时 * 30
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();

    painter.setPen(minuteColor);

    for (int j = 0; j < 60; ++j) {
        if ((j % 5) != 0)
            painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }

    // 绘制秒针
    painter.setPen(Qt::NoPen);
    painter.setBrush(secondColor);
    painter.save();
    painter.rotate(6.0 * ( time.second()));
    painter.drawConvexPolygon(secondHand, 3);
    painter.restore();
}
