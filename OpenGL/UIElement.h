//
// Created by snake0x8 on 4/21/25.
//

#ifndef UIELEMENT_H
#define UIELEMENT_H

#include "common.h"

class UIElement {
public:
    virtual ~UIElement() = default;
    virtual void Render() = 0;
    virtual void OnMouseEvent(wxMouseEvent& event) {}
};


#endif //UIELEMENT_H
