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

for i in range(17):
    frezze()
    poison()
    heal()
    cheat()   
    
    if (i != 16): 
        frezze()
        frezze()

poison()
frezze()

r.recvuntil(b"flag: ")

flag = r.recvline().strip() # Mengambil output flag
result = ""
key = 9 + (libc.rand() % (90 - 9 + 1))
for i in range(len(flag)): 
    tmp = flag[i] ^ key
    result += chr(tmp)

r.interactive()

print(result)
