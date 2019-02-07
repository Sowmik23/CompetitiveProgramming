
import java.math.BigInteger;
import java.util.Scanner;


public class Main {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
        
        BigInteger x;
        BigInteger sum = new BigInteger("0");
        BigInteger c = new BigInteger("0");
        
        while(true)
        {
            x = input.nextBigInteger();
         
            if(x.compareTo(c)==0) break;
            
            sum = sum.add(x);
            //System.out.println("sum "+sum);
        }
        System.out.println(sum);
        
    }
    
}

