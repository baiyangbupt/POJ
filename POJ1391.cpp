//
//  main.cpp
//  POJ1391
//
//  Created by B-YMac on 14-7-6.
//  Copyright (c) 2014年 B-YMac. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include<map>
#include<queue>
using namespace std;

int p,n,cnt,au[10000],d[10000];
bool adj[10000][10000],visit[10000];

struct node{
    char c[40];
    node(char *p){
        strcpy(c,p);
    }
};

bool operator<(const node &a, const node &b){
    return strcmp(a.c,b.c)<0;
}

map<node, int> mp;

void bfs(){
    memset(d,-1,sizeof(d));
    memset(visit,0,sizeof(visit));
    int st = mp[node("Erdos, P.")];
    d[st] = 0;
    queue<int> qn, ql;
    qn.push(st), ql.push(0);
    while(!qn.empty()){
        int id = qn.front(), l = ql.front();
        qn.pop(), ql.pop();
        if(visit[id]) continue;
        
        visit[id] = 1;
        d[id] = l;
        for(int i = 0; i < cnt; i++)
            if(adj[id][i]){
                qn.push(i), ql.push(l+1);
            }
    }
}

int main(int argc, const char * argv[])
{
    int nc = 1;
    while(scanf("%d%d", &p, &n)&&p){
        mp.clear();
        memset(adj,0,sizeof(adj));
        cnt = 0;
        for(int i = 0; i < p; i++){
            char first[40], last[40], paper[250];
            int num = 0;
            while(scanf("%s %s", first, last)){
                int t,l1 = strlen(first), l2 = strlen(last);
                bool stepover = last[l2-1]==':';
                last[l2-1] = '\0';
                first[l1] = ' ', first[l1+1] = '\0';
                strcat(first, last);
                node temp(first);
                if(mp.find(temp)==mp.end())
                    mp[temp] = t = cnt++;
                else
                    t = mp[temp];
                au[num++] = t;
                
                if(stepover)
                    break;
            }
            
            for(int i = 0; i < num; i++)
                for(int j = i+1; j < num; j++)
                    adj[au[i]][au[j]] = adj[au[j]][au[i]] = 1;
            gets(paper);
        }
        
        bfs();
        cout << "Database #" << nc++ << endl;
        
        for(int i = 0; i < n; i++){
            char first[40], last[40];
            scanf("%s %s",first, last);
            int l1 = strlen(first);
            first[l1] = ' ';
            first[l1+1] = '\0';
            strcat(first,last);
            node temp(first);
            if(mp.find(temp)==mp.end()){
                cout << first << ": infinity" << endl;
            }
            else{
                int t = mp[temp];
                if(d[t]<0)
                    cout << first << ": infinity" << endl;
                else
                    cout << first << ": " << d[t] << endl;
            }
        }
        
        cout << endl;
    }
    return 0;
}

