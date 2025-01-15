# Resident Evil – Code: Veronica X Decompilation

<img src="https://i.imgur.com/xj2ujPy.jpeg"/>

## About

This project aims to reconstruct the source code for Resident Evil: Code Veronica X, with the main goal of doing a PC port of the game since it's one of the few main installments of the Resident Evil series that hasn't gotten one yet. To achieve this goal, code is being disassembled from the North American PlayStation 2 version of the game, which was specifically chosen for the task due to the following reasons:

1) It has a full set of debugging symbols which includes not only function names, but also their signatures and local variables.
2) You are never required to swap disks at any point during gameplay, as opposed to the GameCube and Dreamcast versions. Since all of the game is contained within a single DVD, this removes the need to decompile some extra code.  
3) The PS2 uses a MIPS-based CPU, the R5900 a.k.a the Emotion Engine, and thus decompiling the assembly instructions back to the high-level language the game was originally programmed on (C) is relatively easier than doing so with other console ports of the game that use different, more complex Instruction Set Architectures.

At this very early stage of the project, there is no compilation environment set up, just raw code. Once there is enough to make the game playable up to the start menu screen on modern operating systems, the logic for rendering graphics and such will be rewritten to work without Sony's API for the PS2.

Discord server: https://discord.gg/VwCPdfbxgm
