def main():
    while(True):
        try:
            f,n,s=input().split()
            f=int(f)
            n=int(n)
            s=int(s)
        except:
            break
        if n==0 and s==0:
            print("1/1")
        elif n==0 and s!=0:
            print("0/1")
        elif s>n*f:
            print(f"0/{f**n}")
        else:
            dp = [[0 for x in range(s+2)] for y in range(n+2)]
            for i in range(1,min(f+1,s+1)):
                dp[1][i]=1
            for i in range(2,n+1):
                for j in range(i,s+1):
                    for k in range(1,f+1):
                        if j-k>=0:
                            dp[i][j]+=dp[i-1][j-k]
            print(f"{dp[n][s]}/{f**n}")
main()