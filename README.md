# Plasma Desktop Run Command

This is a simple plugin for KDE Plasma which allows running a custom command, by invoking a specified mouse action on the desktop area. To give you an example, such feature may be useful if you want to run third-party application launchers, or to quickly spawn Konsole with a single click, or to launch a custom script, etc.

## Screenshot

![](screenshot.png)

## Installation

### From source

First, to install required dependencies for your distro, run:

```
./helper.sh installBuildDependencies ubuntu|fedora|opensuse|arch
```

Then, to compile the plugin and install it in a single step, run: `./helper.sh install`

Note: To uninstall the plugin, run: `./helper.sh uninstall`

## Configuration

1. Open the Desktop Settings and the Mouse Actions tab
2. Click the Add Action button (it'll turn into the Input Here button)
3. Assign an action event by interacting with the button:
    - either press the right mouse button,
    - or press the mouse wheel button,
    - or scroll the mouse wheel up or down
4. Select Run Command from the list
5. Click a button to open the configuration dialog
6. Enter the command to be run when the event occurs
7. Click OK and then Apply in the parent configuration dialog

Note: As for the command, for a mouse wheel scroll action you can also use the `$SCROLL` variable, that has either "UP" or "DOWN" value, and which can be, for example, passed as an input argument for a script, so it can do something conditionally (change screen's brightness, or similar ideas).

## License

Copyright (C) 2020 wsdfhjxc

[GNU General Public License v3.0](LICENSE)
