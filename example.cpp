#include "jsonreader.h"

#include <QDebug>
#include <QFile>
#include <QJsonDocument>

int main(int argc, char *argv[])
{
    QFile file(EXAMPLE_JSON_PATH);
    if (!file.open(QIODevice::ReadOnly)) {
        qCritical() << "Failed to open " EXAMPLE_JSON_PATH;
        return 1;
    }
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());

    JsonReader reader(doc);
    qDebug() << "errorCode:" << reader["error"]["code"].toInt();
    qDebug() << "first user:" << reader["users"][0]["name"].toString();
    qDebug() << "second user:" << reader["users"][1]["name"].toString();

    qDebug() << "-- inline";
    qDebug() << "errorCode:" << JsonReader(doc)["error"]["code"].toInt();
    qDebug() << "first user:" << JsonReader(doc)["users"][0]["name"].toString();
    qDebug() << "second user:" << JsonReader(doc)["users"][1]["name"].toString();

    qDebug() << "-- partial";
    JsonReader userReader = JsonReader(doc)["users"];
    qDebug() << "first user:" << userReader[0]["name"].toString();
    qDebug() << "second user:" << userReader[1]["name"].toString();

    return 0;
}
