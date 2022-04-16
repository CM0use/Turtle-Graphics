<!--
*** If you like this README,
*** it is available as a template in my repositories,
*** here is the link:
*** https://github.com/CM0use/README-TEMPLATE
-->

<h1 align="center">
  <br>Turtle Graphics<br>
  <a href="https://shields.io/"><img src="https://img.shields.io/badge/Windows-0078d7?style=for-the-badge&logo=windows&logoColor=ffffff" alt="Windows"></a>
  <a href="https://shields.io/"><img src="https://img.shields.io/badge/mac%20OS-313131?style=for-the-badge&logo=macos&logoColor=d7d7d7" alt="macOS"></a>
  <a href="https://shields.io/"><img src="https://img.shields.io/badge/Linux-ffffff?style=for-the-badge&logo=linux&logoColor=000000" alt="Linux"></a>
  <br><a href="https://github.com/CM0use/Turtle-Graphics/blob/main/LICENSE"><img src="https://img.shields.io/badge/License-BSL_1.0-4a6484?style=for-the-badge" alt="License BSL-1.0"></a>
</h1>

<h4 align="center">Use the turtle as a cursor to draw on the map.</h4>

<p align="center">
  <a href="#features">Features</a> •
  <a href="#requirements">Requirements</a> •
  <a href="#install--run">Install & Run</a> •
  <a href="#uninstall">Uninstall</a> •
  <a href="#contributing">Contributing</a> •
  <a href="#contact-with-me">Contact with me</a> •
  <a href="#license">License</a>
</p>

<div align="center">



</div>

## Features

* If you want to make the map smaller or bigger you can do it by changing the value of the MAX_COLUMNS and MAX_ROWS constants to the value you want, these constants are in the header/turtle.h file.
* You can also change the appearance of the turtle and what it is drawing.
* No installation necessary - just use the binary.
* Easy to modify.
* Multi-Platform
  - Windows, macOS and Linux.

## Requirements

* gcc
* git (optional)

## Install & Run

To **clone** and **compile** this game, you will need to have **git** and **gcc** installed on your computer.<br>
From your command line:

```bash

git clone https://github.com/CM0use/Turtle-Graphics.git
cd Turtle-Graphics
gcc -O2 -std=c2x src/main.c src/turtle.c -o turtleGraphics

```

Run on **macOS & Linux**:

```bash

./turtleGraphics

```

Run on **Windows**:

```cmd

turtleGraphics.exe

```

## Uninstall

Just delete the folder you have cloned/downloaded from the repository.

## Contributing

**Any contribution you make will be greatly appreciated.**<br>
If you have any ideas/suggestions to improve the repository, please make a fork of the repository and create a pull request.<br>
You can also <a href="https://github.com/CM0use/Turtle-Graphics/issues">open the issue tracker</a> to report any improvements or bugs.<br>
**Don't forget to give a star to the repository, Thanks!.**

## Contact with me

**Feel free to <a href="mailto:dilanuzcs@gmail.com">contact with me</a> for any project** (preferably C/C++).

**As a courtesy** (but not required), please <a href="mailto:dilanuzcs@gmail.com">send me an email</a> if you use this repository (or part of this repository) outside of github (or inside github). **I'd really appreciate it. Thanks again!.**

## License

**Distributed under the Boost Software License, Version 1.0.**<br>
See accompanying file <a href="https://github.com/CM0use/Turtle-Graphics/blob/main/LICENSE">LICENSE.txt</a><br>
or copy at https://www.boost.org/LICENSE_1_0.txt