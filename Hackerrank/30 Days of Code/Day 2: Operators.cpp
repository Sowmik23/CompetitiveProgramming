#include <bits/stdc++.h>
using namespace std;

int main(){
	
	double mealCost;
	int tipPercent, taxPercent;
	
	cin>>mealCost;
	cin>>tipPercent>>taxPercent;
	
	double x = mealCost*(tipPercent/100.0 + taxPercent/100.0);
	//x = round(x);
	//cout<<x<<endl;
	
	cout<<round(mealCost+x)<<endl;
	
	
	return 0;
}
