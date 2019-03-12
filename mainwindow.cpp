#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

#define FUNCTION "x * 10"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(QCoreApplication::applicationName());

    ui->function->setText(FUNCTION);
    this->chart = ui->chartView->chart();
    ui->chartView->setRubberBand(QChartView::RectangleRubberBand);
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

    chart->removeAllSeries();
    Expression expression(ui->function->text().toStdString());

    int lb = ui->lbSpinBox->value();
    int ub = ui->ubSpinBox->value();

    QSplineSeries *series = new QSplineSeries();
    series->setName("Function");
    expression.addVariable("x", lb);
    for (double i = lb; i < ub; i++) {
        *series << QPointF(i, expression.solve());
        expression.changeVariable("x", 1);
    }
    chart->addSeries(series);
    this->chart->createDefaultAxes();
}

void MainWindow::on_actionReset_triggered()
{
    chart->removeAllSeries();
    ui->function->setText(FUNCTION);
    ui->lbSpinBox->setValue(0);
    ui->ubSpinBox->setValue(100);
    ui->stepsSB->setValue(10);
    ui->bisectionRB->setChecked(true);
}

void MainWindow::on_actionZoomIn_triggered()
{
    this->chart->zoomIn();
}

void MainWindow::on_actionZoomOut_triggered()
{
    this->chart->zoomOut();
}

void MainWindow::on_actionResetZoom_triggered()
{
    this->chart->zoomReset();
}
