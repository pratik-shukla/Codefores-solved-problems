import os
import sys
from io import BytesIO, IOBase
from collections import Counter

BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)



def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


def lcm(a, b):
    return (a * b) / gcd(a, b)


pow2=[1]
d={}

def main():
    while(1):
        n=int(input())
        if n==0:
            break
        if n==2 or n==3 or n==5 or n==7 or n==11 or n==13 or n==17 or n==19 or n==23 or n==29 or n==31:#m==2*an:
            po = pow2[n]
            f=po//2
            s=po-1
            m=0
            for i in range(0,32):
                if f%pow2[i]==0:
                    m+=pow2[i]
            if s!=1:
                i=2
                while i*i<=s:
                    if s%i==0:
                        m=float('inf')
                        break
                    i+=1
                m=m*s+m
            if m==2*f*s:
                print('Perfect:',(po//2)*(po-1),end='')
                print('!')
            else:
                print('Given number is prime. But, NO perfect number is available.')
        else:
            print('Given number is NOT prime! NO perfect number is available.')
    return

if __name__=="__main__":
    for i in range(1,32):
        pow2.append(pow2[i-1]*2)
    main()
