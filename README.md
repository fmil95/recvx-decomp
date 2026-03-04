# Resident Evil - Code: Veronica X Decompile

[![Build Status]][actions] [![Code Progress]][progress] [![Data Progress]][progress] 

[Build Status]: https://github.com/fmil95/recvx-decomp/actions/workflows/progress.yml/badge.svg
[actions]: https://github.com/fmil95/recvx-decomp/actions/workflows/progres.yml

[Code Progress]: https://decomp.dev/fmil95/recvx-decomp.svg?mode=shield&label=Code&measure=matched_code_percent
[Data Progress]: https://decomp.dev/fmil95/recvx-decomp.svg?mode=shield&label=Functions&measure=matched_functions
[progress]: https://decomp.dev/fmil95/recvx-decomp

<img src="https://i.imgur.com/3Fl2QNQ.png"/> 

## About

The purpose of this project is to reverse-engineer ***Resident Evil - Code: Veronica X*** in order to rebuild its codebase and allow for multiple different uses of it. More specifically, the PlayStation 2 version of the game released in North America (identifiable by its serial number, **SLUS-20184**) is being decompiled due to the presence of DWARF format debugging data in the PS2 executable, as well as the relative ease of reconstructing MIPS assembly back to the C language as opposed to other, more complex types of architectures. 

While function matching via the [decomp.me](https://decomp.me/preset/145) website is the preferred method of decompilation, the project does not compile an ELF binary that's identical bit for bit to the one found on the game disk. RE: CVX was developed with the MetroWerks CodeWarrior IDE, and MWCC¹ does not feature an equivalent to GCC's INCLUDE_ASM functionality which renders the process of building a matching binary less flexible. Instead, the current build system produces an executable which only contains the code that has been decompiled so far, and the resulting ELF can be run on a repackaged DVD image of the game that is bootable on the PCSX2 emulator (and technically should also work on an actual PS2 console).

Additionally, this project also consists of reverse-engineering the CRI Middleware library that was employed by the developers to handle different aspects of the game such as audio and the AFS filesystem. There is also an on-going [decompilation of the Nintendo GameCube version](https://github.com/fmil95/recvx-gc-decomp), which does compile a matching binary so if you prefer that setup and have some knowledge of PowerPC and don't mind working with less debug info, feel free to contribute to that one instead. The [Dreamcast version is being decompiled](https://github.com/fmil95/recv-dc-decomp), too, but even though it can build a matching executable, the tools for decompiling DC need to be expanded upon greatly.

*¹ This version of MWCCPS2 also seems to have an issue where unreferenced functions affect code-gen throughout the compile unit, see this [decomp.me scratch](https://decomp.me/scratch/NIx9k) for an example. MWLDPS2 removes all functions with no references during linktime and while some can be recovered from the Dreamcast version, files that are only present on PS2 have all that unused code erased beyond recovery.*

## Building

The very first step should be to clone the repository: 
```
git clone --recursive https://github.com/fmil95/recvx-decomp.git
```

Next you have to place your copy of the SLUS_201.84 file in the config folder. The setup now depends on whether you want to use a dev container or not.

### With Dev Container

If you're using an IDE that supports [dev containers](https://containers.dev/), such as Visual Studio Code, you can simply open the repository with as a dev container. 

You will need to have [Docker](https://www.docker.com/) or [Podman](https://podman.io/) installed and running on your machine to open a dev container.

### Without Dev Container

Requisites:
- Python
- MIPS Binutils
- wibo (if using Linux, for running Windows binaries)

Install splat with the following command: 
```
pip install -r config/requirements.txt
```

---

**Follow these instructions after entering the dev container or installing the requisites:**

Use the following command to setup objdiff:
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
* [Mc-Muffin](https://github.com/Mc-Muffin): Created the splat config for the game binary, solved an important issue with the compiler, developed the script for rebuilding the game ISO and provided the most help with matching the functions, in quality and quantity. Also implemented objdiff for local diffing and progress report generation.  
* [karas84](https://github.com/karas84): Helped to match very difficult functions like PS2DrawOTagSub which involved complex logic for rendering graphics on the PS2, as well as many other ones like Ps2TextureGarbageCollectionAll.

Additionally, some appreciation must go to:

* [simonlindholm](https://github.com/simonlindholm): For his brilliant asm-differ, m2c and permuter tools.
* [Fothsid](https://github.com/Fothsid): For sharing his experience with reversing Resident Evil Outbreak.
* [apstygo](https://github.com/apstygo): For his CRI Middleware decompilation work on Street Fighter III: 3rd Strike. 
* [GirianSeed](https://github.com/GirianSeed): For providing knowledge of the many different versions of the PS2 API, and finding extra debug info for CRI ADX not present in the game.
* [patope](https://github.com/patope), [Lovey847](https://github.com/Lovey847), [ladysilverberg](https://github.com/ladysilverberg), [ThirstyWraith](https://github.com/ThirstyWraith), [break-core](https://github.com/break-core) and [Hertzole](https://github.com/Hertzole): For giving additional help with function matching.
* [Video Game Esoterica](https://www.youtube.com/@VideoGameEsoterica): For covering the project on the channel.

## Community

The primary way to discuss the project is through the `GC/Wii Decompilation` server on Discord, which has a dedicated channel for the decomp called `resident-evil-code-veronica-x`. See you there!

[![Join the Discord](https://dcbadge.limes.pink/api/server/https://discord.gg/hKx3FJJgrV)](https://discord.gg/https://discord.gg/hKx3FJJgrV)

## Resources

Associated decomp projects:
- [Resident Evil - Code: Veronica X (Nintendo GameCube)](https://github.com/fmil95/recvx-gc-decomp)
- [Resident Evil - Code: Veronica (Dreamcast)](https://github.com/fmil95/recv-dc-decomp)
- [Legacy of Kain: Soul Reaver](https://github.com/fmil95/soul-re)
- [Fahrenheit](https://github.com/fmil95/santamonica)
- [Fatal Frame](https://github.com/Mikompilation/Himuro)
- [Silent Hill](https://github.com/Vatuu/silent-hill-decomp)

## Disclaimer

This repository and the code therein, is made public on this site by fmil95 for preservational and educational purposes. I do not claim to hold any affiliation to the Resident Evil franchise, Capcom Co., Ltd or any other related party, nor mean to infringe upon the copyright of Resident Evil: Code: Veronica X.
