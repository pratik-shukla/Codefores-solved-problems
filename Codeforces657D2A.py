for _ in range(int(input())):
    a,b,n=map(int, input().split())
    c=0
    while (1):
        k=a
        l=b
        a=min(k,l)
        b=max(k,l)
        if a>n or b>n:
            break
        else:
            a+=b
            c+=1
    print(c)


