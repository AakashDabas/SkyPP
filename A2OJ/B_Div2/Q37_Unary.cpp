#include<iostream>
#include<map>
#include<string>

#define mod 1000003

using namespace std;

int main(){
    map<char, int> ref;
    ref['>'] = 8;
    ref['<'] = 9;
    ref['+'] = 10;
    ref['-'] = 11;
    ref['.'] = 12;
    ref[','] = 13;
    ref['['] = 14;
    ref[']'] = 15;

    string str;
    cin >> str;
    long long int out = 0;
    for(int i = 0; i < str.length(); i++)
        out = (out*16 + ref[str.at(i)]) % mod;
    cout << out;
    return 0;
}
