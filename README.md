# 42 School — Milestone 4

Welcome to **Milestone 4** of the 42 School curriculum! This milestone marks a significant shift in your programming journey—you'll move beyond C and into **C++ (C++98)**, as well as tackle advanced graphics programming with **raycasting**.

## Overview

Milestone 4 consists of three major components:

| Project | Type | Language | Key Concepts |
|---------|------|----------|--------------|
| **CPP Modules (0-4)** | Learning Modules | C++98 | OOP, classes, inheritance, polymorphism, advanced concepts |
| **cub3D** | 3D Graphics Engine | C | Raycasting, graphics rendering, first-person view |
| **NetPractice** | Networking Exercises | Conceptual | TCP/IP, subnetting, routing, network configuration |

---

## Component 1: C++ Modules (CPP 0-4)

### What They Are

The **CPP modules** are a series of progressive coding exercises that teach you **Object-Oriented Programming (OOP)** using **C++98** (also called C++03). You'll learn how C++ extends C with classes, inheritance, polymorphism, and other advanced paradigms.

**Important Constraint: C++98 Only**

All cpp modules are restricted to **C++98 standard**. This means:
- No C++11 features (no auto, no nullptr, no range-based for loops)
- No C++14 or C++17+ features
- You must use older syntax and practices
- This teaches deeper understanding of C++ fundamentals

Why C++98? The 42 curriculum enforces this to ensure you learn core concepts, not rely on modern syntactic sugar.

### C++00: Introduction to C++

**Topics Covered:**
- Classes and objects
- Member variables and member functions (methods)
- Constructors and destructors
- Access modifiers (public, private, protected)
- The `this` pointer
- Const correctness
- Static members

**Example Exercise:**
Building a simple class like:
```cpp
class Megaphone
{
public:
    std::string makeItLoud(std::string str);
};
```

Learning to instantiate and use objects, understanding the object lifecycle.

### C++01: Memory and Pointers in C++

**Topics Covered:**
- `new` and `delete` operators (C++ way of dynamic allocation)
- References (the `&` operator as reference, not just address-of)
- Member pointers and function pointers
- Proper resource management
- Deep vs shallow copy

**Key Concepts:**
```cpp
// C way: malloc/free
int *ptr = (int *)malloc(sizeof(int));
free(ptr);

// C++ way: new/delete
int *ptr = new int;
delete ptr;
ptr = NULL;  // Important: prevent dangling pointer
```

### C++02: Ad-Hoc Polymorphism

**Topics Covered:**
- Function overloading
- Operator overloading (making `+`, `-`, `*`, etc. work with custom types)
- The assignment operator (`operator=`)
- Conversion operators

**Example:**
```cpp
class Fixed
{
    int fixed_point_number;
public:
    Fixed &operator=(const Fixed &other);
    Fixed operator+(const Fixed &other) const;
    bool operator>(const Fixed &other) const;
    // ... etc
};

Fixed a(5);
Fixed b(3);
Fixed c = a + b;  // Uses operator+
if (a > b) { }    // Uses operator>
```

### C++03: Inheritance and Polymorphism

**Topics Covered:**
- Class inheritance (deriving classes from base classes)
- Virtual functions
- Abstract classes (pure virtual functions)
- Method overriding
- Polymorphic behavior
- The `virtual` keyword
- `protected` access specifier

**Concept:**
```cpp
class Animal
{
public:
    virtual void speak() = 0;  // Pure virtual (abstract)
    virtual ~Animal() {}        // Virtual destructor
};

class Dog : public Animal
{
public:
    void speak() { std::cout << "Woof!\n"; }
};

Animal *animal = new Dog();
animal->speak();  // Calls Dog::speak() - polymorphism!
delete animal;
```

### C++04: Advanced Concepts

**Topics Covered:**
- Subtype polymorphism (more inheritance patterns)
- RTTI (Run-Time Type Information)
- Exception handling (try/catch/throw)
- Standard containers and iterators
- The Standard Template Library (STL) basics
- Casts and casting operators

