#ifndef THROWCHARTWIDGET_H
#define THROWCHARTWIDGET_H

#include <QGLWidget>
#include <QPainter>
#include <QPaintEvent>
#include "horizontalthrow.h"
#include "throwcontrolpanel.h"

class ThrowChartWidget : public QGLWidget
{
    Q_OBJECT
public:
    static const int MinSizeX = 400;
    static const int MinSizeY = 300;
    static const int LRMargin = 15;
    static const int UDMargin = 15;

    explicit ThrowChartWidget(ThrowControlPanel * thrCP ,QWidget *parent = 0);

public slots:
    void newThrow();

protected:
    void paintEvent(QPaintEvent *);

private:
    HorizontalThrow th;

    ThrowControlPanel * tcp;

    QPen axisPen;
    QFont axisLabelFont;
    QBrush background;
    QPen chartPen;
    
    void drawAxes(QPainter * painter);
    void drawChart(QPainter * painter);
};

#endif // THROWCHARTWIDGET_H
