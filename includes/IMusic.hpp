/**
 * @file IMusic.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief
 * @date 2025-09-24
 *
 * @addtogroup iaudio
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
             * @brief Starts playback.
             *
             * Three states, and every action does ONLY what it says :
             *
             *     stopped --play()--> playing  --pause()--> paused
             *     paused  --play()--> playing  (resumes where it was)
             *     stopped --play()--> playing  (from zero)
             *
             * play() on a stream that is already playing DOES NOTHING. It
             * does not restart from the beginning : without that rule, a
             * play() called every frame stutters on one vendor and plays
             * normally on the other. To restart, call stop() then play(),
             * or setTime(0) - explicitly.
             */
            virtual void play() = 0;

            /**
             * @brief Suspends playback without touching the position.
             *
             * Does nothing if the stream is not playing. Idempotent.
             */
            virtual void pause() = 0;

            /**
             * @brief Stops playback AND rewinds to zero.
             *
             * Does nothing if the stream is already stopped. Idempotent.
             */
            virtual void stop() = 0;

            /**
             * @brief Must be called every frame.
             *
             * On a backend that refills its buffer in a thread this is a
             * no-op - the call stays mandatory and always valid, otherwise
             * game code would have to know which vendor is behind it.
             *
             * This is also where a non-looping stream that reaches its end
             * moves itself into the state of a stop().
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
             * @brief Set the time of the music in seconds.
             *
             * The position is CLAMPED to [0, getLength()] : asking past the
             * end stops at the end, a negative value rewinds to zero.
             * Without that rule each vendor improvises - raylib wrapped
             * around (115s on a 109s track gave 6s) where sfml fell to 0.
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

/** @} */

#endif /* !IMUSIC_HPP_ */
