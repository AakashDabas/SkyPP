#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
    for(int i = 0; i < 200 * 200; i++)
        cout << rand() % 10000 << " ";
    return 0;
}
