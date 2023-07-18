from pwn import *
from ctypes import CDLL

r = process('./chall')
# r = remote("localhost", 2022)
libc = CDLL("libc.so.6")
libc.srand(libc.time(0))

def cheat():
    acak = 1000 + (libc.rand() % (99999 - 1000 + 1))
    r.sendlineafter(b': ', str(acak).encode())

def frezze():
    acak = 1000 + (libc.rand() % (99999 - 1000 + 1))
    r.sendlineafter(b': ', b'1')

def lightning():
    acak = 1000 + (libc.rand() % (99999 - 1000 + 1))
    r.sendlineafter(b': ', b'3')

def heal():
    acak = 1000 + (libc.rand() % (99999 - 1000 + 1))
    r.sendlineafter(b': ', b'4')

for x in range(10):
    for i in range(3):
        frezze()
    cheat()

r.interactive()