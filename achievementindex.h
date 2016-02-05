#ifndef ACHIEVEMENTINDEX_H
#define ACHIEVEMENTINDEX_H

#include <QMap>
#include "armory.h"

struct AchievementIndex: Armory
{
    Q_OBJECT
public:
    void init();

private:
    void processAnswer(QString) override;
    void processError(QString) override;

};
extern const AchievementIndex achievementIndex;

#endif // ACHIEVEMENTINDEX_H
