#include<iostream>
using namespace std;

bool winornot[110][13][32],visit[110][13][32];

int getfinal(int y, int m){
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12) return 31;
   else if(m==2)
   {
        if((y%100!=0&&y%4==0)||y%400==0) return 29;
        else return 28;
   }
   else return 30;
}

void nextcalday(int y, int m, int d, int &ny, int &nm, int &nd){
    if(d+1<=getfinal(y,m))
    {
      ny = y, nm = m, nd = d+1;
      return ;
    }
    else
    {
        if(m!=12)
        {
         ny = y;
         nm =  m+1;
         nd=1;
         return;
         }
         else
         {
          nm = 1;
          ny = y+1;
          nd=1;
          return ;
         }
    }
}

void nextmonth(int y, int m, int d, int &ny, int &nm, int &nd){
     if(m!=12)
     {
              nm = m+1;
      if(d>getfinal(y,m)) {
                          ny = -1;
                          return;
      }
      else{
           ny = y;
           nd = d;
           return ;
      }
     }
     else
     {
         nm=1;
         ny = y+1;
         nd = d;
         return;
     }
}

bool dfs(int year, int month, int day){
     //cout << year+1900 <<" " << month << " " << day << endl;
     if(year>2001-1900||(year==2001-1900&&month>11)||(year==2001-1900&&month==11&&day>4))
                                                                               return 1;
     if(visit[year][month][day])
                                return winornot[year][month][day];
     
     visit[year][month][day] = 1;
     if(year==2001-1900&&month==11&&day==4)
                                           return winornot[year][month][day] = 0;
     
     int ny1,nm1,nd1,ny2,nm2,nd2;
     nextcalday(year,month,day,ny1,nm1,nd1);
     nextmonth(year,month,day,ny2,nm2,nd2);
     if(dfs(ny1,nm1,nd1)==0)
                            return winornot[year][month][day] = 1;
     else if(ny2>0&&dfs(ny2,nm2,nd2)==0)
          return winornot[year][month][day] = 1;
     
     return winornot[year][month][day] = 0;
}

int main(){
    memset(visit,0,sizeof(visit));
    int year,month,day,nc;
    cin >> nc;
    while(nc--&&cin>>year>>month>>day){
                                       if(dfs(year-1900,month,day))
                                                                   cout << "YES" << endl;
                                       else
                                           cout << "NO" << endl;
                                       
    }
}
    
