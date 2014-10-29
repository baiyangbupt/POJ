#include<iostream>
#include<map>
#include<string>
using namespace std;

map<char,string> dict;
map<string,char> idict;

void init(){
    
dict['A'] = ".-", dict['H'] = "....", dict['O'] = "---", dict['V'] = "...-";
dict['B'] = "-...", dict['I'] = "..", dict['P'] = ".--.", dict['W'] = ".--";
dict['C'] = "-.-.", dict['J'] = ".---", dict['Q'] = "--.-", dict['X'] = "-..-";
dict['D'] = "-..", dict['K'] = "-.-", dict['R'] = ".-.", dict['Y'] = "-.--";
dict['E'] = ".", dict['L'] = ".-..", dict['S'] = "...", dict['Z'] = "--..";
dict['F'] = "..-.";
dict['M'] = "--";
dict['T'] = "-";
dict['G'] = "--.", dict['N'] = "-.", dict['U'] = "..-";
dict['_'] = "..--", dict[','] = ".-.-", dict['.'] = "---.", dict['?'] = "----";

for(map<char, string>::iterator it = dict.begin(); it!=dict.end(); it++)
              idict[it->second] = it->first;
}

void reverse(string &a){
     int l = 0, h = a.size()-1;
     while(l<h){
                swap(a[l],a[h]);
                l++, h--;
     }
}

int main(){
    int n, ic = 1;
    init();
    cin >> n;
    while(n--){
               string s;
               cin >> s;
               string t, num, res;
               for(int i = 0; i < s.size(); i++){
                       //cout << s[i] << " " <<dict[s[i]] << endl;
                       t.append(dict[s[i]]);
                       num.push_back('0'+dict[s[i]].size());
               }
               //cout << t << endl;
               //cout << num << endl;
               reverse(num);
               int p = 0, i = 0;
               while(p<t.size()){
                                 string tmp = t.substr(p,num[i]-'0');
                                 res.push_back(idict[tmp]);
                                 p += num[i]-'0';
                                 i++;
               }
               cout << ic++ << ": " <<res <<endl;
    }
}
                                 
