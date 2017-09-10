# Part Minus One
(Jump to [ASSIGNMENT](#ASSIGNMENT) to skip the introduction material.)

# Table of Contents
[What is CAEN?](#CAEN)
* [Linux on CAEN](#LINUX_ON_CAEN)
* [Why is Linux on CAEN useful?](#WHY_USEFUL)
* [Why not use Linux for everything?](#WHY_NOT)
[The Actual Assignment](#ASSIGNMENT)
* [Note on CAEN's SSH URL](#URL_NOTE)
* [Step One: Install an SSH Client](#1)
    * [Chrome](#CHROME)
    * [Windows](#WINDOWS)
    * [macOS](#MAC_OS)
    * [Linux/Ubuntu](#LINUX)
* [Step Two: Choose a Text Editor](#2)
* [Step Three: Start the Project](#3)

# <a name="CAEN">What is CAEN?</a>
If you're in the College of Engineering, you have access to the
University's Computer Aided Engineering Network (CAEN, pronounced "Cain").

CAEN is comprised of several different components, ranging from access to
CAEN computers in university computer labs (and all of the eye-bogglingly
expensive CAD software that they contain) to an extra $40 of printing
allowance that you--as an engineering student--will inevitably never use
for anything except poster printing, whether that be for class
presentations or for making wall-sized prints of Dickbutt at the end of a
term.

The part that we're interested in is the **CAEN Linux Login Service.**

## <a name="LINUX_ON_CAEN">Linux on CAEN</a>

The CAEN Linux Login Service gives you _remote access to your CAEN Linux
account_ (i.e. what you log into when you boot a CAEN computer into Red Hat
Linux rather than Windows). You can do this with VNC ("VM-ing" into CAEN,
though that's not what that word technically means), or you can do it
through SSH.

This gives you access to your Linux home folder within a bash shell on your
computer from anywhere with an Internet connection. **tl;dr: It's like
opening a terminal window on a CAEN computer running Linux and controlling
that window remotely, from your own computer.**

### <a name="WHY_USEFUL">Why does that matter?</a>

You can do development work within that "terminal window" using
a command-line text editor (like nano or vim) and the g++ compiler--all of
which are pre-installed on CAEN--regardless of what operating system you
use from any computer with an Internet connection.

That means that you can do meaningful dev work even without a powerful
laptop. All of the actual computation will be done by the CAEN servers, not
your machine.

[You can even use CAEN from a Chromebook!](https://goo.gl/hJf5om)

### <a name="WHY_NOT">Then why not use CAEN Linux for everything?</a>

You aren't able to install new applications on CAEN without resorting to
[shenanigans](https://github.com/agiantwhale/caenhacks). That greatly
limits what you can do with CAEN.
* You can't (easily) install new dependencies for programming projects,
  e.g. you can't install Eigen3 or BulletPhysics, both of which are needed
  to compile the MAAV codebase.
* You can't (easily) install new applications to help you code more
  productively.

You can't install, for instance, the [neovim text
editor](https://github.com/agiantwhale/caenhacks), nor can you install
[mosh](https://mosh.org/).

CAEN Linux is really only usable for small and simple programming projects,
like projects for ENGR101, ENGR151, EECS183.I (yiliny) completed all of my
programming projects for ENGR151 by SSHing into CAEN and writing my files
in vim, but I stopped using it entirely when I took EECS280.

However, that's just fine for completing something like Project 0!

**If you're having trouble getting Ubuntu to work on your machine (on a
virtual machine or as a dual-boot installation), you may want to consider
using CAEN to complete Project 0. Alternatively, if you're just interested in
learning how to SSH into CAEN just for heck of it, you can try this too!**





# <a name="ASSIGNMENT">Assignment</a>

## <a name="URL_NOTE">Note on CAEN's SSH URL</a>
When I say to connect to:
    [your-uniqname]@login.engin.umich.edu

You should replace the entirety of `[your-uniqname]` with your uniqname,
_including_ the square brackets.

For instance, this is the address I use:
    yiliny@login.engin.umich.edu


## <a name="1">STEP ONE:</a> Get an SSH Client
You need an SSH client to access the CAEN servers.

Installing one isn't difficult. Depending on your operating system, you
have a variety of options.


### <a name="CHROME">ChromeOS (or the Chrome Web Browser)</a>
**Secure Shell**
[Link](https://goo.gl/hJf5om)

This is probably the easiest SSH client to install, by far, and it'll work
on all three major operating systems (Window, macOS, and Linux) just
because you're able to install Chrome on all three.

Just open the link in Chrome and click the `INSTALL` button.

To use, type this URL into the Chrome address bar and hit Enter:

    ssh://[your-uniqname]@login.engin.umich.edu

You'll have to authenticate using your student account password (the one
you use to sign into Wolverine Access).

**Note:** The `CTRL-BACKSPACE` keyboard shortcut won't work while you're
using SSH. The shortcut you use for "delete the previous word" is `CTRL-W`,
which you may recognize as the standard web browser shortcut for "close
current tab".

`CTRL-W` does work within Secure Shell, but to use it, you have to do the
following:
1. Go to `chrome://apps`
2. Right click on Secure Shell
3. Click on "Open as Window".
4. To launch Secure Shell, click on its icon on the `chrome://apps` page.

You'll have to set up a new connection manually. Enter a memorable name for
the connection, your username (i.e. your uniqname), and the hostname
(`login.engin.umich.edu`). You can leave the other fields blank.

**Remember that Secure Shell is a terminal interface, so clicking with the
mouse won't do anything. Switch between text boxes by pressing `TAB` (to go
forward) or `SHIFT-TAB` (to go backwards). "Click" buttons by pressing
`ENTER`).**

### <a name="WINDOWS">Windows</a>

**Windows Subsystem for Linux (WSL), a.k.a. Bash on Ubuntu on Windows**
[Link](https://goo.gl/d77ZC3)

Allows you to natively run Ubuntu 14.04 on a Windows 10 machine. Like SSH,
this only gives you access to a bash command-line interface (hence why it'll
show up on your machine as "Bash on Ubuntu on Windows").

Modern Ubuntu installations come with an SSH client preinstalled. After
setting up your WSL installation, connect to CAEN by executing:

    ssh [your-uniqname]@login.engin.umich.edu

from within Bash on Ubuntu on Windows.

**PuTTY**
[Link](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html)
[Alternate Link (Ubuntu's Documentation)](https://goo.gl/bcBTBw)

This is the SSH client that CAEN's documentation recommends using. It's
less annoying to install than WSL, but you have to change some settings to
get it to support colored text-highlighting.

### macOS
macOS is actually a Unix-based operating system. (You'll note that its
terminal uses the same command-line syntax as a terminal on Linux.) The
macOS terminal, like Ubuntu, comes with an SSH client pre-installed.

**macOS Terminal**
[Link](http://osxdaily.com/2017/04/28/howto-ssh-client-mac/)
[Alternate Link (Ubuntu's Documentation)](https://goo.gl/bcBTBw)

Connect to CAEN by opening a terminal window and executing:
    ssh [your-uniqname]@login.engin.umich.edu

### <a name="LINUX">Linux/Ubuntu</a>
Modern Ubuntu installations come with an SSH client preinstalled.

**Linux Terminal**
[Link (Ubuntu's Documentation)](https://goo.gl/bcBTBw)

Connect to CAEN by executing:

    ssh [your-uniqname]@login.engin.umich.edu

from within the Terminal, which you can open by pressing `CTRL-ALT-T`.

## <a name="2">STEP TWO:</a> Choose a Text Editor
There are a number of command-line text editors that you can use in a CAEN
SSH session. Here are some of the common ones (that are also already
installed on CAEN and therefore usable without shenanigans).

To open a file with one of these text editors, run:

    [NAME_OF_EDITOR] [PATH_TO_FILE]

### nano
[Wikipedia Link](https://en.wikipedia.org/wiki/GNU_nano)
[Usage Tutorial](https://goo.gl/orTXxd)

nano is arguably the most user-friendly text editor out of those listed
here. It provides a good starting point if you want to get up and running
as quickly as possible, though I would argue that you're better off using
vim or emacs (since both of those are powerful enough to become your
primary text editor for the rest of college and your career).

**nano comes preinstalled on Ubuntu 16.04 and is already installed on
CAEN.**

**Open a file with:** `nano path/to/file`

### vim
[Wikipedia Link](https://en.wikipedia.org/wiki/Vim_(text_editor))
[Basic Usage Tutorial](http://www.openvim.com/)
(Or run `vimtutor` from the terminal.)

vim is the most popular text editor out of those listed here. It has a
somewhat steep learning curve, but it is [extraordinarily
powerful](https://youtu.be/o6omymj1JZI?t=55s) once you figure out how to
use it.

You can install plugins to customize vim's existing functionality or add
new features altogether. Without even installing new plugins, you can
rebind almost all of vim's keymappings by editing your `~/.vimrc` file.
With plugins, vim can support [code
autocompletion](https://github.com/Valloric/YouCompleteMe), [syntax
checking](https://github.com/vim-syntastic/syntastic/), [Git
integration](https://github.com/tpope/vim-fugitive),
[and jumping directly to the definition of the function or class whose name
is under your cursor](https://youtu.be/4f3AENLrdYo?t=2m52s).

The vast majority of MAAV's software team uses vim.

**vim may not be installed on Ubuntu 16.04 by default. Install it with
`sudo apt install vim`.**

**vim is already installed on CAEN.**

**Open a file with:** `vim path/to/file`

### neovim
[GitHub Page](https://github.com/neovim/neovim)
[Usage Tutorial](http://www.openvim.com/)
(Or run `vimtutor` from the terminal.)

neovim is a fork of vim. It supports all of the same basic features,
keymappings, and plugins, with some internal refactoring and some new
features of its own. The most notable of these features are a built-in
terminal (so that you can view your code in one half of your screen and
compile it from the other, all from within neovim) and support for "remote
plugins", which are like vim plugins, except they're written in Python
rather than vimscript. When it was first released, one of neovim's selling
points over vim was built-in support for multithreaded ("asynchronous", or
"async") plugins that could run "in the background" without freezing the
terminal.

**neovim is not installed on Ubuntu 16.04 by default. Reference the GitHub
page for installation instructions.**

**You have to resort to shenanigans to get neovim installed on CAEN, so you
probably shouldn't try for now.**

**If you install it on your local machine, open a file with:**
		nvim path/to/file

You won't notice a major difference between neovim and vim when you first
start using them, but when you feel like switching over, you should
consider using:

**For Autocompletion**
YouCompleteMe is the most population autocompletion engine for vim, but it
was written before standard vim had async support. Because of this,
YouCompleteMe has its own "in-house" multithreading library that makes its
codebase huge (>30MB). These plugins use neovim's built-in async API.
* [nvim-completion-manager](https://github.com/roxma/nvim-completion-manager)
* [deoplete](https://github.com/Shougo/deoplete.nvim)

**For Syntax Checking**
* [neomake](https://github.com/neomake/neomake)

**For An IDE-Like Debugging Interface**
The installation process for this plugin can be finicky, just because LLDB
(one of the prerequisites for using it) often doesn't install correctly.
Contact `yiliny` if you want information on how to install this.
* [lldb.nvim](https://github.com/dbgx/lldb.nvim)

### emacs
[Wikipedia Page](https://en.wikipedia.org/wiki/Emacs)

No.


## <a name="3">Step Three: Start the Project</a>
Clone this project repo into a directory on your CAEN drive with:

		git clone https://github.com/maavumich/project0.git

And you're set!
