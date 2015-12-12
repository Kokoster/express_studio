#include "main_window.h"
#include "ui_mainwindow.h"

#include <QPixmap>

#include "QDesktopWidget"
#include "clickable_label.h"
#include "src/model/band.h"

const QString BACKGROUND = ":/background/grey_room.jpg";
const QString BACKGROUND_LOAD = "MainWindow {background-image: url(:/background/grey_room.jpg);}";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     Q_INIT_RESOURCE(resources);

    ui->setupUi(this);

    initBackground();
    centerWindow();

    band = std::unique_ptr<Band>(new Band(size()));

    const std::vector<std::unique_ptr<Instrument>>& instruments = band->getInstruments();
    for (int i = 0; i < (int) instruments.size(); ++i) {
        std::unique_ptr<ClickableLabel> label(new ClickableLabel(this, instruments[i]->getEnabledImageName(),
                                                                       instruments[i]->getDisabledImageName()));
        label->setProperty("instrumentIndex", i);

        // set position to label
        Point position = instruments[i]->getPosition();
        QRect rect(position.x, position.y,
                   position.x + label->size().width(),
                   position.y + label->size().height());

        label->setGeometry(rect);

        connect(label.get(), &ClickableLabel::clicked, this, &MainWindow::labelClicked);

        labels.push_back(std::move(label));
    }
}

void MainWindow::labelClicked(ClickableLabel *label) {
    band->toggleInstrument(label->property("instrumentIndex").toInt());
}


void MainWindow::initBackground() {
    setStyleSheet(BACKGROUND_LOAD);

    QImage background(BACKGROUND);
    QSize imageSize = background.size();
    setFixedSize(imageSize.width(), imageSize.height());
}

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
