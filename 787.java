import java.util.Scanner;
import java.util.ArrayList;
import java.math.BigInteger;
public class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		BigInteger n;
		BigInteger end=new BigInteger("-999999");
		BigInteger a[]=new BigInteger[101];
		int len=0;
		while(sc.hasNext()) {
			n=sc.nextBigInteger();
			if(n.compareTo(end)!=0) {
				a[len]=n;
				len++;
			}
			else {
				BigInteger res=a[0];
				BigInteger max_temp=a[0];
				BigInteger min_temp=a[0];
				for(int i=1;i<len;i++) {
					BigInteger temp=max_temp;
					max_temp=max(a[i],max(min_temp.multiply(a[i]),max_temp.multiply(a[i])));
					min_temp=min(a[i],min(min_temp.multiply(a[i]),temp.multiply(a[i])));
					res=max(max_temp,res);
				}
				System.out.println(res);
				len=0;
			}
		}
	}
	public static BigInteger max(BigInteger a,BigInteger b) {
		if(a.compareTo(b)==1) {
			return a;
		}
		return b;
	}
	public static BigInteger min(BigInteger a,BigInteger b) {
		if(a.compareTo(b)==1) {
			return b;
		}
		return a;
	}

}
