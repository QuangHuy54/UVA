from math import comb
def main():
    case=1
    while(True):
        try:
            n,m=input().split()
            n=int(n)
            m=int(m)
            res=m**n
            for i in range(1,m):
                res=res+((-1)**i)*comb(m,i)*((m-i)**n)
            res=res/(m**n)
            res=1-res
            print(f"Case {case}: {res:.7f}")
            case=case+1
        except:
            break
main()