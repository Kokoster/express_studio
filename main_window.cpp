#include "main_window.h"
#include "ui_mainwindow.h"

#include "QDesktopWidget"

#include "background.h"

const QString BACKGROUND = "/Users/kokoster/ExpressStudio/res/background/grey_room_trial2.jpg ";
const QString BACKGROUND_LOAD = "background-image: url(/Users/kokoster/ExpressStudio/res/background/grey_room_trial2.jpg)";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setBackground();
}

void MainWindow::setBackground() {
    setStyleSheet(BACKGROUND_LOAD);

    QImage background(BACKGROUND);
    QSize imageSize = background.size();
    setFixedSize(imageSize.width(), imageSize.height());
    centerWindow();
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
