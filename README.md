# todos

todos is my final project for the CS200 section of Johnson County Community
College's summer 2024 session.

## Author

Nolan Clark

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

### Linux

The usual C++ toolchain on Linux is the [GCC toolchain](https://gcc.gnu.org).
The method of installation will vary depending on which package manager your
distribution uses. In general, you'll need to install the package that provides
the `g++` command. If you'll be using Git for fetching the source code, you'll
need to install the package that provides the `git` command too. Finally, if
you'd like to use the Makefile included in this repository to build the
executable, you'll also need to install the package that provides the `make`
command, if it's not already installed.

A sample command for the latest Ubuntu LTS release could look like this:

```sh
sudo apt-get install g++ git make
```

## Getting the source

The source files for this project are available in
[a GitHub repository](https://github.com/tweakdeveloper/todos). You can
download a ZIP file with the source code from the repository's web page, or use
the `git` command line tool:

```sh
git clone https://github.com/tweakdeveloper/todos.git todos
```

## Building

Once you have the sources, the next step is to compile and run the program.

### macOS and Linux

For these UNIX-like environments, a Makefile is included to assist with
compilation. To compile, simply enter the source directory and run the `make`
utility:

```sh
cd todos
make
```

You'll now have a binary, `todos`, in the source directory.
