#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

#define FUNCTION "x - 2.5"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(QCoreApplication::applicationName());

    ui->function->setText(FUNCTION);
    this->chart = ui->chartView->chart();
    ui->chartView->setRubberBand(QChartView::RectangleRubberBand);

    method = NULL;
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
    double accuracy = ui->accuracyDoubleSpinBox->value();

    QSplineSeries *series = new QSplineSeries();
    series->setName("Function");
    expression->addVariable("x", lb);
    for (double i = lb; i <= ub; i++) {
        *series << QPointF(i, expression->solve());
        expression->changeVariable("x", 1);
    }
    chart->addSeries(series);
    this->chart->createDefaultAxes();

    if(ui->bisectionRB->isChecked()){
        method = new BisectionMethod(expression, chart, lb, ub, accuracy);
    } else if(ui->secantRB->isChecked()){
        //method = new SecantMethod(expression, chart, lb, ub, accuracy);
    } else {
        //method = new NewtonMethod(expression, chart, lb, ub, accuracy);
    }
    //on_actionNext_triggered();
}

void MainWindow::on_actionReset_triggered()
{
    chart->removeAllSeries();
    ui->function->setText(FUNCTION);
    ui->lbSpinBox->setValue(0);
    ui->ubSpinBox->setValue(10);
    ui->accuracyDoubleSpinBox->setValue(0.01);
    ui->bisectionRB->setChecked(true);
    ui->resultLabel->setText("");
    ui->statusLabel->setText("Not finished");
    delete method;
    method = NULL;
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

void MainWindow::on_actionNext_triggered()
{
    if(method && !method->hasFinished()){
        if(!ui->actionStepByStep->isChecked()){
            method->finish();
        } else {
            method->next();
        }
        method->display();
        ui->resultLabel->setNum(method->getCurrentResult());
        if(method->hasFinished()){
            ui->statusLabel->setText("Finished");
        }
    }
}
