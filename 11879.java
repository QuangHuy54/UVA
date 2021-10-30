import java.util.Scanner;
import java.math.BigInteger;
public class Main{
	public static void main(String[] args) {
		BigInteger ten=BigInteger.valueOf(10);
		BigInteger five=BigInteger.valueOf(5);
		BigInteger seventeen=BigInteger.valueOf(17);
		Scanner sc=new Scanner(System.in);
		while(true) {
			BigInteger N=sc.nextBigInteger();
			if(N.compareTo(BigInteger.ZERO)==0) {
				break;
			}
			BigInteger d=N.mod(ten);
			N=N.divide(ten);
			d=d.multiply(five);
			BigInteger res=(N.subtract(d)).mod(seventeen);
			if(res.compareTo(BigInteger.ZERO)==0) {
				System.out.println("1");
			}
			else {
				System.out.println("0");
			}
		}
	}

}
