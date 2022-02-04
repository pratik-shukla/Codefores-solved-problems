import os
import sys
from io import BytesIO, IOBase
from collections import Counter
import math

from pip._vendor.distlib.compat import raw_input

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


def ispali(k):
    return str(k) == str(k)[::-1]


def main():
    while 1:
        s = raw_input()
        if len(s) == 0:
            break
        n, m = map(int, s.split())
        a = []
        k=[]
        c=0
        while 1:
            t=list(map(int, input().split()))
            c+=len(t)
            for j in t:
                k.append(j)
            if c==m*n:
                break
        c=0
        for i in range(n):
            t=[]
            for j in range(m):
                t.append(k[c])
                c+=1
            t.reverse()
            a.append(t)

        dp = [[float('inf') for j in range(m)] for i in range(n)]
        par = [[float('inf') for j in range(m)] for i in range(n)]
        for i in range(n):
            dp[i][0] = a[i][0]
            par[i][0] = -1
        ans = []
        for j in range(m - 1):
            for i in range(n):
                for k in range(-1 , 2 ):
                    if a[(i + k) % n][j + 1] + dp[i][j] < dp[(i + k) % n][j + 1] or (a[(i + k) % n][j + 1] + dp[i][j] == dp[(i + k) % n][j + 1] and  par[(i + k) % n][j + 1]>i):
                        dp[(i + k) % n][j + 1] = a[(i + k) % n][j + 1] + dp[i][j]
                        par[(i + k) % n][j+1] = i
        k=[]
        curr=float('inf')
        for i in range(n):
            if dp[i][m-1]<curr:
                curr=dp[i][m-1]
                k=[i, m-1]
        fans=dp[k[0]][k[1]]
        while par[k[0]][k[1]] != -1:
            ans.append(k[0] + 1)
            k[0]= par[k[0]][k[1]]
            k[1]-=1
        ans.append(k[0] + 1)
        print(*ans)
        print(fans)

    return


if __name__ == "__main__":
    main()
