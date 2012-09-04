#include "throwcontrolpanel.h"
#include <QtGui>

ThrowControlPanel::ThrowControlPanel(QWidget *parent) :
    QWidget(parent)
{
    hRadio = new QRadioButton(tr("Wysokość"));
    tRadio = new QRadioButton(tr("Czas"));
    vRadio = new QRadioButton(tr("Prędkość"));
    sRadio = new QRadioButton(tr("Zasięg"));

    valBoxOne = new QDoubleSpinBox();
    valBoxTwo = new QDoubleSpinBox();

    button= new QPushButton(tr("Rzuć!"));

    QVBoxLayout * layout = new QVBoxLayout();

    layout->addWidget(createGroupBox(hRadio,tRadio,valBoxOne,20.0));
    layout->addWidget(createGroupBox(vRadio,sRadio,valBoxTwo,15.0));
    layout->addWidget(createComboBox());
    layout->addWidget(button);

    connect(button,SIGNAL(clicked()),this,SIGNAL(throwRequested()));

    setLayout(layout);
}

QGroupBox * ThrowControlPanel::createGroupBox(QRadioButton * radioA, QRadioButton * radioB, QDoubleSpinBox * spinBox, double spinBoxVal)
{
    QGroupBox *groupBox = new QGroupBox();

    spinBox->setValue(spinBoxVal);
    radioA->setChecked(true);

    QGridLayout * grid = new QGridLayout();
    grid->addWidget(radioA,0,0);
    grid->addWidget(radioB,0,1);
    grid->addWidget(spinBox,1,0,1,2);

    groupBox->setLayout(grid);

    return groupBox;
}

QGroupBox * ThrowControlPanel::createComboBox()
{
    this->gravBox = new QComboBox();

    QGroupBox *groupBox = new QGroupBox(tr("Wartość przyspieszenia ziemskiego:"));

    gravBox->addItem(tr("Normalne (%1)").arg(GravAcc::NORM),GravAcc::NORM);
    gravBox->addItem(tr("Biegun (%1)").arg(GravAcc::POLE),GravAcc::POLE);
    gravBox->addItem(tr("Równik (%1)").arg(GravAcc::EQUATOR), GravAcc::EQUATOR);
    gravBox->addItem(tr("Kraków (%1)").arg(GravAcc::KRA),GravAcc::KRA);
    gravBox->addItem(tr("Gdańsk (%1)").arg(GravAcc::GDA),GravAcc::GDA);
    gravBox->addItem(tr("Warszawa (%1)").arg(GravAcc::WWA),GravAcc::WWA);

    QHBoxLayout * layout = new QHBoxLayout();
    layout->addWidget(gravBox);

    groupBox->setLayout(layout);

    return groupBox;
}
