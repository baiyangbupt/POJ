#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string ss[101];
int nc,ns;
    

string reverse(string s){
       int i = 0, j = s.size()-1;
       string res = s;
       while(i<j){
                  swap(res[i],res[j]);
                  i++,j--;
       }
       return res;
}

bool sunday(string p, string s){
     int temp[256],plen = p.size(), slen = s.size();
     memset(temp,-1,sizeof(temp));
     for(int i = 0; i < p.size(); i++) 
             temp[p[i]] = plen-i;
     
     int i=0,j=0;
     while(i<plen&&j<slen){
                                   if(p[i]==s[j]){
                                                  i++,j++;
                                                  continue;
                                   }
                                   int t = plen-i+j;
                                   if(t>=slen) return 0;
                                   if(temp[s[t]]<0)
                                                   i = 0, j = t+1;
                                   else
                                       i = 0, j += temp[s[t]];
     }
     if(i==plen)
                return 1;
     return 0;
}

bool test(string s){
     string res = reverse(s);
     //cout << s << endl;
     for(int i = 0; i < ns; i++){
             //cout << ss[i] << endl;
             if(sunday(s,ss[i])==0&&sunday(res,ss[i])==0)
                                                         return 0;
     }
     
     return 1;
}
     
     
int main(){
    cin >> nc;
    
    for(int i = 0; i < nc; i++){
            string minstring;
           int minlen=1000000;
            cin >> ns;
            for(int j = 0; j < ns; j++){
                    cin >> ss[j];
                    //cout << ss[j] << minstring << endl;
                    if(minlen>ss[j].size())
                                           minlen = ss[j].size(), minstring = ss[j];
            }
            
            int res = minlen;
            bool undo = 1;
            vector<string> vv;
            for(int len = res; len>0; len--){
                    for(int i = 0; i+len-1<minlen; i++){
                                  string t = minstring.substr(i,res);
                                  vv.push_back(t);
                                  vv.push_back(reverse(t));
                    }
            }
            sort(vv.begin(),vv.end());
            int j;
            for(j = vv.size()-1; j >= 0&&undo; j--)
                    if(test(vv[j]))
                                   undo = 0;
            cout << vv[j].size() << endl;
    }
    return 0;
}

