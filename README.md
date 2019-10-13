# Cheeseburger-Man

This is a game designed to be goofy.  It's a "mad libs" type game for
Windows, Linux, and the C64; it also has a JavaScript port, so it works
on Macs, mobile devices and other systems I don't know how to code for
yet. :)

The main code base is written in C, and uses a little library I wrote
called "Terminator".  Terminator is a cross-platform terminal library
for things like changing colors, clearing the screen, and probably more
stuff down the road (it will eventually have its own Git repo).  The web
port will also be hosted on my website, but I wanted to make sure the
source code was available for that too.

# Contents

In this folder is another folder labeled "bin" and also the source code:

* "build.sh" (a Bash script I wrote for Linux and the C64)
* "Terminator.h" (the terminal library described above)
* "main.c" (the code for the game itself)
* An icon I'm using on my website and on the web port
* README.md (you are here :))
* "main.o" (partially compiled object file for the C64 port; I've never
    actually looked at it, but it's there if you want to).

In the "bin" folder are the compiled binaries and web port:

* "cheeseburger-man.prg" (C64)
* "cheeseburger-man.exe" (Windows)
* "cheeseburger-man" (Linux)
* "web" (source code for the web port)
