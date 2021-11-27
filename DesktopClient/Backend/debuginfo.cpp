#include "debuginfo.h"

DebugInfo::DebugInfo()
{

}

void DebugInfo::CheckConnect(bool ok, QString info){
    if(!ok){
        qDebug() << info << "::connect(...);";

    }
}
