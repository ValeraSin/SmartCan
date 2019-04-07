#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class SmartCanView;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

signals:

public slots:

private:
    SmartCanView *smartCanView;
};

#endif // MAINWINDOW_H
