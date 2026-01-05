INSTALL — cub3D

This short INSTALL document complements README.md with step-by-step commands and a WSL2 walkthrough for Windows.

1) Quick checklist (Linux)
- Install X11 dev packages
- Build MinilibX
- Install MinilibX headers/libs to /usr/local OR use a local install and pass INC_DIR/LIB_DIR to make

2) Commands to run on a fresh Linux laptop (copy/paste)

# Install prerequisites (Debian/Ubuntu)
sudo apt update
sudo apt install -y build-essential git libx11-dev libxext-dev libxrender-dev

# Get MinilibX and build
mkdir -p ~/src && cd ~/src
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux
make

# Install system-wide (requires sudo)
sudo cp mlx.h /usr/local/include/
sudo cp libmlx.a /usr/local/lib/
sudo ldconfig

# Build this project
cd ~/path/to/cub3d
make clean
make

# Run
./cub3d map.cub

3) No-sudo local install (if you can't run sudo)

# after building minilibx-linux
mkdir -p $HOME/local/include $HOME/local/lib
cp ~/src/minilibx-linux/mlx.h $HOME/local/include/
cp ~/src/minilibx-linux/libmlx.a $HOME/local/lib/

# build using the Makefile's variables
cd ~/path/to/cub3d
make clean
make INC_DIR=$HOME/local/include LIB_DIR=$HOME/local/lib

4) Windows (recommended: WSL2 + X server)

- Install WSL2 and an Ubuntu distro from Microsoft Store.
- Install an X server on Windows (VcXsrv recommended).
- Start VcXsrv (default settings are OK for local testing).

In WSL2 terminal:

# install dependencies
sudo apt update
sudo apt install -y build-essential git libx11-dev libxext-dev libxrender-dev

# build and install MinilibX (see Linux commands above)
# set DISPLAY so GUI apps can reach Windows X server
export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0
export LIBGL_ALWAYS_INDIRECT=1

# build project
cd ~/path/to/cub3d
make clean
make
./cub3d map.cub

Notes about screenshots
- I didn't embed screenshots in this file. If you want, I can add PNGs showing:
  - Where to add SSH keys in Gitea (if needed)
  - How to run VcXsrv on Windows
  - Expected `make` outputs on success

Troubleshooting
- "mlx.h: No such file or directory": ensure `mlx.h` is in an include path; use INC_DIR override if it is installed locally.
- "cannot find -lmlx" or "cannot find -lX11": install dev packages and ensure `libmlx.a` is in LIB_DIR; run `sudo ldconfig` if installed system-wide.
- On WSL2: if no window appears, ensure VcXsrv is running and `DISPLAY` is set correctly.

If you want, tell me which of the following to do next:
- Add screenshots to this file (I can create example images and add them),
- Patch `README.md` to reference this `INSTALL.md`, or
- Walk you through these commands interactively: paste any command output and I'll diagnose.