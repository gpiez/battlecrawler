#include <QThread>

#include "armoryguild.h"

ArmoryGuild::ArmoryGuild()
{

}

void ArmoryGuild::processAnswer(QString s) {
    qDebug() << s;
}

void ArmoryGuild::processError(QString s) {
    qDebug() << s;
}