**Example:**
```cpp
try {
    throw std::runtime_error("Something went wrong!");
}
catch (const std::exception &e) {
    std::cout << "Caught: " << e.what() << "\n";
}
```

### Why C++98 Matters

Learning C++98 teaches:
- **Explicit resource management**: You manually control memory allocation/deallocation
- **Core OOP principles**: Inheritance, polymorphism without modern syntax hiding them
- **Understanding the language**: Not just writing code, but understanding how it works
- **Pain that modern C++ alleviates**: Appreciate why C++11+ features exist

### C++98 vs Modern C++

| Feature | C++98 | Modern C++ (11+) |
|---------|-------|-----------------|
| Dynamic allocation | `new`/`delete` | `std::unique_ptr`, `std::make_unique` |
| Type deduction | Manual types | `auto` keyword |
| Range iteration | Manual loops | `for (int x : array)` |
| Null pointer | `NULL` or `0` | `nullptr` |
| Move semantics | Copy only | Move constructors |

### Compilation & Usage

```bash
cd cpp/cpp0_git/ex00
make                 # Compile with C++98 flag
# Output: executable for each exercise
```

The Makefile typically enforces:
```makefile
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
```

### Learning Path

1. **Start with CPP00**: Understand classes and objects
2. **Then CPP01**: Learn C++ memory management
3. **Continue through CPP02-04**: Build on OOP knowledge
4. **Do all exercises**: 2-3 per module (ex00, ex01, ex02, etc.)

Each module gets progressively more sophisticated. Finishing all cpp modules builds a solid foundation for using C++ in games, systems programming, or general development.

---

## Component 2: cub3D

### What It Is

**cub3D** is a **3D First-Person Shooter (FPS) engine** built using **raycasting**—the same technique used in the legendary Wolfenstein 3D (1992). You'll render a 3D maze environment where the player can navigate in first-person perspective.

### Raycasting Explained

Raycasting is a 2D-to-3D rendering technique:

```
Top-down 2D map:          First-person 3D view:
                          
111111                    [Rendered wall textures]
100001    Ray cast         [Floor and ceiling colors]
1000P1  --------->        [Player looking at walls]
100001    per pixel       [Distance-based perspective]
111111
```

**How it works:**
1. For each pixel on screen, cast a ray from player position
2. Find where the ray hits a wall
3. Calculate distance to wall
4. Draw a vertical line: closer = taller, farther = shorter
5. Apply textures and colors

### Key Features

**Mandatory:**
- Load `.cub` map file with texture paths and floor/ceiling colors
- First-person navigation (WASD keys)
- Rotation (arrow keys)
- Smooth raycasting rendering
- Textured walls (different textures for North, South, East, West)
- Floor and ceiling colors
- Collision detection
- Window management

**Bonus Features Implemented:**
- Mouse controls for rotation
- Minimap display
- Interactive doors
- Animated sprites/enemies
- Weapon system with shooting
- Wall damage effects
- Enhanced visual effects

### Example Map File (.cub)

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

111111111111111111
100000000000000001
100000000000000001
100000P00000000001
100000000000000001
111111111111111111
```

- `NO/SO/WE/EA`: Texture file paths
- `F`: Floor color (RGB)
- `C`: Ceiling color (RGB)
- Map: 1 = wall, 0 = empty, P/N/S/E/W = player spawn position and direction

### Rendering Pipeline

```
Read map file
    ↓
Initialize player/camera
    ↓
Main loop:
    - Get input (keyboard/mouse)
    - Cast rays for each x-pixel
    - Calculate wall distances
    - Apply textures based on direction
    - Render floor/ceiling
    - Display frame
    ↓
Handle events (window close, ESC)
```

### Graphics Library: MLX

cub3D uses **MLX** (a minimal graphics library created for 42):
- Window creation and management
- Pixel drawing
- Image loading (XPM format)
- Event handling (keyboard, mouse, window events)

### Compilation & Usage

```bash
cd cub3d_git
make                      # Compile mandatory
./cub3D maps/test.cub    # Run with a map file

