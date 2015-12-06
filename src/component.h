#ifndef COMPONENT_H
#define COMPONENT_H

#include <QImage>
#include <QLabel>
#include <memory>

#include "point.h"

class Component
{
public:
    Component();

    void showLabel();

protected:
    std::unique_ptr<QLabel> enabledLabel;
    std::unique_ptr<QLabel> disabledLabel;

    bool enabled;

    QSize size;
    Point position;
};

#endif // COMPONENT_H
