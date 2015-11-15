#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QNetworkReply;
class CensusDatabase;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonCensus_clicked();

private:
    Ui::MainWindow *ui;
    CensusDatabase* db;
};

#endif // MAINWINDOW_H
