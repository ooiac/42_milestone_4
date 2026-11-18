# Milestone 4 — C++00–04, cub3D, NetPractice

Three parts of the 42 Common Core: the first C++98 modules, a raycasting-based first-person renderer, and exercises in IPv4 addressing and routing.

## C++ modules 00–04

Source: [`CPP_Modules/`](CPP_Modules/)

These exercises introduce object-oriented programming using **C++98**, without later language features such as `auto`, `nullptr`, or range-based loops. Each exercise has its own directory and Makefile.

| Module | Main topics | Typical exercise |
| --- | --- | --- |
| **CPP00** | Classes, access control, constructors/destructors, static members, streams | `PhoneBook`, `Account` |
| **CPP01** | `new`/`delete`, references, pointers to members, lifetime and ownership | `Zombie`, `Weapon`, `Harl` |
| **CPP02** | Orthodox Canonical Form, fixed-point numbers, operator overloading | `Fixed` |
| **CPP03** | Inheritance, constructor chaining, diamond-style class relationships | `ClapTrap`, `ScavTrap`, `FragTrap`, `DiamondTrap` |
| **CPP04** | Subtype polymorphism, virtual destructors, abstract classes, deep copies | `Animal`, `Brain`, `Materia` |

### What changes compared with C

A class can tie its state to construction and destruction. When an object owns memory, copying it may need a **deep copy** rather than copying the raw pointer. Inheritance introduces another problem: deleting a derived object through a base pointer requires a virtual destructor when that pointer owns the object.

In the `Fixed` exercises, operator overloads make a class usable with arithmetic and comparisons. In the `Animal` and `Materia` exercises, virtual functions let behavior depend on the actual object type at runtime rather than the type of pointer used to access it.

Build one exercise at a time:

```sh
cd CPP_Modules
# Enter the module and exercise directory you want to build.
# Each exercise has its own Makefile.
make
```

Use the actual folder names in `CPP_Modules/`; the example illustrates the usual per-exercise workflow. Compilers are invoked with `-std=c++98 -Wall -Wextra -Werror`.

## cub3D

Source: [`Cub3d/`](Cub3d/) · [Detailed README](Cub3d/README.md)

A first-person maze rendered from a 2D map using MiniLibX and **raycasting**. A ray is cast for each vertical screen column, then DDA (Digital Differential Analysis) walks the map grid to find the wall hit. The corrected distance determines how tall the wall appears; the side hit determines which wall texture to sample.

The mandatory part reads `.cub` configuration files, including four directional texture paths, floor and ceiling RGB colors, and an enclosed map. Player movement uses WASD, rotation uses arrow keys, and walls block movement. The bonus adds doors, a minimap, sprites/enemies, weapons, and mouse controls.

A simplified map:

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

`1` marks a wall, `0` a free tile, and `N/S/E/W` the player's spawn direction. A valid map also needs to be enclosed so rays and movement cannot escape into undefined space.

```sh
cd Cub3d
make
./cub3D maps/test.cub
make bonus
./cub3D_bonus maps/test_bonus.cub
```

The project is built for Linux and needs X11/MiniLibX dependencies. The internal README covers controls, map formatting, and the bonus.

## NetPractice

Source: [`NetPractice/`](NetPractice/) · [Detailed README](NetPractice/README.md)

Ten networking exercises solved through a local browser interface. You configure IP addresses, subnet masks, default gateways, and static routes to connect hosts across networks. There is no C program to compile.

For example, the network `192.168.1.0/24` covers `192.168.1.0` through `192.168.1.255`. The first address identifies the network, the last is the broadcast address, and usable host addresses are generally `.1` through `.254`. A host on another subnet needs a route via a reachable router; just changing an IP address does not make the networks communicate.

The exercises get harder as more routers and overlapping address ranges appear. You must work out which routes are reachable and where the default gateway belongs. The training interface checks the configuration and exports the files required for evaluation.

See the internal README for the launcher, export steps, and evaluation mode.
