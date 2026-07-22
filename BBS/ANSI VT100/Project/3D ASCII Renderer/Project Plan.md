# 3D ASCII Renderer - Development Project Plan

## Project Overview

A terminal-based 3D rendering engine that outputs wireframe and solid-mode graphics using ASCII characters. Leverages VT100 escape sequences for color, cursor positioning, and screen control to produce real-time 3D visuals in any compatible terminal.

---

## Goals and Objectives

- Render 3D wireframe and solid models using ASCII character sets
- Support perspective projection with configurable field of view
- Implement dynamic lighting with VT100 color attribute mapping
- Achieve interactive frame rates (15+ FPS) in standard terminals
- Provide a clean API for loading and displaying 3D model files

---

## Technical Requirements

### Core Dependencies
- Language: C or C++ (for performance and direct terminal control)
- Terminal: VT100-compatible emulator
- Build system: Make or CMake

### VT100 Features Used
- Cursor positioning: `ESC[row;colH`
- Color attributes: SGR codes (30-37 foreground, 40-47 background)
- Screen clearing: `ESC[2J`
- Bold/underline: `ESC[1m`, `ESC[4m`
- Double-width characters for aspect ratio correction

---

## Architecture

```
┌─────────────────────────────────────────┐
│            Application Layer            │
│   (Scene setup, camera control, UI)     │
├─────────────────────────────────────────┤
│           Rendering Pipeline            │
│  ┌───────────┬───────────┬───────────┐  │
│  │  Vertex   │ Rasterizer│  Color    │  │
│  │Transform  │  Engine   │ Mapper   │  │
│  └───────────┴───────────┴───────────┘  │
├─────────────────────────────────────────┤
│           Geometry Engine               │
│  (Mesh loading, transformations)        │
├─────────────────────────────────────────┤
│          Terminal Abstraction            │
│  (Escape sequences, frame buffer)       │
└─────────────────────────────────────────┘
```

---

## Development Phases

### Phase 1: Foundation (Weeks 1-2)
- [ ] Terminal abstraction layer (clear screen, cursor move, color set)
- [ ] Double-buffered frame buffer implementation
- [ ] Basic character set for shading (space, `.`, `:`, `o`, `O`, `#`, `@`)
- [ ] Simple 2D triangle rasterizer

### Phase 2: 3D Mathematics (Weeks 3-4)
- [ ] Vector and matrix math library
- [ ] Model-View-Projection matrix pipeline
- [ ] Perspective division and viewport mapping
- [ ] Camera system (position, rotation, FOV)

### Phase 3: Wireframe Rendering (Weeks 5-6)
- [ ] Line drawing with Bresenham's algorithm
- [ ] Load simple mesh formats (OBJ)
- [ ] Wireframe mode with depth-based brightness
- [ ] Rotation/translation controls (keyboard input)

### Phase 4: Solid Rendering (Weeks 7-9)
- [ ] Triangle fill algorithm
- [ ] Z-buffer implementation
- [ ] Flat shading with directional light
- [ ] Character-based intensity mapping

### Phase 5: Lighting and Color (Weeks 10-11)
- [ ] Gouraud shading interpolation
- [ ] Ambient, diffuse, specular lighting model
- [ ] VT100 color palette mapping (8 colors + brightness)
- [ ] Depth-based fog effect

### Phase 6: Polish and Features (Week 12)
- [ ] FPS counter and performance overlay
- [ ] Command-line argument parsing
- [ ] Multiple model loading
- [ ] Demo scenes and documentation

---

## ASCII Shading Character Map

```
Intensity:  0%   10%  25%  40%  55%  70%  85%  100%
Character:  ' '  '.'  ':'  '-'  '='  'o'  'O'  '@'
```

---

## Controls (Planned)

| Key     | Action                    |
|---------|---------------------------|
| W/A/S/D | Move camera forward/left/back/right |
| Q/E     | Strafe left/right         |
| Arrow keys | Rotate camera           |
| +/-     | Zoom in/out               |
| F       | Toggle wireframe/solid    |
| L       | Toggle lighting           |
| R       | Reset camera              |
| ESC     | Quit                      |

---

## Testing Strategy

- Unit tests for math library (vectors, matrices)
- Visual regression tests comparing rendered frames to reference output
- Performance benchmarks measuring frame time across terminal sizes
- Compatibility testing with major terminal emulators (xterm, putty, Windows Terminal)

---

## Success Criteria

- Renders a rotating 3D cube at 15+ FPS in 80x24 terminal
- Supports at least 500 triangle meshes
- Correct perspective projection and depth sorting
- Smooth color transitions using VT100 palette
- Clean exit with terminal state restoration
