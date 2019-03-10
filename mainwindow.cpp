#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

#define F1 "x + 1"
#define F2 "0"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(QCoreApplication::applicationName());

    ui->function1->setText(F1);
    ui->function2->setText(F2);
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
    Expression e1(ui->function1->text().toStdString());
    Expression e2(ui->function2->text().toStdString());
    e1.setVariable("x", 5);
    e2.setVariable("x", 5);
    std::cout << e1.solve() << std::endl;
    std::cout << e2.solve() << std::endl;
}

void MainWindow::on_actionReset_triggered()
{
    ui->function1->setText(F1);
    ui->function2->setText(F2);
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
