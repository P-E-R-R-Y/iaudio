# Iaudio

version: 0.1.0

> AudioSharedLoader

Split out of [igraphic](https://github.com/P-E-R-R-Y/igraphic) - audio has
no real coupling to a window in any backend (`InitAudioDevice()` doesn't
need `InitWindow()`), so it's a fully independent, separately loadable
contract, not something bundled into the graphics module.

## IAudioModule

- music -> IMusic
- sound -> ISound
