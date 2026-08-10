#pragma once
#include "ISound.hpp"

class DummySound : public audio::ISound {
public:
    DummySound() {}
    ~DummySound() {}

    bool isReady() const override { return true; }
    void play() override {}
    void pause() override {}
    void stop() override {}
    void setVolume(float volume) override { _volume = volume; }
    float getVolume() const override { return _volume; }

private:
    float _volume = 1.f;
};
