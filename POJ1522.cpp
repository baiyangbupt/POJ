//
//  main.cpp
//  POJ1522
//
//  Created by B-YMac on 14-8-9.
//  Copyright (c) 2014年 B-YMac. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAX = 49919;

struct node{
    int v, next;
}ee[MAX];

int cnt, n,firstedge[MAX+5], st, ed;
bool visit[MAX+5];


void add(int a, int b){
    ee[cnt].v = b;
    ee[cnt].next = firstedge[a];
    firstedge[a] = cnt++;
    
    ee[cnt].v = a;
    ee[cnt].next = firstedge[b];
    firstedge[b] = cnt++;
}

bool dfs(int p){
    if(visit[p])
        return 0;
    
    if(p==ed)
        return 1;
    visit[p] = 1;
    for(int i = firstedge[p]; i!=-1; i= ee[i].next){
        int v = ee[i].v;
        if(dfs(v))
            return 1;
    }
    
    return 0;
}

int main(int argc, const char * argv[])
{
    int nc = 1;
    while(cin>>n, n){
        cnt = 0;
        memset(firstedge,-1,sizeof(firstedge));
        memset(visit,0,sizeof(visit));
        st = ed = 0;
        for(int i = 0; i < n; i++){
            int t;
            cin >> t;
            st = st*10+t;
            st %= MAX;
        }
        for(int i = 0; i < n; i++){
            int t;
            cin >> t;
            ed = ed*10+t;
            ed %= MAX;
        }
        
        while(1){
            int t, tst = 0,ted = 0;
            cin >> t;
            if(t==-1)
                break;
            for(int i = 1; i < n; i++){
                cin >> t;
                tst = tst*10+t;
                tst %= MAX;
            }
            
            for(int i = 0; i < n; i++){
                cin >> t;
                ted = ted*10+t;
                ted %= MAX;
            }
            
            add(tst,ted);
        }
        
        
        
        bool reach = dfs(st);
        cout << "Maze #" << nc++ << " ";
        if(reach)
            cout << "can be travelled" << endl;
        else
            cout << "cannot be travelled" << endl;

        
    }
    return 0;
}

