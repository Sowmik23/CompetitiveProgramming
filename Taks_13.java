
package javaapplication2;

import java.util.Scanner;

/**
 *
 * @author sowmik
 * 
 */


class ClockTime{
	private	int hours;
	private int minutes;
        private int seconds;
        private String time;
	
        public ClockTime(){
		hours=12;
		minutes=0;
		seconds =0;
                
                time = hours +" : "+ minutes +" : "+seconds;
	}
	public	ClockTime(int h,int m,int s){
		hours=h;
		minutes=m;
		seconds=s;
	}	
	public ClockTime(int s){
		hours = s/3600;
                s = s%3600;
                minutes = s/60;
                seconds = s%60;
		
                time = hours +":"+ minutes +":"+seconds;
	}
        
        public void setClock(int s){
            hours = s/3600;
            s = s%3600;
            minutes = s/60;
            seconds = s%60;

            time = hours +":"+ minutes +":"+seconds;
            System.out.println(time);
        }
        
	public int getHours(){
		return hours;
	}
	public int getMinutes(){
	
		return minutes;
	}
	public int getSeconds(){
		
		return seconds;
	}
        
        
        public void tick(){
            //increment the time of clock by 1 seconds;
            
            int k =0;
            int count = this.seconds;
            boolean flag = true;
            while(flag)
            {
                try {
                
                    System.out.println(hours +":"+ minutes +":"+seconds);
                    Thread.sleep(1000);
                    count ++;
                    k++;
                    
                    if(count>=60){
                        minutes ++;
             
                        count =0;
                        if(minutes>=60){
                            hours++;
                            minutes=0;
                            if(hours>=23){
                                hours=0;
                            }
                        }
                    
                    }
                    this.seconds = count;
                    if(k==10){
                        flag = false;
                    }
                    
                } catch (InterruptedException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
            }
            
            
            
        }
        
        public void addClock(ClockTime ct){
            
            int hh = getHours();
            int mm = getMinutes();
            int ss = getSeconds();
            
            //System.out.println(hh+":"+mm+":"+ss); //time of B
            
            int j =ct.hours;
            int l = ct.minutes;
            int f = ct.seconds;
            
            //System.out.println(j+":"+l+":"+f); //time of A
            
            int newSeconds, newMinutes, newHours;
            
            newSeconds = ss + f;
            
            newMinutes = mm + l;
             
            if(newSeconds>=60){
                newMinutes++;
            }
            
            newHours = hh + j;
            
            if(newMinutes>=60){
                newHours++;
            }
            
            if(newHours>23){
                newHours = 23-newHours;
            }
            System.out.println(newHours+":"+newMinutes+":"+newSeconds);   
        }
        
        public String toString(){
                hours = this.hours;
                minutes = this.minutes;
                seconds = this.seconds;
		return hours+":"+minutes+":"+seconds;
	}
        
        public String tickDown(){
            //decrements time in one second;
            hours = this.hours;
            minutes = this.minutes;
            seconds = this.seconds;
            
            if(seconds!=0){
                seconds--;
            }
            else if(seconds==0 && minutes!=0 ) {
                minutes--;
                seconds=59;
            }
            else if(seconds==0 && minutes==0 && hours!=0){
                minutes =59;
                seconds =59;
                hours--;
            }
   
            return "("+hours+":"+minutes+":"+seconds+" )";
        }
        
        public void subtractClock(ClockTime t){
            //return the difference of time
            int hh = getHours();
            int mm = getMinutes();
            int ss = getSeconds();
            
            
            int i = t.hours;
            int j = t.minutes;
            int k = t.seconds;
            
            int time1 = hh*3600 + mm*60 + ss;
            int time2 = i*3600 + j*60 + k;
            
            int difference;
            
            if(time1>=time2){
                difference = time1-time2;
            }
            else difference = time2-time1;
            
            
            System.out.print("The difference between the firstClock and SecondClock is ");
            setClock(difference);
            
          
        }
}




public class Taks_13 {

    
    public static void main(String[] args) {
       
        
        Scanner input = new Scanner(System.in);
        
        int second = input.nextInt();
        
        ClockTime A = new ClockTime(second);
		System.out.println(A.toString());
               
                
            A.tick();
            
            
        int a,b,c;
        a = input.nextInt();
        b = input.nextInt();
        c = input.nextInt();
        
        ClockTime B = new ClockTime(a,b,c);
        
            B.tick();
            
        B.addClock(A);
            
        
        System.out.println(A.toString());
        System.out.println(B.toString());
        
        
        B.subtractClock(A);
            
            //E.tickDown();
            //System.out.println(E.toString());
            
    }
    
}
