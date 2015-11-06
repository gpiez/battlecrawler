#include "censusdatabase.h"
#include "wowinterface.h"

#include <QFile>
#include <QString>

WoWInterface::WoWInterface()
{
    readLUA("/mnt/d/World of Warcraft/WTF/Account/GPIEZ/SavedVariables/CensusPlus.lua");
}

void WoWInterface::readLUA(QString fileName) {
    QFile f(fileName);
    f.open(QIODevice::ReadOnly);
    QString s = f.readAll();
    CensusDatabase db(s);
}
