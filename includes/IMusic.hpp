/**
 * @file IMusic.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief
 * @date 2025-09-24
 *
 * @addtogroup audio
 * @{
 */

#ifndef IMUSIC_HPP_
    #define IMUSIC_HPP_

    #include "Type.hpp"
    #include <string>

namespace audio {

    class IMusic {

        public:

            virtual ~IMusic() = default;

            virtual bool isReady() const = 0;

            /**
             * @brief play the music
             */
            virtual void play() = 0;

            /**
             * @brief pause the music
             *
             */
            virtual void pause() = 0;

            /**
             * @brief stop the music and reset it to the beginning
             *
             */
            virtual void stop() = 0;

            /**
             * @brief update the music
             *
             */
            virtual void update() = 0;

            /**
             * @brief set the volume of the music
             *
             * @param volume
             */
            virtual void setVolume(float volume) = 0;

            /**
             * @brief get the volume of the music
             *
             * @return float
             */
            virtual float getVolume() const = 0;

            /**
             * @brief set the music to loop or not
             *
             * @param loop
             */
            virtual void setLoop(bool loop) = 0;

            /**
             * @brief get if the music is looping or not
             *
             * @return true
             * @return false
             */
            virtual bool getLoop() const = 0;

            /**
             * @brief Set the time of the music in seconds
             *
             * @param position
             */
            virtual void setTime(float position) = 0;

            /**
             * @brief Get the current time of the music in seconds
             *
             * @return float
             */
            virtual float getTime() const = 0;

            /**
             * @brief Get the Length of the music
             *
             * @return float
             */
            virtual float getLength() const = 0;

            /**
             * @brief set the 3D position of the music, for backends that
             *        spatialize against a listener. A backend without real
             *        spatial audio may just store this and keep playing at
             *        full volume - a no-op here still leaves usable music,
             *        unlike a fake 3D model with nothing to render.
             *
             * @param position
             */
            virtual void setPosition(Vector3f position) = 0;

            /**
             * @brief get the 3D position of the music
             *
             * @return Vector3f
             */
            virtual Vector3f getPosition() const = 0;

            /**
             * @brief set the velocity of the music, used by backends that
             *        apply a doppler effect
             *
             * @param velocity
             */
            virtual void setVelocity(Vector3f velocity) = 0;

            /**
             * @brief get the velocity of the music
             *
             * @return Vector3f
             */
            virtual Vector3f getVelocity() const = 0;
    };

}

#endif /* !IMUSIC_HPP_ */
