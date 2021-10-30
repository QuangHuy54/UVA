from bisect import bisect_right
fib=[i for i in range(0, 201)]
fib[0]=1
fib[1]=2
for i in range(2, 201):
    fib[i] = fib[i-1] + fib[i-2]
def to_res(n):
    res=[]
    index=bisect_right(fib,n)
    while index>=0:
        if(n>=fib[index]):
            res.append('1')
            n-=fib[index]
        else:
            res.append('0')
        index-=1
    ans=''.join(res).lstrip('0')
    return ans
case=0
flag=True
while(True):
    try:
        s1=input().strip()[::-1]
        if(s1==""):
            continue
        s2=input().strip()[::-1]
    except:
        break
    if s1=="0" and s2=="0":
        if(case>0):
            print("")
        print("0")
        case+=1
    else:
        s1=sum(fib[i] for i in range(len(s1)) if s1[i]=='1')
        s2=sum(fib[i] for i in range(len(s2)) if s2[i]=='1')
        s=s1+s2
        ans=to_res(s)
        if(case>0):
            print("")
        print(ans)
        case+=1

