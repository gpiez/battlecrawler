#include "censusdatabase.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonCensus_clicked()
{
    db = new CensusDatabase("/mnt/d/World of Warcraft/WTF/Account/GPIEZ/SavedVariables/CensusPlus.lua");
    ui->labelCensus->setText(QString::number(db->nPlayers()));
    db->createGuilds();
    ui->labelGuilds->setText(QString::number(db->nGuilds()));
    db->updateGuilds();
}
