#include "instrument.h"

#include <QPixmap>
#include <iostream>

Instrument::Instrument(const std::string& enabledImageName,
           const std::string& disabledImageName, const std::string& soundtrack, Point position)
{
    this->enabledImageName  = enabledImageName;
    this->disabledImageName = disabledImageName;

////    set position to label
//    QRect rect(position.x, position.y,
//               position.x + enabledLabel->size().width(),
//               position.y + enabledLabel->size().height());

//    enabledLabel->setGeometry(rect);
//    disabledLabel->setGeometry(rect);

    this->position = position;

    player = std::unique_ptr<QMediaPlayer>(new QMediaPlayer);
    player->setMedia(QUrl(soundtrack.c_str()));
    player->setVolume(100);
}

//void Instrument::enable() {
//    disabledLabel->hide();
//    enabledLabel->show();

////    player->play();
//    if (player->isMuted()) {
//        player->setMuted(false);
//    } else {
//        player->play();
//    }
//}

//void Instrument::disable() {
//    enabledLabel->hide();
//    disabledLabel->show();

//    if (!player->isMuted()) {
//        player->setMuted(true);
//    }
//}
