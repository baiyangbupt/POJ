#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool dp[300][300];


int main(){
    int nc;
    cin >> nc;
    while(nc--){
                vector<string> p1,p2;
                memset(dp,0,sizeof(dp));
                string s1,s2;
                cin >> s1 >> s2;
                string temp;
                for(int i = 0; i < s1.size(); i++)
                        if(s1[i]=='*'){
                                       p1.push_back("?");
                                       p1.push_back("*");
                        }
                        else if(s1[i]=='?'){
                             p1.push_back("?");
                             p1.push_back("!");
                             p1.push_back("!");
                        }
                        else if(s1[i]=='!'){
                             p1.push_back("?"), p1.push_back("?"), p1.push_back("?"), p1.push_back("*");
                        }
                        else if(s1[i]=='.'){
                             if(temp.size()>0)
                                              p1.push_back(temp), temp.clear();
                        }
                        else
                            temp.push_back(s1[i]);
                if(temp.size()>0)
                                 p1.push_back(temp), temp.clear();    
                for(int i = 0; i < s2.size(); i++)
                        if(s2[i]=='*'){
                                       p2.push_back("?");
                                       p2.push_back("*");
                        }
                        else if(s2[i]=='?'){
                             p2.push_back("?");
                             p2.push_back("!");
                             p2.push_back("!");
                        }
                        else if(s2[i]=='!'){
                             p2.push_back("?"), p2.push_back("?"), p2.push_back("?"), p2.push_back("*");
                        }
                        else if(s2[i]=='.'){
                             if(temp.size()>0)
                                              p2.push_back(temp), temp.clear();
                        }
                        else
                            temp.push_back(s2[i]);
                if(temp.size()>0)
                                 p2.push_back(temp), temp.clear();
                
                /*for(int i = 0; i < p1.size(); i++)
                        cout << p1[i] << "  ";
                cout << endl;
                for(int i = 0; i < p2.size(); i++)
                        cout << p2[i] << " ";
                cout << endl;*/
                int l1 = p1.size(), l2 = p2.size();
                dp[0][0] = 1;
                for(int i = 1; i <= l1; i++){
                        for(int j = 1; j <= l2; j++){
                                if(p1[i-1]!="*"&&p2[j-1]!="*"&&p1[i-1]!="!"&&p2[j-1]!="!"&&p1[i-1]!="?"&&p2[j-1]!="?"){
                                                                                                           if(p1[i-1]==p2[j-1])
                                                                                                                           dp[i][j] = dp[i-1][j-1];
                                                                                                           else
                                                                                                               dp[i][j] = 0;
                                }
                                if(p1[i-1]=="*")
                                              dp[i][j] = dp[i][j]||dp[i][j-1]||dp[i-1][j];
                                if(p1[i-1]=="!")
                                              dp[i][j] = dp[i][j]||dp[i-1][j]||dp[i-1][j-1];
                                if(p1[i-1]=="?")
                                                dp[i][j] = dp[i][j]||dp[i-1][j-1];
                                if(p2[j-1]=="*")
                                                dp[i][j] = dp[i][j]||dp[i][j-1]||dp[i-1][j];
                                if(p2[j-1]=="!")
                                                dp[i][j] = dp[i][j]||dp[i][j-1]||dp[i-1][j-1];
                                if(p2[j-1]=="?")
                                                dp[i][j] = dp[i][j]||dp[i-1][j-1];
                        }
                }
                if(dp[l1][l2])
                               cout << "YES" << endl;
                else cout << "NO" << endl;
    }
}
                                
