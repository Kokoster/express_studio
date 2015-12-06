#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <QObject>
#include <QMainWindow>
#include <QWidget>
#include <QtMultimedia>

#include "component.h"
#include "point.h"

//class MainWindow;

class Instrument : public Component
{
public:
    Instrument(QMainWindow* mainWindow, const std::string& inputEnabledImage,
               const std::string& inputDisabledImage, const std::string& soundtrack, Point position);

private:
    QMediaPlayer* player;
    std::string soundtrackName;
};

#endif // INSTRUMENT_H
