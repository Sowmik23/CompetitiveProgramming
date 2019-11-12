#include <iostream>

using namespace std;

int x;

int gcd(int a, int b){
    
    x = a%b;
    if(x==0) return b;
    a = b;
    b = x;
    
    return gcd(a,b);
}


int main() {
    int a, b;
    cin >> a >> b;
    
    int x = gcd(a,b);
    
    printf("%d\n",x);
    
    
    return 0;
}
