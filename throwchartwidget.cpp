#include "throwchartwidget.h"

ThrowChartWidget::ThrowChartWidget(QWidget *parent) :
    QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    background = QBrush(Qt::lightGray, Qt::CrossPattern);

    axisPen = QPen(Qt::black);
    axisPen.setWidth(4);
    axisPen.setJoinStyle(Qt::MiterJoin);
    axisPen.setCapStyle(Qt::RoundCap);

    chartPen = QPen(Qt::red);
    chartPen.setWidth(2);

    setMinimumSize(MinSizeX + 2*LRMargin,MinSizeY + 2*UDMargin);
}

void ThrowChartWidget::paintEvent(QPaintEvent * event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);

    //background
    painter.fillRect(event->rect(), background);
    painter.translate(LRMargin,UDMargin);

    //skalowanie?
    drawAxes(&painter);

    //TODO: drawing code here
    painter.end();
}

void ThrowChartWidget::drawAxes(QPainter * painter)
{
    painter->save();

    painter->setPen(axisPen);

    const int arrowWidth = 20;
    const int arrowHeigth = 10;

    // Y-Axis
    int yLen = this->height()-2*UDMargin;

    painter->drawLine(0,0,0,yLen);
    painter->drawLine(0,0,-arrowWidth/2,arrowHeigth);
    painter->drawLine(0,0,arrowWidth/2,arrowHeigth);

    // X-Axis
    int xLen = this->width() - 2*LRMargin;
    painter->drawLine(0,yLen,xLen,yLen);
    painter->drawLine(xLen,yLen,xLen-arrowHeigth,yLen+arrowWidth/2);
    painter->drawLine(xLen,yLen,xLen-arrowHeigth,yLen-arrowWidth/2);

    painter->restore();
}

void ThrowChartWidget::drawChart(QPainter * painter)
{
    painter->save();

    painter->setPen(chartPen);

    const int PX_PER_M = 4;
    const int HEIGHT = 20;
    const int VEL = 15;
    const int G = 10;

    HorizontalThrow th(Length(HEIGHT),Speed(VEL),G);

    int x = 0;
    int y = HEIGHT;
    do
    {
       // painter->drawPoint();
       //x & y
    } while (y >= 0)

    paiter->restore();
}
