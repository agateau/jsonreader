/*
 * JsonReader - (C) 2016 Aurélien Gâteau <mail@agateau.com>
 *
 * https://github.com/agateau/jsonreader
 *
 * This code is released under the BSD 3-Clause license.
 * https://opensource.org/licenses/BSD-3-Clause
 */
#ifndef JSONREADER_H
#define JSONREADER_H

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

/**
 * Usage example:
 *
 * Suppose you have a JSON document like this:
 *
 * ```
 * {
 *   "error": {
 *     "code": 12,
 *     "message": "Something went wrong"
 *   }
 * }
 * ```
 *
 * To access the "message" field inside the "error" object, you can use:
 *
 * ```
 * QString message = JsonReader(document)["error"]["message"].toString();
 * ```
 *
 * It also works with arrays. If you have this JSON:
 *
 * ```
 * {
 *   "users": [
 *     {
 *       "name": "Alice"
 *     },
 *     {
 *       "name": "Bob"
 *     }
 *   ]
 * }
 * ```
 *
 * You can get the name of the first user with:
 *
 * ```
 * QString firstUserName = JsonReader(document)["users"][0]["name"].toString();
 * ```
 */
class JsonReader : public QJsonValue {
public:
    JsonReader(const QJsonDocument& doc)
        : QJsonValue(doc.isObject() ? QJsonValue(doc.object()) : QJsonValue(doc.array()))
    {
    }

    JsonReader(const QJsonValue& value)
        : QJsonValue(value)
    {
    }

    JsonReader operator[](const QString& key) const
    {
        return JsonReader(toObject()[key]);
    }

    JsonReader operator[](int idx) const
    {
        return JsonReader(toArray()[idx]);
    }
};

#endif /* JSONREADER_H */
