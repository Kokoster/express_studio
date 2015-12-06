#include "main_window.h"
#include "ui_mainwindow.h"

#include <QPixmap>

#include "QDesktopWidget"

const QString BACKGROUND = ":/background/grey_room.jpg";
const QString BACKGROUND_LOAD = "MainWindow {background-image: url(:/background/grey_room.jpg);}";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     Q_INIT_RESOURCE(resources);

    ui->setupUi(this);

    setBackground();
    loadInstruments();

//    for (int i = 0; i < (int) instruments.size(); ++i) {
//        instruments[i]->showLabel();
//    }
}

void MainWindow::loadInstruments() {
    Point position(size().width() / 8, size().height() / 2);
    std::unique_ptr<Instrument> guitar(new Instrument(this, ":/instruments/instruments/Guitars/main_guitar/guitar.png",
                                                      ":/instruments/instruments/Guitars/main_guitar/disabled_guitar.png",
                                                      ":/tracks/tracks/main_vocal_voice.mp3", position));

    instruments.push_back(std::move(guitar));
}

void MainWindow::setBackground() {
    setStyleSheet(BACKGROUND_LOAD);

    QImage background(BACKGROUND);
    QSize imageSize = background.size();
    setFixedSize(imageSize.width(), imageSize.height());
    centerWindow();
}

//void MainWindow::showLabel(QImage& imageToLabel) {
////    std::unique_ptr<QLabel> label(new QLabel("some text", this));
//    label->setPixmap(QPixmap::fromImage(imageToLabel));
//    label->show();
//}

void MainWindow::centerWindow() {
    QDesktopWidget desktopWindow;
    int x = (desktopWindow.width()-width()) / 2;
    int y = (desktopWindow.height()-height()) / 2;
    move(x, y);
}

MainWindow::~MainWindow()
{
    delete ui;
}
