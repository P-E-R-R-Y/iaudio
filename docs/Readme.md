# Iaudio

version: 0.1.0

> Contrat audio : musiques, sons, buffers d'echantillons.

[![Docs](https://img.shields.io/badge/docs-doxygen-blue.svg)](https://p-e-r-r-y.github.io/iaudio)

Un seul contrat, pas deux : aucun vendor n'est force de simuler l'audio
spatial. Un backend stereo qui ignore `setPosition()` joue quand meme le
son et le jeu reste jouable, donc rien ne justifie un `IAudio3Module` a
cote.

## IAudioModule

- music -> `IMusic`, diffusee depuis le disque, un flux par instance
- sound buffer -> `ISoundBuffer`, les echantillons charges
- sound -> `ISound`, construit depuis un `ISoundBuffer`

## Ressources chargees et objets qui les referencent

`ISoundBuffer` porte les echantillons, `ISound` n'en porte qu'une
reference, et N sons peuvent partager un buffer : supprimer tous les sons
ne supprime pas le buffer, seul `deleteSoundBuffer()` le fait. `IMusic` n'a
pas de buffer du tout - elle diffuse, il n'y a rien a partager.

## Ce qui n'est pas ici

- le graphique -> [igraphic](https://github.com/P-E-R-R-Y/igraphic), dont
  ce contrat a ete detache : l'audio n'a de couplage a une fenetre dans
  aucun backend (`InitAudioDevice()` n'a besoin d'aucun `InitWindow()`)
- le chargement des vendors -> [imodule](https://github.com/P-E-R-R-Y/imodule).
  Ce repo ne charge rien : il ne contient que des interfaces.
