Project Specification
================================================================================

Completing the Project
================================================================================
Project 0 is split into multiple parts, each covering a different set of
topics.

We intend for you to complete these parts in sequence, as they each build
on material covered in the parts before.


Part -1 (OPTIONAL, BUT SUGGESTED) - Develop on CAEN
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

See `./part_minus_one.md` for more details.

Note that Part -1 overlaps _heavily_ with Part -0.5, since you'll be using
CAEN through a text-only command-line interface.. We suggest that you
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


Part -0.5 - Figure Out How to Terminal
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

See `./part_minus_point_five.md` for more details.

Part 0 - Hello, World!
--------------------------------------------------------------------------------
Traditionally, when students are learning a programming language, the first
project they create is called "Hello, world!"

The only thing "Hello, world!" does is print the string `Hello, world!` to
the terminal. If you're still working through kinks in your development
environment, this is the best time to work those out.

See `./part_zero.md` for more details.

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

See `./part_one.md`. for more details.

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

See `./part_two.md`. for more details.

Part 3 - Functions (a.k.a Methods)
--------------------------------------------------------------------------------
Up until now, you've been writing all of your code in a `main` method.
You've probably noticed that this function swiftly becomes bloated.

Writing all of your code inside `main` is fast and easy when solving small
problems, but when you're solving larger problems, there are just too many
_things_ that `main` needs to do. You wind up lumping together several
different "chunks" of code, all of which do different and largely unrelated
things. The more complex the problem, the more cumbersome and awkward
`main` becomes.

A better approach would be to take the problem that you're trying to solve
and break it down into small "chunks". Say you were trying to bake a cake:
there's a step where you fetch ingredients, a step where you mix flour and
water, a step where you crack open eggs, a step where you stick something
in an oven, and so on.

If you put _all_ of that in `main`, you would get a program that looks
something like:
		int main()
		{
			// get all the ingredients
			//	...
			//	...
			//	...

			// turn on faucet
			// stick hands under water
			// put soap on hands
			// rub hands
			// stick hands under water
			// dry hands on towel
			// turn off faucet

			//	...and so on.

This is clunky and inelegant. Notice that the second "chunk" of code
describes the process of washing your hands; that's something that you'd do
multiple times as you prepare food.
			// ...
			// pour egg yolks and egg whites into bowl
			// need to clean uncooked egg off of hands

			// turn on faucet
			// stick hands under water....

Every time you wanted to wash your hands in this process, you'd have to
copy-paste that chunk of code.

That's inefficient and wasteful. More than that, that sort of **code
duplication** makes it much easier to introduces bugs into your code.

Let's say that your hand-drying towels were stolen by gremlins, and you had
to dry your hand some other way. Because cooking is hard and you want your
cake _now_, you decide to dry your hands on your face.

You open your text editor's find-replace tool and replace every instance of
"towel" with "my face".
			// turn on faucet
			// stick hands under water
			// put soap on hands
			// rub hands
			// stick hands under water
			// dry hands on **my face**
			// turn off faucet

Huzzah! That works as intended! But, wait, what about this code?
			// ...
			// as cake cooks, clean up mess in kitchen
			// wipe up spilled cooking ingredients with **towel**

Wait! _Noooooo!_
			// wipe up spilled cooking ingredients with **my face**

We wrote a program that successfully bakes a cake, but not the kind of cake
we wanted. Not a chocolate cake, a red velvet cake, a moist and delicious
cake smelling of sweet-cooked bread and tasting like the mirth of your
fifth birthday party. No, this cake tastes like sadness. Like ten years' mistakes
distilled into a clear liquor, a crystal glass filled with regret. You
throw back the shot. You eat the cake. It burns on its way down.

How did this happen, you ask yourself. You were so happy, so capable, so
full of promise. Did you squander that promise, channeling your energies into
the pursuit of the basest pleasures? Watching your peers move on, their
silhouettes fading into the rose-red glow of the evening, of adulthood,
wisdom, maturity, peace? That could have been you, you think, swirling the
last drops around the glass. The heat from your hand seeps into the glass,
into the drink. The drops shrink, vaporize.

Was that my mistake--you think, letting the glass drop to the
table--lethargy, sloth, a lack of ambition?

No, you realize, you cleaned a kitchen by scrubbing it with our face.

_You were a fool._

Issues like this often occur when you duplicate your code. This is why one
of the points of emphasis in the MAAV style guide is to [Not Repeat
Yourself.](https://en.wikipedia.org/wiki/Don%27t_repeat_yourself).

You only have one procedure for washing your hands. Put it all in one
place, maybe add some parameters (which sink do you use? are you just
rinsing, or are your washing properly?), then slap a name of in
(`washHands`) and call it a day.
		void washHands(Location sink_loc, WashMethod method)
		{
			moveTo(sink_loc);
			// turn on faucet
			// stick hands under water
			if (method == "wash_properly")
			{
				// put soap on hands
				// rub hands
				// stick hands under water
			}
			// dry hands on towel
			// turn off faucet
		}

You just wrote a function.
