class Robot {
public:
    
    int currX = 0;
    int currY = 0;
    
    int w;
    int h;
    
    string directions = "East";
    
    Robot(int width, int height) {
        w = width;
        h = height;
    }
    
    void move(int num) {
        
        num = num%((w-1+h-1)*2);
        if(num==0){
            if(currX==0 and currY==0) directions="South";
        }
        if(directions.compare("East")==0){
            while(currX<w-1 and num>0){
                currX++;
                num--;
                directions = "East";
            }
            while(currY<h-1 and num>0){
                currY++;
                num--;
                directions = "North";
            }
            while(currX>0 and num>0){
                currX--;
                num--;
                directions = "West";
            }
            while(currY>0 and num>0){
                currY--;
                num--;
                directions = "South";
            }
            while(currX<w-1 and num>0){
                currX++;
                num--;
                directions = "East";
            }
        }
        else if(directions.compare("North")==0){
            while(currY<h-1 and num>0){
                currY++;
                num--;
                directions = "North";
            }
            while(currX>0 and num>0){
                currX--;
                num--;
                directions = "West";
            }
            while(currY>0 and num>0){
                currY--;
                num--;
                directions = "South";
            }
            while(currX<w-1 and num>0){
                currX++;
                num--;
                directions = "East";
            }
            while(currY<h-1 and num>0){
                currY++;
                num--;
                directions = "North";
            }
        }
        else if(directions.compare("West")==0){
            while(currX>0 and num>0){
                currX--;
                num--;
                directions = "West";
            }
            while(currY>0 and num>0){
                currY--;
                num--;
                directions = "South";
            }
            while(currX<w-1 and num>0){
                currX++;
                num--;
                directions = "East";
            }
            while(currY<h-1 and num>0){
                currY++;
                num--;
                directions = "North";
            }
            while(currX>0 and num>0){
                currX--;
                num--;
                directions = "West";
            }
        }
        else if(directions.compare("South")==0){
            while(currY>0 and num>0){
                currY--;
                num--;
                directions = "South";
            }
            while(currX<w-1 and num>0){
                currX++;
                num--;
                directions = "East";
            }
            while(currY<h-1 and num>0){
                currY++;
                num--;
                directions = "North";
            }
            while(currX>0 and num>0){
                currX--;
                num--;
                directions = "West";
            }
            while(currY>0 and num>0){
                currY--;
                num--;
                directions = "South";
            }
        }
    }
    
    vector<int> getPos() {
        
        return {currX, currY};
    }
    
    string getDir() {
        
        return directions;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
