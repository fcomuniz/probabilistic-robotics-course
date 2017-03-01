#include "DiscreteWorldGUI.h"
#include "ui_DiscreteWorldGUI.h"

DiscreteWorldGUI::DiscreteWorldGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DiscreteWorldGUI)
{
    ui->setupUi(this);
}

DiscreteWorldGUI::~DiscreteWorldGUI()
{
    delete ui;
}
