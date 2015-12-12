#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <QObject>
#include <QMainWindow>
#include <QWidget>
#include <QtMultimedia>

#include "point.h"

//class MainWindow;

class Instrument
{
public:
    Instrument(const std::string& enabledImageName,
               const std::string& disabledImageName, const std::string& soundtrack, Point position);

    std::string getEnabledImageName()  { return enabledImageName;  }
    std::string getDisabledImageName() { return disabledImageName; }

    Point getPosition() { return position; }

private:
    std::string enabledImageName;
    std::string disabledImageName;

    Point position;

    std::unique_ptr<QMediaPlayer> player;
//    std::string soundtrackName;

    bool playing;
};

#endif // INSTRUMENT_H
