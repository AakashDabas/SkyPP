#include<iostream>
#include<string>

using namespace std;

int main(){
    string str;
    cin >> str;
    int ref[str.length()];
    ref[0] = 0;
    int i = 0;
    for(int j = 1; j < str.length();){
        if(str[i] == str[j]){
            ref[j] = i + 1;
            i++, j++;
        }
        else{
            while(i > 0 && str[i - 1] != str[j])
                i = ref[i - 1];
            ref[j] = i;
            j++;
        }
    }
    for(int j = 0; j < str.length(); j++)
        cout << ref[j] << " ";
    return 0;
}
