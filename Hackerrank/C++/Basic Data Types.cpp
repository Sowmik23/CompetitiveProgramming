#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    
    int a;
    long b;
    char ch;
    float c;
    double d;
    
    scanf("%d%ld", &a, &b);
    cin.ignore();
    scanf("%c", &ch);
    getchar();
    scanf("%f%lf",  &c, &d);
    
    printf("%d\n%ld\n%c\n%f\n%lf\n", a, b, ch, c, d);
    
    return 0;
}
