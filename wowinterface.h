#ifndef WOWINTERFACE_H
#define WOWINTERFACE_H

#include <QString>



class WoWInterface
{
public:
    WoWInterface();
    void readLUA(QString fileName);
};

#endif // WOWINTERFACE_H
