#include "DiscreteWorldGUI.h"
#include "ui_DiscreteWorldGUI.h"
#include "representations/DiscreteWorldData.h"
#include <QColor>

RobotPositionPlotData::RobotPositionPlotData(const representations::Position<int> &robotPosition, const QColor &color, const QString & plotName): robotPosition(robotPosition), color(color), plotName(plotName) {

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
    plotFMP(customPlot);
    plotRobotRealPosition(customPlot);
    plotRobotEstimatePosition(customPlot);
    rescaleAxis(customPlot);
}

void DiscreteWorldGUI::plotFMP(QCustomPlot *customPlot) {
    auto & fmp = data.at(index).fmp;

    QCPColorMap * colorMap = new QCPColorMap(customPlot->xAxis, customPlot->yAxis);
    auto nx = fmp.cols();
    auto ny = fmp.rows();
    colorMap->data()->setSize(nx,ny);
    colorMap->data()->setRange(QCPRange(-1,nx+1), QCPRange(-1,ny+1));
    for(int xIndex = 0; xIndex < nx ; xIndex++){
        for(int yIndex = 0 ; yIndex < ny ; yIndex ++){
            colorMap->data()->setCell(xIndex, yIndex, fmp(yIndex, xIndex));
        }
    }

    QCPColorScale * colorScale = new QCPColorScale(customPlot);
    customPlot->plotLayout()->addElement(0,1,colorScale);
    colorScale->setType(QCPAxis::atRight);
    colorMap->setColorScale(colorScale);
    colorScale->axis()->setLabel("Probability");
    colorMap->setGradient(QCPColorGradient::gpPolar);
    colorMap->setInterpolate(false);
    colorMap->rescaleDataRange();
}

void DiscreteWorldGUI::rescaleAxis(QCustomPlot *customPlot) {
    QCPMarginGroup * marginGroup = new QCPMarginGroup(customPlot);
    customPlot->axisRect()->setMarginGroup(QCP::msBottom | QCP::msTop, marginGroup);
    customPlot->rescaleAxes();
}

void DiscreteWorldGUI::plotRobotRealPosition(QCustomPlot *customPlot) {

    RobotPositionPlotData plotData(data[index].robotRealPosition, Qt::blue, "RealRobotPosition");
    plotRobotPosition(customPlot, plotData);
}

void DiscreteWorldGUI::plotRobotEstimatePosition(QCustomPlot *customPlot) {
    RobotPositionPlotData plotData(data[index].robotEstimate, Qt::red, "RobotEstimatePosition");
    plotRobotPosition(customPlot, plotData);
}

void DiscreteWorldGUI::plotRobotPosition(QCustomPlot *customPlot, const RobotPositionPlotData & robotPositionPlotData) {
    customPlot->addGraph();
    customPlot->graph()->setPen(QPen(robotPositionPlotData.color));
    customPlot->graph()->setLineStyle(QCPGraph::lsNone);
    customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 20));
//    customPlot->graph()->setName(robotPositionPlotData.plotName);
    QVector<double> x(1),y(1);
    x[0] = robotPositionPlotData.robotPosition.x;
    y[0] = robotPositionPlotData.robotPosition.y;
    customPlot->graph()->setData(x,y);

}

void DiscreteWorldGUI::clearPlot(QCustomPlot *customPlot) {

    customPlot->clearFocus();
    customPlot->clearGraphs();
    customPlot->clearItems();
    customPlot->clearPlottables();
    customPlot->clearMask();
}

