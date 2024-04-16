#include "CameraCapture.h"

#include <QDebug>
#include <QRandomGenerator>
#include <QThread>

CameraCapture::CameraCapture(QObject *p)
{
    connect(this, &CameraCapture::runningChanged, this, [this]() {
        if (!running())
        {
            futureData.wait();
        }
        else
        {
            generateData();
        }
    });
}

void CameraCapture::start() { setRunning(true); }

void CameraCapture::stop() { setRunning(false); }

void CameraCapture::generateData()
{
    futureData = std::async(std::launch::async, [this]() {
        while (running())
        {
            QVector<QColor> data(600 * 600);

            int k = 0;
            for (int i = 0; i < 600; ++i)
            {
                for (int j = 0; j < 600; ++j)
                {
                    QColor cc(QRandomGenerator::global()->generate() % 255,
                              QRandomGenerator::global()->generate() % 255,
                              QRandomGenerator::global()->generate() % 255);
                    data[k++] = cc;
                }
            }

            qDebug() << "Generated data with size: " << data.size();
            emit newDataGenerated(&data);

            QThread::msleep(500);
        }
    });
}

bool CameraCapture::running() const { return m_running; }

void CameraCapture::setRunning(bool newRunning)
{
    if (m_running == newRunning) return;
    m_running = newRunning;
    emit runningChanged();
}
