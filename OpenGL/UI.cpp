//
// Created by snake0x8 on 4/21/25.
//

#include "UI.h"

UI::UI() = default;
UI::~UI() = default;

void UI::Render() {
    for (auto element : m_elements) {
        element->Render();
    }
}

void UI::HandleMouse(wxMouseEvent& event) {
    for (auto element : m_elements) {
        element->OnMouseEvent(event);
    }
}

void UI::AddElement(UIElement* element) {
    m_elements.push_back(element);
}

