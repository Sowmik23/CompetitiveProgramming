import java.util.Scanner;
import java.math.BigInteger;

/**
 *
 * @author sowmik
 */
public class Very_Easy {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
        BigInteger  A;
	int N;
        
        while(input.hasNextInt())
        {
            N =input.nextInt();
            A = input.nextBigInteger();
            
           // System.out.println(x +"\n"+y);
        
            //System.out.println(x.multiply(y));
            
            BigInteger ans = BigInteger.ZERO;
            BigInteger power = BigInteger.ONE;
            
            for(int i = 1 ; i <= N; i++)
            {
				power = power.multiply(A);
				ans = ans.add(power.multiply(BigInteger.valueof(i)));
	    }
	   System.out.println(ans);
        }

    }
}
