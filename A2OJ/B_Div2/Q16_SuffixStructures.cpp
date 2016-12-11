#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    string str1, str2;
    cin >> str1 >> str2;
    vector<int> arr1(26, 0), arr2(26, 0);
    int itr = 0;
    //Checks for substring
    for(int i = 0; i < str1.length(); i++){
        if(str1.at(i) == str2.at(itr))  itr++;
        if(itr == str2.length()){
            cout << "automaton";
            return 0;
        }
    }
    //Prepares the arrays to store the count
    for(int i = 0; i < str1.length(); i++)
        arr1[str1.at(i) - 'a']++;
    for(int i = 0; i < str2.length(); i++)
        arr2[str2.at(i) - 'a']++;
    bool flag = true;
    for(int i = 0; i < 26; i++){
        if(arr1[i] < arr2[i] && arr2[i]){
            cout << "need tree";
            return 0;
        }
        if(arr1[i] > arr2[i])   flag = false;
    }
    if(flag)    cout << "array";
    else    cout << "both";
    return 0;
}
