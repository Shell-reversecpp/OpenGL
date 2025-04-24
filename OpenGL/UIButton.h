//
// Created by snake0x8 on 4/21/25.
//

#ifndef UIBUTTON_H
#define UIBUTTON_H


#include <functional>

#include "IButtonListener.h"
#include "UIElement.h"


class UIButton : public UIElement  {
public:
    UIButton(float x, float y, float w, float h, const std::string& imagePath);

    void Render() override;
    void OnMouseEvent(wxMouseEvent& event) override;

    void SetOnClick(function<void()> callback);

    void SetListener(IButtonListener* listener);

private:
    float m_x, m_y, m_width, m_height;
    GLuint m_texture;
    std::function<void()> m_onClick;

    IButtonListener* m_listener = nullptr;

    void LoadTexture(const std::string& path);
    bool IsInside(float px, float py) const;
};



#endif //UIBUTTON_H
