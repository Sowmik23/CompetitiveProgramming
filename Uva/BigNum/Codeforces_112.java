/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javacodepractise;

import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author sowmik
 */
public class Codeforces_112 {

    public static void main(String[] args) {
      
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
                          
                        System.out.println(a.pow(y));
                        
			z = a.pow(y).subtract(b.pow(x));

			//System.out.println(z);
		}
        
        
    }
    
}
