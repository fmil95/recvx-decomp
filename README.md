# Resident Evil Code: Veronica X (SLUS-20184) Decompilation

<img src="https://i.imgur.com/xj2ujPy.jpeg"/>

## About

This project aims to reconstruct the source code for Resident Evil: Code Veronica X, with the main goal of doing a PC port of the game since it's one of the few main installments of the Resident Evil series that hasn't gotten one yet. To achieve this goal, code is being disassembled from the North American PlayStation 2 version of the game, which was specifically chosen for the task due to the following reasons:

1) It has a full set of debugging symbols which includes not only function names, but also their signatures and local variables.
2) You are never required to swap disks at any point during gameplay, as opposed to the GameCube and Dreamcast versions. Since all of the game is contained within a single DVD, this removes the need to decompile some extra code.  
3) The PS2 uses a MIPS-based CPU, the R5900 a.k.a the Emotion Engine, and thus decompiling the assembly instructions back to the high-level language the game was originally programmed on (C) is relatively easier than doing so with other console ports of the game that use different, more complex Instruction Set Architectures.

## Community

The primary way to discuss the project is through the `PS1/PS2 Decompilation` server on Discord, which has a dedicated channel for the decomp called `re-code-veronica`. See you there!

[![Join the Discord](https://dcbadge.limes.pink/api/server/https://discord.gg/tch8h5Vw8E)](https://discord.gg/https://discord.gg/tch8h5Vw8E)
