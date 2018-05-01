
Debian
====================
This directory contains files used to package testd/test-qt
for Debian-based Linux systems. If you compile testd/test-qt yourself, there are some useful files here.

## test: URI support ##


test-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install test-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your testqt binary to `/usr/bin`
and the `../../share/pixmaps/test128.png` to `/usr/share/pixmaps`

test-qt.protocol (KDE)

