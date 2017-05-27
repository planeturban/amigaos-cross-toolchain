AmigaOS cross compiler for Linux / Windows
===

THIS IS A FORK OF https://github.com/cahirwpz/amigaos-cross-toolchain - great thanks to [Krystian Bacławski](mailto:krystian.baclawski@gmail.com) - but do not bother him with the changes made here! 

### What's different here?

 * Main focus is getting gcc 6 to work,
 * for AmigaOS with Motorola CPUs.
 * I am testing with Windows Cygwin 32 bit, Ubuntu 32/64 bit and CentOs 64 bit.
 * current version is quite usable.


**Contributor:** [Stefan "Bebbo" Franke](mailto:bebbo@bejy.net)

**Donations?** <a href="https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=YRRBRLCKDU3H6">
<img src="https://www.paypalobjects.com/de_DE/DE/i/btn/btn_donate_LG.gif" border="0" alt="Donate with PayPal.">
</a>


### Overview

**this fork of amigaos-cross-toolchain** project provides an easy way to build AmigaOS 3.x (m68k) target toolchain in a Unix-like environment.

Build process should produce following set of tools for **m68k-amigaos** target:

 * gcc 6 (recent version vom gcc-6-branch) **[default]**
 * binutils 2.14 (assembler, linker, etc.) - patched to work with gcc6 **[default]**
 * libnix 2.2 (standard ANSI/C library replacement for AmigaOS)
 * libm 5.4 (provides math library implementation for non-FPU Amigas)
 * AmigaOS headers & libraries & autodocs (for AmigaOS 3.9)

... also yet present is:

 * binutils 2.9.1 (assembler, linker, etc.)
 * vbcc toolchain (most recent release) including vasm, vlink and C standard library
 * IRA: portable M68000/010/020/030/040 reassembler for AmigaOS hunk-format
   executables, libraries, devices and raw binary files
 * vda68k: portable M68k disassembler for 68000-68060, 68851, 68881, 68882

... and following set of tools for **ppc-amigaos** target:

 * gcc 4.2.4
 * g++ 4.2.4
 * binutils 2.18 (assembler, linker, etc.)
 * newlib
 * clib 2.2
 * AmigaOS headers & libraries & autodocs (for AmigaOS 4.1)

**Note:** *Patches are welcome!*

### Commits
I am using funny symbols in my commits:

 * @B : this is a bug fix
 * @S : <submodule(s)> look into the submodule(s) [Maybe more text]
 * @R : redesign or change which affects other files (e.g. changing a header)
 * @I : internal redesign
 * @D : debugging related changes
 * @C : comments added / remove / changed
 * @S : see submodule
 * @T : test related
 * @V : version stuff


### Downloads

There is one download available now:

  [amiga-toolchain-centos.tgz](http://franke.ms/download/amiga-toolchain-centos.tgz) - built for /opt/amiga (mandatory path!)
  

### Documentation

Documentation from Free Software Fundation:

 * [gcc 2.95.3](http://gcc.gnu.org/onlinedocs/gcc-2.95.3/gcc.html)
 * [binutils](http://sourceware.org/binutils/docs/)

Texinfo documents from GeekGadgets converted into HTML:

 * [libnix - a static library for GCC on the amiga](http://cahirwpz.users.sourceforge.net/libnix/index.html)
 * [AmigaOS-only features of GCC](http://cahirwpz.users.sourceforge.net/gcc-amigaos/index.html)

AmigaOS specific documents:

 * [Amiga Developer Docs](http://amigadev.elowar.com)

### Compiling

*Firstly… you should have basic understanding of Unix console environment, really* ;-)

#### Prerequisites

You have to have following packages installed in your system:

 * GNU gcc 5.x **32-bit version!** or Clang
 * Python 2.7.x
 * libncurses-dev
 * python-dev 2.7
 * GNU make 4.x
 * perl 5.22
 * git
 * GNU patch
 * GNU gperf
 * GNU bison

*For MacOSX users*: you'll likely need to have [MacPorts](http://www.macports.org) or [Homebrew](http://brew.sh) installed in order to build the toolchain.

##### Windows 10 64-bit with Cygwin 32bit.

Install cygwin via setup.exe and add wget. Then open cygwin shell and:

    wget https://raw.githubusercontent.com/transcode-open/apt-cyg/master/apt-cyg
    install apt-cyg /bin
    apt-cyg install gcc-core gcc-g++ python git perl-Pod-Simple gperf patch automake make makedepend bison flex libncurses-devel python-devel gettext-devel libgmp-devel libmpc-devel libmpfr-devel

##### Ubuntu 16.04 LTS 32-bit (gcc 5.4.0)
   
    sudo apt-get install git gcc g++ python-dev gperf patch automake make bison libncurses-dev gettext libgmp-dev libmpc-dev libmpfr-dev
    git clone https://github.com/bebbo/amigaos-cross-toolchain

#### How to build?

**Warning:** *Building with `sudo` is not recommended. I'm not responsible for any damage to your system.*

Follow steps listed below:

1. Fetch *amigaos-cross-toolchain* project to your local drive:  

    git clone git://github.com/bebbo/amigaos-cross-toolchain.git
    cd amigaos-cross-toolchain

2. Run `toolchain-m68k` or `toolchain-ppc` script (with `--prefix` option to specify where to install the toolchain). Note, that the destination directory must be writable by the user. 

    ./toolchain-m68k --prefix=/opt/m68k-amigaos build

I also suggest to use the option **--threads <n>** to speedup your build.

3. Restart on error and wait for the results :-)

4. *(optional)* Install additional SDKs (e.g. AHI, CyberGraphX, Magic User Interface, etc.):

    ./toolchain-m68k --prefix=/opt/m68k-amigaos install-sdk ahi cgx mui

#### What if something goes wrong?

If the build process fails, please write me an e-mail.  I'll try to help out. Don't forget to put into e-mail as much data about your environment as possible! 
It's **vitally important** to send me a full log from build process. You can capture it by redirecting output to a file with following command:

    ./toolchain-m68k build 2>&1 | tee build.log

... but remember to cleanup your build environment beforehand with:

    rm -rf .build-m68k
    rm -rf /opt/m68k-amigaos
