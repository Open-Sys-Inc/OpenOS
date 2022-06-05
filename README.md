# OpenOS
Welcome to OpenOS the Operating System of the Future.

OpenOS is a 64 Bit operating system written in assembly and C++.

OpenOS is going to be a easy to use operating system for everyone.

* [Please see the License for more information](#license)

# OpenOS' Current State
 - [ ] GUI
 - [ ] Basic Input / Output
 - [ ] USB Support
 - [ ] Executables
 - [ ] Cursor
 - [X] German keyboard layout
 - [X] US Keyboard layout
 - [X] C++ Entry
 - [X] Bootloader

# How to build it yourself (Windows Only)
What you will need 
  - WSL

Open WSL and setup if needed then run these commands in order in wsl (enter password when needed)
To build OpenOS just run compile.cmd and open the bochs source file now youre runnning OpenOS in bochs.
##First Time installation
 - sudo apt update
 - sudo apt install build-essential
 - sudo apt install bison
 - sudo apt install flex
 - sudo apt install libgmp3-dev
 - sudo apt install libmpc-dev
 - sudo apt install libmpdr-dev
 - sudo apt install texinfo
 - export PREFIX="/usr/local/x86_64elf64gcc"
 - export TARGET="x86_64-elf"
 - export PATH="$PREFIX/bin:$PATH"
 - mkdir /tmp/src
 - cd /tmp/src
 - curl -O http://ftp.gnu.org/gnu/binutils/binutils-2.35.1.tar.gz
 - tar xf binutils-2.35.1.tar.gz
 - mkdir binutils-build
 - cd binutils-build
 - ../binutils-2.35.1/configure --target=$TARGET --enable-interwork --enable-multilib --disable-nls --disable-werror --prefix=$PREFIX 2>&1 | tee configure.log
 - sudo make all install 2>&1 | tee make.log
 - cd /tmp/src
 - curl -O https://ftp.gnu.org/gnu/gcc/gcc-10.2.0/gcc-10.2.0.tar.gz
 - tar xf gcc-10.2.0.tar.gz
 - mkdir gcc-build
 - cd gcc-build
 - ../gcc-10.2.0/configure --target=$TARGET --prefix=$PREFIX --disable-nls --disable-libssp --enable-language=c++ --without-headers
 - sudo make all-gcc

# License
OpenOS is a open source project for you to learn from, none of the code is allowed to be copied or reused for commercial purposes.
