#include<iostream>
#include<algorithm>
#include<cmath>
#define eps 1e-12
using namespace std;

double a[4],target;

bool dfs(int p, double temp){
     //cout << temp << endl;
     if(p==4){
              if(fabs(temp-target)<eps)
                            return 1;
              return 0;
     }
     
     if(dfs(p+1,temp*a[p]))
                           return 1;
     if(dfs(p+1,temp+a[p]))
                           return 1;
     if(fabs(a[p])>eps&&dfs(p+1,temp/a[p]))
                           return 1;
     if(fabs(temp)>eps&&dfs(p+1,a[p]/temp))
                           return 1;
     if(dfs(p+1,a[p]-temp))
                           return 1;
     if(dfs(p+1,temp-a[p]))
                           return 1;
     return 0;
}

bool test(int p, double aa, double b){
     if(p==1)
              return fabs(aa*b-target)<eps||fabs(aa+b-target)<eps||fabs(aa-b-target)<eps||fabs(b-aa-target)<eps\
              ||aa!=0&&fabs(b/aa-target)<eps||b!=0&&fabs(aa/b-target)<eps;
     if(test(1,aa*a[1],b*a[2]))
                               return 1;
     if(test(1,aa*a[1],b+a[2]))
                               return 1;
     if(test(1,aa*a[1],b-a[2]))
                               return 1;
     if(fabs(a[2])>eps&&test(1,aa*a[1],b/a[2]))
                               return 1;
     if(test(1,aa+a[1],b*a[2]))
                               return 1;
     if(test(1,aa+a[1],b+a[2]))
                               return 1;
     if(test(1,aa+a[1],b-a[2]))
                               return 1;
     if(fabs(a[2])>eps&&test(1,aa+a[1],b/a[2]))
                               return 1;
     if(test(1,aa-a[1],b*a[2]))
                               return 1;
     if(test(1,aa-a[1],b+a[2]))
                               return 1;
     if(test(1,aa-a[1],b-a[2]))
                               return 1;
     if(fabs(a[2])>eps&&test(1,aa-a[1],b/a[2]))
                               return 1;
     if(fabs(a[1])>eps){
                 if(test(1,aa/a[1],b*a[2]))
                               return 1;
                 if(test(1,aa/a[1],b+a[2]))
                               return 1;
                 if(test(1,aa/a[1],b-a[2]))
                               return 1;
                 if(fabs(a[2])>eps&&test(1,aa/a[1],b/a[2]))
                               return 1;
     }
     return 0;
}

int main(){ 
    while(cin>>a[0]&&a[0]!=-1){
                               bool get =0;
                               cin >> a[1] >> a[2] >> a[3] >> target;
                               cout << a[0] <<' '<< a[1]<<' ' << a[2]<<' ' << a[3]<<' ' << target<<' ';
                               do{
                                   if(dfs(1,a[0])||test(2,a[0],a[3])){
                                                   get = 1;
                                                   break;
                                   }
                               }while(next_permutation(a,a+4));
                               if(get)
                                      cout <<"OK!" << endl;
                               else
                                   cout << "NO!" << endl;
    }
}

