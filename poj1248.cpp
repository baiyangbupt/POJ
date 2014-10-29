#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int a[12];

bool valid(int a, int b, int c, int d, int e){
     return a!=b&&a!=c&&a!=d&&a!=e&&b!=c&&b!=d&&b!=e&&c!=d&&c!=e&&d!=e;
}

int main(){
    int target,v,w,x,y,z;
    string s;
    while(cin>>target&&target){
                               cin >> s;
                               int n = s.size();
                               sort(s.begin(),s.end());
                               bool undo = 1;
                               for(int i = n-1; i >= 0 && undo; i--)
                                       for(int j = n-1; j >= 0 && undo; j--)
                                               for(int k = n-1; k >= 0 && undo; k--)
                                                       for(int l = n-1; l >= 0 && undo; l--)
                                                               for(int m = n-1; m >= 0 && undo; m--)
                                                                       if(valid(i,j,k,l,m)){
                                                                                            v = s[i]-'A'+1, w = s[j]-'A'+1, x = s[k]-'A'+1, y = s[l]-'A'+1, z = s[m]-'A'+1;
                                                                                            if(v-w*w+x*x*x-y*y*y*y+z*z*z*z*z==target)
                                                                                                                                     undo = 0;
                                                                       }
                               if(undo==0)
                                       cout << char(v-1+'A') << char(w-1+'A')<<char(x-1+'A') << char(y-1+'A') << char(z-1+'A') << endl;
                               else
                                   cout << "no solution" << endl;
    }
}
                                                                       
