#include<iostream>
#define ll long long
using namespace std;

ll n,m,num[105][105];

ll gcd(ll a,ll b){
    if(a>b)
           return gcd(b,a);
    if(a==0)
            return b;
    return gcd(b%a,a);
}

ll query(ll a, ll b){
    if(num[a][b]>0)
                    return num[a][b];
    
    ll p = a;
    num[a][1] = a;
    for(ll i = 2; i <= b; i++){
            ll todivid = i, tomul = a-i+1;
            ll g = gcd(tomul,todivid);
            todivid/=g, tomul/=g;
            num[a][i] = num[a][i-1]/todivid*tomul;
    }
    return num[a][b];
}

int main(){
    memset(num,0,sizeof(num));
    while(cin>>n>>m&&(n||m)){
                             cout <<n << " things taken " << m<<" at a time is " << query(n,m) <<" exactly." << endl;
    }
}
    
