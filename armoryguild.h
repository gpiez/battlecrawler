#ifndef ARMORYGUILD_H
#define ARMORYGUILD_H

#include "armory.h"



class ArmoryGuild : public Armory
{
    Q_OBJECT
public:
    ArmoryGuild();
    void processAnswer(QString);
    void processError(QString);
};

#endif // ARMORYGUILD_H
