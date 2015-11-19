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
    db = new CensusDatabase(this);
    Player::load();
    Guild::load();
}

MainWindow::~MainWindow()
{
    Guild::save();
    Player::save();
    delete ui;
}

void MainWindow::addPlayerToTree(QString realm, QString guild, QString player)
{
    if (!realmTree.contains(realm)) {
        realmTree[realm] = new QTreeWidgetItem(ui->treeWidget);
        realmTree[realm]->setText(0, realm);
    }

    if (!guildTree[realm].contains(guild)) {
        guildTree[realm][guild] = new QTreeWidgetItem(realmTree[realm]);
        guildTree[realm][guild]->setText(0, guild);
    }

    if (!playerTree[realm][guild].contains(player)) {
        playerTree[realm][guild][player] = new QTreeWidgetItem(guildTree[realm][guild]);
        playerTree[realm][guild][player]->setText(0, player);
    }


}

void MainWindow::on_pushButtonCensus_clicked()
{
    db->update("/mnt/d/World of Warcraft/WTF/Account/GPIEZ/SavedVariables/CensusPlus.lua");
    ui->labelCensus->setText(QString::number(db->nPlayers()));
    ui->labelGuilds->setText(QString::number(db->nGuilds()));
}

void MainWindow::on_pushButtonPlayers_clicked()
{
    db->updatePlayers();

}

void MainWindow::on_pushButtonGuilds_clicked()
{
    db->updateGuilds();

}
