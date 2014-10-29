#include<iostream>
#include<stack>
using namespace std;

bool instack[1001];
int n,a[1000];

int main(){
    while(cin>>n&&n){
                     while(cin >> a[0]&&a[0]){
                             for(int i = 1; i < n; i++)
                                     cin >> a[i];
                             
                             int id = 1;
                             stack<int> s;
                             bool valid = 1;
                             memset(instack,0,sizeof(instack));
                             for(int i = 0; i < n; i++){
                                     if(instack[a[i]]){
                                                       int t = s.top();
                                                       s.pop();
                                                       instack[t] = 0;
                                                       if(t!=a[i]){
                                                                   valid = 0;
                                                                   break;
                                                       }
                                     }
                                     else{
                                          if(id>a[i]){
                                                      valid = 0;
                                                      break;
                                          }
                                          while(id!=a[i]){
                                                          s.push(id);
                                                          instack[id] = 1;
                                                          id++;
                                          }
                                          id++;
                                     }
                             }
                             if(valid)
                                      cout << "Yes" << endl;
                             else 
                                  cout << "No" << endl;
                     }
                             cout << endl;
    }
}
                                               
