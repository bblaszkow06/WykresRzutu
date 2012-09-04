#ifndef THROWCONTROLPANEL_H
#define THROWCONTROLPANEL_H

#include <QWidget>
#include <QRadioButton>
#include <QGroupBox>
#include <QDoubleSpinBox>
#include <QComboBox>
#include "F:/CPP/Fizyka/Jednostki/grav_acc.h"

class QPushButton;

class ThrowControlPanel : public QWidget
{
    Q_OBJECT
public:
    explicit ThrowControlPanel(QWidget *parent = 0);
    
    bool isHSelected() {return hRadio->isChecked(); }
    bool isTSelected() {return tRadio->isChecked(); }
    bool isSSelected() {return sRadio->isChecked(); }
    bool isVSelected() {return vRadio->isChecked(); }

    double getValueA() {return valBoxOne->value(); }
    double getValueB() {return valBoxTwo->value(); }
    double getValueG() {return gravBox->itemData(gravBox->currentIndex()).toDouble(); }

signals:
    void throwRequested();

private:
    QRadioButton * hRadio;
    QRadioButton * tRadio;
    QRadioButton * vRadio;
    QRadioButton * sRadio;

    QDoubleSpinBox * valBoxOne;
    QDoubleSpinBox * valBoxTwo;
    QComboBox * gravBox;

    QPushButton * button;

    QGroupBox *createComboBox();
    QGroupBox * createGroupBox(QRadioButton * radioA, QRadioButton * radioB, QDoubleSpinBox * spinBox, double spinBoxVal);

};

#endif // THROWCONTROLPANEL_H
