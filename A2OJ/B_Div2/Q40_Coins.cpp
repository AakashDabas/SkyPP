#include<iostream>
#include<vector>

using namespace std;

struct node{
    int cnt = 0;
    int val = 0;
    node *ptr = NULL;
};

node* find(int n){
    int i = n / 2;
    node *fin = new node;
    fin->cnt = 1;
    fin->val = 1;
    if(n == 1)
        return fin;
    while(i > 0){
        if(n % i == 0){
            node *tmp = find(i);
            if(tmp->cnt > fin->cnt)
                fin = tmp;
        }
        i--;
    }
    node *ret = new node;
    ret->ptr = fin;
    ret->cnt = fin->cnt + 1;
    ret->val = n;
    if(n == 12 || 1){
        node *tmp = ret;
    }
    /*fin->ptr = fin;
    fin->cnt++;
    fin->val = n;*/
    return ret;
}

int main(){
    int n;
    cin >> n;
    node *ptr = find(n);
    //cout << "Length is : " << ptr->cnt << endl;
    while(ptr){
        cout << ptr->val << " ";
        ptr = ptr->ptr;
    }
    return 0;
}
