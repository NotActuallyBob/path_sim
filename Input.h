//
// Created by Mikael on 20/02/2024.
//

#ifndef TICK_TACK_TOE_INPUT_H
#define TICK_TACK_TOE_INPUT_H


class Input {
public:
    Input();
    enum Key {
        LeftMouse = 0,
        RightMouse = 1,
        MiddleMouse = 2
    };
    void Update();
    bool IsKeyPressed(Key keycode) const;
    bool IsKeyDown(Key keycode) const;
    bool IsKeyUp(Key keycode) const;
private:
    unsigned short currentFrameKeys;
    unsigned short lastFrameKeys;
};


#endif //TICK_TACK_TOE_INPUT_H
