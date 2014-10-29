#include<iostream>
#include<string>
#include<vector>
using namespace std;

unsigned int base[33];

void init(){
     base[0] = 1;
     unsigned int  ba = 2;
     for(int i = 1; i < 33; i++){
             ba <<= 1;
             base[i] = ba-1;
     }
}

int main(){
    int nc;
    init();
    cin >> nc;
    while(nc--){
                vector<int> res;
                int x;
                cin >> x;
                cout << x << ' ' << '[';
                if(x==0){
                        cout << ']' << endl;
                        continue;
                }
                for(int i = 32; i >= 0; i--){
                        if(x==base[i]*2){
                                         res.push_back(i), res.push_back(i);
                                         break;
                        }
                        else if(x==base[i]){
                             res.push_back(i);
                             break;
                        }
                        else if(x>base[i]){
                             res.push_back(i);
                             x -=base[i];
                        }
                }
                cout << res[res.size()-1];
                for(int i = res.size()-2; i>=0; i--)
                        cout << ',' << res[i];
                cout << ']' << endl;
    }
}
                                         
                
