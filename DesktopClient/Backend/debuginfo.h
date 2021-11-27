#ifndef DEBUGINFO_H
#define DEBUGINFO_H

#include <QDateTime>
#include <QDebug>
#include <QFile>


// type of messages
enum MessageType{
    INFO,
    WARNING,
    ERROR,
    FATAL,
};

// Singleton for Debug and Logging
// can write in log file and display in qDebug
class DebugInfo
{
private:
    QString filename;
    QFile* logFile;

    static DebugInfo* log;

    DebugInfo() {}
    DebugInfo(const DebugInfo&);
    DebugInfo& operator=(DebugInfo&);
    ~DebugInfo();

    void CreateLogFile();

public:
    static DebugInfo* Debug();

    // CheckConnect - check QOb connections
    void CheckConnect(bool ok, QString info = "");
    void WriteToLog(QString info, MessageType type = INFO);
};

#endif // DEBUGINFO_H
