#include<iostream>
#include<vector>
using namespace std;
 
void reverse(vector<int> &v){
     int i = 0, j = v.size()-1;
     while(i<j){
                swap(v[i],v[j]);
                i++, j--;
     }
}

vector<int> multi(vector<int> &v1, vector<int> &v2){
            vector<int> res(v1.size()+v2.size()-1,0);
            
            //cout << v1.size() << " " << v2.size() <<" " <<res.size() << endl;
            reverse(v1), reverse(v2);
            for(int i = 0; i<v1.size(); i++)
                    for(int j = 0; j<v2.size(); j++){
                            //cout << i << " " << j << " " << v1[i] << " " << v2[j] << endl;
                            res[i+j] += v1[i]*v2[j];
                    }
            for(int i = 0; i < res.size(); i++) res[i] = res[i]%2;
            reverse(res);
            return res;
}



vector<int> modu(vector<int> &v1, vector<int> &v2){
            if(v1.size()<v2.size()) return v1;
            if(v1.size()==v2.size()){
                                     int i = 0;
                                     while(i<v1.size()&&v1[i]==v2[i]) i++;
                                     if(i==v1.size()) return vector<int>(1,0);
                                     if(v1[i]<v2[i]) return v1;
            }
            
            int k = 0;
            while(k<=v1.size()-v2.size()){
                                         for(int j = k; j < k+v2.size(); j++){
                                                 //cout << v1[j] << " " << v2[j-k]<< " ";
                                                 v1[j] = v1[j]^v2[j-k];
                                                 //cout << v1[j] << endl;
                                         }
                                         //cout << endl;
                                         while(v1[k]==0) k++;
            }
            
            
            vector<int> res;
            int i = 0;
            while(i<v1.size()&&v1[i]==0) i++;
            if(i==v1.size()) res.push_back(0);
            else
                 while(i<v1.size()) res.push_back(v1[i]), i++;
            
            return res;
}

void print(vector<int> &v){
     cout << v.size();
     for(int i = 0; i < v.size(); i++)
             cout << " " << v[i];
     cout << endl;
}

int main(){
           int n,m,l,nc;
           cin >> nc;
           while(nc--){
                       cin >> n;
                       vector<int> v1(n,0);
                       for(int i = 0; i < n; i++) cin >> v1[i];
                       cin >> m;
                       vector<int> v2(m,0);
                       for(int i = 0; i < m; i++) cin >> v2[i];
                       cin >> l;
                       vector<int> v3(l,0);
                       for(int i = 0; i < l; i++) cin >> v3[i];
                       vector<int> mul = multi(v1,v2), res;
                       res = modu(mul, v3);
                       print(res);
           }
           
}
 
