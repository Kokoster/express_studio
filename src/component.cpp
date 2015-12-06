#include "component.h"

Component::Component() {}

void Component::showLabel() {
    if (!enabled) {
        enabledLabel->show();
     } else {
        disabledLabel->show();
    }
}
