#ifndef XMLDATAEXTRACTOR_H
#define XMLDATAEXTRACTOR_H


#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>

class xmlDataExtractor
{
    QFile file;
public:
    xmlDataExtractor(QString xmlFilePath);
    bool parseXml();
    bool read();

    static inline QString idAttribute() { return QStringLiteral("Id"); }
    static inline QString ipAttribute() { return QStringLiteral("IP"); }
    static inline QString maxbitsAttribute() { return QStringLiteral("Max_Bits"); }
    static inline QString bitPositionAttribute() { return QStringLiteral("Bit_Position"); }
    static inline QString nameAttribute() { return QStringLiteral("Name"); }
    static inline QString typeAttribute() { return QStringLiteral("Type"); }
    static inline QString msgIdAttribute() { return QStringLiteral("MsgId"); }
    static inline QString subSystemAttribute() { return QStringLiteral("SubSystem"); }
    static inline QString periodicityAttribute() { return QStringLiteral("Periodicity"); }
    static inline QString isPersistentAttribute() { return QStringLiteral("isPersistent"); }
    static inline QString defaultValueAttribute() { return QStringLiteral("Default_Value"); }
    static inline QString assignToAttribute() { return QStringLiteral("ASSIGN_TO"); }
    static inline QString strTimerAttribute() { return QStringLiteral("STR_TIMER"); }
    static inline QString stpTimerAttribute() { return QStringLiteral("STP_TIMER"); }
    static inline QString loggingAttribute() { return QStringLiteral("Logging"); }
    static inline QString countAttribute() { return QStringLiteral("Count"); }
    static inline QString valueAttribute() { return QStringLiteral("VALUE"); }


private:

    QXmlStreamReader xml;

    void readInput();
    void readCardInput();
    void readCard();
    void readExtSystem();
    void readSubSystemMsg();
    void readVariables();
    void readOutput();
    void readCircuit();
    void readLogic();
    void readExpr();
    void readDetails();


};

#endif // XMLDATAEXTRACTOR_H
