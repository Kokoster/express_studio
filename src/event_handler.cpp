#include "event_handler.h"

//EventHandler::EventHandler(std::vector<Instrument> instruments)
//{
//    this->instruments = instruments;

//    for (int i = 0; i < instruments.size(); ++i) {
//        ClickableLabel::connect((*instruments)[i].getEnabledLabelPtr(),
//                                SIGNAL(clicked),
//                                this, SLOT(disable));

//        ClickableLabel::connect((*instruments)[i].getDisabledLabelPtr(),
//                                SIGNAL(clicked),
//                                this,
//                                SLOT(enable));
//    }

//    enabledInstrumentsCount = 0;
//}

//void EventHandler::enable(Instrument* instrument) {
//        instrument->getDisabledLabel()->hide();
//        instrument->getEnabledLabel()->show();

//        if (enabledInstrumentsCount == 0) {
//            for (Instrument el : instruments) {
//                    el->getPlayer()->stop();
//                    el->getPlayer()->play();
//                    el->getPlayer()->setMuted(true);
//            }
//        }

//        instrument->getPalyer()->setMuted(false);
//        enabledInstrumentsCount++;
//}

//void EventHandler::disable(Instrument* instrument) {
//        instrument->getEnabledLabel()->hide();
//        instrument->getDisabledLabel()->show();

//        instrument->getPlayer->setMuted(true);
//        enabledInstrumentsCount--;
//}

