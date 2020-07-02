import java.util.*;
import java.math.*;


public class acm112Codeforces
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		BigInteger a,b;
		int x,y;
		
		while(cin.hasnextInt())
		{
			x = cin.nextInt();
			y = cin.nextInt();
			
			a = BigInteger.valueof(x);
			b = BigInteger.valueof(y);

			BigInteger z = BigInteger.ZERO;

			z = x.pow(y).subtract(y.pow(x));

			System.out.println(z);
		}
	}
}
