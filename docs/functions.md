Functions
================================================================================

What is a function?
--------------------------------------------------------------------------------
A function is a self-contained block of code that does one specific task.
Functions have names (**identifiers**), parameters (values that it should
work with, which are usually called **arguments**), and a **return type**
(which is what the function "gives back" when it's finished running.) The
combination of these three things is called the function's **signature.**

Why are functions useful?
--------------------------------------------------------------------------------
Say you were trying to bake a cake.  there's a step where you fetch
ingredients, a step where you mix flour and water, a step where you crack
open eggs, a step where you stick something in an oven, and so on.

If you put _all_ of that in `main`, you would get a program that looks
something like:

    int main()
    {
        // get all the ingredients
        //  ...
        //  ...
        //  ...

        // turn on faucet
        // stick hands under water
        // put soap on hands
        // rub hands
        // stick hands under water
        // dry hands on towel
        // turn off faucet

        //  ...and so on.

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

No, you realize, you cleaned a kitchen by scrubbing it with your face.

_You were a fool._

Issues like this often occur when you duplicate your code. This is why one
of the points of emphasis in the MAAV style guide is to [Not Repeat
Yourself](https://en.wikipedia.org/wiki/Don%27t_repeat_yourself).

You only have one procedure for washing your hands. Just put it all in one
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

You just wrote a function!

What's the syntax for writing a function in C++?
--------------------------------------------------------------------------------

### Functions That Return Something

#### Returns a Primitive

	int integerDivide(int lhs, int rhs)
    {
        return lhs / rhs;
    }

    double divide(double lhs, double rhs)
    {
        return lhs / rhs;
    }

Note that **strings are weird** in C++. How to use them is usually an
entire lecture in a class like ENGR101/151 or EECS280. Technically, `char*`
is a "primitive" string type, while `std::string` is the (non-primitive)
type that you'll actually use most of the time.

### Functions That Return Nothing ("return type `void`")
`void` functions usually do one of

    void doSomething()

### Functions That Return References

### The `main` function

	int main(int argc, char* argv[])
	{

	}

Forward Declarations
--------------------------------------------------------------------------------
