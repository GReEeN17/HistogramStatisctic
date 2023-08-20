#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "histogramwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    drawHistogram();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_openFileButton_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, "Open a file", "/");
    ui->selectedFileLabel->setText("Selected file: " + fileName);
}


void MainWindow::on_selectLengthButton_clicked()
{
    if (ui->radioButton->isChecked()) {
        length = 1;
    } else if (ui->radioButton_2->isChecked()) {
        length = 2;
    } else if (ui->radioButton_3->isChecked()) {
        length = 3;
    } else if (ui->radioButton_4->isChecked()) {
        length = 4;
    } else if (ui->radioButton_5->isChecked()) {
        length = 5;
    } else if (ui->radioButton_6->isChecked()) {
        length = 6;
    } else if (ui->radioButton_7->isChecked()) {
        length = 7;
    } else if (ui->radioButton_8->isChecked()) {
        length = 8;
    } else if (ui->radioButton_9->isChecked()) {
        length = 9;
    } else if (ui->radioButton_10->isChecked()) {
        length = 10;
    } else if (ui->radioButton_11->isChecked()) {
        length = 11;
    } else if (ui->radioButton_12->isChecked()) {
        length = 12;
    } else if (ui->radioButton_13->isChecked()) {
        length = 13;
    } else if (ui->radioButton_14->isChecked()) {
        length = 14;
    } else if (ui->radioButton_15->isChecked()) {
        length = 15;
    } else if (ui->radioButton_16->isChecked()) {
        length = 16;
    }
}

void MainWindow::drawHistogram() {
    histogramWindow* histogram = new histogramWindow(this, fileName, length);
    histogram->show();
}

void MainWindow::on_drawHistogramButton_clicked()
{
    drawHistogram();
}

