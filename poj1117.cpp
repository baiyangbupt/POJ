#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
       string a,b;
       node(string x, string y):a(x), b(y){}
};

string reverse(string s){
     string res = s;
     int i = 0, j = s.size()-1;
     while(i<j){
                swap(res[i],res[j]);
                i++,j--;
     }
     return res;
}

string n,a,b;
vector<node> v;

bool operator<(const node &x, const node &y){
     if(x.a.size()==y.a.size())
                               return x.a<y.a;
     return x.a.size()<y.a.size();
}

void dfs(int p, int dif, int jinwei){
     //cout << p << endl;
     if(p==n.size()-1){
                       if(dif){
                               if(n[p]=='1'&&jinwei){
                                                     //cout << reverse(a) <<" " << reverse(b) << endl;
                                                     if(a[p-1]=='0'||b[p-1]!='0') return;
                                                     string aa = a, bb = b;
                                                     bb.erase(bb.end()-1);
                                                     aa = reverse(aa), bb = reverse(bb);
                                                     int i=0,zeros = 0;
                                                     while(i<bb.size()&&bb[i]=='0') zeros++,i++;
                                                     /*if(zeros<=1)*/ v.push_back(node(aa,bb));
                               }     
                               else if(n[p]-jinwei==b[p-1]){
                                                a.push_back(n[p]-jinwei);
                                                string aa = reverse(a), bb = reverse(b);
                                                int i=0,zeros = 0;
                                                while(i<bb.size()&&bb[i]=='0') zeros++,i++;
                                                /*if(zeros<=1)*/ v.push_back(node(aa,bb));
                                                a.erase(a.end()-1);
                               }
                       }
                       else if(n[p]-jinwei!='0'){
                            a.push_back(n[p]-jinwei);
                            if(a.size()==n.size()){
                                                   string aa = reverse(a), bb = reverse(b);
                                                   int i=0,zeros = 0;
                                                   while(i<bb.size()&&bb[i]=='0') zeros++,i++;
                                                   /*if(zeros<=1)*/v.push_back(node(aa,bb));
                                                   a.erase(a.end()-1);
                            }
                       }
                       
                       return;
     }
     
     if(dif==0){
                for(char c = '0'; c <= '9'; c++)
                         if(n[p]-jinwei>=c){
                                            a.push_back(c);
                                            b.push_back(n[p]-jinwei-c+'0');
                                            if(a[p]==b[p]) dfs(p+1,0,0);
                                            else dfs(p+1,1,0);
                                            a.erase(a.end()-1);
                                            b.erase(b.end()-1);
                         }
                         else{
                              a.push_back(c);
                              b.push_back(n[p]-jinwei+10-c+'0');
                              if(a[p]==b[p]) dfs(p+1,0,1);
                              else dfs(p+1,1,1);
                              a.erase(a.end()-1);
                              b.erase(b.end()-1);
                         }
     }
     else{
          a.push_back(b[p-1]);
          //cout << a[p] << " " << b[p-1] << endl;
          if(n[p]-jinwei>=a[p]){
                               b.push_back(n[p]-jinwei-a[p]+'0');
                               dfs(p+1,1,0);
          }
          else{
               b.push_back(n[p]-jinwei+10-a[p]+'0');
               dfs(p+1,1,1);
          }
          a.erase(a.end()-1), b.erase(b.end()-1);
     }
          
}

int main(){
    string m;
    cin >> m;
    n = reverse(m);
    dfs(0,0,0);
    sort(v.begin(),v.end());
    int mm = min(int(v.size()),1);
    for(int i = 1; i < v.size(); i++)
            if(v[i].a!=v[i-1].a||v[i].b!=v[i-1].b)
                                                  v[mm++] = v[i];
    cout << mm << endl;
    for(int i = 0; i < mm; i++)
            cout << v[i].a << " + " << v[i].b <<" = " << m<< endl;
            
    system("pause");
}
