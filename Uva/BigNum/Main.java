
import java.util.Scanner;
import java.math.BigInteger;

/**
 *
 * @author sowmik
 */
public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
        BigInteger x,y;
        
        while(input.hasNextBigInteger())
        {
            x = input.nextBigInteger();
            y = input.nextBigInteger();
            
           // System.out.println(x +"\n"+y);
        
            System.out.println(x.multiply(y));
        }
    }
}

