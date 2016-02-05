#ifndef ARMORYCHARACTER_H
#define ARMORYCHARACTER_H

#include "armory.h"

class ArmoryCharacter : public Armory
{
    Q_OBJECT
public:
    ArmoryCharacter();
    void processAnswer(QString) override;
    void processError(QString) override;

    void updateCharacters();

    static void insert(const Character&);
    static void save();
    static void load();

private:
    QStringList itemSlots;
};

#endif // ARMORYPLAYER_H
