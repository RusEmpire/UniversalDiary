#include "debuginfo.h"

DebugInfo* DebugInfo::log = nullptr;

DebugInfo* DebugInfo::Debug(){
    if(log == nullptr){
        log = new DebugInfo();
        log->CreateLogFile();
    }

    return log;
}

void DebugInfo::CheckConnect(bool ok, QString info){
    if(!ok){
        qDebug() << "[WRN]:> " + info + "::connect(...);";
        WriteToLog(info + "::connect(...);", WARNING);
    }
}

void DebugInfo::CreateLogFile(){
    try{
        // get filename
        QDateTime DateTime = QDateTime::currentDateTime();

        filename = "log_" + DateTime.date().toString("yyyyMMdd") + ".txt";
        logFile = new QFile(filename);

        logFile->setFileName(filename);
        logFile->open(QIODevice::Append);
    }
    catch (std::exception& ex) {
        qDebug() << "[FTL]:> DebugInfo::CreateLogFile();";
        qDebug() << "[ERR]:> " << ex.what();
    }
}


void DebugInfo::WriteToLog(QString info, MessageType type){
    // get filename
    QDateTime DateTime = QDateTime::currentDateTime();
    QTextStream logStream(logFile);
    QString typeString = "";

    switch (type) {
    case INFO:
        typeString = "[INF]:> ";
        break;
    case WARNING:
        typeString = "[WRN]:> ";
        break;
    case ERROR:
        typeString = "[ERR]:> ";
        break;
    case FATAL:
        typeString = "[FTL]:> ";
        break;
    }

    logStream << DateTime.toString("yyyy:MM:dd hh:mm:ss") << " " << typeString << info << "\n";
}
