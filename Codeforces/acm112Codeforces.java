import java.util.*;
import java.math.*;


public class acm112Codeforces
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		BigInteger a,b;
		int x,y;
		
		//while(input.hasNextInt())
		{
			x = input.nextInt();
			y = input.nextInt();
			
			a = BigInteger.valueOf(x);
			b = BigInteger.valueOf(y);

			BigInteger z = BigInteger.ZERO;

			z = a.pow(y).subtract(b.pow(x));

			System.out.println(z);
		}
        
	}
}
