
package javaapplication2;

import java.util.Scanner;

/**
 *
 * @author sowmik
 */

class Complex{
    
    private double realPart;
    private double imaginaryPart;
    
    
    public Complex(){
        realPart = 0;
        imaginaryPart = 0;
    }
    public Complex(double realPart, double imaginaryPart){
       // this.realPart = realPart;
       // this.imaginaryPart = imaginaryPart;
       
       //another way
       
       setRealPart(realPart);
       setImaginaryPart(imaginaryPart);
    }
    
    
    public void ComplexAdd(double rp, double ip){
        
        double nRP = getRealPart() + rp;
        double nIP = getImaginaryPart() + ip;
        
        System.out.println("After addition: "+nRP+"+"+nIP+"i");
    }
    public void ComplexSubtract(double rp, double ip){
        
        double nRP = getRealPart() - rp;
        double nIP = getImaginaryPart() - ip;
        
        System.out.println("After subtraction: "+nRP+"+"+nIP+"i");
    }
    public void ComplexMultiply(double rp, double ip){
        
        double nRP = getRealPart() * rp;
        double nIP = getImaginaryPart() * ip;
        
        System.out.println("After multiplication: "+nRP+"+"+nIP+"i");
    }
    public void ComplexDivide(double rp, double ip){
        
        double nRP = getRealPart() / rp;
        double nIP = getImaginaryPart() / ip;
        
        System.out.println("After division: "+nRP+"+"+nIP+"i");
    }
    
    
    public void setRealPart(double realPart){
        this.realPart = realPart;
    }
    public void setImaginaryPart(double impart){
        this.imaginaryPart = impart;
    }
    
    
    public double getRealPart(){
        return this.realPart;
    }
    public double getImaginaryPart(){
        return this.imaginaryPart;
    }
    
    
    public String toString(){
        return realPart+"+"+imaginaryPart+"i";
    }
    
}




public class Task_14 {  
/* the name of this class will
  *be ComplexDemo as question.
  *  
*/
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
        
        double rp,ip;
        
        rp = input.nextDouble();
        ip = input.nextDouble();
        
        Complex C = new Complex(rp,ip);
        
        System.out.println("The Complex number is: "+C.toString());
        
        double rp1,ip1;
        
        System.out.println("Give another real part of a complex number: ");
        
        rp1 = input.nextDouble();
        
        
        System.out.println("Give another imaginary part of a complex number: ");
        
        ip1 = input.nextDouble();
       
        
        C.ComplexAdd(rp1, ip1);
        C.ComplexSubtract(rp1, ip1);
        C.ComplexMultiply(rp1, ip1);
        C.ComplexDivide(rp1, ip1);
        
    }
       
}
