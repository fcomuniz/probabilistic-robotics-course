#ifndef DISCRETEWORLDGUI_H
#define DISCRETEWORLDGUI_H

#include <QWidget>
#include <eigen3/Eigen/Eigen>
#include "representations/Position.h"

// Forward Declarations
class DiscreteWorldData;

namespace Ui {
class DiscreteWorldGUI;
}

class QCustomPlot;

class QColor;
class QCPColorMap;
// Class Definitions

struct RobotPositionPlotData {

  RobotPositionPlotData(const representations::Position<int> & robotPosition, const QColor & color, QString plotName, const QCPColorMap * colorMap);

    const representations::Position<int> & robotPosition;
    const QColor & color;
    QString plotName;
    const QCPColorMap * colorMap;
};


class DiscreteWorldGUI : public QWidget
{
    Q_OBJECT

public:
    explicit DiscreteWorldGUI(QWidget *parent = 0);
    ~DiscreteWorldGUI();

    virtual void setWorldData(std::vector<DiscreteWorldData> worldData);

private slots:

    void on_nextButton_clicked();

    void on_previousButton_clicked();

private:
    virtual void replot();
    virtual void plotCurrentData(QCustomPlot * customPlot);
    virtual void plotWorldData(QCustomPlot *customPlot);
    virtual void plotRobotPosition(QCustomPlot * customPlot, const RobotPositionPlotData & plotData
    );
    virtual void clearPlot(QCustomPlot * customPlot);
    virtual void rescaleAxis(QCustomPlot * customPlot);
    virtual void plotSensors(QCustomPlot * customPlot, QCPColorMap * colorMap);
    int index;
    std::vector<DiscreteWorldData> data;
    Ui::DiscreteWorldGUI *ui;
};

#endif // DISCRETEWORLDGUI_H
