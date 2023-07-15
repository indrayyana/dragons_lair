from pwn import *
from ctypes import CDLL

p = process('./solo_lord2')
# r = remote("localhost", 2022)
libc = CDLL("libc.so.6")
libc.srand(libc.time(0))

def attack():
    acak = (libc.rand() % 99991 + 8)
    p.sendlineafter(b': ', str(acak).encode())

def regen():
    acak = (libc.rand() % 99991 + 8)
    p.sendlineafter(b': ', b'4')

for x in range(4):
    for i in range(5):
        attack()
    for i in range(10):
        regen()

p.interactive()
