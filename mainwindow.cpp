#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

#define F1 "x * 10"
#define F2 "x ^ 2"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(QCoreApplication::applicationName());

    ui->function1->setText(F1);
    ui->function2->setText(F2);
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
    Expression e1(ui->function1->text().toStdString());
    Expression e2(ui->function2->text().toStdString());

    int lb = ui->lbSpinBox->value();
    int ub = ui->ubSpinBox->value();

    QSplineSeries *f1 = new QSplineSeries();
    f1->setName("Function 1");
    e1.addVariable("x", lb);
    for (double i = lb; i < ub; i++) {
        *f1 << QPointF(i, e1.solve());
        e1.changeVariable("x", 1);
    }
    chart->addSeries(f1);

    QSplineSeries *f2 = new QSplineSeries();
    f2->setName("Function 2");
    e2.addVariable("x", lb);
    for (double i = lb; i < ub; i++) {
        *f2 << QPointF(i, e2.solve());
        e2.changeVariable("x", 1);
    }
    chart->addSeries(f2);
    this->chart->createDefaultAxes();
}

void MainWindow::on_actionReset_triggered()
{
    chart->removeAllSeries();
    ui->function1->setText(F1);
    ui->function2->setText(F2);
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
