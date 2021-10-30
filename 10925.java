import java.util.Scanner;
import java.math.BigInteger;
public class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n,f;
		int t=1;
		while(true) {
			n=sc.nextInt();
			f=sc.nextInt();
			if(n==0&&f==0) {
				break;
			}
			BigInteger sum=BigInteger.ZERO;
			for(int i=0;i<n;i++) {
				BigInteger V=sc.nextBigInteger();
				sum=sum.add(V);
			}
			System.out.println("Bill #"+(t++)+" costs "+sum+": each friend should pay "+sum.divide(BigInteger.valueOf(f)));
		}
	}
}
