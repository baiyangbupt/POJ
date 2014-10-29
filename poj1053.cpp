#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct card{
       string attr;
       card(string s){
                   attr = s;
       }
};

vector<card> vv;
vector<vector<int> > set;

void solve(){
     cout << "CARDS: ";
     for(int i = 0; i < vv.size(); i++) cout << " " << vv[i].attr;
     cout << endl;
     cout << "SETS:   ";
     bool same[4];
     for(int i = 0; i < vv.size(); i++)
             for(int j = i+1; j< vv.size(); j++){
                     for(int k = 0; k < 4; k++) {
                             //cout << vv[i].attr[k] << " " << vv[j].attr[k] << endl;
                             same[k] = (vv[i].attr[k]==vv[j].attr[k]);
                     }
                     for(int k = j+1; k < vv.size(); k++){
                             bool valid = 1;
                             for(int ii = 0; ii < 4 && valid; ii++)
                                     if(same[ii]&&vv[k].attr[ii]!=vv[i].attr[ii]) valid = 0;
                                     else if(same[ii]==0&&(vv[k].attr[ii]==vv[i].attr[ii]||vv[k].attr[ii]==vv[j].attr[ii])) valid = 0;
                             
                             if(valid){
                                       vector<int> temp;
                                       temp.push_back(i), temp.push_back(j), temp.push_back(k);
                                       set.push_back(temp);
                             }
                     }
             }
     if(set.size()==0)  cout << "*** None Found ***" << endl;
     else{
          int ca = 1;
          cout << ca++ << ". ";
          for(int i = 0; i < 3; i++) cout << " " << vv[set[0][i]].attr ;
          cout << endl;
          for(int i = 1; i < set.size(); i++){
                  cout << "        "<< ca++<<". ";
                  for (int k = 0; k < 3; k++) cout << " " << vv[set[i][k]].attr;
                  cout << endl;
          }
     }
     cout << endl;
     vv.clear();
     set.clear();
}
                             
                     

int main(){
    string s;
    while(cin>>s){
                  vv.push_back(card(s));
                  for(int i = 0; i < 11; i++){
                          cin >> s;
                          vv.push_back(card(s));
                  }
                  solve();
    }
}
                  

