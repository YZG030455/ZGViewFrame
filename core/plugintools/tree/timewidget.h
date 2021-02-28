#ifndef TIMEWIDGET_H
#define TIMEWIDGET_H

#include <QWidget>

class TimeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TimeWidget(QWidget *parent = 0);

signals:

public slots:
    void slotTimerOut();

    QRectF  textRectF(double radius, int pointSize, double angle);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};

#endif // TIMEWIDGET_H
