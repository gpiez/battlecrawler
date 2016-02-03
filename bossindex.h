#ifndef BOSSINDEX_H
#define BOSSINDEX_H

#include <QMap>

struct BossIndex: QMap<QString, int> {
    BossIndex();
    static int index;
    //int& operator[](const QString& key);
    void save();
    static constexpr int nBoss = 168;
};
extern const BossIndex bossIndex;

#endif // BOSSINDEX_H
