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
    void setPosition(Vector3f position) override { _position = position; }
    Vector3f getPosition() const override { return _position; }
    void setVelocity(Vector3f velocity) override { _velocity = velocity; }
    Vector3f getVelocity() const override { return _velocity; }

private:
    float _volume = 1.f;
    Vector3f _position{};
    Vector3f _velocity{};
};
