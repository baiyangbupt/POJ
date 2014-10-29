#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int m,n,st,adj[21][21];
int atoi(string s){
    stringstream ss;
    ss<<s;
    int res;
    ss>>res;
    return res;
}

int main(){
    string s;
    while(cin>>s&&s!="ENDOFINPUT"){
                                   memset(adj,0,sizeof(adj));
                                   cin >> st>> n;
                                   int edgenum = 0;
                                   cin.get();
                                   for(int u = 0; u < n; u++){
                                           getline(cin,s);
                                           string temp;
                                           for(int j = 0; j < s.size(); j++)
                                                   if(s[j]==' '&&temp.size()>0){
                                                              int v = atoi(temp);
                                                              temp.clear();
                                                              edgenum++;
                                                              adj[u][v]++;
                                                              adj[v][u]++;
                                                   }
                                                   else if(s[j]!=' ') temp.push_back(s[j]);
                                           if(temp.size()>0){
                                                             int v = atoi(temp);
                                                             edgenum++;
                                                             adj[u][v]++;
                                                             adj[v][u]++;
                                           }
                                   }
                                   cin>>s;
                                   bool valid = 1;
                                   if(st==0){
                                             for(int i = 0; i < n; i++){
                                                     int deg = 0;
                                                     for(int j = 0; j < n; j++)
                                                             deg+=adj[j][i];
                                                     if(deg%2){
                                                               valid=0;
                                                               break;
                                                     }
                                             }
                                   }
                                   else{
                                        for(int i = 0; i < n; i++){
                                                int deg = 0;
                                                for(int j = 0; j < n; j++)
                                                        deg+=adj[j][i];
                                                if(i==0||i==st){
                                                                if(deg%2==0){
                                                                             valid = 0;
                                                                             break;
                                                                }
                                                }
                                                else if(deg%2){
                                                     valid = 0;
                                                     break;
                                                }
                                        }
                                   }
                                   if(valid==0)
                                               cout << "NO" << endl;
                                   else
                                       cout << "YES " << edgenum << endl;
    }
}
    
