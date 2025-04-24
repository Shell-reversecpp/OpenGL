//
// Created by snake0x8 on 4/21/25.
//

#define STB_IMAGE_IMPLEMENTATION
#include "UIButton.h"
#include <stb/stb_image.h>


UIButton::UIButton(float x, float y, float w, float h, const std::string& imagePath)
    : m_x(x), m_y(y), m_width(w), m_height(h), m_texture(0) {
    LoadTexture(imagePath);
}

void UIButton::SetOnClick(std::function<void()> callback) {
    m_onClick = std::move(callback);

}

void UIButton::SetListener(IButtonListener *listener) {

    m_listener = listener;

}

void UIButton::LoadTexture(const std::string& path) {
    int width, height, channels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &channels, 4);

    if (!data) {
        wxLogError("Failed to load UI texture: %s", path);
        return;
    }

    glGenTextures(1, &m_texture);
    glBindTexture(GL_TEXTURE_2D, m_texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_image_free(data);
}

void UIButton::Render() {
    if (!m_texture) return;


    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBindTexture(GL_TEXTURE_2D, m_texture);

    glColor4f(1.f, 1.f, 1.f, 1.f);

    glBegin(GL_QUADS);
    glTexCoord2f(0.f, 0.f); glVertex2f(m_x,           m_y);
    glTexCoord2f(1.f, 0.f); glVertex2f(m_x + m_width, m_y);
    glTexCoord2f(1.f, 1.f); glVertex2f(m_x + m_width, m_y + m_height);
    glTexCoord2f(0.f, 1.f); glVertex2f(m_x,           m_y + m_height);
    glEnd();

    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
}
void UIButton::OnMouseEvent(wxMouseEvent& event) {
    if (event.LeftDown()) {
        wxPoint mousePos = event.GetPosition();
        float px = static_cast<float>(mousePos.x);
        float py = static_cast<float>(mousePos.y);

        if (IsInside(px, py)) {
            if (m_onClick) {
                m_onClick();
            }
        }
    }
}

bool UIButton::IsInside(float px, float py) const {
    return (px >= m_x && px <= m_x + m_width &&
            py >= m_y && py <= m_y + m_height);
}