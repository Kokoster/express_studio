#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <memory>

#include "instrument.h"
#include "clickable_label.h"

class Band;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void labelClicked(ClickableLabel *label);

private:
    Ui::MainWindow *ui;

    std::unique_ptr<Band> band;
    std::vector<std::unique_ptr<ClickableLabel>> labels;

    void centerWindow();
    void initBackground();
};

#endif // MAIN_WINDOW_H
