#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <QObject>
#include <QWidget>

class Instrument
{
public:
    Instrument();

private:
    std::string enabledInstrumentFile;
    std::string disabledInstrumentFile;
    std::string soundFile;

    bool enabled;
};

#endif // INSTRUMENT_H
