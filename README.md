# Plasma Desktop Run Command

This is a simple plugin for KDE Plasma which allows running a custom command, by invoking a specified mouse action on the desktop area. To give you an example, such feature may be useful if you want to run third-party application launchers, or to quickly spawn Konsole with a single click, or to launch a script on the mouse wheel scroll event, etc.

## Screenshot

![](screenshot.png)

## Installation

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

## Configuration

The configuration of Plasma's desktop module plugins is a little bit weird.

1. Open the Desktop Settings and the Mouse Actions tab
2. Click the Add Action button, so it turns into the Input Here button
3. Keep the mouse cursor over the button and assign an action event:
    - Press the right mouse button,
    - or press the mouse wheel button,
    - or scroll the mouse wheel in any direction
4. Select Run Command from the list
5. Click a button to open the configuration dialog
6. Enter the command to be run when the event occurs
    - If this is a mouse wheel scroll event, you can use the `$SCROLL` variable, \
      that has either "UP" or "DOWN" value, and which can be passed as an argument for a script, \
      so it can do something conditionally, e.g.: `sh /home/user/screen_brightness.sh $SCROLL`
7. Click OK and then Apply in the parent configuration dialog

You can also change the assigned action event for an already existing entry, but it'll reset the command, so you'll have to enter it once again. That's in case you are wondering why the plugin stops working after changing the action event.
