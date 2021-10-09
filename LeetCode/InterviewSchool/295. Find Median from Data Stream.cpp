class MedianFinder {
public:
    /** initialize your data structure here. */
   /* priority_queue<int> small, large;
    
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
    
        small.push(num);
        large.push(-small.top());
        small.pop();
        
        if(small.size()<large.size()){
            small.push(-large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if(small.size()>large.size()){
            return small.top();
        }
        else {
            return (small.top()-large.top())/2.0;
        }
    }
    */
    
    
    ///another approach: using max and min priority queue
    priority_queue<int> maxpq;
    priority_queue<int, vector<int> , greater<int> > minpq;
    
    MedianFinder(){
        
    }
    
    void addNum(int num){
        if(maxpq.size()==0 or num<=maxpq.top()){
            maxpq.push(num);
            
            if(maxpq.size()>minpq.size()+1){ //keeping maxpq 1 more element
                minpq.push(maxpq.top());
                maxpq.pop();
            }
        }
        else {
            minpq.push(num);
            if(minpq.size()>maxpq.size()){
                maxpq.push(minpq.top());
                minpq.pop();
            }
        }
    }
    
    double findMedian(){
        if(maxpq.size()>minpq.size()){
            return 1.0*maxpq.top();
        }
        else {
            return (maxpq.top()+minpq.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
