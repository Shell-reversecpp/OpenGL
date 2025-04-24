//
// Created by snake0x8 on 4/19/25.
//

#include "GLCanvas.h"
#include "Game.h"

wxBEGIN_EVENT_TABLE(GLCanvas, wxGLCanvas)
    EVT_PAINT(GLCanvas::OnPaint)
    EVT_SIZE(GLCanvas::OnSize)
    EVT_KEY_DOWN(GLCanvas::OnKeyDown)
    EVT_ERASE_BACKGROUND(GLCanvas::OnEraseBackground)
wxEND_EVENT_TABLE()

GLCanvas::GLCanvas(wxWindow* parent)
    : wxGLCanvas(parent, wxID_ANY, nullptr,
                 wxDefaultPosition, wxDefaultSize,
                 wxFULL_REPAINT_ON_RESIZE),
      m_context(nullptr),
      m_glInitialized(false),
      m_game(nullptr)
{
    SetFocus();
    SetFocusFromKbd();
}

GLCanvas::~GLCanvas() {
    delete m_game;
    delete m_context;
}

void GLCanvas::EnsureGLContext() {
    if (!m_context)
        m_context = new wxGLContext(this);

    wxGLCanvas::SetCurrent(*m_context);
}

void GLCanvas::MakeCurrentContext() {
    if (m_context && IsShownOnScreen())
        wxGLCanvas::SetCurrent(*m_context);
}

bool GLCanvas::InitGL() {
    if (!gladLoadGL()) {
        wxLogError("Failed to initialize GLAD");
        return false;
    }

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    return true;
}

void GLCanvas::OnPaint(wxPaintEvent& WXUNUSED(event)) {
    wxPaintDC dc(this);
    EnsureGLContext();

    if (!m_glInitialized) {
        if (!InitGL()) return;
        m_glInitialized = true;

        m_game = new Game(this);
        if (!m_game->Initialise()) {
            wxLogError("Game initialization failed.");
            return;
        }
    }

    Render();
}

void GLCanvas::OnKeyDown(wxKeyEvent& event) {
    if (event.GetKeyCode() == WXK_ESCAPE) {
        wxLogMessage("Escape pressed — closing window");
        GetParent()->Close();
    }

    event.Skip();
}
void GLCanvas::Render() {
    if (m_game) {
        m_game->Render();
    } else {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        SwapBuffers();
    }
}

void GLCanvas::OnSize(wxSizeEvent& event) {
    event.Skip();

    if (!m_glInitialized || !m_game) return;

    MakeCurrentContext();

    wxSize sz = GetClientSize();
    glViewport(0, 0, sz.x, sz.y);
    m_game->UpdateProjectionMatrix(sz.x, sz.y);
}

void GLCanvas::OnEraseBackground(wxEraseEvent& event) {

    event.Skip(true);
}