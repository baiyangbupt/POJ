#include<iostream>
#include<vector>
#include<string>
using namespace std;

string name[6],dict[3] = {"pretty", "beautiful", "lovely"};
int g,w;
bool hasname[6];

bool issep(char c){
     return c==' '||c=='!';
}

void solve(string &wish){
     memset(hasname,0,sizeof(hasname));
     
     bool praise = 0, muchword = 0;
     vector<string> specified;
     int wordcount = 0;
     string temp;
     for(int i = 0; i < wish.size(); i++)
             if(issep(wish[i])&&temp.size()>0){
                                               if(temp[0]<'a')
                                                              temp[0]+='a'-'A';
                                                              
                                               for(int j = 0; j < g; j++)
                                                       if(temp==name[j]){
                                                                         hasname[j] = 1;
                                                                         break;
                                                       }
                                               if(praise==0){
                                                           for(int j = 0; j < 3; j++)
                                                                   if(temp==dict[j]){
                                                                                     praise = 1;
                                                                                     break;
                                                                   }
                                               }
                                               temp.clear();
                                               wordcount++;
             }
             else if(0==issep(wish[i]))
                  temp.push_back(wish[i]);
     
     if(temp.size()>0){
                       if(temp[0]<'a')
                                      temp[0]+='a'-'A';
                                      
                       for(int j = 0; j < g; j++)
                               if(temp==name[j]){
                                                 hasname[j] = 1;
                                                 break;
                               }
                       if(praise==0){
                                   for(int j = 0; j < 3; j++)
                                           if(temp==dict[j]){
                                                             praise = 1;
                                                             break;
                                           }
                       }
                       temp.clear();
                       wordcount++;
     }
     
     for(int i = 0; i < g; i++)
             if(hasname[i])
                           specified.push_back(name[i]);
             
     if(specified.size()>0){
                            cout << specified[0];
                            for(int i = 1; i < specified.size(); i++)
                                    cout << ' '<< specified[i];
     }
     else
         cout << "All";
     cout << ':';
     
     if(wordcount<=9)
                     cout << " oh" << endl;
     else if(praise)
          cout << " xixi" << endl;
     else
         cout << " hehe" << endl;
}
                                                                      

int main(){
    cin >> g >> w;
    for(int i = 0; i < g; i++)
            cin >> name[i];
    
    string wish;
    cin.get();
    for(int i = 0; i < w; i++){
            getline(cin,wish);
            solve(wish);
    }
    system("pause");
}
