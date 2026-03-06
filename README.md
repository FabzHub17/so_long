# so_long    🎮

*This project has been created as part of the 42 curriculum by FabzHub17.* 

## Description 📝

**so_long** is a small 2D game developed using the **MiniLibX** graphical library. The goal of this project is to explore basic graphics management, including window handling, event monitoring (keyboard and mouse), and rendering textures/sprites.

In this specific implementation, the player must navigate through a map, collect all available items, and reach the exit using the shortest possible route. The project focuses on building a functional game engine that parses map files (`.ber`) and handles real-time user input.

## Instructions 🛠️

### Prerequisites

To run this project, you need the **MiniLibX** library installed on your system.

### Compilation

The project includes a `Makefile` that complies with school standards. To compile the game, run:

```bash
make

```

This will generate the `so_long` executable.

### Execution

To launch the game, you must provide a map file with the `.ber` extension as an argument:

```bash
./so_long maps/map.ber

```

### Controls ⌨️

* **W / A / S / D** (or arrow keys): Move the character.

* **ESC**: Close the window and exit the game cleanly.

* **Window Cross (X)**: Close the window and exit the game cleanly.


## Resources 📚

* **Documentation:** [MiniLibX Handbook](https://harm-smits.github.io/42docs/libs/minilibx) for window and image management.
  
* **Algorithms:** Flood Fill algorithm concepts for verifying valid map paths.
  
* **Assets:** Various tilesets sourced from OpenGameArt or itch.io.

---

### Features (Mandatory Part) ✅

* **Map Validation:** Checks for rectangular shape, enclosed walls, and valid paths.

* **Movement Tracking:** Displays the current number of moves in the terminal.

* **Smooth Graphics:** Handles window resizing and minimizing without crashing.

