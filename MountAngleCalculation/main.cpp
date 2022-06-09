#include "MountAngleCalculation.h"
#include <QtWidgets/QApplication>

#define PROGRAM "MountAngle Calculation"
#define VERSION "v1.3.4"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MountAngleCalculation w;
	w.setWindowTitle(PROGRAM + QString("-") + VERSION);
    w.show();
    return a.exec();
}
