//
// Created by snake0x8 on 2/2/24.
//

#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H


#include "GLCanvas.h"

class GameWindow : public wxFrame {
public:
    explicit GameWindow(const wxString& title = "wxWidgets Settings");

private:
    GLCanvas* m_glCanvas;

    void OnClose(wxCloseEvent& event);
    wxDECLARE_EVENT_TABLE();
};


#endif // GAME_WINDOW_H