#include <QApplication>
#include <QFile>
#include <QDebug>

#include "xmldataextractor.h"
#include "appConfigData.h"


using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bool result = true;

    QString schemaFileLocation("D:/Project_23_24/iCBTC/TestCode/XMLValidator/CbiConfigSchema.xsd");
    QString xmlFileLocation("D:/Project_23_24/iCBTC/TestCode/XMLValidator/CBI_Config_Copy.xml");

    if(result)
    {
        xmlDataExtractor objXmlParser(xmlFileLocation);
        result = objXmlParser.read();
    }
    return 0;
}
