#pragma once

#include <QColor>
#include <QObject>
#include <QVector>
#include <future>

class CameraCapture : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged FINAL)

public:
    CameraCapture(QObject *p = nullptr);

    bool running() const;
    void setRunning(bool newRunning);

public slots:
    void start();
    void stop();

private slots:
    void generateData();

signals:
    void newDataGenerated(const QVector<QColor> *data);
    void runningChanged();

private:
    bool m_running = false;
    std::future<void> futureData;
};
