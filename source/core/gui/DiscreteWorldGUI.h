#ifndef DISCRETEWORLDGUI_H
#define DISCRETEWORLDGUI_H

#include <QWidget>

namespace Ui {
class DiscreteWorldGUI;
}

class DiscreteWorldGUI : public QWidget
{
    Q_OBJECT

public:
    explicit DiscreteWorldGUI(QWidget *parent = 0);
    ~DiscreteWorldGUI();

private:
    Ui::DiscreteWorldGUI *ui;
};

#endif // DISCRETEWORLDGUI_H
