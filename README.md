# Resident Evil - Code: Veronica X Decompile

<img src="https://i.imgur.com/3Fl2QNQ.png"/> 

## About

The purpose of this project is to reverse-engineer ***Resident Evil - Code: Veronica X*** in order to rebuild its codebase and allow for multiple different uses of it. More specifically, the PlayStation 2 version of the game released in North America (identifiable by its serial number, **SLUS-20184**) is being decompiled due to the presence of DWARF format debugging data in the PS2 executable, as well as the relative ease of reconstructing MIPS assembly back to the C language as opposed to other, more complex types of architectures. 

While function matching via the [decomp.me](https://decomp.me/preset/145) website is the preferred method of decompilation, the project does not compile an ELF binary that's identical bit for bit to the one found on the game disk. RE: CVX was developed with the MetroWerks CodeWarrior IDE, and MWCC does not feature an equivalent to GCC's INCLUDE_ASM functionality which renders the process of building a matching binary more difficult. Instead, the current build system produces an executable which only contains the code that has been decompiled so far, and the resulting ELF can be run on a repackaged DVD image of the game that is bootable on the PCSX2 emulator (and technically should also work on an actual PS2 console).

Additionally, this project also consists of reverse-engineering the CRI Middleware library that was employed by the developers to handle different aspects of the game such as audio and the AFS filesystem. There is also an on-going [decompilation of the Nintendo GameCube version](https://github.com/fmil95/recvx-gc-decomp), which does compile a matching binary so if you prefer that setup and have some knowledge of PowerPC and don't mind working with less debug info, feel free to contribute to that one instead. The [Dreamcast version is being decompiled](https://github.com/fmil95/recv-dc-decomp), too, but the tooling is fairly experimental and it can't build a matching executable yet. 

## Progress 

<img src="https://i.imgur.com/GlW9gJ7.png"/>

<!-- PROGRESS-START -->
```
Resident Evil CODE: Veronica X: 1130 implemented functions / 3834 total (29.47%)
CRI ADX (March 13, 2001): 661 implemented functions / 661 total (100%)
Tamsoft Sound Driver (EE): 34 implemented functions / 34 total (100%)

Decomp progress: 1825 implemented functions / 4529 total (40.3%)
```
<!-- PROGRESS-END -->

## Building

Requisites:
- Python
- Mips Binutils
- Wibo (if using Linux, for running Windows binaries)

The very first step should be to clone the repository: 
```
git clone --recursive https://github.com/fmil95/recvx-decomp.git
```

Next you have to place your copy of the SLUS_201.84 file in the config folder, and afterwards install splat with the following command: 
```
pip install -r config/requirements.txt
```

Once that is done, you can use the following command to setup objdiff:
```
python compile.py --setup
```

Or run this command to setup the ASM dump to create decomp.me scratches more easily:
```
python compile.py --split
```

Either command should run without errors and generate an `objdiff.json` project file or a `config/asm` folder respectively.

From now on to build the project you just need to type the following command:
```
python compile.py
```

If you're using Linux, an installation of wibo is needed in order to run the Windows-only MWCC binary, 
a small prompt with install steps will be shown if the script can't find wibo in your path.

With the main.elf from compilation, you can repackage RE: CVX's ISO file with it to see the decompiled code in action. You need to put your copy of the game's DVD on the elf/iso folder, and dump its contents with the following command:
```
python mkiso.py -m extract --iso elf/iso/RE_CVX.iso
```

Then rebuild the disk with:
```
python mkiso.py -m insert
```

If successful, you will now see an ISO called "RECVX_NEW" in the elf/iso folder that you can use to test the results with an emulator (preferrably PCSX2 for its debugging capabilities) or console.  

## Credits

This work couldn't have been possible without the contributions of the following users:

* [WuGambinos](https://github.com/WuGambinos) and [daru](https://github.com/davnpsh): Officially part of the RE: CVX decompilation team. 
* [benoitren](https://git.sr.ht/~benoitren): First to tag along when mentioning an interest to reverse-engineer the game in the PS1/PS2 Decompilation server. Decompiled several files on his own.
* [Mc-Muffin](https://github.com/Mc-Muffin): Created the splat config for the game binary, solved an important issue with the compiler, developed the script for rebuilding the game ISO and provided the most help with matching the functions, in quality and quantity.   
* [karas84](https://github.com/karas84): Helped to match very important functions like PS2DrawOTagSub which involved complex logic for rendering graphics on the PS2, as well as many other ones.

Additionally, some appreciation must go to:

* [simonlindholm](https://github.com/simonlindholm): For his brilliant asm-differ, m2c and permuter tools.
* [Fothsid](https://github.com/Fothsid): For sharing his experience with reversing Resident Evil Outbreak.
* [apstygo](https://github.com/apstygo): For his CRI Middleware decompilation work on Street Fighter III: 3rd Strike. 
* [GirianSeed](https://github.com/GirianSeed): For providing knowledge of the many different versions of the PS2 API, and finding extra debug info for CRI ADX not present in the game.
* [patope](https://github.com/patope), [Lovey847](https://github.com/Lovey847), [ladysilverberg](https://github.com/ladysilverberg) and [ThirstyWraith](https://github.com/ThirstyWraith): For giving additional help with function matching.

## Community

The primary way to discuss the project is through the `GC/Wii Decompilation` server on Discord, which has a dedicated channel for the decomp called `resident-evil-code-veronica-x`. See you there!

[![Join the Discord](https://dcbadge.limes.pink/api/server/https://discord.gg/hKx3FJJgrV)](https://discord.gg/https://discord.gg/hKx3FJJgrV)

## Resources

Associated decomp projects:
- [Resident Evil - Code: Veronica X (Nintendo GameCube)](https://github.com/fmil95/recvx-gc-decomp)
- [Resident Evil - Code: Veronica (Dreamcast)](https://github.com/fmil95/recv-dc-decomp)
- [Legacy of Kain: Soul Reaver](https://github.com/fmil95/soul-re)
- [Fatal Frame](https://github.com/Mikompilation/Himuro)
- [Silent Hill](https://github.com/Vatuu/silent-hill-decomp)

## Disclaimer

This repository and the code therein, is made public on this site by fmil95 for preservational and educational purposes. I do not claim to hold any affiliation to the Resident Evil franchise, Capcom Co., Ltd or any other related party, nor mean to infringe upon the copyright of Resident Evil: Code: Veronica X.
