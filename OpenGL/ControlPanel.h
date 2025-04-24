//
// Created by snake0x8 on 4/22/25.
//

#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include "UIButton.h"


class ControlPanel : public UIElement {
public:
    explicit ControlPanel(wxWindow* parent);
    ~ControlPanel() override;

    void Show(bool show);
    bool IsShown() const;

    void Render() override {}

    void OnMouseEvent(wxMouseEvent& event) override {}

    float GetSliderValue() const;
    bool GetCheckBoxValueShowPyramid() const;
    bool GetCheckBoxValueShowCube() const;

private:
    wxPanel* m_panel;
    wxSlider* m_slider;
    wxCheckBox* m_checkBoxShowCube;
    wxCheckBox* m_checkBoxShowPyramid;
};

#endif //CONTROLPANEL_H
