#include<iostream>
#include<queue>
using namespace std;

int m,n,r,c;
int a[250][250], sum[250][250];

double getmost(int *a, int len, int lines, int &st, int &ed){
    int s = 0, ii = 0;
    double res;
    queue<int> q;
    for(int i =0; i < c; i++)
            res+=a[i], s+=a[i], q.push(a[i]);
    
    res = s/(c*lines*1.0);
    st = 0, ed = c-1;
    for(int i = c; i < len; i++){
            int t = a[i];
            q.push(a[i]);
            int l = q.size();
            s+=t;
            if(s/(lines*l*1.0)>res)
                             res = s/(lines*l*1.0), st = i-l+1, ed = i;
            while(q.size()>=c&&t>=q.front()){
                                             s-=q.front();
                                             l--;
                                             q.pop();
                                             if(s/(lines*l*1.0)>res)
                                                              res = s/(lines*l*1.0), st = i-l+1, ed = i;
            }
    }
    return res;
}
    

int main(){
    while(cin>>m&&m){
                     cin >> n >> r  >> c;
                     for(int i = 0; i < m; i++)
                             for(int j = 0; j < n; j++)
                                     cin >> a[i][j];
                     for(int i = 0; i < n; i++)
                             sum[0][i]=  a[0][i];
                     for(int i = 1; i < m; i++)
                             for(int j = 0; j < n; j++)
                                     sum[i][j] = a[i][j]+sum[i-1][j];
                     double res = 0;
                     int str, stc, edr, edc;
                     for(int baseline = 0; baseline+r-1<m; baseline++){
                             if(baseline>0){
                                            for(int i = baseline; i < m; i++)
                                                    for(int j = 0; j < n; j++)
                                                            sum[i][j]-=a[baseline-1][j];
                             }
                             int st,ed;
                             for(int endline = baseline+r-1; endline<m; endline++){
                                     double t = getmost(sum[endline],n,endline-baseline+1,st,ed);
                                     //cout <<baseline << ' ' << endline << ' ' << st << ' ' << ed << ' '<<t << endl;
                                     if(res<t){
                                               res = t;
                                               str = baseline, stc = st, edr = endline, edc = ed;
                                     }
                             }
                     }
                     cout << str+1 << ' ' << stc+1 << ' '  << edr+1 << ' '<< edc+1 << endl;
           }
           cout << '*' << endl;
}
