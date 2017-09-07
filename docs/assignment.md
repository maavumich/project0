Project Specification
================================================================================

Completing the Project
================================================================================
Project 0 is split into multiple parts, each covering a different set of
topics.

We intend for you to complete these parts in sequence, as they each build
on material covered in the parts before.


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

See `./terminal.md` for more details.

Intro to projects
-------------------------------------------------------------------------------
This project will be using the material located at [c++.com] (www.cplusplus.com/doc/tutorial/) to
teach you c++. You will be given a series of exercises to demonstrate your understanding of the
material. These excercises will be due on Wednesday October 4th, 2017 after the meeting.

Part 0 - Hello, World!
--------------------------------------------------------------------------------
Traditionally, when students are learning a programming language, the first
project they create is called "Hello, world!"

The only thing "Hello, world!" does is print the string `Hello, world!` to the terminal. If you're still working through kinks in your development environment, this is the best time to work those out.

See `./hello_world.md` for more details.

Write your implementation in exercise0.cpp. 

Part 1 - Basic C++ Syntax
--------------------------------------------------------------------------------
Part 1 is meant to teach the very basics of C++ syntax, such as structure of a program, variables and types, constants, operators, and basic I/O (input and output)

First, you should go to [c++.com] (www.cplusplus.com/doc/tutorial/), read the sections
under "Basics of C++" and attempt to use them yourself and then complete the solution
to exercise1.

### Exercise 1:
Write a program that converts farenheit to celsius. It should accept the temperature in farenheit
as input into the program using std::cin, and output the temperature in celcius to the
terminal. 

Write your implementation in exercise1.cpp.

Part 2 - Selection (if, else) and Iteration (loops)
--------------------------------------------------------------------------------
Read the material at [c++.com/control] (www.cplusplus.com/doc/tutorial/control). Focus on
selection statements, For Loops, and While Loops. You won't be tested on range-based for
loops, do-while, or switch statments.

### Exercise 2:
Write a guessing game program.  The game will ask the player to guess a number between 1-20 using
cin. The random number can be generated using the information found [Here](www.cplusplus.com/reference/cstlib/rand/).
Give feedback based on the guess. If the number was too high output "Too High", if number was
too low output "Too Low." If number was correct output "You win" then exit the program. Give the
player an infinite number of guesses at first, then give the player a finite number of guesses. 

Write your implementation in exercise2.cpp.

*Extra Challenge:*
Make a dynamic number of guesses using rand and modulus.

Part 3 - Functions (a.k.a Methods)
--------------------------------------------------------------------------------
Read the material at [c++.com/function] (www.cplusplus.com/doc/tutorial/functions). Do not read
"recursivity."  Passing in by reference vs. value is very important, so we have supplementary
material found [here](). NEED LINK TO NECKARDTS SLIDE ON TOPIC 

### Exercise 3:


Write your implementation in exercise3.cpp.

Part 4 - Vectors (lists) and Strings
--------------------------------------------------------------------------------
Need to link to @necktards slides.

### Exercise 4:
Write a sorting algorithm. Your task is to sort a vector of words alphabetically. Given the list 
{banana, pear, apple} your program should output {apple, banana, pear}.

Write your implementation in exercise4.cpp.

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

See `./header_files_and_compilation.md` for more details.

Part 5 (OPTIONAL) - Classes and Structs
--------------------------------------------------------------------------------


Part 6 (OPTIONAL, BUT SUGGESTED) - Coding Style
--------------------------------------------------------------------------------

