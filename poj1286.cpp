#include<iostream>
using namespace std;

int n;
bool visit[100];

long long power(int e){
    long long res = 3;
    for(int i = 1; i < e; i++)
            res *= 3;
    return res;
}

long long transf(){
     if(n==0) return 0;
    long long add = power(n),mapnum = n;
    for(int d = 1; d < n; d++){
        memset(visit,0,sizeof(visit));
        int res = 0, cnt = 0;
        while(cnt<n){
                     int st = 0;
                     while(visit[st]) st++;
                     
                     while(visit[st]==0)
                                        visit[st] = 1, cnt++, st = (st+d)%n;
                     res++;
        }
        
        add += power(res);
    }
    //cout << add << endl;
    if(n%2){
            int t = power((n+1)/2);
            add += n*t;
            mapnum += n;
    }
    else{
         int t = power((n+1)/2);
         add += n/2*t+n/2*power(n/2+1);
         mapnum += n;
    }
    
    //cout << add << " " << mapnum << endl;
    //add += power((n+1)/2);
    return add/mapnum;
}
    

int main(){
    while(cin>>n&&n!=-1){
                  cout << transf() << endl;
    }
}
     
