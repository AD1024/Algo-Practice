import java.math.*;
import java.util.*;
class Main{
	public static void main(String args[]){
		String a=new String();
		String b=new String();
		Scanner scan = new Scanner(System.in);
		a=scan.next();
		b=scan.next();
		BigInteger x=new BigInteger(a);
		BigInteger y=new BigInteger(b);
		while(!x.equals(0) || !y.equals(0)){
			x.mod(y);
			BigInteger t=y;
			y=x;
			x=t;
		}
		System.out.println(y);
		return;
	}
}