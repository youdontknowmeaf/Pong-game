#!/bin/bash

sed -i '/^Exec=/d' Pong.desktop

EXEPATH="$(pwd)/Pong"
INSTALLPATH="$HOME/.local/share/applications"
EXEC="Exec=$EXEPATH"

printf "Installing Pong to:\n$INSTALLPATH"
printf "Executable:\n$EXEPATH\n"

echo  "$EXEC" >> Pong.desktop
cp Pong.desktop $INSTALLPATH/Pong.desktop

echo "Done."
