#ifndef DEBUGINFO_H
#define DEBUGINFO_H

#include <QDebug>

class DebugInfo
{
private:
    DebugInfo();

public:
    static DebugInfo debug;

    void CheckConnect(bool ok, QString info = "");
};

#endif // DEBUGINFO_H
