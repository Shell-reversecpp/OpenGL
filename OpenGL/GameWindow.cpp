//
// Created by snake0x8 on 2/2/24.
//

#include "GameWindow.h"

wxBEGIN_EVENT_TABLE(GameWindow, wxFrame)
    EVT_CLOSE(GameWindow::OnClose)
wxEND_EVENT_TABLE()

GameWindow::GameWindow(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)) {

    m_glCanvas = new GLCanvas(this);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(m_glCanvas, 1, wxEXPAND);
    SetSizer(sizer);
    Layout();
}

void GameWindow::OnClose(wxCloseEvent& event) {
    Destroy();
}