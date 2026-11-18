# cub3D

*42 Common Core project by `caida-si` and `smetz`.*

A first-person maze renderer written in C with MiniLibX, inspired by early raycasting games such as *Wolfenstein 3D*. The map is two-dimensional; walls are rendered in perspective by casting rays across the player's field of view.

## Rendering

For each vertical screen column, the program:

1. Computes a ray direction from the player's direction and camera plane.
2. Uses **DDA** (Digital Differential Analysis) to step across map cells until it reaches a wall.
3. Calculates the perpendicular distance to avoid a fish-eye distortion.
4. Draws a textured wall slice whose height depends on that distance.
5. Fills the remainder with the configured ceiling and floor colors.

```text
2D grid                  Screen
111111                   |        | wall texture
100001   rays --->       |   ||   | depends on
10N001                   |  ||||  | distance
111111                   |________|
```

The player moves through the 2D map, while the rendered view makes the walls appear three-dimensional. Collision tests stop movement into solid cells. Because textures are assigned by wall direction, the same wall can look different from the north and from the east.

## Features

**Mandatory:** `.cub` file parsing, four directional wall textures, RGB floor/ceiling colors, player movement, camera rotation, wall collision, and window cleanup.

**Bonus:** minimap, interactive doors, animated sprites/enemies, weapon and shooting behavior, mouse rotation, and additional effects.

## Build and run

Linux is required, along with GCC or Clang, Make, MiniLibX, and the X11 development libraries.

```sh
cd Cub3d
make
./cub3D maps/test.cub

make bonus
./cub3D_bonus maps/test_bonus.cub
```

Other Makefile targets: `clean` removes object files, `fclean` removes build products, and `re` rebuilds everything.

## `.cub` map files

```text
NO ./assets/textures/north_texture.xpm
SO ./assets/textures/south_texture.xpm
WE ./assets/textures/west_texture.xpm
EA ./assets/textures/east_texture.xpm

F 220,100,0
C 225,30,0

111111
100001
1000N1
100001
111111
```

- `NO`, `SO`, `WE`, `EA`: XPM texture paths for the four wall directions.
- `F`, `C`: floor and ceiling colors as RGB triplets.
- `1`: wall; `0`: open space.
- `N`, `S`, `E`, `W`: player's initial position and direction.
- `D`: a door in bonus maps.

The map must have a valid spawn point and be enclosed by walls. Config parsing also needs to reject missing identifiers, invalid color values, and inaccessible textures before starting the renderer.

## Controls

| Input | Action |
| --- | --- |
| W / A / S / D | Move forward, left, backward, right. |
| Left / right arrow | Rotate camera. |
| Esc | Quit. |
| Mouse movement (bonus) | Rotate camera. |
| E (bonus) | Interact with a door. |
| Left click (bonus) | Shoot. |

## Code and references

The source is organized into initialization and cleanup, map parsing, player state/movement, raycasting, and rendering. The bonus code lives separately in `bonus/`, with headers in `inc/` and shared libraries alongside the project.

- [Lode's raycasting tutorial](https://lodev.org/cgtutor/raycasting.html) — DDA, camera geometry, textures.
- [Permadi's raycasting tutorial](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/) — classic explanation of the same technique.
- [MiniLibX reference](https://harm-smits.github.io/42docs/libs/minilibx) — window, image, and input functions.

AI tools were used for planning the code structure, understanding the raycasting math, debugging, and the original documentation. The team implemented the renderer and gameplay logic.
