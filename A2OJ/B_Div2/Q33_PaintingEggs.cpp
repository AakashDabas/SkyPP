#include<iostream>
#include<cmath>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int arr[n][2];
    for(int i = 0; i < n; i++)
        cin >> arr[i][0] >> arr[i][1]; 
    int s1 = 0, s2 = 0;
    string out;
    for(int i = 0; i < n; i++){
        if(abs(s1 - s2 + arr[i][0]) <= 500){
            out += "A";
            s1 += arr[i][0];
        }
        else{
            out += "G";
            s2 += arr[i][1];
        }
    }
    if(abs(s1 - s2) > 500)
        cout << "-1";
    else
        cout << out;
    return 0;
}
