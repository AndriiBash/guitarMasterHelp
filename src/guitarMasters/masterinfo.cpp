#include "masterinfo.h"

MasterInfo::MasterInfo() {}

MasterInfo::MasterInfo(const QString &contactNumber, const QString &FIO, int rating, const QString &region, const QString &services)
    : contactNumber(contactNumber), FIO(FIO), rating(rating), region(region), services(services) {}

void MasterInfo::setDataJson(const QJsonObject &json)
{
    contactNumber = json["ContactNumber"].toString();
    FIO = json["FIO"].toString();
    rating = json["Rating"].toInt();
    region = json["Region"].toString();
    services = json["Services"].toString();
}

QString MasterInfo::getContactNumber() const
{
    return contactNumber;
}

QString MasterInfo::getFIO() const
{
    return FIO;
}

int MasterInfo::getRating() const
{
    return rating;
}

QString MasterInfo::getRegion() const
{
    return region;
}

QString MasterInfo::getServices() const
{
    return services;
}
