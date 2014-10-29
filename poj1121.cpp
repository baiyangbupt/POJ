#include<iostream>
#include<string>
#include<vector>
using namespace std;

int n,adj[55][55],stock[55][26],visit[55];


void print(){
     for(int i = 1; i <= n; i++){
             for(int j = 0; j < 26; j++)
                     if(stock[i][j]==1) cout << char('A'+j);
             cout << endl;
     }
}

void inversedfs(int p){
     visit[p] = 1;
     
     bool instock[30];
     memset(instock,0,sizeof(instock));
     for(int i = 1; i <= n; i++)
             if(adj[i][p]){
                           if(visit[i]==0) inversedfs(i);
                           for(int j = 0; j < 26; j++)
                                   if(stock[i][j]==1)
                                                     instock[j] = 1;
             }
     for(int i = 0; i < 26; i++)
             if(instock[i]&&stock[p][i]!=-1)
                                            stock[p][i] = 1;
     //cout << p << endl;
     //print();
     //cout << endl;
     return;
}
                           

int main(){
    memset(adj,0,sizeof(adj));
    memset(visit,0,sizeof(visit));
    memset(stock,0,sizeof(stock));
    cin >> n;
    string a,b;
    for(int i = 1; i <= n; i++){
            cin >> a >> b;
            for(int j = 0; j < a.size(); j++)
                    if(a[j]!='.')
                                 stock[i][a[j]-'A'] = 1;
            for(int j = 0; j < b.size(); j++)
                    if(b[j]!='.')
                                 stock[i][b[j]-'A'] = -1;
    }
    int i1,i2;
    while(cin>>i1>>i2&&i1)
                           adj[i1][i2] = 1;
    vector<int> src;
    for(int i = 1; i <= n; i++)
            if(visit[i]==0)
                           inversedfs(i);
    for(int i = 1; i <= n; i++){
            cout << ":";
            for(int j = 0; j < 26; j++)
                    if(stock[i][j]==1)
                                   cout << char('A'+j);
            cout << ":";
            cout << endl;
    }
    system("pause");
}
