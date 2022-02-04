def isPrime(n):
    for i in range(3,(int((n)**(0.5))+1)):
        if (n%i==0):
            return 0
    return 1

for _ in range(int(input())):
    n = int(input())
    k = n
    if (n == 1):
        print('FastestFinger')
    elif n == 2:
        print('Ashishgup')
    else:
        if (n % 2 == 1):
            print('Ashishgup')
        else:
            c=0
            while (n % 2 == 0):
                c+=1
                n //= 2
            if (n == 1 ):
                print('FastestFinger')
            elif c==1:
                if isPrime(n):
                    print('FastestFinger')
                else:
                    print('Ashishgup')
            else:
                print('Ashishgup')
