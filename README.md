# SFML bouncing shapes

Small example for familiarizing with the [SFML library](www.sfml-dev.org/)

## Learning objectives

* familiarize with the [CircleShape](https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1CircleShape.php) and [RectangleShape](https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RectangleShape.php) classes

* practice with classes
* practice with building software from multiple files
* learn about make and Makefile
* practice good coding practices

## What should the software do?

The software should do the following:

* collect information from configuration file
* draw shapes based on input from configuration file
* shapes should move according to information from configuration file
* shapes should bounc off the edges of the window

## Build and running instructions

### On Linux

Requires make and the sfml library (dev version to be installed).

Install SFML library (on Ubuntu):

`sudo apt-get install libsfml-dev`

Make is usually installed by default.

Clone the github repository:

`git clone <repo_URL>`

Open the terminal and move to the root folder.

You have to manually build the debug and release version.

Make sure you run `make clean` if you are switching between building `debug` and `release`.

#### Release

From the root folder run:

`make`

#### Debug

From the root folder run:

`make debug`

## Running instructions

Make sure you are in the `bin` folder. If you are not in the right folder, loading the font will not work. No font = no fun.

Depending on your build:

1. `./SFMLGame` for running release
2. `./SFMLGame_debug` for running debug

Enjoy! :D
