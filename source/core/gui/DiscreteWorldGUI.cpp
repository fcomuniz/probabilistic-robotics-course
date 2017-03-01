#include "DiscreteWorldGUI.h"
#include "ui_DiscreteWorldGUI.h"
#include "representations/DiscreteWorldData.h"

DiscreteWorldGUI::DiscreteWorldGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DiscreteWorldGUI)
{
    index = 0;
    ui->setupUi(this);
}

DiscreteWorldGUI::~DiscreteWorldGUI()
{
    delete ui;
}


void DiscreteWorldGUI::on_nextButton_clicked()
{
    
}

void DiscreteWorldGUI::on_previousButton_clicked()
{

}
