#ifndef MASTERINFO_H
#define MASTERINFO_H

#include <QString>
#include <QList>
#include <QMap>

class MasterInfo
{
public:
    MasterInfo();

private:
    QString fullName;
    QString description;
    QMap<QString, QString> socialLinks;
    double rating;
    QList<QString> comments;

};

#endif // MASTERINFO_H
