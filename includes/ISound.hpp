/**
 * @file ISound.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief
 * @date 2025-09-24
 *
 * @addtogroup iaudio
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
             * @brief Fires the sound from the beginning.
             *
             * The ONLY deliberate divergence from IMusic::play() : an ISound
             * is a one-shot, not a transport. play() on a sound already
             * playing RESTARTS it from zero - that is what lets a gunshot
             * retrigger faster than its own duration. IMusic, by contrast,
             * ignores a play() while playing.
             *
             * The difference is written here because it is intended. It
             * cannot be guessed from the signature, and both vendors have
             * to honour it identically.
             */
            virtual void play() = 0;

            /**
             * @brief Suspends the sound without touching the position.
             *
             * Does nothing if the sound is not playing. Idempotent.
             */
            virtual void pause() = 0;

            /**
             * @brief Stops the sound AND rewinds to zero.
             *
             * Does nothing if the sound is already stopped. Idempotent.
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

/** @} */

#endif /* !ISOUND_HPP_ */
