#ifndef MASTERINFO_H
#define MASTERINFO_H

#include <QString>
#include <QJsonObject>

class MasterInfo
{
public:
    MasterInfo();
    MasterInfo(const QString &contactNumber, const QString &FIO, int rating, const QString &region, const QString &services);
    void setDataJson(const QJsonObject &json);

    QString getContactNumber() const;
    QString getFIO() const;
    int getRating() const;
    QString getRegion() const;
    QString getServices() const;

private:
    QString contactNumber;
    QString FIO;
    int rating;
    QString region;
    QString services;
};

#endif // MASTERINFO_H
