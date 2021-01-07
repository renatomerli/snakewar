# SnakeWar game engine for AI

![](demo/demo.gif)

This project is not a human playable game and  aims to provide a platform for the development and evaluation of snake game solving algorithms.

The Snake game has become a popular case study of AI topics and this project provides an engine that validates and presents all games in the multiplayer environment, giving the student the possibility to focus only on the game resolution algorithm

It is a functional but beta version, working with the engine and "players" running in the same process

A simple "player" function is already provided for testing

To create a "player" code all you have to do is write your algorithm in a function that receives all the game data and returns with the game decision

## How to write a snake player

All it takes to create a "player" is to write a method with the following signature:

    Spin SnakeBase::play (cartesian _resolution, cartesian _target, std::list <SnakeBase *> snakes)

**_resolution** maintain the size of the board

**_target** holds the target (people use names like 'apple', 'gold', etc ... let's use the generic name 'target' for this)

**_list \<SnakeBase>** a list of snakes
(the snake itself is nothing more than a list of Cartesians representing its bdy)

**(Spin)** class in return is just a specialization of the class Direction that keeps the four possible Cartesian directions in an operable representation

Cartesian and direction was built to operate together, resulting that: Cartesian + direction = Cartesian target direction

## Architecture

As the problem suggests, the central architecture is based on cartesian and directional components, operated by classes called "Cartesian" and "Direction" in the source code. Those two components provide all the necessary resources to represent and operate all game data  
A Cartesian class maintains and operates a cartesian position and, of course, maintains two integers that represent that position  
The Direction class represents the "player" decision and operates over a Cartesian position  The change of direction is validated and there are operators to add (+), compare (==) and calculate the distance (%) between two given points  
In the development version there are no dynamic association (at runtime) between "players" and engine and the only graphic presentation available is in a text terminal operated through the ncurses library
