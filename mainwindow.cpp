#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include "bisectionmethod.h"

#define FUNCTION "x * 10 + 4"

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
    Expression *expression = new Expression(ui->function->text().toStdString());

    int lb = ui->lbSpinBox->value();
    int ub = ui->ubSpinBox->value();
    uint steps = UINT(ui->stepsSB->value());

    QSplineSeries *series = new QSplineSeries();
    series->setName("Function");
    expression->addVariable("x", lb);
    for (double i = lb; i < ub; i++) {
        *series << QPointF(i, expression->solve());
        expression->changeVariable("x", 1);
    }
    chart->addSeries(series);
    this->chart->createDefaultAxes();
    /*BisectionMethod b(expression, chart, lb, ub, steps);
    b.nextStep();
    std::printf("%f", expression->derivative());*/
}

void MainWindow::on_actionReset_triggered()
{
    chart->removeAllSeries();
    ui->function->setText(FUNCTION);
    ui->lbSpinBox->setValue(0);
    ui->ubSpinBox->setValue(10);
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
