#ifndef ARMORYPLAYER_H
#define ARMORYPLAYER_H

#include "armory.h"



class ArmoryPlayer : public Armory
{
    Q_OBJECT
public:
    ArmoryPlayer();
    void processAnswer(QString);
    void processError(QString);

};

#endif // ARMORYPLAYER_H
