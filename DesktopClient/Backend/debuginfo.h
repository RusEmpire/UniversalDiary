#ifndef DEBUGINFO_H
#define DEBUGINFO_H

#include <QDateTime>
#include <QDebug>
#include <QFile>

enum MessageType{
    INFO,
    WARNING,
    ERROR,
    FATAL,
};

class DebugInfo
{
private:
    QString filename;
    QFile* logFile;

    static DebugInfo* log;

    DebugInfo() {}
    DebugInfo( const DebugInfo&);
    DebugInfo& operator=(DebugInfo&);
    ~DebugInfo();

    void CreateLogFile();

public:
    static DebugInfo* Debug();

    // only for connections
    void CheckConnect(bool ok, QString info = "");
    // log files
    void WriteToLog(QString info, MessageType type = INFO);
};

#endif // DEBUGINFO_H
