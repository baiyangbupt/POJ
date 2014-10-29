#include<iostream>
using namespace std;

bool getball[33];
int n,next,ball,cnt;

int main(){
     while(cin>>n&&n){
                      memset(getball,0,sizeof(getball));
                      bool left[33];
                      ball = 0;
                      cin >> next;
                      next-=1;
                      char c;
                      for(int i = 0; i < n; i++){
                              cin >> c;
                              left[i] = c=='L';
                      }
                      cnt = 0;
                      int toss = 0;
                      while(cnt<n){
                                   //cout << next << endl;
                                   if(getball[next]==0)
                                                       getball[next] = 1, cnt++;
                                   if(ball==(next+n-1)%n&&left[next]==0){
                                                                         int t = next;
                                                                         next = (next+1+n)%n;
                                                                         left[t] = 1;
                                                                         ball = t;
                                                                         toss++;
                                                                         continue;
                                   }
                                   if(ball==(next+1+n)%n&&left[next]==1){
                                                                         int t =next;
                                                                         next= (next-1+n)%n;
                                                                         left[t] = 0;
                                                                         ball = t;
                                                                         toss++;
                                                                         continue;
                                   }
                                   int t = next;
                                   if(left[next])
                                                 next = (ball+n-1)%n;
                                   else
                                       next = (ball+n+1)%n;
                                   left[t] = 1-left[t];
                                   ball = t;
                                   toss++;
                      }
                      cout << "Classmate " << ball+1<<" got the ball last after " << toss << " tosses." << endl;
     }
}
                                   
