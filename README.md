# todos

todos is my final project for the CS200 section of Johnson County Community
College's summer 2024 session.

## Author

Nolan Clark

## Toolchain

This project was built using [clang++](https://clang.llvm.org), as I use macOS
for development and this is the default C++ compiler included with Apple's
toolchain, but any C++ compiler that supports the C++11 standard should work.

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

### macOS

To install the compiler if you don't already have it, open Terminal and execute
the following command:

```sh
xcode-select --install
```

This will also install the `make` utility, allowing you to use the Makefile in
this repository for compilation.

### Linux

The usual C++ toolchain on Linux is the [GCC toolchain](https://gcc.gnu.org).
The method of installation will vary depending on which package manager your
distribution uses. In general, you'll need to install the package that provides
the `g++` command. If you'd like to use the Makefile included in this
repository to build the executable, you'll also need to install the package
that provides the `make` command, if it's not already installed.

A sample command for the latest Ubuntu LTS release could look like this:

```sh
sudo apt-get install g++ make
```
