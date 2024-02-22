//
// Created by Mikael on 20/02/2024.
//

#ifndef TICK_TACK_TOE_INPUT_H
#define TICK_TACK_TOE_INPUT_H


class Input {
public:
    enum Key {
        LeftMouse = 0,
        RightMouse = 1,
        MiddleMosue = 2
    };
    void Update();
    bool IsKeyPressed(Key keycode);
    bool IsKeyDown(Key keycode);
    bool IsKeyUp(Key keycode);
private:
    unsigned short currentFrameKeys;
    unsigned short lastFrameKeys;
};


#endif //TICK_TACK_TOE_INPUT_H
