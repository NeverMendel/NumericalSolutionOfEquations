#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCharts>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->chart = ui->chartView->chart();
    this->chart->createDefaultAxes();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_displayButton_clicked()
{
    //TODO check the method to be used and display the chart
}
