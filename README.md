# Resident Evil Code: Veronica X (SLUS-20184) Decompilation

<img src="https://i.imgur.com/xj2ujPy.jpeg"/>

## About

This project aims to reconstruct the source code for Resident Evil: Code Veronica X, with the main goal of doing a PC port of the game since it's one of the few main installments of the Resident Evil series that hasn't gotten one yet. To achieve this goal, code is being disassembled from the North American PlayStation 2 version of the game, which was specifically chosen for the task due to the following reasons:

1) It has a full set of debugging symbols which includes not only function names, but also their signatures and local variables.
2) You are never required to swap disks at any point during gameplay, as opposed to the GameCube and Dreamcast versions. Since all of the game is contained within a single DVD, this removes the need to decompile some extra code.  
3) The PS2 uses a MIPS-based CPU, the R5900 a.k.a the Emotion Engine, and thus decompiling the assembly instructions back to the high-level language the game was originally programmed on (C) is relatively easier than doing so with other console ports of the game that use different, more complex Instruction Set Architectures.

## Credits

This work couldn't have been possible without the contributions of the following users:

* [benoitren](https://git.sr.ht/~benoitren): First to tag along when mentioning an interest to reverse-engineer the game in the PS1/PS2 Decompilation server. Decompiled several files on his own.
* [Mc-Muffin](https://github.com/Mc-Muffin): Created the splat config for the game binary, solved an important issue with the compiler, tested the build environment on WSL, developed the script for rebuilding the game ISO and provided the most help with matching the functions, in quality and quantity.   
* [karas84](https://github.com/karas84): Helped to match very important functions like PS2DrawOTagSub which involved complex logic for rendering graphics on the PS2, as well as many other ones.

Additionally, some appreciation must go to:

* [ethteck](https://github.com/ethteck): For creating decomp.me, splat and also adding support for MIPSEE to m2c.
* [simonlindholm](https://github.com/simonlindholm): For his brilliant asm-differ, m2c and permuter tools.
* [Fothsid](https://github.com/Fothsid): For sharing his experience with reversing RE: Outbreak. 
* [GirianSeed](https://github.com/GirianSeed): For providing knowledge of the many different versions of the PS2 API.
* [patope](https://github.com/patope) and [ThirstyWraith](https://github.com/ThirstyWraith): For giving additional help with function matching.

## Community

The primary way to discuss the project is through the `PS1/PS2 Decompilation` server on Discord, which has a dedicated channel for the decomp called `re-code-veronica`. See you there!

[REDACTED].

## Resources

Associated decomp projects:
- [Legacy of Kain: Soul Reaver](https://github.com/fmil95/soul-re)
- [Fatal Frame](https://github.com/Mikompilation/Himuro)
- [Silent Hill](https://github.com/Vatuu/silent-hill-decomp)

## Disclaimer

This repository and the code therein, is made public on this site by fmil95 for preservational and educational purposes. I do not claim to hold any affiliation to the Resident Evil franchise, Capcom Co., Ltd or any other related party, nor mean to infringe upon the copyright of Resident Evil: Code: Veronica X.
