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

def poison():
    acak = 1000 + (libc.rand() % (99999 - 1000 + 1))
    r.sendlineafter(b': ', b'2')

def heal():
    acak = 1000 + (libc.rand() % (99999 - 1000 + 1))
    r.sendlineafter(b': ', b'3')

for x in range(1):
    poison()
    frezze()
    heal()
    # cheat()

# testing
# for x in range(5):
#     frezze()
#     poison()
#     heal()
#     cheat()

r.interactive()