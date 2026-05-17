#include "stdafx.h"
#include "Qt_GUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Qt_GUI window;
    window.show();
    return app.exec();
}
