# das68k
Building a m68k retro computer with SNES class graphics and audio

A lot of hobbyists and semi-pros are building 8-bit retro computers. It's cool to see and to keep that part of our history alive. A lot of us born in the 1960's and early 70's grew up with these machines and earned our chops in BASIC and 6502 assembly language. It is the foundation of who we are as programmers.

An interesting thing happened in the second half of the 80's. The 8-bit machines gave way to the next generation 16-bits. There were some exciting machines, especially the Commodore Amiga and the Atari ST and the Apple Macintosh, all based on the Motorola 68000 processor. There was also a really boring machine based in the Intel x86 processors and ran DOS. At the end of the day, the ecosystem of the PC won the day and boring won. I think we paid a heavy price for that which led to a period of stagnation at least until the second half of the 90's with Windows 95, despite the fact that these machines from the 80's already had windowing operating systems.

So the purpose of this project is to wind back the clock and present an alternative history. What if you built a m68k system that had the Super Nintendo type graphics with lots of hardware sprites and tiled graphics, that was purely a game machine but booted up to a DOS type interface that has great programming environments like we had with Turbo Pascal and Turbo C, and has Python instead of BASIC. That let programmers build some really cool games with the underlying 16-bit gaming hardware. I think we could build something really cool.

The other thing that's happening now is the growing accessibility of low cost FPGA boards with open source tooling. The ULX3S from Croatia is my favorite example. It's relatively low cost at $155US for the biggest Latice ECP5-85 FPGA. It has a ton of I/O ports, including a pseudo uncertified HDMI, two USB ports, one for programming and power and the other you could theoretically connect USB devices to. It has 32 MB RAM, enough SPI Flash for the FGPA and a bootloader, and an SD Card. Theres even an ESP32 that could provide wireless networking to the system. Crazy.

So that's the plan. First I need to build up a soft m68k that boots off the Flash and can access the RAM. Then I need to build up the graphics end. The Commander X16 VERA board is inspirational. Output would be to the HDMI port but at qHDMI (quarter), to keep it realistic for the video memory we would have.

You need some SNES style audio that the VERA is also doing. Access to the SD card for loading programs and saving data. And you need a USB host interface to hook up a USB hub and the keyboard and joysticks.

Then you need software. My current thinking is to base it off the gcc m68k C cross compiler. I'd use the newlib C runtime library. I would provide some of it's POSIX process capabilities to execvp a new process and send it signals. Then we could build up a POSIX shell. But we wouldn't have a MMU so no memory spaces and protection. Everything would have to be position independent. And we'd have to have a slim operating system that manages it.

We'd then provide shared libraries for the peripherals. Of course we then need a program loader and we can use ELF and the loader can managed the shared libraries and hooking things up. Hopefully that all fits in the small memory that we have, but did for Linux which was born on such machines.

And we go from there. Take a look at bringing MicroPython and hooking that up. And then bring on the games.
