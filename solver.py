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

frezze()
poison()
heal()
cheat()
frezze()
poison()
frezze() #7
frezze() #8
heal() #9
cheat() #10
frezze() #11
poison() #12
frezze() #13
frezze() #14
heal() #15
cheat() #16
frezze() #17
heal() #18
frezze() #19
for i in range(16):
    heal()
poison() #36
cheat() #37
poison() #38
heal() #39
frezze() #40
cheat() #41
heal() #42
frezze() #43
for i in range(16):
    heal()
poison() #60
cheat() #61
poison() #62
heal() #63
frezze() #64
cheat() #65
heal() #66
frezze() #67
for i in range(16):
    heal()
poison() #84
cheat() #85
poison() #86
for i in range(16):
    heal()
frezze() #103
cheat() #104
heal() #105
for i in range(16):
    heal()
poison() #122
frezze() #123
cheat() #124
frezze() #125

r.recvuntil(b"flag: ")

flag = r.recvline().strip() # Mengambil output flag
result = ""
key = 9 + (libc.rand() % (90 - 9 + 1))
for i in range(len(flag)): 
    tmp = flag[i] ^ key
    result += chr(tmp)

r.interactive()

print(f"slashroot7{{{result}}}")