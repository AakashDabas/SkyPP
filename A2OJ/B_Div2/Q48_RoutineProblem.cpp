#include<iostream>

using namespace std;

int hcf(int a, int b){
    int val = 1;
    for(int i = 1; i <= a && i <= b; i++)
        if(a % i == 0 && b % i == 0)
            val = i;
    return val;
}

int main(){
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double o1 =  a * d / c, o2 = b * c / d;
    int area = a * b;
    if(o1 < b){
        int num = area * c - a * a * d;
        int den = c * area;
        int f = hcf(num, den);
        num /= f;
        den /= f;
        if(num == 0)
            den = 1;
        cout << num << "/" << den;
    }
    else{
        int num = area * d - b * b * c;
        int den = d * area;
        int f = hcf(num, den);
        num /= f;
        den /= f;
        if(num == 0)
            den = 1;
        cout << num << "/" << den;
    }
    return 0;
}
