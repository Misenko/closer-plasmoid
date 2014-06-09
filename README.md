closer-plasmoid
===============

KDE plasmoid that closes all applications on current desktop.

## Build instructions

```bash
cd /where/your/applet/is/installed
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=$KDEDIRS .. 
make 
make install
```
(your $KDEDIRS is where you install your KDE 4)

Restart plasma to load the applet
```bash
kquitapp plasma-desktop
plasma-desktop
```
You might need to run *kbuildsycoca4*
in order to get the .desktop file recognized.