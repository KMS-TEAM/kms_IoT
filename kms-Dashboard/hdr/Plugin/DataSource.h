#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QtCore/QObject>
#include <QtCharts/QAbstractSeries>
#include <QQmlApplicationEngine>

QT_CHARTS_USE_NAMESPACE

class DataSource : public QObject
{
    Q_OBJECT
public:
    explicit DataSource(QQmlApplicationEngine *engine, QObject *parent = 0);

Q_SIGNALS:

public slots:
    void generateData(int type, int rowCount, int colCount);
    void update(QAbstractSeries *series);

private:
    QQmlApplicationEngine  *m_engine;
    QList<QVector<QPointF> > m_data;
    int m_index;
};

#endif // DATASOURCE_H
