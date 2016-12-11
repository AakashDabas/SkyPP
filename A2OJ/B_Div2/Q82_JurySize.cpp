#include<cstdio>

inline int getNum(int d, int m){
    int ans = 0;
    int arr[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int i = 1; i < m; i++)
        ans += arr[i];
    ans += d;
    return ans + 100;
}

int main(){
    FILE * inputFile = fopen("input.txt","r");
    int n; 
    fscanf(inputFile, "%d\n", &n);
    int cntReq[470] = {0};
    for(int i = 0; i < n; i++){
        int m, d, p, t;
        fscanf(inputFile, "%d %d %d %d\n", &m, &d, &p, &t);
        int ref = getNum(d, m);
        for(int j = 1; j <= t; j++)
            cntReq[ref - j] += p;
    }
    int mx = 0;
    for(int i = 0; i < 470; i++)
        if(cntReq[i] > mx)
            mx = cntReq[i];
    FILE * outputFile = fopen("output.txt","w");
    fprintf(outputFile, "%ld\n", mx);
    fclose(outputFile);
    return 0;
}
