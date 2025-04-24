//
// Created by snake0x8 on 4/21/25.
//

#ifndef UI_H
#define UI_H

#include "UIElement.h"

class UI {
public:
    UI();
    ~UI();

    void Render();
    void HandleMouse(wxMouseEvent& event);

    void AddElement(UIElement* element);
private:
    std::vector<UIElement*> m_elements;
};


#endif //UI_H
