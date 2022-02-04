n=int(input())
x=0
y=0
f=0
print(8*(n+1)-n)
print(x,y)
for i in range(n+1):
    if f==0:
        print(x+1,y)
        print(x+2,y)
        print(x,y+1)
        print(x+2,y+1)
        print(x, y + 2)
        print(x + 1, y+2)
        print(x + 2, y+2)
        x+=2
        f=1
    else:
        print(x + 1, y)
        print(x + 2, y)
        print(x, y - 1)
        print(x + 2, y - 1)
        print(x, y - 2)
        print(x + 1, y - 2)
        print(x + 2, y - 2)
        x+=2
        f=0

