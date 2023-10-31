import pwn
import re
from ctypes import CDLL

r = pwn.process('./chall')
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

enc_flag = r.recvline().strip() # Mengambil output flag
dec_flag = ""
key = 9 + (libc.rand() % (90 - 9 + 1))

for c in enc_flag: 
    dec_flag += chr(c ^ key)


arr_num = re.findall(r'\d{3}', dec_flag)
shifted_results = []

for num in arr_num:
    right_shift = int(num) >> 7
    shifted_results.append(right_shift)

flag = dec_flag
for num, result in zip(arr_num, shifted_results):
    flag = flag.replace(num, str(result))

r.interactive()

print(flag)