make bonus                # Compile with bonus features
./cub3D_bonus maps/test_bonus.cub
```

### Learning Outcomes

- **Computer Graphics**: Understanding raycasting and rendering
- **Mathematical Concepts**: Trigonometry, distance calculations, angle handling
- **Performance Optimization**: Real-time rendering (~60 FPS)
- **Game Development**: Game loops, event handling, collision detection
- **File Parsing**: Reading and validating `.cub` configuration files

### Challenges

- **Ray-wall intersection**: Calculating accurate collision points
- **Texture mapping**: Mapping wall pixels from texture files to screen
- **Performance**: Rendering 1920x1080 pixels with raycasting in real-time
- **Edge cases**: Handling map boundaries, player getting stuck in walls
- **Minimap implementation** (bonus): Rendering a top-down view alongside first-person

---

## Component 3: NetPractice

### What It Is

**NetPractice** is a **networking fundamentals training platform** with 10 progressive exercises teaching TCP/IP addressing, routing, and network configuration. Unlike coding projects, NetPractice is **conceptual**—you configure networks visually through a web interface.

### Networking Concepts

**TCP/IP Addressing:**
- IPv4 addresses (192.168.1.1)
- Subnet masks (255.255.255.0)
- CIDR notation (/24 means 255.255.255.0)
- Network ranges and broadcast addresses

**Subnetting:**
```
Network: 192.168.1.0/24
Usable IPs: 192.168.1.1 to 192.168.1.254
Broadcast: 192.168.1.255
Gateway: 192.168.1.1 (or .254)
```

**Routing:**
- Default gateway (route to unknown networks)
- Static routing (specific paths for specific destinations)
- Routing decisions based on destination IP and subnet mask

**Network Devices:**
- **Router**: Connects networks, routes packets between them
- **Switch**: Connects devices within same network
- **Host**: End device (computer, server)

### Exercise Progression

1. **Levels 1-3**: Simple network configuration with single router
2. **Levels 4-6**: Multiple subnets and interconnected routers
3. **Levels 7-9**: Complex routing and overlapping networks
4. **Level 10**: Comprehensive network design challenge

### Example Exercise

**Goal**: Connect 3 computers through a router

```
   Computer A              Computer B
   192.168.1.2            192.168.1.3
          |                    |
          +-------- ROUTER --------+
                   192.168.1.1
```

**Configuration:**
- Computer A: IP = 192.168.1.2, Mask = 255.255.255.0, Gateway = 192.168.1.1
- Computer B: IP = 192.168.1.3, Mask = 255.255.255.0, Gateway = 192.168.1.1
- Router: IP = 192.168.1.1, Mask = 255.255.255.0

### Key Skills Developed

- **IP addressing**: Assigning valid IPs in appropriate ranges
- **Subnet calculation**: Determining network boundaries
- **Gateway configuration**: Routing packets between networks
- **Routing tables**: Static route configuration
- **Network design**: Planning device interconnection

### Learning Outcomes

- Understand how the internet actually works
- Configure real network scenarios
- Plan network topology
- Debug network connectivity issues
- Foundation for network administration or security roles

---

## Curriculum Context

| Milestone | Projects | Focus |
|-----------|---------|-------|
| 0 | libft | C foundation |
| 1 | ft_printf, get_next_line | C I/O |
| 2 | push_swap, minitalk, fract-ol | C algorithms & graphics |
| 3 | minishell, philosophers | C systems programming |
| **4** | **cpp 0-4, cub3D, netpractice** | **C++ OOP, advanced graphics, networking** |

Milestone 4 is where the curriculum branches:
- **C++ modules**: Transition to object-oriented programming
- **cub3D**: Advanced graphics taking fract-ol concepts to 3D
- **NetPractice**: Non-coding but essential systems knowledge

---

## Tips for Success

### CPP Modules
1. **Start with basics**: Understand how objects work before diving into inheritance
2. **Read error messages**: C++ compiler errors are verbose but informative
3. **Use const**: Learn const correctness early (methods and parameters)
4. **Avoid common pitfalls**:
   - Forget `virtual` destructors in base classes (leads to memory leaks)
   - Forgetting `operator=` and copy constructor (shallow copy issues)
   - Not using `new`/`delete` pairing (memory leaks)

### cub3D
1. **Understand raycasting first**: Study the algorithm before coding
2. **Start simple**: Get a basic room rendering before adding textures
3. **Debug with minimap** (bonus): See player position and ray paths
4. **Test map loading**: Verify your parser handles various map formats
5. **Profile performance**: Use tools to ensure smooth 60 FPS

### NetPractice
1. **Learn by doing**: Each level teaches concepts progressively
2. **Understand subnetting**: Master subnet calculation (most important concept)
3. **Think logically**: Each device needs a valid IP in correct subnet
4. **Use reference tools**: Subnet calculators help verify your work
5. **Don't guess**: Understand why each configuration works

---

## Advanced Topics

### CPP98 Smart Pointers (Manual)
Since C++98 doesn't have `std::unique_ptr`, you learn why it's needed:
```cpp
class Resource { /* ... */ };

