#include<iostream>
#include<string>
using namespace std;
bool upp[100],downn[100],upleftt[100],uprightt[100],midd[100],downleftt[100],downrightt[100];
bool up(char s){
     return s!='1'&&s!='4';
}

bool upleft(char s){
     return s=='4'||s=='5'||s=='6'||s=='8'||s=='9'||s=='0';
}

bool upright(char s){
     return s!='5'&&s!='6';
}

bool mid(char s){
     return s!='1'&&s!='7'&&s!='0';
}

bool downleft(char s){
     return s=='2'||s=='6'||s=='8'||s=='0';
}

bool downright(char s){
     return s!='2';
}

bool down(char s){
     return s!='1'&&s!='4'&&s!='7';
}

int main(){
    int n;
    string s;
    while(cin>>n>>s&&(n!=0||s!="0")){
                                    for(int i = 0; i < s.size(); i++){
                                            upp[i] = up(s[i]);
                                            downn[i] = down(s[i]);
                                            midd[i] = mid(s[i]);
                                            upleftt[i] = upleft(s[i]);
                                            uprightt[i] = upright(s[i]);
                                            downleftt[i] = downleft(s[i]);
                                            downrightt[i] = downright(s[i]);
                                    }
                                    
                                    string level(n,'-'), space(n,' ');
                                    for(int i = 0; i<s.size()-1; i++){
                                            cout << ' ';
                                            if(upp[i]) cout << level;
                                            else cout << space;
                                            cout << ' ';
                                            cout << ' ';
                                    }
                                    cout << ' ';
                                    if(upp[s.size()-1]) cout << level;
                                    cout << ' ';
                                    cout <<endl;
                                    
                                    for(int i = 1; i <= n; i++){
                                            for(int j = 0; j < s.size()-1; j++){
                                                    if(upleftt[j]) cout << '|';
                                                    else cout << ' ';
                                                    cout << space;
                                                    if(uprightt[j]) cout << '|';
                                                    else cout << ' ';
                                                    cout << ' ';
                                            }
                                            if(upleftt[s.size()-1]) cout << '|';
                                            else cout << ' ';
                                            cout << space;
                                            if(uprightt[s.size()-1]) cout << '|';
                                            else cout << ' ';
                                            cout << endl;
                                    }
                                    
                                    for(int i = 0; i<s.size()-1; i++){
                                            cout << ' ';
                                            if(midd[i]) cout << level;
                                            else cout << space;
                                            cout << ' ';
                                            cout << ' ';
                                    }
                                    cout << ' ';
                                    if(midd[s.size()-1]) cout << level;
                                    cout << ' ';
                                    cout << endl;
                                    
                                    for(int i = 1; i <= n; i++){
                                            for(int j = 0; j < s.size()-1; j++){
                                                    if(downleftt[j]) cout << '|';
                                                    else cout << ' ';
                                                    cout << space;
                                                    if(downrightt[j]) cout << '|';
                                                    else cout << ' ';
                                                    cout << ' ';
                                            }
                                            if(downleftt[s.size()-1]) cout << '|';
                                            else cout << ' ';
                                            cout << space;
                                            if(downrightt[s.size()-1]) cout << '|';
                                            else cout << ' ';
                                            cout << endl;
                                    }        
                                    
                                    for(int i = 0; i<s.size()-1; i++){
                                            cout << ' ';
                                            if(downn[i]) cout << level;
                                            else cout << space;
                                            cout << ' ';
                                            cout << ' ';
                                    }
                                    cout << ' ';
                                    if(downn[s.size()-1]) cout << level;
                                    cout << ' ';
                                    cout << endl;
                                    cout << endl;
    }
}
                                    
