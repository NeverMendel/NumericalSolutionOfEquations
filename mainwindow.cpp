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

    if(ui->bisectionRB->isChecked()){
        method = new BisectionMethod(expression, chart, lb, ub, steps);
    } else if(ui->secantRB->isChecked()){
        //method = new SecantMethod(expression, chart, lb, ub, steps);
    } else {
        //method = new NewtonMethod(expression, chart, lb, ub, steps);
    }
    method->next();
    method->display();
    ui->resultLabel->setNum(method->getCurrentResult());
}

void MainWindow::on_actionReset_triggered()
{
    chart->removeAllSeries();
    ui->function->setText(FUNCTION);
    ui->lbSpinBox->setValue(0);
    ui->ubSpinBox->setValue(10);
    ui->stepsSB->setValue(10);
    ui->bisectionRB->setChecked(true);
    ui->resultLabel->setText("");
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
    method->next(uint(ui->singleStepSpinBox->value()));
    method->display();
    ui->resultLabel->setNum(method->getCurrentResult());
}
