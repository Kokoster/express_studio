#include "clickable_label.h"

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent, f) {}

ClickableLabel::ClickableLabel(const QString& text, QWidget* parent, Qt::WindowFlags f)
    : QLabel(text, parent, f) {}

ClickableLabel::ClickableLabel(QWidget *parent, std::string enabledLabelName, std::string disabledLabelName) :
    QLabel(parent),
    enabledImage(QPixmap::fromImage(QImage(enabledLabelName.c_str()))),
    disabledImage(QPixmap::fromImage(QImage(disabledLabelName.c_str())))
{
    setEnabled(false);
}

void ClickableLabel::setEnabled(bool enabled) {
    this->enabled = enabled;
    setFixedSize(this->enabled ? enabledImage.size() : disabledImage.size());
    setPixmap(this->enabled ? enabledImage : disabledImage);
}

void ClickableLabel::mouseReleaseEvent(QMouseEvent* event) {
    setEnabled(!enabled);
    emit clicked(this);
}

