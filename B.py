n=int(input())
s='codeforces'
k=0
a=[1]*10
curr=1
f=0
while (1):
    if curr >= n:
        f = 1
        break
    for i in range(10):
        curr/=a[i]
        curr*=(a[i]+1)
        a[i]+=1
        if curr>=n:
            f=1
            break
    if f:
        break
for i in range(10):
    print(s[i]*(a[i]),end='')
