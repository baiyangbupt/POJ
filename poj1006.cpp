#include<iostream>
using namespace std;

int main(){
    int a[3] = {23, 28, 33}, total = 1;
    int m[3],t[3];
    for(int i = 0; i< 3; i++) m[i] = a[(i+1)%3]*a[(i+2)%3], total*=a[i];
    for(int i = 0; i < 3; i++){
            t[i] = 1;
            while(t[i]*m[i]%a[i]!=1) t[i]++;
            //cout << t[i] << endl;
    }
    int x[4],count = 1;
    while(cin>>x[0]>>x[1]>>x[2]>>x[3]){
                                        if(x[0]==-1&&x[1]==-1&&x[2]==-1&&x[3]==-1) break;
                                        int sum=0;
                                        for(int i = 0; i < 3; i++) sum+=x[i]*t[i]*m[i];
                                        sum%=total;
                                        while(sum<=x[3]) sum+=total;
                                        sum-=x[3];
                                        cout  <<"Case " << count << ": the next triple peak occurs in " << sum <<" days."<< endl;
                                        count++;
    }
    system("pause");
}
