#include "censusdatabase.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bossindex.h"
#include "achievementindex.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QProgressBar>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    progress = new QProgressBar();
    progress->setFormat("%v/%m %p");
    ui->statusBar->addPermanentWidget(progress);

    QSettings settings("piesoft","battlecrawler");
    QString apikey = settings.value("apikey").toString();

    Armory::init(this, apikey);
    ai.init();
    db = new CensusDatabase(this, &ag, &ap);
    connect(&ag, SIGNAL(requestsDone()), this, SLOT(requestsDone()));
    connect(&ap, SIGNAL(requestsDone()), this, SLOT(requestsDone()));
    ArmoryCharacter::load();
    ArmoryGuild::load();
}

MainWindow::~MainWindow()
{
    ArmoryGuild::save();
    ArmoryCharacter::save();
//    bossIndex.save();
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

void MainWindow::setProgress(int now, int end)
{
    progress->setMaximum(end);
    progress->setValue(now);
    if (now == end) {
        progress->reset();
    }
}

void MainWindow::on_pushButtonCensus_clicked()
{
    action = CENSUS;
    db->update("/mnt/d/World of Warcraft/WTF/Account/GPIEZ/SavedVariables/CensusPlus.lua");
    ui->labelCensus->setText(QString::number(db->nPlayers()));
    ui->labelGuilds->setText(QString::number(db->nGuilds()));
}

void MainWindow::on_pushButtonPlayers_clicked()
{
    action = PLAYERS;
    db->updatePlayers();

}

void MainWindow::on_pushButtonGuilds_clicked()
{
    action = GUILDS;
    db->updateGuilds();

}

void MainWindow::on_testAchieve_clicked()
{
    action = TESTACHIEVE;
    ArmoryCharacter::insert(Character("Giganteus", "Thrall"));
    ArmoryCharacter::insert(Character("Gigahuf", "Thrall"));
    ArmoryCharacter::insert(Character("Sauerbruch", "Thrall"));
    ArmoryCharacter::insert(Character("Giganteus", "Antonidas"));
    db->updatePlayers();
}

void MainWindow::requestsDone()
{
    switch(action) {
    case NIX:
        break;
    case CENSUS:
        break;
    case PLAYERS:
        break;
    case GUILDS:
        break;
    case TESTACHIEVE:
        QMap<int,int> acount;
        QMap<int,int> ts;
        for(Character c: ArmoryCharacter::characters) {
            qDebug() << c.achievements.size() << c.achievementsTimestamp.size() << c.name;
            for (int i=0; i<c.achievements.size(); i++) {
                int a = c.achievements[i];
                if (i==0) qDebug() << a << c.achievementsTimestamp[i];
                if (acount[a] > 0) {
                    if (ts[a] == c.achievementsTimestamp[i])
                        acount[a]++;
                } else {
                    acount[a] = 1;
                    ts[a] = c.achievementsTimestamp[i];
                }
            }
        }
        for(int a: acount.keys()) {
            if (acount[a] == 4) {
                qDebug() << Armory::achievementIndex[a];
            }
        }
        break;
    }
}
