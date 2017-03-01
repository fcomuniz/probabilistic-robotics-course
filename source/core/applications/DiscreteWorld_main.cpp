
#include <QApplication>
#include "gui/DiscreteWorldGUI.h"

using DiscreteWorldData = int;

int main(int argc, char * argv[]){

//	Genarating the data for the robot



#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
    QApplication::setGraphicsSystem("raster");
#endif
    QApplication a(argc, argv);
	DiscreteWorldGUI gui;

	gui.show();
	return a.exec();
}