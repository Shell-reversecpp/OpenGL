//
// Created by snake0x8 on 4/19/25.
//

#ifndef GLCANVAS_H
#define GLCANVAS_H

#include "common.h"
#include "Game.h"

class GLCanvas : public wxGLCanvas {
public:
    GLCanvas(wxWindow* parent);
    ~GLCanvas();

    bool IsGLInitialized() const { return m_glInitialized; }
    wxGLContext* GetContext() const { return m_context; }

    void MakeCurrentContext();

private:
    wxGLContext* m_context;
    bool m_glInitialized;
    Game* m_game;

    void EnsureGLContext();
    bool InitGL();
    void Render();

    void OnPaint(wxPaintEvent& event);
    void OnSize(wxSizeEvent& event);
    void OnEraseBackground(wxEraseEvent& event);

    void OnKeyDown(wxKeyEvent& event);

    wxDECLARE_EVENT_TABLE();
};

#endif // GLCANVAS_H