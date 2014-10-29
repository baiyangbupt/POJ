#include <iostream>
#include <map>

using namespace std;
map<char, char> dict;

void init(){
     dict['A'] = dict['B'] = dict['C'] = '2';
     dict['D'] = dict['E'] = dict['F'] = '3';
     dict['G'] = dict['H'] = dict['I'] = '4';
     dict['J'] = dict['K'] = dict['L'] = '5';
     dict['M'] = dict['N'] = dict['O'] = '6';
     dict['P'] = dict['R'] = dict['S'] = '7';
     dict['T'] = dict['U'] = dict['V'] = '8';
     dict['W'] = dict['X'] = dict['Y'] = '9';
}

string convert(string s){
       int count = 0;
       string res;
       for(int i = 0; i < s.size(); i++){
               if(s[i]!='-'){
                             if(s[i]>'9'||s[i]<'0') s[i] = dict[s[i]];
                             res.push_back(s[i]);
                             count++;
                             if(count==3) res.push_back('-');
               }
       }
       return res;
}
int main(){
    int n;
    init();
    string s;
    cin >> n;
    map<string, int> mp;
    for(int i = 0; i < n; i++){
            cin >> s;
            s = convert(s);
            if(mp.find(s)==mp.end()) mp[s] = 1;
            else mp[s]++;
    }
    int count = 0;
    for(map<string, int>::iterator it = mp.begin(); it!=mp.end(); it++)
                    if(it->second>1){
                                     count++;
                                    cout << it->first << " " << it->second << endl;
                    }
    if(count==0) cout << "No duplicates" << endl;
    system("pause");
}
