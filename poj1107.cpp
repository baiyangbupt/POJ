#include<iostream>
#include<string>
using namespace std;

void reverse(string &s){
     int i = 0, j = s.size()-1;
     while(i<j){
                swap(s[i],s[j]);
                i++,j--;
     }
}

void rightshift(string &s, int num){
     if(num==0) return;
     string res, a, b;
     reverse(s);
     a = s.substr(0,num);
     b = s.substr(num,s.size()-num+1);
     reverse(a);
     reverse(b);
     res.append(a);
     res.append(b);
     s = res;
}

int main(){
    string s;
    int k1,k2,k3;
    while(cin>>k1>>k2>>k3&&(k1||k2||k3)){
                           cin >> s;
                           string s1, s2, s3;
                           int len = s.size();
                           for(int i = 0; i < len; i++)
                                   if(s[i]<='i'&&s[i]>='a')
                                                           s1.push_back(s[i]);
                                   else if(s[i]>='j'&&s[i]<='r')
                                        s2.push_back(s[i]);
                                   else
                                       s3.push_back(s[i]);
                           if(k1>0&&s1.size()>0) k1 = k1%s1.size();
                           if(k2>0&&s2.size()>0) k2 = k2%s2.size();
                           if(k3>0&&s3.size()>0) k3 = k3%s3.size();
                           if(s1.size()>0) rightshift(s1,k1);
                           if(s2.size()>0) rightshift(s2,k2);
                           if(s3.size()>0) rightshift(s3,k3);
                           string res;
                           int i1=0,i2=0,i3=0;
                           for(int i = 0; i < len; i++)
                                   if(s[i]<='i'&&s[i]>='a')
                                                           res.push_back(s1[i1++]);
                                   else if(s[i]>='j'&&s[i]<='r')
                                        res.push_back(s2[i2++]);
                                   else
                                       res.push_back(s3[i3++]);
                           cout << res << endl;
    }
}
     
