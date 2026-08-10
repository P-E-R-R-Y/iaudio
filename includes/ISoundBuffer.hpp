/**
 * @file ISoundBuffer.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief
 * @date 2026-08-10
 *
 * @addtogroup audio
 * @{
 */

#ifndef ISOUNDBUFFER_HPP_
    #define ISOUNDBUFFER_HPP_

namespace audio {

    /**
     * @brief Loaded audio samples, independent of any ISound that plays
     *        them - deleting every ISound built from a buffer does not
     *        delete the buffer, only deleteSoundBuffer() does. Not used by
     *        IMusic, which streams from disk instead of loading a full
     *        buffer, so there's nothing to share there.
     * @interface ISoundBuffer
     */
    class ISoundBuffer {

        public:

            virtual ~ISoundBuffer() = default;

            /**
             * @brief notice if the buffer is ready
             *
             * @return bool
             */
            virtual bool isReady() const = 0;

            /**
             * @brief Get the Length of the buffered sound, in seconds
             *
             * @return float
             */
            virtual float getLength() const = 0;
    };

}

#endif /* !ISOUNDBUFFER_HPP_ */
