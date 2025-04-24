//
// Created by snake0x8 on 4/22/25.
//

#include "ControlPanel.h"


ControlPanel::ControlPanel(wxWindow* parent) {
    constexpr int panelWidth = 300;
    constexpr int panelHeight = 180;


    m_panel = new wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(panelWidth, panelHeight));
    m_panel->SetBackgroundColour(*wxLIGHT_GREY);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    m_slider = new wxSlider(m_panel, wxID_ANY, 50, 0, 100,
                            wxDefaultPosition, wxSize(250, -1), wxSL_HORIZONTAL);
    m_checkBoxShowCube = new wxCheckBox(m_panel, wxID_ANY, "Show Cube");

    m_checkBoxShowPyramid = new wxCheckBox(m_panel, wxID_ANY, "Show Piramid");


    sizer->AddStretchSpacer(1);
    sizer->Add(m_slider, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);
    sizer->Add(m_checkBoxShowCube, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);
    sizer->Add(m_checkBoxShowPyramid, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);
    sizer->AddStretchSpacer(1);

    m_panel->SetSizer(sizer);

    wxSize parentSize = parent->GetSize();
    int x = ((parentSize.GetWidth() - panelWidth) / 2);
    int y = ((parentSize.GetHeight() - panelHeight) / 2)+parentSize.GetWidth()/4;
    m_panel->SetPosition(wxPoint(x, y));

    m_panel->Hide();
}

ControlPanel::~ControlPanel() {
    m_panel->Destroy();
}

void ControlPanel::Show(bool show) {
    if (show)
        m_panel->Show();
    else
        m_panel->Hide();
    m_panel->GetParent()->Layout();
}

bool ControlPanel::IsShown() const {
    return m_panel->IsShown();
}

float ControlPanel::GetSliderValue() const {
    return m_slider->GetValue();
}

bool ControlPanel::GetCheckBoxValueShowCube() const {
    return m_checkBoxShowCube->GetValue();
}

bool ControlPanel::GetCheckBoxValueShowPyramid() const {
    return m_checkBoxShowPyramid->GetValue();
}