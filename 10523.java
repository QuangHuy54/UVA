import java.util.Scanner;
import java.math.BigInteger;
public class Main{
	public static void main(String[] args) {
		int n,a;
		Scanner sc=new Scanner(System.in);
		while(sc.hasNextInt()) {
			n=sc.nextInt();
			a=sc.nextInt();
			BigInteger sum=BigInteger.ZERO;
			BigInteger temp=BigInteger.valueOf(a);
			for(int i=1;i<=n;i++) {
				sum=sum.add(BigInteger.valueOf(i).multiply(temp.pow(i)));
			}
			System.out.println(sum);
		}
	}

}
