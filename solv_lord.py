from pwn import *
from ctypes import CDLL

p = process('./lord')
# r = remote("localhost", 2022)
libc = CDLL("libc.so.6")
libc.srand(libc.time(0))

def attack():
    acak = 1000 + (libc.rand() % (99999 - 1000 + 1))
    p.sendlineafter(b': ', str(acak).encode())

def regen():
    acak = 1000 + (libc.rand() % (99999 - 1000 + 1))
    p.sendlineafter(b': ', b'4')

for x in range(4):
    for i in range(5):
        attack()
    for i in range(10):
        regen()

p.interactive()