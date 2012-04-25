#!/bin/bash

clear
echo 'Export PKG_CONFIG_PATH'
export PKG_CONFIG_PATH=/home/laurent/gtk_win32/lib/pkgconfig
echo 'Compilation....'

i586-mingw32msvc-gcc *.c -o $1.exe `pkg-config --cflags --libs gtk+-2.0` -lm

echo 'Finish !'
echo 'Launch !'

//wine $1.exe 
