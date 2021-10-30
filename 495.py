fib=[i for i in range(0, 5001)]
fib[0]=0
fib[1]=1
for i in range(2, 5001):
    fib[i] = fib[i-1] + fib[i-2]
while(True):
    try:
        a=int(input())
    except:
        break
    print(f"The Fibonacci number for {a} is {fib[a]}")
