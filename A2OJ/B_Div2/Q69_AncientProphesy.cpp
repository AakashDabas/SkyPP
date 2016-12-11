#include<iostream>
#include<string>

#define digit(x) (x >= '0' && x <= '9')

using namespace std;

struct data{
    int d = 0, m = 0, y = 0;
};

int main(){
    ios :: sync_with_stdio(false);
    string str;
    cin >> str;
    int mat[3][13][32] = {0};
    for(int i = 0; i < str.length(); i++){
        if(i <= str.length() - 4){
            if(str[i] == '2' && str[i + 1] == '0' && str[i + 2] == '1'){
                int ch = str[i + 3];
                if(ch == '3' || ch == '4' || ch == '5'){
                    int lst = i + 3;
                    if(lst >= 9){
                        int strt = lst - 9;
                        if(digit(str[strt]) && 
                                digit(str[strt + 1]) &&
                                digit(str[strt + 3]) &&
                                digit(str[strt + 4]) &&
                                str[strt + 2] == '-' &&
                                str[strt + 5] == '-'){
                            bool valid = false;
                            data tmp;
                            tmp.d = str[strt] - '0';
                            tmp.d = tmp.d * 10 + str[strt + 1] - '0';
                            tmp.m = str[strt + 3] - '0';
                            tmp.m = tmp.m * 10 + str[strt + 4] - '0';
                            tmp.y = str[strt + 6] - '0';
                            tmp.y = tmp.y * 10 + str[strt + 7] - '0';
                            tmp.y = tmp.y * 10 + str[strt + 8] - '0';
                            tmp.y = tmp.y * 10 + str[strt + 9] - '0';
                            if(tmp.m == 2){
                               if(tmp.d <= 28)
                                valid = true;
                            }
                            else if(tmp.m == 4 || tmp.m == 6 || tmp.m == 9 || tmp.m == 11){
                               if(tmp.d <= 30)
                                valid = true;
                            }
                            else if(tmp.d <= 31 && tmp.m >= 1 && tmp.m <= 12)
                                valid = true; 
                            if(valid && tmp.d >= 1)
                                mat[tmp.y - 2013][tmp.m][tmp.d]++;
                        }
                    }
                }
            }
        }
    }
    int d, m, y, cnt = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j <= 12; j++)
            for(int k = 0; k <= 31; k++)
                if(mat[i][j][k] > cnt){
                    d = k;
                    m = j;
                    y = i + 2013;
                    cnt = mat[i][j][k];
                }
    if(d < 10)
        cout << "0";
    cout << d << "-";
    if(m < 10)
        cout << "0";
    cout << m << "-" << y;
    return 0;
}
