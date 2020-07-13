
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
        
        int t = input.nextInt();
        
        while(true)
        {
            t--;
            if(t==0) break;
            x = input.nextBigInteger();
            y = input.nextBigInteger();
            
           // System.out.println(x +"\n"+y);
        
            System.out.println(x.multiply(y));
        }
    }
}
