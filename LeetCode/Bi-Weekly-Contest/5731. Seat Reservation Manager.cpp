#include <bits/stdc++.h>
using namespace std;


class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    SeatManager(int n) {
        for(int i=1;i<=n;i++){
			pq.push(i);
		}
    }
    
    int reserve() {
		int top = pq.top();
        pq.pop();
        return top;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};


int main(){
	
	SeatManager* sm = new SeatManager(5);
	
	int k;
	k =  sm->reserve();
	cout<<k<<endl;
	k =  sm->reserve();
	cout<<k<<endl;
	sm->unreserve(2);
	k =  sm->reserve();
	cout<<k<<endl;
	k =  sm->reserve();
	cout<<k<<endl;
	k =  sm->reserve();
	cout<<k<<endl;
	k =  sm->reserve();
	cout<<k<<endl;
	sm->unreserve(5);
	
	//cout<<k<<endl;
	
	return 0;
}

