for _ in range(int(input())):
    n=int(input())
    a=list(map(int, input().split()))
    e=[]
    o=[]
    for i in range(len(a)):
        if a[i]%2==0:
            e.append(i)
        else:
            o.append(i)
    if len(e)%2==0 and len(o)%2==0:
        if (len(e)!=0):
            for i in range(0,len(e)-2,2):
                print(e[i]+1,e[i+1]+1)
            for i in range(0,len(o),2):
                print(o[i]+1,o[i+1]+1)
        else:
            for i in range(0,len(e),2):
                print(e[i]+1,e[i+1]+1)
            for i in range(0,len(o)-2,2):
                print(o[i]+1,o[i+1]+1)
    else:
        for i in range(0,len(e)-1,2):
            print(e[i]+1,e[i+1]+1)
        for i in range(0,len(o)-1,2):
            print(o[i]+1,o[i+1]+1)