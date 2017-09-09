Project Specification
================================================================================

Completing the Project
================================================================================
Project 0 is split into multiple parts, each covering a different set of
topics.

We intend for you to complete these parts in sequence, as they each build
on material covered in the parts before.


Part -2 (OPTIONAL, BUT SUGGESTED) - Develop on CAEN
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

See `./caen_and_cli_editors.md` for more details.

Note that Part -2 overlaps _heavily_ with Part -1, since you'll be using
CAEN through a text-only command-line interface. We suggest that you
work through them "side by side", rather than completing them in strictly
sequential order.

### CAEN Access for LSA Students
If you're an LSA student who has declared computer science as their major,
CAEN treats you as if you're an engineering student and grants you all of
the amenities of a CoE user (including the bonus printing allowance!).

In general, however, students in the College of LSA do not receive CAEN
access by default. To use CAEN, you have to [request CAEN
access](https://caen.engin.umich.edu/accounts/eligibility/).

You may be able to obtain limited access as a "non-engineering member of a
student design team." Talk to a team lead if you're interested in doing
that.


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

Part 0 - Hello, World!
--------------------------------------------------------------------------------
Traditionally, when students are learning a programming language, the first
project they create is called "Hello, world!"

The only thing "Hello, world!" does is print the string `Hello, world!` to
the terminal. If you're still working through kinks in your development
environment, this is the best time to work those out.

See `./hello_world.md` for more details.

Write your implementation in exercise0.cpp.

Part 1 - Basic C++ Syntax
--------------------------------------------------------------------------------
Oftentimes, when somebody tries to teach you a skill that's entirely new to
you, they'll struggle a bit because you make small, "simple" mistakes.
These are mistakes that your teacher made when they learned that skill for
the first time, but it's been so long since you're teacher was a novice
that they've forgotten that those hurdles exist.

Part 1 is meant to teach the very basics of C++ syntax, and some of the
common mistakes that people make when they're first trying to program in
the language.

See `./basic_syntax.md`. for more details.

Part 2 - Selection and Iteration
--------------------------------------------------------------------------------
One of the properties of a conventional programming language is called
**sequential execution.** What that means is that, when you write a
program, the lines of code in that program will (generally speaking) be
executed in order, line-by-line.

You can still do useful things with this--the dependency installation bash
scripts that you'll see in the navigation repository are "plain" scripts
that run through from start to finish--but it greatly limits how complex
your programs can be.

This is where selection and iteration come in handy.

### What Are Selection and Iteration?
**Selection** is just ["if-then-else"
statements](https://en.wikipedia.org/wiki/Control_flow#Choice). If this
condition is true, do this; if that's not true, but this other condition
_is_ true, then do this; if none of those conditions are true, then do
this, and so on.

See `./selection.md` for more details.

**Iteration** is the formal term for
[loops.](https://en.wikipedia.org/wiki/Control_flow#Loops) Loops are useful
when you have a particular piece of code that you want to execute over and
over again.

The kinds of loops that you'll use most often while working with C++ are:
* `for` loops
	* `range-for` loops (sometimes called "auto" for loops)
* `while` loops

See `./iteration.md` for more details.

### Your Assignment
We've written out some short exercises for you that require the use of
selection and iteration. These are tasks like finding the maximum value
within a list of numbers and writing an algorithm for integer division,
among other things.

See `./selection_and_iteration.md`. for more details.

Part 3 - Functions (a.k.a Methods)
--------------------------------------------------------------------------------
Up until now, you've been writing all of your code in a `main` method.
You've probably noticed that this swiftly becomes bloated.

Writing all of your code inside `main` is fast and easy when solving small
problems, but when you're solving larger problems, there are just too many
_things_ that `main` needs to do. You wind up lumping together several
different "chunks" of code, all of which do different and largely unrelated
things. The more complex the problem, the more cumbersome and awkward
`main` becomes.

A better approach would be to take the problem that you're trying to solve
and break it down into small procedural "chunks". These chunks can then be
converted into **functions**, which group the actions performed in those
chunk togther.

Almost all major programming and scripting languages implement functions
in some way, and C++ is no exception. Using functions makes your code
easier to read, easier to maintain, easier to debug, and easier to use.
You'll write implementations for functions in this part.

See `./functions.md` for more details.

Part 4 - Header Files and the Compilation Process
--------------------------------------------------------------------------------
Though this is technically an EECS280 topic, it's used in almost every file
in MAAV's codebase, so understanding how this works is crucial. Thankfully,
header files aren't very complicated.

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

