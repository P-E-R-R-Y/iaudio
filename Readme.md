# Iaudio

version: 0.1.0

> AudioSharedLoader

Split out of [igraphic](https://github.com/P-E-R-R-Y/igraphic) - audio has
no real coupling to a window in any backend (`InitAudioDevice()` doesn't
need `InitWindow()`), so it's a fully independent, separately loadable
contract, not something bundled into the graphics module.

## IAudioModule

- music -> IMusic (streams from disk, no shared buffer - one IMusic always
  owns its own stream, same as sf::Music/LoadMusicStream)
- sound buffer -> ISoundBuffer (loaded samples, independent of any ISound
  that plays them - deleting every ISound built from a buffer does not
  delete the buffer, only deleteSoundBuffer() does)
- sound -> ISound (built from an ISoundBuffer, mirrors sf::SoundBuffer/sf::Sound)
