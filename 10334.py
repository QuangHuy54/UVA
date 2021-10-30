fib=[i for i in range(0, 1001)]
fib[0]=1
fib[1]=2
for i in range(2, 1001):
    fib[i] = fib[i-1] + fib[i-2]
while(True):
    try:
        a=int(input())
    except:
        break
    print(fib[a])
