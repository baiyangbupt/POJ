#include<iostream>
#include<cstdio>
using namespace std;

struct node{
       int x, y;
       double p;
}nn[7];

double p[500][500],pre[500][500];

void init(){
     for(int i = 0; i < 500; i++)
             for(int j = 0; j < 500; j++)
                     pre[i][j] = p[i][j] = 0;
     nn[0].x = 21, nn[0].y = 20, nn[0].p = 3./16;
     nn[1].x = 21, nn[1].y = 19, nn[1].p = 2./16;
     nn[2].x = 22, nn[2].y = 19, nn[2].p = 1./16;
     nn[3].x = 20, nn[3].y = 21, nn[3].p = 2./16;
     nn[4].x = 20, nn[4].y = 20, nn[4].p = 6./16;
     nn[5].x = 19, nn[5].y = 22, nn[5].p = 1./16;
     nn[6].x = 20, nn[6].y = 19, nn[6].p = 1./16;
     pre[0][0] = 1;
}

void update(){
     for(int i = 0; i < 500; i++)
             for(int j = 0; j < 500; j++)
                     pre[i][j] = p[i][j], p[i][j] = 0;
}

int main(){
    init();
    cout << "Round   A wins    B wins    Tie" << endl;
    for(int i = 1; i <= 20; i++){
            for(int j = 0; j < 500; j++)
                    for(int k = 0; k < 500; k++)
                            if(pre[j][k]>0){
                                            for(int ii = 0; ii < 7; ii++)
                                                    p[j+nn[ii].x][k+nn[ii].y] += pre[j][k]*nn[ii].p;
                            }
            double awin = 0, tie = 0;
            for(int i = 0; i < 500; i++)
                    for(int j = 0; j < i; j++){
                            if(p[i][j]>0)
                                         awin+=p[i][j];
                    }
            for(int i = 0; i < 500; i++)
                    if(p[i][i])
                               tie += p[i][i];
            printf("%5d   %7.4f%% %8.4f%% %8.4f%%\n",i,awin*100,(1-awin-tie)*100,tie*100);
            update();
    }
    system("pause");
}
    
    
