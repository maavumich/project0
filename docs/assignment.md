Project Specification
================================================================================
This project is meant to teach you C++. You will be given a series of
exercises to demonstrate your understanding of the material. These
excercises will be due on Wednesday, October 4th, 2017, after the meeting.

Completing the Project
================================================================================
Project 0 is split into multiple parts, each covering a different set of
topics.

We intend for you to complete these parts in sequence, as they each build
on material covered in the parts before.

Introduction
-------------------------------------------------------------------------------
This project will be use a combination of instructional materials written
by MAAV members and preexisting instructional materials that can be found
online.

MAAV's documentation for this project can be found
[here](https://goo.gl/e7jazg) and inside this folder (`./docs`).

If you want a more detailed reference, a more in-depth tutorial can be
found [here](www.cplusplus.com/doc/tutorial/).

Part -2 (OPTIONAL) - Develop on CAEN
--------------------------------------------------------------------------------
The University's CAEN servers provide a "ready-to-use-(ish)" development
environment, making it easy to get up and running with C++. This is
optional, since you can also set up a C++ development environment on your
local machine.

### What is CAEN?
It's a way to give yourself easy access to a Linux terminal environment
without having to go through the trouble of getting Linux working on your
machine.

It's not practical to do this for "heavy" programming projects, but it's
more than sufficient for something small like Project 0.

See `./caen_and_cli_editors.md` for more details. **This is optional; you
don't need to do this to complete this project.**


Part -1 - Figure Out How to Terminal
--------------------------------------------------------------------------------
The Linux command line, or **terminal**, is an essential tool for a C++
developer. It's similar to the Windows Command Prompt, but it has some added
features that make it extremely useful while doing software development.

However, like the Windows Command Prompt, there are situations when the
terminal is the only thing that you have access to. Running code on our
quadcopter requires connecting to it wirelessly through SSH, and doing that
drops you into a purely text-based command-line interface. Learning how to
do things using a CLI (i.e. mastering [command line
bullshittery](http://www.pgbovine.net/command-line-bullshittery.htm)) is
one of the essential skills that you _need_ to understand to do development
work in Linux.

Because the terminal is a Command Line Interface (CLI) and not a Graphical
User Interface (GUI), you may find it difficult to use if you haven't had
experience with CLI's in the past.

See the Linux terminal cheat sheet [here](https://goo.gl/p3Voyh).


Part 0 - Hello, World!
--------------------------------------------------------------------------------
Traditionally, when students are learning a programming language, the first
project they create is called "Hello, world!"

The only thing "Hello, world!" does is print the string `Hello, world!` to
the terminal. If you're still working through kinks in your development
environment, this is the best time to work those out.

See the "Hello, World" slide from our C++ material slides
[here](https://goo.gl/jqVWck).

Write your implementation in `exercise0.cpp`.


Part 1 - Basic C++ Syntax
--------------------------------------------------------------------------------
Part 1 is meant to teach the very basics of C++ syntax, such as structure
of a program, variables and types, constants, operators, and basic I/O
(input and output)

First, you should go to "Part 1 C++ Basics" on the slides. Read through the
slides, run the example code, then complete the solution to exercise1.

### Exercise 1:
Write a program that converts Fahrenheit to Celsius. It should accept the
temperature in Fahrenheit as input using `std::cin`, and output the
temperature in Celsius to the terminal.

Write your implementation in `exercise1.cpp`.


Part 2 - Selection (`if`, `else`) and Iteration (loops)
--------------------------------------------------------------------------------
Read the slides covering Part 2: Selection and Iteration, then complete the exercise.

### Exercise 2:
Write a guessing game program.  The game will ask the player to guess a
number between 1-20 using cin. The random number can be generated using the
information found [here](http://www.cplusplus.com/reference/cstdlib/rand/).
Give feedback based on the guess. If the number was too high output "Too
High", if number was too low output "Too Low." If number was correct output
"You win" then exit the program. Give the player an infinite number of
guesses at first, then give the player a finite number of guesses.

Write your implementation in `exercise2.cpp`.

*Extra Challenge:*
Make a dynamic number of guesses using `rand` and modulus.


Part 3 - Vectors (lists) and Strings
--------------------------------------------------------------------------------
Read the slides covering Part 3: Selection and Iteration, then complete the
exercise.

### Exercise 3:
Create a program that can print out a vector. A vector is defined for you
in exercise3.cpp.

Write your implementation in `exercise3.cpp`.


Part 4 - Functions
--------------------------------------------------------------------------------
Read the slides covering Part 4: Functions, then complete the exercise.

### Exercise 4:
*Part 1:* In Exercise 3 you created a program that could print a vector.
Move your code from Exercise 3 into a function.

*Part 2:* Write a sorting algorithm. Your task is to sort a vector of words
alphabetically. Given the list {banana, pear, apple} your program should
output {apple, banana, pear}.

Write your implementation in `exercise4.cpp`.


Part 5 - Header Files and the Compilation Process
--------------------------------------------------------------------------------
Though this is technically an EECS280 topic, it's used in almost every file
in MAAV's codebase, so understanding how it works is crucial. Thankfully,
it's actually pretty simple.

Your code for "Hello, World!" and "Basic C++ Syntax" was written entirely
inside of `.cpp` files, which is the standard file extension for a
C-Plus-Plus source file. Header files are C++ files with the extension
`.hpp` (or `.h`, but `.hpp` is preferred) that are `#include`d at the top
of `.cpp` files or `.hpp` files.

`.cpp` files are for _implementations,_ i.e. the "nitty-gritty" details of
how your code really works. `.hpp` files, on the other hand, are for
_documentation_ (i.e. "high-level" explanations of what your code does)
and _declarations_ (function headers, class and struct definitions, and so
on). You can think of header files as "outlines" of what your code should
be.

### Exercise 5:
See `./header_files_and_compilation.md` for more details.

Write your implementation in `exercise5-0.hpp`, `exercise5-0.cpp`,
`exercise5-1.hpp`, and your code in `exercise4.cpp`.
