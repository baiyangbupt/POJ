#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(const int &a, const int &b){
     return a>b;
}

int col[100];

int nc, s[20], n, ts, area;
bool suc,used[100];

bool dfs(int fillnum){
     if(fillnum==0) return 1;
     int c = 1, mincol = 10000;
     for(int i = 1; i <= ts; i++)
             if(col[i]<mincol){
                               c = i;
                               mincol = col[i];
             }
     
     for(int i = 10; i >= 1; i--)
             if(s[i]>0){
                            int width = 0;
                            if(col[c]+i>ts||c+i-1>ts)  continue;
                            for(int j = c; j <= c+i-1; j++){
                                    if(col[j]<=col[c]){
                                                       width++;
                                                       continue;
                                    }
                                    break;
                            }
                            if(width>=i){
                                            for(int j = c; j < c+i; j++)
                                                    col[j]+=i;
                                            s[i]--;
                                            if(dfs(fillnum-1)) return 1;
                                            for(int j = c; j < c+i; j++)
                                                    col[j]-=i;
                                            s[i]++;
                            }
             }
     return 0;
}
                            

int main(){
    cin >> nc;
    while(nc--){
                memset(col,0,sizeof(col));
                memset(s,0,sizeof(s));
                int cnt = 0, tt;
                cin >> ts >> n;
                area = ts*ts;
                for(int i = 1; i<=n; i++) {
                        cin >> tt;
                        s[tt]++;
                        if(tt*2>ts) cnt++;
                        area -= tt*tt;
                }
                if(area!=0||cnt>1){
                            cout << "HUTUTU!" << endl;
                            continue;
                }
                
                if(dfs(n))
                                                cout << "KHOOOOB!" << endl;
                else 
                     cout <<"HUTUTU!" << endl;
    }
}
