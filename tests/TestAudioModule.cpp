#include <gtest/gtest.h>
#include "IModule.hpp"
#include "IAudioModule.hpp"
#include "DummyAudioModule.hpp"

TEST(AudioModuleTest, AudioObject) {
    DummyAudioModule mod;

    EXPECT_STREQ(mod.name(), "DummyAudio");
    EXPECT_STREQ(mod.type(), "audio");

    audio::IMusic *music = mod.createMusic("");
    audio::ISound *sound = mod.createSound("");

    ASSERT_NE(music, nullptr);
    ASSERT_NE(sound, nullptr);

    music->play();
    sound->play();

    mod.deleteMusic(music);
    mod.deleteSound(sound);
}
