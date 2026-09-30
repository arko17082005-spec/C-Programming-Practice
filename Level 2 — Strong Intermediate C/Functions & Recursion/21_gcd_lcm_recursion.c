#include <stdio.h>

int gcd(int a, int b) {
    if (b==0) {
        return a;
    }
    return gcd(b, a%b);
}

int main() {
    int a, b, g, lcm;

    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);
    
    g=gcd(a,b);
    lcm=(a*b)/g;

    printf("GCD = %d\n", g);
    printf("LCM = %d\n",lcm);

    return 0;
}