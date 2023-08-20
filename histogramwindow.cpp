#include "histogramwindow.h"
#include "ui_histogramwindow.h"
using std::string;

histogramWindow::histogramWindow(QWidget *parent, QString fileName, int length) :
    QMainWindow(parent),
    ui(new Ui::histogramWindow)
{
    ui->setupUi(this);
    string  stringFileName = fileName.toUtf8().constData();
    if (stringFileName == "") {
        QMessageBox::information(this, "File Error", "There was no file selected");
        return;
    }
    Ffile file(stringFileName);
    unsigned char* fileMass = file.fread(file.getSize());
    Statistic stat(fileMass);
    int* statMass = stat.makeStatistic(length, file.getSize());
    int statSize = (int) pow(2, length);

    auto statSet = new QBarSet(fileName);

    for (int i = 0; i < statSize; i++) {
        *statSet << statMass[i];
    }

    QBarSeries *series = new QBarSeries();
    series->append(statSet);

    auto chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistic for file");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    auto axisX = new QBarCategoryAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QChartView *chartView = new QChartView(chart);
    chartView->setParent(ui->horizontalFrame);
}

histogramWindow::~histogramWindow()
{
    delete ui;
}
