#pragma once
#include "ISoundBuffer.hpp"

class DummySoundBuffer : public audio::ISoundBuffer {
public:
    DummySoundBuffer() {}
    ~DummySoundBuffer() {}

    bool isReady() const override { return true; }
    float getLength() const override { return 0.f; }
};
