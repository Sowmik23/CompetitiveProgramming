/*For the given circular array please create a tracing table which traverses the whole circular array in a backward manner. The starting is to //be chosen randomly by the students.
//create a tracing table according to the following code.

*/

import java.io.*;
import java.util.Scanner;

public class Nishi {
	public static void main(String[] args){

		int[] arr = new int[]{10,20,30,40,50,60,70,80,90,100}; //given

		Scanner input = new Scanner(System.in);
		int start;
		
		//Find the index of the last elemlent in the circular array -----> that means array size ber korte hobe
	
		int size = arr.length;
		System.out.println("Give your start index value: ");
		start = input.nextInt();

		int k = (start + size - 1) % arr.length;
		for(int i = 0; i<size; i++){
			//visit(arr[k]);---->that means amader value ache arr[k] te
			//move k backwards, ---> k theke amader k back e jete hobe and -1 paile again arr[size-1]e jete hobe
			//wrapping if necessary
			System.out.println("index "+k+" value "+arr[k]);
			k--;
			if(k==-1)
				k = arr.length - 1;
		}
	}
}
