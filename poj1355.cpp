#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int n,m;
string id[50], name[50], dep[50];
int score[50], vote[50], vode[50][10];

map<string,int> code;

struct node{
       string num, name, depart;
       int score,vote,vode[10];
       node(int a, int b, string c, string d, string e) : score(a), vote(b), num(c), name(d),depart(e){}
};

bool operator<(const node &a, const node &b){
     if(a.score==b.score){
                          if(a.vote==b.vote)
                                            return a.num < b.num;
                          return a.vote>b.vote;
     }
     return a.score > b.score;
}

int bench[10] = {15     ,12,     9   ,  7 ,    6 ,    5    ,   4  ,    3 ,    2   , 1};

int main(){
    while(cin>> n&&n!=-1){
                code.clear();
                code["00"] = 0;
                cin >> m;
                string num,nam,depa;
                for(int i = 0; i < n; i++){
                        cin >> num >> nam >> depa;
                        id[i] = num, name[i]= nam, dep[i] = depa;
                        code[num] = i;
                }
                memset(score,0,sizeof(score));
                memset(vote,0,sizeof(vote));
                memset(vode,0,sizeof(vode));
                string s;
                for(int i = 0; i < m; i++){
                        cin >> s;
                        bool valid = 1;
                        for(int j = 0; j < 10; j++){
                                string tovote = s.substr(2*j,2);
                                if(code.find(tovote)==code.end()){
                                                                  valid = 0;
                                                                  break;
                                }
                                bool repeat = 0;
                                for(int k = j+1; k < 10; k++)
                                        if(k!=j&&tovote==s.substr(2*k,2)&&tovote!="00"){
                                                                          repeat = 1;
                                                                          break;
                                        }
                                if(repeat){
                                           valid = 0;
                                           break;
                                }
                        }
                        if(valid==0)
                                    continue;
                        for(int j = 0; j < 10; j++){
                                string tovote = s.substr(2*j,2);
                                if(tovote=="00")
                                                continue;
                                int tv = code[tovote];
                                score[tv]+=bench[j];
                                vote[tv]++;
                                vode[tv][j]++;
                        }
                }
                vector<node> vv;
                for(int i = 0; i < n; i++){
                        node nn(score[i],vote[i],id[i],name[i],dep[i]);
                        for(int j = 0; j < 10; j++)
                                nn.vode[j] = vode[i][j];
                        vv.push_back(nn);
                }
                sort(vv.begin(),vv.end());
                for(int i = 0; i < n; i++){
                        printf("%-2d  %02d  %-15s%-37s%6d%6d", i+1, vv[i].num, vv[i].name, vv[i].depart, vv[i].score, vv[i].vote);
                        //cout << i+1 <<' ' << vv[i].num<<' ' << vv[i].name << ' ' << vv[i].depart << ' ' <<vv[i].score<< ' '<< vv[i].vote;
                        for(int j = 0; j < 10; j++)
                                printf("%6d", vv[i].vode[j]);
                        cout << endl;
                }
    }
}
                        
                        
