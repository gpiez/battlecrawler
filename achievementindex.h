#ifndef ACHIEVEMENTINDEX_H
#define ACHIEVEMENTINDEX_H

#include <QMap>

struct AchievementIndex: QMap<QString, int> {
    AchievementIndex();
};
extern const AchievementIndex achievementIndex;

#endif // ACHIEVEMENTINDEX_H
