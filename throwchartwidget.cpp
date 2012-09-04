#include "throwchartwidget.h"

ThrowChartWidget::ThrowChartWidget(ThrowControlPanel *thrCP, QWidget *parent) :
    QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    tcp = thrCP;
    newThrow();

    background = QBrush(Qt::lightGray, Qt::CrossPattern);

    axisPen = QPen(Qt::black);
    axisPen.setWidth(4);
    axisPen.setJoinStyle(Qt::MiterJoin);
    axisPen.setCapStyle(Qt::RoundCap);

    chartPen = QPen(Qt::red);
    chartPen.setWidth(2);

    setMinimumSize(MinSizeX + 2*LRMargin,MinSizeY + 2*UDMargin);
}

void ThrowChartWidget::newThrow()
{
    if (tcp->isHSelected())
    {
        if (tcp->isVSelected())
        {
            th = HorizontalThrow(Length(tcp->getValueA()),Speed(tcp->getValueB()),tcp->getValueG());
        }
        else if (tcp->isSSelected())
        {
            th = HorizontalThrow(Length(tcp->getValueA()),Length(tcp->getValueB()),tcp->getValueG());
        }
    }
    else if (tcp->isTSelected())
    {
        if (tcp->isVSelected())
        {
            th = HorizontalThrow(Time(tcp->getValueA()),Speed(tcp->getValueB()),tcp->getValueG());
        }
        else if (tcp->isSSelected())
        {
            th = HorizontalThrow(Length(tcp->getValueB()),Time(tcp->getValueA()),tcp->getValueG());
        }
    }

    update();
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
    drawChart(&painter);

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

    const double PX_PER_M = 4.0;
//    const double HEIGHT = 20.0;
//    const double VEL = 15.0;
//    const double G = 10.0;
//    HorizontalThrow th(Length(HEIGHT),Speed(VEL),G);

    int yLen = this->height()-2*UDMargin;
    double x = 0;
    double y = yLen - th.getHeight()*PX_PER_M;
    do
    {
        painter->drawPoint(QPointF(x,y));
        x++;
        y = yLen - (th.getY(x/PX_PER_M)*PX_PER_M);
    } while (y <= yLen);

    painter->restore();
}
