#include "xmldataextractor.h"

xmlDataExtractor::xmlDataExtractor(QString xmlFilePath)
{
    file.setFileName(xmlFilePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open XML file! Closing Application";
        exit(0);
    }

    xml.setDevice(&file);
}

bool xmlDataExtractor::read()
{
    if (xml.readNextStartElement())
    {
        if (xml.name() == QLatin1String("CBI_CONFIGURATION"))
        {
            parseXml();
        }
        else
        {
            xml.raiseError(QObject::tr("The file is not a CBI_CONFIGURATION file."));
        }
    }

    return !xml.error();
}

bool xmlDataExtractor::parseXml()
{

    Q_ASSERT(xml.isStartElement() && xml.name() == QLatin1String("CBI_CONFIGURATION"));

    while (xml.readNextStartElement())
    {
        if (xml.name() == QLatin1String("Input"))
        {
            readInput();
        }
        else if (xml.name() == QLatin1String("Variables"))
        {
            readVariables();
        }
        else if (xml.name() == QLatin1String("Output"))
        {
            readOutput();
        }
        else if (xml.name() == QLatin1String("Circuit"))
        {
            readCircuit();
        }
        else
        {
            qDebug()<<Q_FUNC_INFO<<xml.name();
            xml.skipCurrentElement();
        }
    }
    return true;
}

void xmlDataExtractor::readInput()
{
    Q_ASSERT(xml.isStartElement() && xml.name() == QLatin1String("Input"));

    while (xml.readNextStartElement())
    {
        if (xml.name() == QLatin1String("CardInput"))
        {
            readCardInput();
        }
        else if (xml.name() == QLatin1String("ExtSystem"))
        {
            readExtSystem();
        }
        else
        {
            qDebug()<<Q_FUNC_INFO<<xml.name();
             xml.skipCurrentElement();
        }
    }
}

void xmlDataExtractor::readCardInput()
{
    Q_ASSERT(xml.isStartElement() && xml.name() == QLatin1String("CardInput"));

    while (xml.readNextStartElement())
    {
        if (xml.name() == QLatin1String("Card"))
        {
            readCard();
        }
        else
        {
            qDebug()<<Q_FUNC_INFO<<xml.name();           
            xml.skipCurrentElement();
        }
    }
}

void xmlDataExtractor::readCard()
{
    Q_ASSERT(xml.isStartElement() && xml.name() == QLatin1String("Card"));

    int cardId = xml.attributes().value(idAttribute()).toInt();
    QString  cardIp = xml.attributes().value(ipAttribute()).toString();
    int maxBits = xml.attributes().value(maxbitsAttribute()).toInt();

    qDebug()<<"Card:-> Id["<<cardId<<"] \tIp["<<cardIp<<"] \tmaxBits["<<maxBits<<"]"<<endl;


    while (xml.readNextStartElement())
    {
        if (xml.name() == QLatin1String("Details"))
        {
            readDetails();
        }
        else
        {
            qDebug()<<Q_FUNC_INFO<<xml.name();
            xml.skipCurrentElement();
        }
    }
}

void xmlDataExtractor::readExtSystem()
{
    Q_ASSERT(xml.isStartElement() && xml.name() == QLatin1String("ExtSystem"));
    while (xml.readNextStartElement())
    {
        if (xml.name() == QLatin1String("SubSystemMsg"))
        {
            readSubSystemMsg();
        }
        else
        {
            // xml.skipCurrentElement();
        }
    }
}

void xmlDataExtractor::readSubSystemMsg()
{
    Q_ASSERT(xml.isStartElement() && xml.name() == QLatin1String("SubSystemMsg"));

    int MsgId = xml.attributes().value(msgIdAttribute()).toInt();
    QString  SubSystem = xml.attributes().value(subSystemAttribute()).toString();
    int Periodicity = xml.attributes().value(periodicityAttribute()).toInt();

    qDebug()<<"Card:MsgId["<<MsgId<<"] SubSystem["<<SubSystem<<"] Periodicity["<<Periodicity<<"]"<<endl;

    while (xml.readNextStartElement())
    {
        if (xml.name() == QLatin1String("Details"))
        {
            readDetails();
        }
        else
        {
            // xml.skipCurrentElement();
        }
    }
}

void xmlDataExtractor::readVariables()
{
    qDebug()<<"Reading Variables section";
}

void xmlDataExtractor::readOutput()
{
    qDebug()<<"Reading Output section";
}

void xmlDataExtractor::readCircuit()
{
    qDebug()<<"Reading Circut section";
}

void xmlDataExtractor::readLogic()
{

}

void xmlDataExtractor::readExpr()
{

}

void xmlDataExtractor::readDetails()
{
    Q_ASSERT(xml.isStartElement() && xml.name() == QLatin1String("Details"));


//    QXmlStreamAttributes attrs = xml.attributes();

//    int bitPosition = attrs.value(bitPositionAttribute()).toInt();
//    QString  Name = attrs.value(nameAttribute()).toString();
//    QString Type = xml.attributes().value(typeAttribute()).toString();

//    qDebug()<<"Details: bitPosition["<<bitPosition<<"] Name["<<Name<<"] Type["<<Type<<"]"<<endl;


      QString text = xml.readElementText();
      qDebug()<<text<<endl;
}
