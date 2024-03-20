# csnake
🐍 A bad implementation of the snake game in C & SDL2

## Building

### Dependencies
The single dependency is **SDL2** which you have to have installed on your system to be picked up by the **CMake** during compilation. So you will need CMake as well. Some **C compiler** also will be useful.

#### Arch install guide

```sh
sudo pacman -S --needed base-devel cmake sdl2
```

#### Ubuntu / Debian install guide

```sh
sudo apt-get install build-essentials cmake libsdl2-dev
```

### Compilation

```sh
mkdir build && cd build
cmake ..
make -j$(nproc)
```

### Running

Start the `csnake` executable from the `build` folder defined before.
