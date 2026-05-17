#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt_GUI.h"

class Qt_GUI : public QMainWindow
{
    Q_OBJECT

public:
    Qt_GUI(QWidget *parent = nullptr);
    ~Qt_GUI();

private:
    Ui::Qt_GUIClass ui;
};

