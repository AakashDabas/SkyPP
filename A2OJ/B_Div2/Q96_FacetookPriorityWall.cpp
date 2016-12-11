#include<iostream>
#include<string>
#include <map>
#include <set>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    std::map<string, int> mappy;
    string my;
    int n;
    cin >> my >> n;
    for(int i = 0; i < n; i++){
        char name1[200], name2[200];
        cin >> name1;
        string tmp1;
        cin >> tmp1;
        if(tmp1 == "posted"){
            cin >> tmp1;
            cin.ignore();
            cin.getline(name2, 100, '\'');
            cin.ignore(100, '\n');
            if(name1 == my)
                mappy[name2] -= 15;
            else if(name2 == my)
                mappy[name1] -= 15;
            else{
                mappy[name1] -= 0;
                mappy[name2] -= 0;
            }
            //cout << name1 << " -> " << mappy[name1] << " : " << name2 << " -> " << mappy[name2] << endl;
        }
        else if(tmp1 == "commented"){
            cin >> tmp1;
            cin.ignore();
            cin.getline(name2, 100, '\'');
            cin.ignore(100, '\n');
            if(name1 == my)
                mappy[name2] -= 10;
            else if(name2 == my)
                mappy[name1] -= 10;
            else{
                mappy[name1] -= 0;
                mappy[name2] -= 0;
            }
            //cout << name1 << " -> " << mappy[name1] << " : " << name2 << " -> " << mappy[name2] << endl;
        }
        else{
            cin.ignore();
            cin.getline(name2, 100, '\'');
            cin.ignore(100, '\n');
            if(name1 == my)
                mappy[name2] -= 5;
            else if(name2 == my)
                mappy[name1] -= 5;
            else{
                mappy[name1] -= 0;
                mappy[name2] -= 0;
            }
            //cout << name1 << " -> " << mappy[name1] << " : " << name2 << " -> " << mappy[name2] << endl;
        }
    }
    std::map<int, set<string> > mappyFin;
    for (map<string, int>::iterator itr = mappy.begin(); itr != mappy.end(); ++itr)
        if(itr->first != my)
            mappyFin[itr->second].insert(itr->first);
    for (map<int, set<string> >::iterator itr = mappyFin.begin(); itr != mappyFin.end(); ++itr) {
        for (set<string>::iterator itr2 = (*itr).second.begin(); itr2 != (*itr).second.end(); ++itr2) {
            cout << *itr2 << "\n";
        }
    }
    return 0;
}
