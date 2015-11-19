#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>

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
    void addPlayerToTree(QString realm, QString guild, QString player);

private slots:
    void on_pushButtonCensus_clicked();

    void on_pushButtonPlayers_clicked();

    void on_pushButtonGuilds_clicked();

private:
    Ui::MainWindow *ui;
    CensusDatabase* db;
    QHash<QString, QHash<QString, QHash<QString, QTreeWidgetItem*> > > playerTree;
    QHash<QString, QTreeWidgetItem*> realmTree;
    QHash<QString, QHash<QString, QTreeWidgetItem*> > guildTree;

};

#endif // MAINWINDOW_H
