For UNIX (Linux/MacOS):
    run ``make unix``
    It should create a executable called "Pong" which you can open with ``./Pong``
    (You may need to make it executable first with this command: ``chmod +x Pong``
    To clean: ``make clean``

For web:
    Install* enscripten and source the envirnomental paths:
    ``git clone https://github.com/emscripten-core/emsdk.git``
    ``cd emsdk``
    ``./emsdk install latest``
    ``./emsdk activate latest``
    ``source ./emsdk_env.sh`` <- Note: you have to source this every time you open a new terminal in order to build the game.
    Now you have to enter the game folder with the Makefile.
    For me it's ~/Pong-game/RayLib/Lightweigh
    When you are here, you run ``make web``. This takes longer than normal build.
    It will spit out .wasm executable and a .html document.
    You do NOT doubleclick the .html document.
    To play the game in your browser over local network:
        Make sure python is installed and run the provided script.
        ``bash launchgameweb.sh {Your desired port here}``
        If you are unsure what to use as port, write this exact command:
        ``bash launchgameweb.sh 8080``
        Open the URL provided. (In modern shells you hold ctrl and press the URL.)
        From there a file manager will appear, you want to click the .html file.
        The game should now be accesible to any computer on your local network with the URL you made.
        To run the game later, just run the script with port again and open the URL in browser.

* - Emscripten from APT is outdated and will not work, you have to use the github release.

# Alternatively you can use a hosted version provided by my friend:

https://nmac.me/meow/pong/
