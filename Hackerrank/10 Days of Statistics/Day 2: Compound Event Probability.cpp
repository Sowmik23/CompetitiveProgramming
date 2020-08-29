#include <bits/stdc++.h>
using namespace std;

int main(){
	
	double X_pro_Red = 4/7.0;
	double X_pro_Black = 3/7.0;
	
	double Y_pro_Red = 5/9.0;
	double Y_pro_Black = 4/9.0;
	
	double Z_pro_Red = 4/8.0;
	double Z_pro_Black = 4/8.0;
	
	//P(2 red, 1 black) = 
	//p(red, red, black) + p(red, black, red) + p(black, red, red);
	
	double probability = X_pro_Red*Y_pro_Red*Z_pro_Black + X_pro_Red*Y_pro_Black*Z_pro_Red + X_pro_Black*Y_pro_Red*Z_pro_Red;
	cout<<probability<<endl;
	
	return 0;
}


