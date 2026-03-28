### System Dependencies (Linux/Ubuntu)

To build the libraries in the `deps/` folder from source, you must install the following development headers via `apt-get`.

- **General Build Tools**
  - `build-essential`
  - `cmake`
  - `git`

- **raylib & raygui**
  - `libasound2-dev`: Audio backend (ALSA).
  - `libx11-dev`: Core X11 windowing system.
  - `libxrandr-dev`: Monitor and resolution management.
  - `libxi-dev`: Input extension (touchscreens/tablets).
  - `libxcursor-dev`: Custom mouse cursor support.
  - `libxinerama-dev`: Multi-monitor support.
  - `libgl1-mesa-dev`: OpenGL driver headers.

- **SDL3**
  - `libwayland-dev`: Modern Linux display protocol support.
  - `libxkbcommon-dev`: Keyboard handling for Wayland/X11.
  - `libdbus-1-dev`: Communication with system services.
  - `libudev-dev`: Device hotplugging (detecting controllers/mice).
  - `libpulse-dev`: PulseAudio/Pipewire support (recommended for modern Linux).
  - `libx11-dev`
  - `libxss-dev`
  - `libxtst-dev`

---

### One-Line Install Command
You can install every dependency required for this project with the following command:

```bash
sudo apt-get update && sudo apt-get install -y \
    build-essential cmake git \
    libasound2-dev libx11-dev libxrandr-dev libxi-dev libxcursor-dev libxinerama-dev \
    libgl1-mesa-dev libwayland-dev libxkbcommon-dev libdbus-1-dev libudev-dev libpulse-dev
