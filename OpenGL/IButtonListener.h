//
// Created by snake0x8 on 4/22/25.
//

#ifndef IBUTTONLISTENER_H
#define IBUTTONLISTENER_H


class UIButton;

class IButtonListener {
public:
    virtual void OnButtonClicked(UIButton* btn) = 0;
};


#endif //IBUTTONLISTENER_H
