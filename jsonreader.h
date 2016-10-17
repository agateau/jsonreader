/*
 * JsonReader - (C) 2016 Aurélien Gâteau <mail@agateau.com>
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
class JsonReader {
public:
    JsonReader(const QJsonDocument& doc)
        : mRoot(doc.isObject() ? QJsonValue(doc.object()) : QJsonValue(doc.array()))
    {
    }

    JsonReader(const QJsonValue& root)
        : mRoot(root)
    {
    }

    JsonReader operator[](const QString& key) const
    {
        return JsonReader(mRoot.toObject()[key]);
    }

    JsonReader operator[](int idx) const
    {
        return JsonReader(mRoot.toArray()[idx]);
    }

    operator QJsonValue() const
    {
        return mRoot;
    }

    // Expose the same API as QJsonValue
    int toInt() const
    {
        return mRoot.toInt();
    }

    QString toString() const
    {
        return mRoot.toString();
    }

    QJsonArray toArray() const
    {
        return mRoot.toArray();
    }

    QJsonObject toObject() const
    {
        return mRoot.toObject();
    }

private:
    QJsonValue mRoot;
};

#endif /* JSONREADER_H */
