# LoomEngine

A modular C++20 game engine I'm building in my free time, with a separate editor and runtime.

![Status](https://img.shields.io/badge/status-early%20development-orange)
![C++20](https://img.shields.io/badge/C%2B%2B-20-blue)
![CMake](https://img.shields.io/badge/build-CMake-informational)
![License](https://img.shields.io/badge/license-MIT-green)

> **Early development.** The project is just getting started. Right now it is mostly the foundations. Build system, module layout and core utilities. There is nothing to run yet beyond the sandbox.

---

## Why a second engine

My first engine, [ArtFX Game Engine](https://github.com/IjulienI/ArtFX_GameEngine), taught me how physics, rendering and gameplay code fit together. It also showed me what happens when an engine grows without a clear structure. A single Visual Studio project, modules depending on each other freely, and no tooling to see what the code is actually doing.

LoomEngine is a fresh start with those lessons in mind. The focus is on getting the foundations right before adding features. Clear module boundaries, a reproducible build, and profiling from day one.

## Architecture

The engine is split into modules, each built as its own CMake target:

| Module | Role |
|---|---|
| `Core` | Base types, memory, logging, smart pointers. Depends on nothing else in the engine |
| `Platform` | Abstraction over the OS: window, input, file system |
| `Engine` | The engine itself, built on top of Core and Platform |
| `Runtime` | Entry point for shipped games |
| `Editor` | Entry point for the editor, optional |
| `Sandbox` | Test project used during development |

Dependencies only go one way, from the top of the stack down to `Core`, which keeps each layer testable and replaceable.

### Build configurations

Inspired by Unreal's build setup, the engine has three configurations:

| Configuration | Purpose |
|---|---|
| `Debug` | No optimizations, full debug info |
| `Development` | Optimized with debug info, the default when working |
| `Shipping` | Fully optimized, editor excluded |

### Profiling

[Tracy](https://github.com/wolfpld/tracy) is integrated in `Core`, including memory allocation tracking, so performance and memory usage can be inspected from the very first features.

## Building

**Requirements:** CMake 4.3+, Ninja, and a C++20 compiler (MSVC, Clang or GCC).

```
git clone https://github.com/IjulienI/LoomEngine.git
cd LoomEngine
cmake --preset development
cmake --build --preset development
```

Use the `debug` or `shipping` presets for the other configurations. Dependencies are downloaded automatically by CMake on the first configure.

## Roadmap

- [x] Modular CMake structure with Debug / Development / Shipping configurations
- [x] Third-party dependencies fetched automatically
- [x] Tracy integration with memory tracking
- [ ] Logging system
- [ ] Platform layer: window and input on SDL3
- [ ] Main loop and engine lifecycle
- [ ] First renderer

## Dependencies

- [SDL3](https://github.com/libsdl-org/SDL): windowing and input
- [GLM](https://github.com/g-truc/glm): math
- [spdlog](https://github.com/gabime/spdlog): logging
- [Tracy](https://github.com/wolfpld/tracy): profiling

## License

MIT. See [`LICENSE`](LICENSE).
