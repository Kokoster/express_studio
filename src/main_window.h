#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <memory>

#include "instrument.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    std::vector<std::unique_ptr<Instrument>> instruments;

    void centerWindow();
    void setBackground();
    void loadInstruments();
//    void showLabel(QImage& imageToLabel);
};

#endif // MAIN_WINDOW_H
