#include <bits/stdc++.h>

using namespace std;

int lowestTriangle(int base, int area){
	int x;
    float h = (area*2.0)/base;
    //cout<<h<<endl;
    x = h;
    //cout<<x<<endl;
    if(h!=x){
		x++;
	}
		
    return x;
}

int main() {
    int base;
    int area;
    cin >> base >> area;
    int height = lowestTriangle(base, area);
    cout << height << endl;
    return 0;
}
