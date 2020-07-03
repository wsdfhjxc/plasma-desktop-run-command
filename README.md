# Plasma Desktop Run Command

This is a simple plugin for KDE Plasma which allows running a custom command, by invoking a specified mouse action on the desktop area. To give you an example, such feature may be useful if you want to run third-party application launchers, or if you want to quickly spawn Konsole with a mouse button click, etc.

## Screenshot

![](screenshot.png)

## Installation

### From source

In order to compile the plugin, you need to have CMake and Extra CMake Modules installed. The plugin depends on Qt and KF5 development libraries. For Kubuntu or KDE neon, the following packages are sufficient:

```
sudo apt install cmake extra-cmake-modules qtbase5-dev libkf5plasma-dev
```

For other distributions, find and install required packages by yourself.

To build the plugin, use the following commands:

```
mkdir build
cd build
cmake ..
make
```

Then, use `sudo make install` to install the plugin.

If you want to uninstall the plugin, use `sudo make uninstall`.
