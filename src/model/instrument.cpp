#include "instrument.h"

Instrument::Instrument(const std::string& enabledImageName,
           const std::string& disabledImageName, const std::string& soundtrack, Point position)
{
    this->enabledImageName  = enabledImageName;
    this->disabledImageName = disabledImageName;

    this->position = position;

//    std::unique_ptr<QMediaPlaylist> playlist(new QMediaPlaylist());
    playlist = std::unique_ptr<QMediaPlaylist>(new QMediaPlaylist());
    playlist->addMedia(QUrl(soundtrack.c_str()));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    player = std::unique_ptr<QMediaPlayer>(new QMediaPlayer);
//    player->setMedia(QUrl(soundtrack.c_str()));

    player->setPlaylist(playlist.get());
    player->setVolume(100);

    playing = false;
}

void Instrument::toggle() {
    if (!playing) {
        player->setMuted(false);
    } else {
        player->setMuted(true);
    }

    playing = !playing;
}

void Instrument::restart() {
    player->stop();
    player->play();
}

