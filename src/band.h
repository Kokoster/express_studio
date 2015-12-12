#ifndef BAND_H
#define BAND_H

#include <vector>

class QSize;
class Instrument;

class Band
{
public:
    Band(QSize mainWindowSize);

    std::vector<std::unique_ptr<Instrument>> const& getInstruments();

    void toggleInstrument(int index);

private:
    std::vector<std::unique_ptr<Instrument>> instruments;
};

#endif // BAND_H
