#include<iostream>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

bool islow(char c){
     return 'a'<=c&&'z'>=c;
}
bool cmp(const char &a, const char &b){
     if(islow(a)){
                  if(islow(b))
                              return a < b;
                  else{
                       if(a-'a'==b-'A')
                                       return 0;
                       else
                           return a-'a'<b-'A';
                  }
     }
     else{
          if(islow(b)){
                       if(a-'A'==b-'a')
                                       return 1;
                       else
                           return a-'A'<b-'a';
          }
          else{
               return a<b;
          }
     }
}
     
unsigned int JSHash(string str)
{
    unsigned int hash = 1315423911;
 
    int i = 0;
    while (i<str.size())
    {
        hash ^= ((hash << 5) + str[i] + (hash >> 2));
        i++;
    }
 
    return (hash & 0x7FFFFFFF);
}
    
void permutation(int p, int len, string &s, set<int> &hash){
     if(p==len){
                int t = JSHash(s);
                if(hash.find(t)==hash.end()){
                                            cout << s << endl;
                                            hash.insert(t);
                }
                return;
     }
     
     for(int i = p; i <= len; i++)
             if(s[i]!=s[p]||i==p){
                            swap(s[i],s[p]);
                            permutation(p+1,len,s,hash);
                            swap(s[i],s[p]);
             }
}

int main(){
    int n;
    string s;
    cin >> n;
    while(n--){
               set<int> hash;
               cin >> s;
               sort(s.begin(),s.end(),cmp);
               int len = s.size();
               permutation(0,len-1,s,hash);
               /*do{
                                        cout << s << endl;
               }while(next_permutation(s.begin(),s.end(),cmp));*/
    }
}
