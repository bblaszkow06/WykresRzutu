#include "mainwindow.h"
#include "throwchartwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ThrowChartWidget *tcw = new ThrowChartWidget(this);
    setCentralWidget(tcw);
    setWindowTitle(tr("Wykres rzutu poziomego"));
}

MainWindow::~MainWindow()
{
}
