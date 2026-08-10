/**
 * @file ISound.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief
 * @date 2025-09-24
 *
 * @addtogroup audio
 * @{
 */

#ifndef ISOUND_HPP_
    #define ISOUND_HPP_

    #include "Type.hpp"
    #include <string>

namespace audio {

    class ISound {

        public:

            virtual ~ISound() = default;

            virtual bool isReady() const = 0;

            /**
             * @brief play the sound
             */
            virtual void play() = 0;

            /**
             * @brief pause the sound
             *
             */
            virtual void pause() = 0;

            /**
             * @brief stop the sound and reset it to the beginning
             *
             */
            virtual void stop() = 0;

            /**
             * @brief set the volume of the sound
             *
             * @param volume
             */
            virtual void setVolume(float volume) = 0;

            /**
             * @brief get the volume of the sound
             *
             * @return float
             */
            virtual float getVolume() const = 0;

            /**
             * @brief set the 3D position of the sound, for backends that
             *        spatialize against a listener. A backend without real
             *        spatial audio may just store this and keep playing at
             *        full volume - a no-op here still leaves a usable sound,
             *        unlike a fake 3D model with nothing to render.
             *
             * @param position
             */
            virtual void setPosition(Vector3f position) = 0;

            /**
             * @brief get the 3D position of the sound
             *
             * @return Vector3f
             */
            virtual Vector3f getPosition() const = 0;

            /**
             * @brief set the velocity of the sound, used by backends that
             *        apply a doppler effect
             *
             * @param velocity
             */
            virtual void setVelocity(Vector3f velocity) = 0;

            /**
             * @brief get the velocity of the sound
             *
             * @return Vector3f
             */
            virtual Vector3f getVelocity() const = 0;
    };

}

#endif /* !ISOUND_HPP_ */