// Manual memory management - error prone!
Resource *ptr = new Resource();
// ... if exception thrown, memory leaks!
delete ptr;

// What C++11+ gives you (smart pointers handle cleanup automatically)
```

### Raycasting Math
```cpp
// DDA (Digital Differential Analyzer) algorithm
// Ray: point + t * direction
// Find intersection with walls
// Calculate perpendicular distance
double perp_distance = distance * cos(ray_angle - player_angle);
int wall_height = SCREEN_HEIGHT / perp_distance;
```

### Network Addressing Formula
```
Network address = IP & Subnet Mask
Broadcast = Network + (2^(32 - CIDR)) - 1
Usable hosts: from Network + 1 to Broadcast - 1
```

---

## Resources

### CPP Learning
- C++ Reference: https://en.cppreference.com/ (even for C++98 concepts)
- "The C++ Programming Language" by Bjarne Stroustrup (author of C++)
- cplusplus.com: Tutorial and reference
- Scotts Meyers: "Effective C++" book series

### Raycasting & Graphics
- Game programming patterns
- Graphics programming introduction
- Ray-casting algorithm tutorials
- Wolfenstein 3D technical documentation

### Networking
- RFC 791 (IPv4 specification)
- RFC 1918 (Private IP addresses)
- Cisco Networking Academy materials
- TCP/IP networking fundamentals
- Subnet mask and CIDR notation guides

---

## Checklist for Completion

### CPP Modules
- [ ] Understand class definition and instantiation
- [ ] Constructors and destructors work correctly
- [ ] Copy constructor and assignment operator implemented
- [ ] No memory leaks in any program
- [ ] Inheritance and virtual functions work
- [ ] All exercises compile with -std=c++98
- [ ] Code follows 42 Norminette for C++ files

### cub3D
- [ ] Map file parsing works
- [ ] Raycasting renders walls
- [ ] Player movement (WASD) works without clipping
- [ ] Rotation (arrow keys) is smooth
- [ ] Textures load and display correctly per direction
- [ ] Floor and ceiling colors display
- [ ] Collision detection prevents walking through walls
- [ ] Window management (close, minimize, ESC)
- [ ] Bonus features (if implemented):
  - [ ] Minimap renders correctly
  - [ ] Mouse controls work
  - [ ] Door mechanism functions
  - [ ] Sprites/enemies render

### NetPractice
- [ ] All 10 levels completed
- [ ] Understand IP addressing and subnets
- [ ] Can calculate network ranges
- [ ] Routing configuration understood
- [ ] Gateway concept clear
- [ ] Can explain network topology

---

**Milestone 4 represents a major shift toward professional development. Master these skills and you're ready for real-world programming challenges.**

Good luck!
