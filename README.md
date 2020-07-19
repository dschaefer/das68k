# das68k
Building a m68k retro computer with SNES class graphics and audio

This is another attempt at building a retro computer using an FPGA. Lots of people are making 8-bit machines, both emulated like the new C64's or real like the Commander X16. My main objective though is to build something that would be fun, that plays great retro games, but also teaches programming, using either a good machine language or a modern interpreted language such as Python or Lua.

I am also inspired by the ulx3s FPGA board developed in Croatia. It has all the modern bells and whistles with a pseudo-HDMI port, USB, PMOD interfaces, SDRAM, SDCard, everything you would need along with the Lattice 85K LUT ECP5 FPGA which appears to be a monster. The fact that it's fast enough to do 30Hz 1080p is impressive. And it should be big enough to do a soft CPU, SNES class graphics with hardware sprites and tiles, and PCM audio.

So take a step past the 8-bit retro world, I start to look at 16-bit. The Commodore Amiga and Atari ST where a great next step after the Commodore 64, TRS-80, Apple II and the like. The new machines focused on blitters to enable building fast graphical windowing environments. And while they did have great games, I think hardware sprites are a lot easier to program.

The other thing that happened in this era was the rise of the DOS x86 machines. They were lesser machines that the Amiga (and I put my money where my mouth was and bought an Amiga 500 in that era when my friends were all buying PC's). But the richer ecosystem led to the demise of the competition. But what if things were different?

So the plan is to build a soft Motorola 68000. This was a great CPU with an instruction set built to make programming easier. Unfortunately in history, Motorola quickly got into thermal problems as they tried to scale it up. Nicely, modern toolchains still support the architecture since it lived a long life in the embedded industry.

The Commander X16 has a really cool graphics card that also does audio. It's also built with an FPGA. It is similar in capability to the Super Nintendo system. It would be interesting to see how well it works running on the same FPGA as the soft CPU.
