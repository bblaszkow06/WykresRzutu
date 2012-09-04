#include "mainwindow.h"
#include "throwchartwidget.h"
#include "throwcontrolpanel.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QTextCodec::setCodecForTr (QTextCodec::codecForName ("UTF-8"));

    QHBoxLayout *layout = new QHBoxLayout();
    ThrowControlPanel *tcp = new ThrowControlPanel();
    ThrowChartWidget *tcw = new ThrowChartWidget(tcp);
    layout->addWidget(tcw,3);
    layout->addWidget(tcp);

    connect(tcp,SIGNAL(throwRequested()),tcw,SLOT(newThrow()));

    QWidget * cw = new QWidget();
    cw->setLayout(layout);
    setCentralWidget(cw);
    setWindowTitle(tr("Wykres rzutu poziomego"));
}

MainWindow::~MainWindow()
{
}
