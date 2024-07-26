# todos

todos is my final project for the CS200 section of Johnson County Community
College's summer 2024 session.

## Author

Nolan Clark

## Features

- Intuitive prompt-based interface
- Color-coded output
- Automatic sorting of tasks based on priority and completion status
- Persistence of tasks in a text file

## Toolchain

This project was built using [clang++](https://clang.llvm.org), as I use macOS
for development and this is the default C++ compiler included with Apple's
toolchain, but any C++ compiler that supports the C++11 standard and the
`#pragma once` statement ([most do](https://en.wikipedia.org/wiki/Pragma_once))
should work.

### Windows

Windows offers a handful of different C++ toolchains. For simplicity's sake,
I'll focus on the Microsoft first-party offerings. To get started, you'll need
to download the
[Visual Studio installer](https://visualstudio.microsoft.com/downloads/). You
shouldn't need to install everything, but at least the "Desktop Development
With C++" toolset should be selected for installation. A more detailed overview
of the installation process is available on
[the Visual Studio Code site](https://code.visualstudio.com/docs/cpp/config-msvc#_prerequisites)
in step 3 of the "Prerequisites" section.

Additionally, if you'd like to use Git to retrieve the source code for this
project, you'll need to install
[Git for Windows](https://git-scm.com/download/win).

### macOS

To install the compiler if you don't already have it, open Terminal and execute
the following command:

```sh
xcode-select --install
```

This will also install the `git` and `make` utilities, allowing you to use Git
for getting the source code, and the Makefile in this repository for
compilation.

Optionally, if you'll be working with the source code, a simple Doxyfile has
been included to generate documentation. The simplest way I'm aware of to get
up and running with this is to install [Homebrew](https://brew.sh) on your Mac,
and install Doxygen with it:

```sh
brew install doxygen
```

### Linux

The usual C++ toolchain on Linux is the [GCC toolchain](https://gcc.gnu.org).
The method of installation will vary depending on which package manager your
distribution uses. In general, you'll need to install the package that provides
the `g++` command.

If you'll be using Git for fetching the source code, you'll need to install the
package that provides the `git` command too.

Generating documentation from comments in the source is supported, but requires
the `doxygen` command to be available, so if you're wanting to do this, you'll
need to install the package that provides that command.

Finally, if you'd like to use the Makefile included in this repository to build
the executable, you'll also need to install the package that provides the
`make` command, if it's not already installed.

A sample command to install the full development toolchain, including the
optional components, for the latest Ubuntu LTS release could look like this:

```sh
sudo apt-get install doxygen g++ git make
```

## Getting the source

The source files for this project are available in
[a GitHub repository](https://github.com/tweakdeveloper/todos). You can
download a ZIP file with the source code from the repository's web page, or use
the `git` command line tool:

```sh
git clone https://github.com/tweakdeveloper/todos.git todos
cd todos
```

## Generating source documentation

Documentation comments are included throughout the source code. These are
[Doxygen](https://doxygen.nl)-style comments.

### Windows

The documentation comments are automatically picked up by the Microsoft's
IntelliSense extensions in Visual Studio products, including Visual Studio
Code. Documentation can be viewed by hovering over the symbol in the editor.

Theoretically, a Windows version of Doxygen is available from the official
[Doxygen downloads page](https://doxygen.nl/download.html) that can be run to
generate standalone documentation, but I have not tested it and therefore
cannot vouch for its ability. Feel free to
[open an issue](https://github.com/tweakdeveloper/todos/issues/new) if you run
into any troubles with this and I'll take a look at it when I have time.

### macOS and Linux

To create standalone HTML documentation of the sources, a `docs` target is
available in the included Makefile:

```sh
make docs
```

Note that this assumes that the `doxygen` command is available in your `$PATH`.

The `make` utility will run Doxygen for you, producing web page documentation
in the `docs/html` subdirectory. This can be viewed by opening
`docs/html/index.html` in your preferred web browser.

## Building

Once you have the sources, the next step is to compile and run the program.

### macOS and Linux

For these UNIX-like environments, a Makefile is included to assist with
compilation. To compile, simply enter the source directory and run the `make`
utility:

```sh
make
```

You'll now have a binary, `todos`, in the source directory that can be executed
as follows:

```sh
./todos
```

Alternatively, if you just want to compile and run the program in one fell
swoop, you can use the `run` target provided in the Makefile:

```sh
make run
```
