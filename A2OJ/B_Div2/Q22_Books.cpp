#include<iostream>

using namespace std;

int main(){
    int ans = 0;
    long long int n, t;
    cin >> n >> t;
    int arr[n], itr = 0, cnt = 0;
    long long int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(sum + arr[i] <= t){
            cnt++;
            sum += arr[i];
        }
        else{
            sum += arr[i];
            cnt++;
            while(sum > t && itr <= i){
                //cout << "done\n";
                cnt--;
                sum -= arr[itr];
                itr++;
            }
        }
        if(cnt > ans)   ans = cnt;
        //cout << itr << " " << i << " " << ans << endl;
    }
    cout << ans;
    return 0;
}
