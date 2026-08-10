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

    // graceful degradation : a backend without real spatial audio can just
    // store this and keep playing at full volume, never a hard failure
    sound->setPosition({1, 2, 3});
    EXPECT_EQ(sound->getPosition(), Vector3f({1, 2, 3}));
    music->setVelocity({0, 0, 1});
    EXPECT_EQ(music->getVelocity(), Vector3f({0, 0, 1}));

    mod.deleteMusic(music);
    mod.deleteSound(sound);
}
