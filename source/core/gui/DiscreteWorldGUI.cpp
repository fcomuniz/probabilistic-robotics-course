#include "DiscreteWorldGUI.h"
#include "ui_DiscreteWorldGUI.h"
#include "representations/DiscreteWorldData.h"
#include <QColor>

RobotPositionPlotData::RobotPositionPlotData(const representations::Position<int> &robotPosition, const QColor &color, const QString & plotName, const QCPColorMap * colorMap): robotPosition(robotPosition), color(color), plotName(plotName), colorMap(colorMap) {

}

DiscreteWorldGUI::DiscreteWorldGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DiscreteWorldGUI)
{
    index = 0;
    ui->setupUi(this);
    ui->customPlot->axisRect()->setupFullAxesBox();

}

DiscreteWorldGUI::~DiscreteWorldGUI()
{
    delete ui;
}


void DiscreteWorldGUI::on_nextButton_clicked()
{
    if(index < data.size() -1)
    {
        index++;
        replot();
    }
}

void DiscreteWorldGUI::on_previousButton_clicked()
{
    if(index > 0){

        index--;
        replot();
    }
}

void DiscreteWorldGUI::setWorldData(std::vector<DiscreteWorldData> worldData) {
    data = worldData;
    replot();
}

void DiscreteWorldGUI::replot() {
    clearPlot(ui->customPlot);
    plotCurrentData(ui->customPlot);
    ui->customPlot->replot();
}

void DiscreteWorldGUI::plotCurrentData(QCustomPlot * customPlot) {
//    Plotting the data from current index
    plotWorldData(customPlot);
//    plotRobotRealPosition(customPlot);
//    plotRobotEstimatePosition(customPlot);
    rescaleAxis(customPlot);
}

void DiscreteWorldGUI::plotWorldData(QCustomPlot *customPlot) {
    auto & fmp = data.at(index).fmp;

    QCPColorMap * colorMap = new QCPColorMap(customPlot->xAxis, customPlot->yAxis);
    auto nx = fmp.cols();
    auto ny = fmp.rows();
    colorMap->data()->setSize(nx,ny);
    colorMap->data()->setRange(QCPRange(0,nx), QCPRange(0,ny));
    for(int xIndex = 0; xIndex < nx ; xIndex++){
        for(int yIndex = 0 ; yIndex < ny ; yIndex ++){
            colorMap->data()->setCell(xIndex, yIndex, fmp(yIndex, xIndex));
        }
    }

    QCPColorScale * colorScale = new QCPColorScale(customPlot);
    if(!customPlot->plotLayout()->hasElement(0,1))
        customPlot->plotLayout()->addElement(0,1,colorScale);
    colorScale->setType(QCPAxis::atRight);
    colorMap->setColorScale(colorScale);
    colorScale->axis()->setLabel("Probability");
    colorMap->setGradient(QCPColorGradient::gpPolar);
    colorMap->setInterpolate(false);
    colorMap->rescaleDataRange(true);
//    Plotting the robot positions
    RobotPositionPlotData realRobotData(data[index].robotRealPosition, Qt::blue, "RealRobot", colorMap);
    plotRobotPosition(customPlot, realRobotData);
    RobotPositionPlotData estimateRobotData(data[index].robotEstimate, Qt::red, "EstimateRobot", colorMap);
    plotRobotPosition(customPlot, estimateRobotData);

}

void DiscreteWorldGUI::rescaleAxis(QCustomPlot *customPlot) {
    QCPMarginGroup * marginGroup = new QCPMarginGroup(customPlot);
    customPlot->axisRect()->setMarginGroup(QCP::msBottom | QCP::msTop, marginGroup);
    customPlot->rescaleAxes();
}


void DiscreteWorldGUI::plotRobotPosition(QCustomPlot *customPlot, const RobotPositionPlotData & robotPositionPlotData) {
    customPlot->addGraph();
    customPlot->graph()->setLineStyle(QCPGraph::lsNone);
    customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 20));
    customPlot->graph()->setPen(QPen(robotPositionPlotData.color));
    QVector<double> x(1), y(1);
    robotPositionPlotData.colorMap->data()->cellToCoord(robotPositionPlotData.robotPosition.x, robotPositionPlotData.robotPosition.y, &x[0],&y[0]);
    customPlot->graph()->setData(x,y);

}

void DiscreteWorldGUI::clearPlot(QCustomPlot *customPlot) {
    customPlot->clearPlottables();
}

