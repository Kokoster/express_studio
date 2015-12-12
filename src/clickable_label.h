#ifndef LABEL_H
#define LABEL_H

#include <QLabel>
#include <QMouseEvent>

class ClickableLabel : public QLabel
{
    Q_OBJECT
public:
    ClickableLabel(QWidget *parent = 0, Qt::WindowFlags f = 0);
    ClickableLabel(const QString &text, QWidget *parent=0, Qt::WindowFlags f = 0);
    ClickableLabel(QWidget *parent, std::string enabledLabelName, std::string disabledLabelName);
    ~ClickableLabel() {}

signals:
    void clicked(ClickableLabel* label);

public slots:
    void changeState();

protected:
    void setEnabled(bool enabled);

private:
    void mouseReleaseEvent(QMouseEvent* event);

    QPixmap enabledImage;
    QPixmap disabledImage;

    bool enabled;
};

#endif // LABEL_H
