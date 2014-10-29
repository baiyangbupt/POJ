#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int atoi(string s){
    int res;
    stringstream ss;
    ss<<s;
    ss>>res;
    return res;
}

int get[3];
int dp[40],newborn[40];

int main(){
    string s;
    while(cin>>s&&s!="-1"){
                           string temp;
                           int cnt = 0;
                           for(int i = 0; i < s.size(); i++)
                                   if(s[i]==','){
                                                 get[cnt++] = atoi(temp);
                                                 temp.clear();
                                   }
                                   else
                                       temp.push_back(s[i]);
                           get[cnt++] = atoi(temp);
                           memset(dp,0,sizeof(dp));
                           memset(newborn,0,sizeof(newborn));
                           dp[0] = newborn[0] = 0,dp[1] = newborn[1] = 1;
                           for(int i = 2; i <= get[2]; i++){
                                   if(i>get[0])
                                          dp[i] = dp[i-1] - newborn[i-get[0]];
                                   else
                                       dp[i] = dp[i-1];
                                   int temp = 0;
                                   if(i>=7)
                                           temp+=newborn[i-6];
                                   if(i>=8)
                                           temp+=newborn[i-7];
                                   for(int j = 1; j <= get[1]; j++){
                                           if(i>=9+j-1)
                                                       temp += 2*newborn[i-9-j+2];
                                           else
                                               break;
                                   }
                                   if(dp[i]>100)
                                               newborn[i] = 0;
                                   else
                                       newborn[i] = temp, dp[i] += temp;
                           }
                           cout <<s << ": " << dp[get[2]] << endl;
    }
}
