#include<iostream>
using namespace std;

int pages,content[51][2],sheet,pagenum;

int main(){
    for(int i = 1; i <= 100; i++)
            content[(i+1)/2][1-i%2] = i;
    while(cin>>pages&&pages){
                             cout << "Printing order for " << pages << " pages:" << endl;
                             if(pages==1){
                                         cout << "Sheet 1, front: Blank, 1" << endl;
                                         continue;
                             }
                             if(pages%4==0){
                                            sheet = pages/4;
                                            pagenum = sheet*2;
                                            int i = 1, j = pagenum, cnt = 1;
                                            while(i<j){
                                                       cout << "Sheet " << cnt << ", front: " << content[j][1] << ", " << content[i][0] << endl;
                                                       cout << "Sheet " << cnt << ", back : " << content[i][1] << ", " << content[j][0] << endl;
                                                       cnt++;
                                                       i++, j--;
                                            }
                             }
                             else{
                                  sheet = pages/4+1;
                                  pagenum = sheet*2;
                                  int i = 1, j = pagenum, cnt = 1, blank = pagenum*2-pages;
                                  while(i<j){
                                             cout << "Sheet " << cnt << ", front: ";
                                             if(blank){
                                                       cout << "Blank, "<< content[i][0] << endl;;
                                                       blank--;
                                             }
                                             else
                                                 cout << content[j][1] << ", " << content[i][0] << endl;
                                             cout << "Sheet " << cnt << ", back : " << content[i][1] << ", ";
                                             if(blank){
                                                       cout << "Blank" << endl;
                                                       blank--;
                                             }
                                             else
                                                 cout << content[j][0] << endl;
                                             cnt++;
                                             i++,j--;
                                  }
                             }
    }
}
