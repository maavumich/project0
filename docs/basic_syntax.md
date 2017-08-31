Part 1 - Basic C++ Syntax
================================================================================
**TODO**
* C++ syntax
	* Meaningful-versus-non-meaningful whitespace
	* Semicolons
	* Variables and variable scopes

Variables
--------------------------------------------------------------------------------

### Instantiation/Declaration

	int foo;

### Initialization

	int foo;
	foo = 5;

	int bar{5};

### Operator Assignment (lvalues and rvalues)

**only give a very, very basic explanation of what an lvalue or rvalue is**

### "Direct Construction" (Curly-Brace Initialization)

### The `new` Keyword And Why You Shouldn't Be Using It Just Now
**This is especially important if you're used to programming in Java, e.g.
from taking AP Computer Science A.**

For now, don't do this:

	AClass instance = new AClass{}; // syntax error

This will produce a syntax error because constructing an object with the
`new` keyword doesn't return the object itself. Instead, it returns a
pointer to the object.

If you fix the syntax error, you'll have this:

	AClass* instance = new AClass{};

Where `instance` is a pointer to a dynamically-allocated object that will
persist until it's `delete`d. If you never `delete` it, you have a memory
leak on your hands.

**Dynamic memory is a somewhat complicated topic that won't be covered
until Project 3.** It's one of the things that makes C++ difficult for
inexperienced programmers to learn. The Michigan computer science core
sequence teaches it midway through EECS280, which is normally a second-year
course.

(Note that even when you're using Java, the `new` keyword still
dynamically allocates memory for the object you're constructing.
`delete`ing the object when it's no longer being used is handled by Java's
garbage collector, which isn't something that C++ does.)

Variable Scope
--------------------------------------------------------------------------------

**basically, you can have curly braces inside of a function and any
variables that you statically-declared inside the curly braces will get
destroyed when you leave the scope**


Meaningful vs. Non-Meaningful Whitespace
--------------------------------------------------------------------------------

**the difference between C++ and Python**


Indenting With Tabs vs. Indenting With Spaces
--------------------------------------------------------------------------------



C++ Primitive Types
--------------------------------------------------------------------------------
A non-exhaustive list of primitive types follows:
* `char`
	* 1 byte unsigned integer type (range: [0, 255])
	* Can be used for math; ordinarily represents an ASCII character (`'a'`, `'Z'` etc.)
	* Printing (to, e.g. `std::cout`) prints ASCII character, not numerical
	  value
* ([`unsigned`]\*) `int`
	* 32-bit (4-byte) integer
	* 2^32 possible values
* ([`unsigned`]\*) `long`
	* 64-bit (
* ([`unsigned`]\*) `long long`
* `float`
* `double`

"unsigned" means that the number literally does not have a sign (i.e. a
`+` or `-`) in front of it. Unsigned integer types have a minimum value of
zero (rather than, say, -1 * 2^32 = `-2147483648`, which is the minimum
possible value of a standard 32-bit `int`).

    unsigned int i1 = 0;
    i1 = i1 - 1;
    std::cout << i1 << std::endl;   // prints 2^32, or `4294967295`, **not** `-1`

    unsigned int i2 = 4294967295;   // maximum value of an unsigned integer
    i2 = i2 + 1;
    std::cout << i2 << std::endl;   // prints `0`

    int i3 = 2147483647;            // maximum value of a signed integer
    i3 = i3 + 1;
    std::cout << i3 << std::endl;   // prints -2147483648

Be warned that **technically, the C++ standard doesn't specify exact sizes
(in bytes) for most of these types.** For many, it only sets minimums (i.e.
this type must be at least this many bytes, etc.) If you're in a situation
where you _need_ a variable to occupy a certain amount of space in memory,
you should use [these](http://en.cppreference.com/w/cpp/types/integer).

Integer vs. Conventional Division
--------------------------------------------------------------------------------


References and Constant References
--------------------------------------------------------------------------------


Pointers
--------------------------------------------------------------------------------


