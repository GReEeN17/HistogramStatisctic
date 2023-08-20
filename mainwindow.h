#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>
using std::string;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_openFileButton_clicked();

    void on_selectLengthButton_clicked();

    void on_drawHistogramButton_clicked();

private:
    Ui::MainWindow *ui;
    QString fileName = "/Users/azelen/Desktop/STCTest/test.txt";
    int length = 2;

    void drawHistogram();

};
#endif // MAINWINDOW_H
