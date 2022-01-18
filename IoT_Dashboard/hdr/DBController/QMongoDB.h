//#ifndef QMONGODB_H
//#define QMONGODB_H

//#include <iostream>
//#include <QObject>
//#include <QJsonObject>
//#include <QJsonArray>
//#include <QJsonDocument>
//#include <QVector>

//#include <bsoncxx/builder/stream/document.hpp>
//#include <bsoncxx/json.hpp>
//#include <bsoncxx/types.hpp>
//#include <bsoncxx/document/element.hpp>

//#include <mongocxx/client.hpp>
//#include <mongocxx/instance.hpp>
//#include <mongocxx/uri.hpp>

//const std::string path = "mongodb.json";

//struct QNodeData{
//    QString database;
//    QString collection;
//};

//class QMongoDB : public QObject
//{
//    Q_OBJECT
//public:
//    QMongoDB();
//    ~QMongoDB();

//    int initHosting();

//    bsoncxx::document::view toBson(const QJsonObject& in);
//    QJsonObject toJson(bsoncxx::document::view view);
//    QString StringFromBson(bsoncxx::document::view view, std::string key);
//    QJsonObject ObjectFromString(const QString& in);
//    std::string StringFromObject(const QJsonObject& in);

//    QJsonArray getData(QNodeData Node);
//    void insertData(QJsonObject item, QNodeData Node);
//    void deleteData(QJsonObject item, QNodeData Node);
//    void updateData(QNodeData Node, QVector<QString> key, QVector<QString> value, QVector<QString> newValue);

//    QJsonArray queryFilter(QNodeData Node, QString key, QString value);

//    QVector<QNodeData> Nodes;

//private:
//    QVector<QString> mongodb_uri;
//    QVector<QString> hostnames;
//};

//#endif // QMONGODB_H
