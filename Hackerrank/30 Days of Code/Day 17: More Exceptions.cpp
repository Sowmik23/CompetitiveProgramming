#include <bits/stdc++.h>
using namespace std;

struct invalidArgument: public exception{
	const char* what() const throw(){
		return ("n and p should be non-negative");
	}
};


class Calculator{
	private:
		int n, p;
	public:
		int power(int n, int p){
			if(n<0 or p<0){
				throw invalidArgument();
			}
			else return pow(n, p);
		}
};


int main(){
		
	Calculator myCalculator = Calculator();
	int t, n, p;
	cin>>t;
	while(t--){
		cin>>n>>p;
		
		try{
			int ans = myCalculator.power(n,p);
			cout<<ans<<endl;
		}
		catch(exception e){
			cout<<e.what()<<endl;
		}
	}
	
	
	return 0;
}
