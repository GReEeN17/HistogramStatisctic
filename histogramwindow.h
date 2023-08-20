#ifndef HISTOGRAMWINDOW_H
#define HISTOGRAMWINDOW_H

#include <QMainWindow>
#include <QtCharts/QtCharts>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChartView>
#include <QMessageBox>
#include "ffile.h"
#include "statistic.h"

namespace Ui {
class histogramWindow;
}

class histogramWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit histogramWindow(QWidget *parent = nullptr, QString fileName = "", int length = 2);
    ~histogramWindow();

private:
    Ui::histogramWindow *ui;
};

#endif // HISTOGRAMWINDOW_H
