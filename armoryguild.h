#ifndef ARMORYGUILD_H
#define ARMORYGUILD_H

#include "armory.h"

class ArmoryGuild : public Armory
{
    Q_OBJECT
public:
    ArmoryGuild();
    void processAnswer(QString) override;
    void processError(QString) override;

    void updateGuilds();
    static void insert(const Guild &g);
    static void save();
    static void load();
};

#endif // ARMORYGUILD_H
