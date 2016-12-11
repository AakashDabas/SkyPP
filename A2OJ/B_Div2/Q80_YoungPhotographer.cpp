#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    int at1, bt1;
    cin >> at1 >> bt1;
    int a1 = min(at1, bt1), b1 = max(at1, bt1);
    for(int i = 0; i < n - 1; i++){
        int at2, bt2;
        cin >> at2 >> bt2;
        int a2 = min(at2, bt2), b2 = max(at2, bt2);
        if(a1 < a2)
            a1 = a2;
        if(b1 > b2)
            b1 = b2;
        //cout << a2 << " " << b2 << endl;
        if(b1 < a1){
            cout << "-1";
            return 0;
        }
    }
    //cout << a1 << " " << b1 << endl;
    if(a1 <= x && x <= b1)
        cout << 0;
    else
        cout << min(abs(a1 - x), abs(b1 - x));
    return 0;
}
