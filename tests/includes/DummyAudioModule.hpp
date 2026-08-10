#pragma once

#include "../includes/IAudioModule.hpp"
#include "DummyMusic.hpp"
#include "DummySound.hpp"
#include "DummySoundBuffer.hpp"

class DummyAudioModule : public IAudioModule {
public:
    DummyAudioModule() {}
    ~DummyAudioModule() {}

    const char *type() const override { return "audio"; }
    const char *name() const override { return "DummyAudio"; }

    audio::IMusic *createMusic(std::string) override { return new DummyMusic(); }
    void deleteMusic(audio::IMusic *m) override { delete m; }

    audio::ISoundBuffer *createSoundBuffer(std::string) override { return new DummySoundBuffer(); }
    void deleteSoundBuffer(audio::ISoundBuffer *b) override { delete b; }

    audio::ISound *createSound(audio::ISoundBuffer *) override { return new DummySound(); }
    void deleteSound(audio::ISound *s) override { delete s; }
};
