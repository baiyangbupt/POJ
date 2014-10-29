#include<iostream>
using namespace std;

int n,a[1001],t,label[1001];

int chk(int p){
    memset(label,0,sizeof(label));
    int res = 0, pre = (p-1+n)%n, post = (p+1)%n;
    label[p] = 1;
    int i = p, cycle = 0;
    while(a[i]==0){
                   cycle = 1;
                   i = (i+1)%n;
                   label[i] = 1;
                   if(i==p)
                           break;
    }
    if(cycle&&i==p)
            return 0;
    i = (i+1)%n;
    if(label[i]>0) 
                   return 1;
    label[i] = -1, res++;
    if(a[pre]==1){
                  if(label[pre]>0)
                                  return 1;
                  if(label[pre]==0)
                                   label[pre] = -1,res++;
                  pre = (pre+n-1)%n;
                  while(a[pre]==0){
                     if(label[pre]>0)
                                     return 1;
                     if(label[pre]==0)
                                      label[pre] = -1, res++;
                     pre = (pre+n-1)%n;
                  }
    }
    
    if(res>t)
             return 1;
    return 0;
}
                  
    
int main(){
    int nc;
    cin >> nc;
    while(nc--){
                cin >> n >> t;
                for(int i = 0; i < n; i++)
                        cin >> a[i];
                int first = -1, num = 0;
                for(int i = 0; i < n; i++){
                        if(chk(i)){
                                   if(first==-1)
                                                first = i+1;
                                   num++;
                        }
                }
                if(first==-1)
                             cout << "0 0" << endl;
                else
                    cout << num << " " << first << endl;
    }
}
