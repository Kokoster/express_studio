#include "instrument.h"

#include <QPixmap>

Instrument::Instrument(QMainWindow* mainWindow, const std::string& inputEnabledImage,
                       const std::string& inputDisabledImage, const std::string& soundtrack, Point position)
{
    QPixmap enabledPixmap(QPixmap::fromImage(QImage(inputEnabledImage.c_str())));
    QPixmap disabledPixmap(QPixmap::fromImage(QImage(inputDisabledImage.c_str())));

    enabledLabel = std::unique_ptr<QLabel>(new QLabel(mainWindow));
    disabledLabel = std::unique_ptr<QLabel>(new QLabel(mainWindow));

    enabledLabel->setFixedSize(enabledPixmap.size());
    disabledLabel->setFixedSize(disabledPixmap.size());

    enabledLabel->setPixmap(enabledPixmap);
    disabledLabel->setPixmap(disabledPixmap);

    QRect rect(position.x, position.y,
               position.x + enabledLabel->size().width(),
               position.y + enabledLabel->size().height());
    enabledLabel->setGeometry(rect);
    disabledLabel->setGeometry(rect);

    disabledLabel->hide();

    player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile(soundtrack.c_str()));
    enabled = false;
}
