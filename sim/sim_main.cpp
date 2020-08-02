#include <verilated.h>
#include <Vdas68k.h>

// 512K ram
#define RAM_START 0
#define RAM_END 512 * 1024
unsigned char ram[RAM_END - RAM_START];

// 64K rom
#define ROM_START 0xFF0000
#define ROM_END 0x1000000
unsigned char rom[ROM_END - ROM_START];

#define OPCODE_NOP  0
#define OPCODE_HALT 1

void init_rom() {
    const int reset_address = ROM_START;
    for (int i = 0; i < 10 + 10; i++) {
        rom[i] = OPCODE_NOP;
    }
    rom[10] = OPCODE_HALT;

    // Reset vector
    rom[0xfffd] = reset_address & 0xFF;
    rom[0xfffe] = (reset_address & 0xFF00) >> 8;
    rom[0xffff] = (reset_address & 0xFF0000) >> 16;
}

void tick(Vdas6824 *cpu) {
    cpu->clk = 1;
    cpu->eval();
    cpu->clk = 0;
    cpu->eval();
}

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    init_rom();

    Vdas68k *cpu = new Vdas68k;

    cpu->clk = 0;
    cpu->reset = 0;
    cpu->eval();
    tick(cpu);
    cpu->reset = 1;

    while (true) {
        if (cpu->mem_read) {
            if (cpu->mem_addr >= RAM_START && cpu->mem_addr < RAM_END) {
                cpu->mem_data = ram[cpu->mem_addr - RAM_START];
                cpu->mem_avail = 1;
            } else if (cpu->mem_addr >= ROM_START && cpu->mem_addr < ROM_END) {
                cpu->mem_data = rom[cpu->mem_addr - ROM_START];
                cpu->mem_avail = 1;
            } else {
                cpu->mem_data = 0;
                cpu->mem_avail = 1;
            }
            printf("mem read 0x%06x = 0x%02x\n", cpu->mem_addr, cpu->mem_data);
        } else {
            cpu->mem_avail = 0;
        }
        tick(cpu);
    }
}
