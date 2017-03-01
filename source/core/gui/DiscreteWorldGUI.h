#ifndef DISCRETEWORLDGUI_H
#define DISCRETEWORLDGUI_H

#include <QWidget>

class DiscreteWorldData;

namespace Ui {
class DiscreteWorldGUI;
}

class DiscreteWorldGUI : public QWidget
{
    Q_OBJECT

public:
    explicit DiscreteWorldGUI(QWidget *parent = 0);
    ~DiscreteWorldGUI();
    
private slots:

    void on_nextButton_clicked();

    void on_previousButton_clicked();

private:
    int index;
    std::vector<DiscreteWorldData> data;
    Ui::DiscreteWorldGUI *ui;
};

#endif // DISCRETEWORLDGUI_H
