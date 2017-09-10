Header Files and Compilation
================================================================================
The reason why `.hpp` and `.cpp` files are separate requires a good deal of
explanation that you'll find in a later project, but it's still helpful to
know how they work, even when you're just starting out.

For reasons we'll discuss in a later project, it's helpful to have function
prototypes (and other such "scaffolding") defined in so-called **header
files**. Header files are text files (whose extensions are, by convention,
`.h` or `.hpp`) populated with scaffolding that are `#include`d inside of
`.cpp` files.

What Does It Mean to `#include` a File?
--------------------------------------------------------------------------------
The statement `#include {TEXT_FILE}` tells your compiler to replace the
`#include` statement with the full, copy-pasted contents of `{TEXT_FILE}`.

To see this in action:
1. Look at the code in `exercise5-0.hpp` and `exercise5-0.cpp`.
2. _Pre-process_ `exercise5-0.cpp` with this terminal command:
   `g++ -E exercise5-0.cpp -o exercise5-0_preprocessed.cpp`

Then open `exercise5-0_preprocessed.cpp` in a text editor. This file is
called a **translation unit**, which we'll explain in more detail in a
later project.

Practice Declaring Function Prototypes
--------------------------------------------------------------------------------
Take the function prototypes from `exercise4.cpp` and move them into
`exercise5-1.hpp`, then `#include` them at the top of `exercise4.cpp`.

Compile `exercise4.cpp` with the following terminal command...

	g++ -E exercise4.cpp -o exercise4_preprocessed.cpp

...and also this terminal command:

	g++ exercise4.cpp -o exercise4.out

Open `exercise4_preprocessed.cpp` with a text editor. What do you think
will happen when you try running `./exercise4.out`? Is it any different
from what `exercise4` did originally?
