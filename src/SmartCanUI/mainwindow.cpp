#include "common.h"
#include "mainwindow.h"
#include "smartcanview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    smartCanView = new SmartCanView("!:/test_mat_v2.1.svg");
    setCentralWidget(smartCanView);
}
