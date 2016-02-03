#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>

#include "armorycharacter.h"
#include "armoryguild.h"

class QNetworkReply;
class CensusDatabase;
class QProgressBar;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    enum Actions { NIX, CENSUS, PLAYERS, GUILDS, TESTACHIEVE };

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addPlayerToTree(QString realm, QString guild, QString player);
    void setProgress(int now, int end);
    QString getApikey() const;

private slots:
    void on_pushButtonCensus_clicked();

    void on_pushButtonPlayers_clicked();

    void on_pushButtonGuilds_clicked();

    void on_testAchieve_clicked();
    void requestsDone();

private:
    Ui::MainWindow *ui;
    CensusDatabase* db;
    ArmoryGuild ag;
    ArmoryCharacter ap;
    QProgressBar *progress;
    QHash<QString, QHash<QString, QHash<QString, QTreeWidgetItem*> > > playerTree;
    QHash<QString, QTreeWidgetItem*> realmTree;
    QHash<QString, QHash<QString, QTreeWidgetItem*> > guildTree;
    Actions action;
    QString apikey;

};

#endif // MAINWINDOW_H
