# Our Last Hope (WIP)
>**Warning:** this game is still under work.
Supports for Linux and MacOS will be included afterwards.

**Our Last Hope** is a interactive text game made in **C** based in a post-apocalyptic world.

## To do:

- Window resizing.
- Permission denied when save deleted (Windows only).
- Ensure player's input can not break the game.
- Use items in inventory.
- Change images for better lisibility.

## Authors

**Made by:**
- PACE--BOULNOIS Lysandre
- MELOCCO David

## Installation

Compile the game (see below), then launch ```game``` (```game.exe``` on Windows) from the main folder.

### Compiling

Open the .zip folder, extract it, and compile it with `make` (it needs `gcc` and `make`):

```make```

Use ```make clean``` to remove the build files.

Then, use the following command line : ```./game``` (```./game.exe``` on Windows) to launch the game from the main folder.

## Project structure

```
include/        Headers (one per module)
src/
  main.c        Entry point
  core/         Game loop and shared game state
  io/           Console helpers and text file reading
  ui/           HUD
  player/       Player's name and inputs
  screens/      Language, title, save files, naming, opening cutscene, map and inventory screens
  areas/        Campfire, forest, town, lake, park and mall
  world/        Map tiles, map generation and save files
assets/
  lang/en, fr/  Translated texts
  art/          ASCII art (title, backgrounds, cutscenes)
data/saves/     Save files (created by the game)
```

### Prerequisites

To play the game correctly, please configure your command prompt to read UTF-8 characters by following these steps:

1. Go to settings (```Win + U```) 
2. Time and language -> Language and region
3. Administration of language settings
4. Change regional settings
5. Enable **Beta** to use **UTF-8** encoding.
6. Restart your computer

## Controls
- e : Interact 👉
- m : Map 🗺️
- i : Inventory 🎒
- s : Save 💾

>Theses settings are likely to be changed in further versions.

## Challenges

This is the list of the challenges that are

***currently featured:***
- Add a possibility to save the progress in a file.
- Add a method of automatic generation of the map in a random way.
- Add an inventory management system in which you can retrieve items and use them.

> Three save slots are available: each one is saved in the ```data/saves``` folder. For now, only the name and the map are saved.

***partially featured:***
- Manage simple typing errors (uppercase instead of lowercase).

***likely to be featured:***
- Add a percentage of progression.
- Random in-game events (traps, attacks, sicknesses, weather conditions...)
- Add in-game events based on the player current game time.
- Add a virtual economy that allows you to buy or sell items based on their rarity.
- Add non-player characters with more advanced behaviors, able to react to the player’s actions.
