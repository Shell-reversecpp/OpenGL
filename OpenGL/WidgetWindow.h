//
// Created by snake0x8 on 4/18/25.
//

#ifndef WIDGETWINDOW_H
#define WIDGETWINDOW_H


#include "Game.h"
#include "GameWindow.h"

class WidgetWindow : public wxApp {
public:
    virtual bool OnInit() {
        GameWindow* frame = new GameWindow();
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(WidgetWindow);

#endif //WIDGETWINDOW_H
