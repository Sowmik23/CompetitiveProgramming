/*#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	double d;
	string str;
	scanf("%d",&n);
	scanf("%lf",&d);
	
	cin.ignore();
	
	getline(cin, str);
	
	printf("%d\n", n+d);
	printf("%.1lf\n", d+d);
	
	cout<<"HackerRank "<<str<<endl;
	
	return 0;
}
*/
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

	int i1;
	double d1;
    cin>>i1;
    cin>>d1;
    string str;
    cin.ignore();
    
    getline(cin, str);
    
    int sum = i+i1;
    printf("%d\n", sum);
    double x = d + d1;
    printf("%.1lf\n", x);
    
    cout<<s+str<<endl;
    
    return 0;
}
