#include <bits/stdc++.h>
using namespace std;


class Difference {
	private:
		vector<int> v1;
	public:
		Difference(vector<int> v):
			v1(v) {};
		
		int maximumDifference;
		
		void computeDifference(){
			sort(v1.begin(), v1.end());
			
			int x = v1.front();
			int y = v1.back();
			
			maximumDifference = abs(x-y);
		}
	};
	
	

int main(){
	
	int n;
	cin>>n;
	
	vector<int> vec;
	
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		vec.push_back(x);
	}
	
	Difference d(vec);
	d.computeDifference();
	
	
	cout<<d.maximumDifference<<endl;
	
	
	return 0;
}
