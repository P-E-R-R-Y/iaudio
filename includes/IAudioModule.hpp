/**
 * @file IAudioModule.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief
 * @version 0.1
 * @date 2026-08-10
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef IAUDIO_MODULE_HPP
#define IAUDIO_MODULE_HPP

#include "IMusic.hpp"
#include "ISound.hpp"

#include "IModule.hpp"

class IAudioModule : public IModule {

public:
    static constexpr const char *entry = "getAudioModule";

    virtual ~IAudioModule() = default;

    // music
    virtual audio::IMusic *createMusic(std::string path) = 0;
    virtual void deleteMusic(audio::IMusic *music) = 0;
    // sound
    virtual audio::ISound *createSound(std::string path) = 0;
    virtual void deleteSound(audio::ISound *sound) = 0;
};

#endif /* !IAUDIO_MODULE_HPP */
