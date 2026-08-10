#pragma once

#include "../includes/IAudioModule.hpp"
#include "DummyMusic.hpp"
#include "DummySound.hpp"

class DummyAudioModule : public IAudioModule {
public:
    DummyAudioModule() {}
    ~DummyAudioModule() {}

    const char *type() const override { return "audio"; }
    const char *name() const override { return "DummyAudio"; }

    audio::IMusic *createMusic(std::string) override { return new DummyMusic(); }
    void deleteMusic(audio::IMusic *m) override { delete m; }

    audio::ISound *createSound(std::string) override { return new DummySound(); }
    void deleteSound(audio::ISound *s) override { delete s; }
};
