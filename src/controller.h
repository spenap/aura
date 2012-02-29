#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QDeclarativeItem>
#include "pipeline.h"

class Controller : public QDeclarativeItem
{
    Q_OBJECT

 public:
    Q_PROPERTY(bool recording
               READ recording
               WRITE setRecording
               NOTIFY recordingChanged)
    Controller(QDeclarativeItem *parent = 0);
    ~Controller();
    void setupEffects();

    // user to set user defined values
    void setResolution(const Pipeline::Resolution value);
    void setZoom(const double value);
    void setColorFilter(const Pipeline::ColorFilter value);

    bool recording() { return m_recording; };

public slots:
    void setRecording(bool recording);
    void setVideoEffect(const QString &value);

signals:
    void recordingChanged(bool recording);

 public slots:
    void startPipeline();
    void stopPipeline();
    void startRecording();
    void stopRecording();
    void shutterClicked();

 private slots:
    void resourcesLost();
    void idleChanged(bool isIdle);

 private:
    Pipeline *m_pipeline;
    bool m_recording;
    // current config
    double m_currentZoom;
    Pipeline::Resolution m_currentResolution;
    Pipeline::ColorFilter m_currentColorFilter;
    QString m_currentVideoEffect;
};
#endif
