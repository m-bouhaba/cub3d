# cub3D — Build & Install Guide

This guide explains how to prepare a machine to build and run this cub3D project. The project depends on MinilibX (libmlx) and X11 on Linux. On Windows the recommended path is to use WSL2 to get a Linux environment.

## Quick summary
- Linux (native): install X11 dev packages, build MinilibX, install headers/libs to `/usr/local`, then run `make`.
- Windows: use WSL2 + an X server (VcXsrv or Xming) and follow the Linux steps inside WSL2. Native Windows builds require alternate toolchains/ports and are more complicated.

---

## A. Linux (Debian / Ubuntu example)

1. Install system dependencies

```bash
sudo apt update
sudo apt install -y build-essential git libx11-dev libxext-dev libxrender-dev
```

2. Clone & build MinilibX (common Linux fork)

```bash
# create a place for third-party sources
mkdir -p ~/src && cd ~/src
# clone a MinilibX for Linux (choose a fork appropriate for your school/environment)
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux
make
```

3. Install MinilibX system-wide (so your Makefile finds it)

```bash
sudo cp mlx.h /usr/local/include/
sudo cp libmlx.a /usr/local/lib/
sudo ldconfig
```

4. Build this project

From the project root:

```bash
make clean
make
```

If your `Makefile` uses configurable variables (INC_DIR / LIB_DIR), you can also build without sudo by installing to a local folder and pointing `make` to it (see next section).


### Local (no-sudo) install option

If you don't want or can't install to `/usr/local`, install MinilibX to a local directory and instruct the build to use it:

```bash
# after building in minilibx-linux
mkdir -p $HOME/local/include $HOME/local/lib
cp ~/src/minilibx-linux/mlx.h $HOME/local/include/
cp ~/src/minilibx-linux/libmlx.a $HOME/local/lib/

# build the project using custom include/lib locations
make clean
make INC_DIR=$HOME/local/include LIB_DIR=$HOME/local/lib
```

If your `Makefile` doesn't read `INC_DIR`/`LIB_DIR`, either edit the Makefile to add these variables or pass compiler/linker flags directly (CFLAGS/LDFLAGS).


### Troubleshooting (Linux)
- "mlx.h: No such file or directory": add `-I/usr/local/include` (or your include dir) to compiler flags.
- "cannot find -lmlx" or "cannot find -lX11": install X11 dev libs (see step 1) and ensure `libmlx.a` is in a linker search path (`/usr/local/lib`) or pass `-L` explicitly.
- After system install: run `sudo ldconfig` to refresh the linker cache.


---

## B. Windows

Native Windows builds for MinilibX are not well standardized and often problematic. The recommended approach is to use WSL2 (Windows Subsystem for Linux) and an X server. This effectively gives you a Linux environment on Windows and is the simplest way to run this project.

### Option 1 (recommended): WSL2 + X server

1. Install WSL2 (follow Microsoft docs) and set up an Ubuntu distro from the Microsoft Store.
2. Inside WSL2, follow the Linux instructions above (install packages, clone + build MinilibX, etc.).
3. On Windows host, install an X server such as VcXsrv or Xming and start it.
4. In WSL2, set your DISPLAY environment variable so programs connect to the Windows X server. Example (PowerShell + VcXsrv default):

```powershell
# On Windows (PowerShell) start VcXsrv (via its installer/shortcut)
# In WSL2 (bash):
export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0
export LIBGL_ALWAYS_INDIRECT=1
# then run your program from WSL2
./cub3d map.cub
```

Notes:
- If you have trouble with visuals, try disabling firewall or allowing VcXsrv through the Windows firewall for private networks.
- WSLg (on newer Windows builds) includes integrated GUI support and may not require a separate X server.

### Option 2: MSYS2 / MinGW native (advanced)

There are MSYS2 / MinGW ports of MinilibX or other windowing alternatives, but they are more involved and vary by fork. If you need a native Windows build, expect to:
- Install MSYS2, install `mingw-w64` toolchain and X11 libs if available
- Find a MinilibX fork for Windows (if your school provides one)
- Adjust Makefile to use the mingw toolchain and link against native libraries

This route is fragile and depends on which MinilibX variant the project expects. For most developers, WSL2 is quicker.


---

## C. Makefile suggestions (portable)

To make the project easier to build on different machines, consider these Makefile improvements:

- Add configurable `INC_DIR` and `LIB_DIR` variables with sensible defaults:

```makefile
INC_DIR ?= /usr/local/include
LIB_DIR ?= /usr/local/lib
CFLAGS ?= -Wall -Wextra -I$(INC_DIR)
LDFLAGS ?= -L$(LIB_DIR) -lmlx -lX11 -lXext -lm -lpthread -ldl
```

- Use `$(CFLAGS)` at compile time and `$(LDFLAGS)` at link time. This lets you run:

```bash
make INC_DIR=$HOME/local/include LIB_DIR=$HOME/local/lib
```


---

## D. Build & run the project

```bash
# from project root
make clean
make
# if build succeeds
./cub3d map.cub
```

If you used local install paths:

```bash
make INC_DIR=$HOME/local/include LIB_DIR=$HOME/local/lib
./cub3d map.cub
```


## E. If something goes wrong

When you hit an error, copy the exact compiler or linker messages and paste them here. Common helpful diagnostics:
- `gcc` / `cc` compile output
- `ls -l /usr/local/include/mlx.h` and `ls -l /usr/local/lib/libmlx.a`
- If using local install: `echo $INC_DIR $LIB_DIR` and the `make` command you ran

---

If you want, I can:
- Patch your `Makefile` now to add `INC_DIR`/`LIB_DIR` and use `CFLAGS`/`LDFLAGS` so building on another machine is simpler, or
- Add a short `INSTALL.md` with screenshots/extra Windows WSL2 tips.

Which would you like next?