#include<iostream>
#include<stack>

using namespace std;
bool ocupy[10001],set[10001];
int des[10001],origin[10001],mov;

void operation(int from, int to){
     ocupy[from] = 0;
     ocupy[to] = 1;
     mov++;
}

int main(){
    int n,k,m,num = 1,q;
    cin >> n >> k;
    for(int i = 1; i <= k; i++) {
            cin >> m;
            for(int j = 1; j <= m; j++){
                    cin >> q;
                    ocupy[q] = 1;
                    origin[num] = q;
                    des[q] = num++;
            }
    }
    
    for(int i = 1;  i<num; i++)
            if(set[origin[i]]==0&&des[origin[i]]!=origin[i]){
                stack<int> s;
                int h = origin[i], d = des[h];
                s.push(h);
                while(ocupy[d]&&d!=h) s.push(d), set[d] = 1, d = des[d];
                if(ocupy[d]==0){
                                if(s.empty()){
                                              operation(h,d);
                                              cout << h << " " << d << endl;
                                }
                                else{
                                     while(!s.empty()){
                                                       cout << s.top() << " " << d << endl;
                                                       operation(s.top(),d);
                                                       d = s.top();
                                                       s.pop();
                                     }
                                }
                }
                else{
                     int emp;
                     for(emp = n; emp>=1; emp--)
                             if(ocupy[emp]==0)
                                              break;
                     cout << d << " " << emp << endl;
                     while(s.size()>1){
                                       cout << s.top() << " "  << d << endl;
                                       d = s.top();
                                       s.pop();
                     }
                     cout << emp <<" " << d << endl;
                }
    }
    if(mov==0) cout << "No optimization needed" << endl;
    system("pause");
}
    
    
