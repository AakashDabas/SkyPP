#include<iostream>
#include<cstdio>
#include<map>
#include<deque>

using namespace std;

int main(){
    FILE *inputFile, *outputFile;
    inputFile = fopen("input.txt", "r");
    outputFile = fopen("output.txt", "w");
    int n, k;
    fscanf(inputFile, "%d %d", &n, &k);
    map<int, deque<int> > mappy;
    for(int i = 0; i < n; i++){
        int tmp;
        fscanf(inputFile, "%d", &tmp);
        mappy[tmp].push_back(i);
    }
    bool ref[n] = {false};
    int cnt = 0;
    map<int, deque<int> >::iterator itr1 = mappy.end();
    itr1--;
    while(cnt < k){
        deque<int>::iterator itr2 = itr1->second.begin();
        while(itr2 != itr1->second.end()){
            ref[*itr2] = true;
            itr2++;
        }
        cnt += itr1->second.size();
        if(cnt >= k)
            fprintf(outputFile, "%d\n", itr1->first);
        itr1--;
    }
    cnt = 0;
    for(int i = 0; i < n && cnt < k; i++)
        if(ref[i]){
            fprintf(outputFile, "%d ", i + 1);
            cnt++;
        }
    return 0;
}
