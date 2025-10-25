# Resident Evil - Code: Veronica X Decompile

<img src="https://i.imgur.com/3Fl2QNQ.png"/> 

## About

The purpose of this project is to reverse-engineer ***Resident Evil - Code: Veronica X*** in order to rebuild its codebase and allow for multiple different uses of it. More specifically, the PlayStation 2 version of the game released in North America (identifiable by its serial number, **SLUS-20184**) is being decompiled due to the presence of DWARF format debugging data in the PS2 executable, as well as the relative ease of reconstructing MIPS assembly back to the C language as opposed to other, more complex types of architectures. 

While function matching via the [decomp.me](https://decomp.me/preset/145) website is the preferred method of decompilation, the project does not compile an ELF binary that's identical bit for bit to the one found on the game disk. RE: CVX was developed with the MetroWerks CodeWarrior IDE, and MWCC does not feature an equivalent to GCC's INCLUDE_ASM functionality which renders the process of building a matching binary more difficult. Instead, the current build system produces an executable which only contains the code that has been decompiled so far, and the resulting ELF can be run on a repackaged DVD image of the game that is bootable on the PCSX2 emulator (and technically should also work on an actual PS2 console).

Additionally, this project also consists of reverse-engineering the CRI Middleware library that was employed by the developers to handle different aspects of the game such as audio and the AFS filesystem. There is also an on-going [decompilation of the Nintendo GameCube version](https://github.com/fmil95/recvx-gc-decomp), which does compile a matching binary so if you prefer that setup and have some knowledge of PowerPC and don't mind working with less debug info, feel free to contribute to that one instead. At some point, research will be done on the Dreamcast version as well. 

## Progress 

<img src="https://i.imgur.com/qiMejZz.png"/>

<!-- PROGRESS-START -->
```
Resident Evil CODE: Veronica X: 803 implemented functions / 3876 total (20.72%)
CRI ADX (March 13, 2001): 584 implemented functions / 653 total (89.43%)

Decomp progress: 1387 implemented functions / 4529 total (30.62%)
```
<!-- PROGRESS-END -->

## Build

The very first step should be to clone the repository: 
```
git clone --recursive https://github.com/fmil95/recvx-decomp.git
```

Once that is done, use the following command to build the executable if you're on Windows:
```
python compile.py
```

If you are on Linux, you have to run compile_wine.py instead.

## Credits

This work couldn't have been possible without the contributions of the following users:

* [Fairlightish](https://github.com/Fairlightish) and [WuGambinos](https://github.com/WuGambinos): Officially part of the RE: CVX decompilation team. 
* [benoitren](https://git.sr.ht/~benoitren): First to tag along when mentioning an interest to reverse-engineer the game in the PS1/PS2 Decompilation server. Decompiled several files on his own.
* [Mc-Muffin](https://github.com/Mc-Muffin): Created the splat config for the game binary, solved an important issue with the compiler, tested the build environment on WSL, developed the script for rebuilding the game ISO and provided the most help with matching the functions, in quality and quantity.   
* [karas84](https://github.com/karas84): Helped to match very important functions like PS2DrawOTagSub which involved complex logic for rendering graphics on the PS2, as well as many other ones.

Additionally, some appreciation must go to:

* [simonlindholm](https://github.com/simonlindholm): For his brilliant asm-differ, m2c and permuter tools.
* [Fothsid](https://github.com/Fothsid): For sharing his experience with reversing Resident Evil Outbreak.
* [apstygo](https://github.com/apstygo): For his CRI Middleware decompilation work on Street Fighter III: 3rd Strike. 
* [GirianSeed](https://github.com/GirianSeed): For providing knowledge of the many different versions of the PS2 API.
* [patope](https://github.com/patope), [Lovey847](https://github.com/Lovey847), [ladysilverberg](https://github.com/ladysilverberg) and [ThirstyWraith](https://github.com/ThirstyWraith): For giving additional help with function matching.

## Community

The primary way to discuss the project is through the `GC/Wii Decompilation` server on Discord, which has a dedicated channel for the decomp called `resident-evil-code-veronica-x`. See you there!

[![Join the Discord](https://dcbadge.limes.pink/api/server/https://discord.gg/hKx3FJJgrV)](https://discord.gg/https://discord.gg/hKx3FJJgrV)

## Resources

Associated decomp projects:
- [Resident Evil - Code: Veronica X (Nintendo GameCube)](https://github.com/fmil95/recvx-gc-decomp)
- Resident Evil - Code: Veronica X (Dreamcast) (no link - but maybe someday...) 
- [Legacy of Kain: Soul Reaver](https://github.com/fmil95/soul-re)
- [Fatal Frame](https://github.com/Mikompilation/Himuro)
- [Silent Hill](https://github.com/Vatuu/silent-hill-decomp)

## Disclaimer

This repository and the code therein, is made public on this site by fmil95 for preservational and educational purposes. I do not claim to hold any affiliation to the Resident Evil franchise, Capcom Co., Ltd or any other related party, nor mean to infringe upon the copyright of Resident Evil: Code: Veronica X.
