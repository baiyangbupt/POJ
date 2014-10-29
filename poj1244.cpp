#include<iostream>
#include<vector>
using namespace std;

struct node{
       int x,y;
       node(int a, int b):x(a), y(b){}
};

int d[13][13][13][13],n;
void init(){
     int id = 1;
     for(int i = 1; i <= 12; i++)
             for(int j = i+1; j <= 12; j++)
                     d[12][i][12][j] = d[12][j][12][i] = j-i;
     
     for(int level = 11; level>=1; level--){
             for(int i = 1; i <=level; i++)
                     for(int j = i+1; j <= level; j++)
                             d[level][i][level][j] = d[level][j][level][i] = j-i;
             
             for(int num = 1; num <= level; num++)
                     for(int tolevel = level+1; tolevel<=12; tolevel++)
                             for(int tonum = 1; tonum <= tolevel; tonum++)
                                     if(tonum>=num&&tonum-num<=tolevel-level)
                                                                             d[level][num][tolevel][tonum] = d[tolevel][tonum][level][num] =  tolevel-level;
                                     else{
                                          d[tolevel][tonum][level][num] = d[level][num][tolevel][tonum] = min(d[tolevel][num][tolevel][tonum],d[tolevel][num+tolevel-level][tolevel][tonum])+tolevel-level;
                                     }
     }
}
void printd(){
    for(int i = 1; i <= 4; i++)
            for(int j = 1; j <= i; j++)
                    for(int k = 1; k <= 4; k++)
                            for(int m = 1; m <= k; m++)
                                    cout << i << " " <<j << " " << k << " " << m << " " << d[i][j][k][m] << endl;
}

int main(){
    init();
    while(cin>>n&&n){
                     char c;
                     bool res[26];
                     int cnt = 0;
                     memset(res,0,sizeof(res));
                     vector<node> v;
                     vector<vector<node> > vv(26,v);
                     for(int i = 1; i <= n; i++)
                             for(int j = 1; j <= i; j++){
                                     cin >> c;
                                     vv[c-'a'].push_back(node(i,j));
                             }
                     
                     for(int i = 0; i < 26; i++){
                             bool undo = 1;
                             for(int j = 0; j < vv[i].size()&&undo; j++)
                                     for(int k = j+1; k < vv[i].size()&&undo; k++)
                                             for(int l = k+1; l < vv[i].size()&&undo; l++){
                                                     int a1 = vv[i][j].x, a2 = vv[i][j].y, a3 = vv[i][k].x, a4 = vv[i][k].y, a5 = vv[i][l].x, a6 = vv[i][l].y;
                                                     if(d[a1][a2][a3][a4]==d[a1][a2][a5][a6]&&d[a3][a4][a5][a6]==d[a1][a2][a3][a4])
                                                                                                                   undo = 0;
                                             }
                             if(undo==0)
                                        res[i] = 1;
                     }
                     for(int i = 0; i < 26; i++)
                             if(res[i]){
                                        cnt++;
                                        cout << char('a'+i);
                             }
                     if(cnt==0)
                               cout << "LOOOOOOOOSER!";
                     cout << endl;
    }

}
    //while(cin>>n&&n){
