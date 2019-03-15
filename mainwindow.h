#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QChart>
#include "expression.h"
#include "bisectionmethod.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void on_displayButton_clicked();

    void on_actionReset_triggered();

    void on_actionZoomIn_triggered();

    void on_actionZoomOut_triggered();

    void on_actionResetZoom_triggered();

    void on_actionNext_triggered();

private:
    Ui::MainWindow *ui;
    QtCharts::QChart *chart;
    SolutionMethod *method;
};

#endif // MAINWINDOW_H
