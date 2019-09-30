#ifndef QSSCLASS_H
#define QSSCLASS_H
#include <qssattribute.h>
#include <qssselector.h>
#include <QString>
class QssClass
{
public:
    QssClass();
    bool LoadQssFile(QString filename);
    void SaveQssFile(QString filename,QString path= "");
public:
    QssSelector     m_selector;
    QssAttribute    m_attribute;
};

#endif // QSSCLASS_H
