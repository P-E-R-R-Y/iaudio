#pragma once
#include "IMusic.hpp"

class DummyMusic : public audio::IMusic {
public:
    DummyMusic() {}
    ~DummyMusic() {}

    bool isReady() const override { return true; }
    void play() override {}
    void pause() override {}
    void stop() override {}
    void update() override {}
    void setVolume(float volume) override { _volume = volume; }
    float getVolume() const override { return _volume; }
    void setLoop(bool loop) override { _loop = loop; }
    bool getLoop() const override { return _loop; }
    void setTime(float position) override { _time = position; }
    float getTime() const override { return _time; }
    float getLength() const override { return 0.f; }

private:
    float _volume = 1.f;
    float _time = 0.f;
    bool _loop = false;
};
