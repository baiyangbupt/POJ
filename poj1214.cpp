#include<iostream>
#include<stack>
#include<string>
#include<queue>

using namespace std;

struct node{
       stack<string> s;
       node *right, *left;
       node(){
              right = left = NULL;
       }
};

void del(node *p){
     if(p->left!=NULL)
                      p->left->right = p->right;
     if(p->right!=NULL)
                       p->right->left = p->left;
}

bool canmerge(node *a, node *b){
     string s1 = a->s.top(), s2 = b->s.top();
     return s1[0]==s2[0]||s1[1]==s2[1];
}

void merge(node *a, node *b){
     string s = b->s.top();
     b->s.pop();
     a->s.push(s);
     if(b->s.empty())
                     del(b);
}

int main(){
    string s;
    while(cin>>s&&s!="#"){
                          node *head = new node, *pre, *p, *q, *l1,*l2,*l3;
                          head->s.push(s);
                          pre = head;
                          for(int i = 0;  i< 51; i++){
                                  cin >> s;
                                  p = new node;
                                  p->s.push(s);
                                  pre->right = p, p->left = pre, pre = p;
                          }
                          
                          while(1){
                                   p = head, q = p->right;
                                   if(q==NULL) break;
                                   if(canmerge(p,q)){
                                                     merge(p,q);
                                                     continue;
                                   }
                                   p = q, q = q->right;
                                   if(q==NULL) break;
                                   if(canmerge(p,q)){
                                                     merge(p,q);
                                                     continue;
                                   }
                                   l1 = head, l2 = p, l3 = q, q = q->right;
                                   bool hasmerge = 0;
                                   while(q!=NULL){
                                                  if(canmerge(l1,q)){
                                                                     merge(l1,q);
                                                                     hasmerge = 1;
                                                                     break;
                                                  }
                                                  if(canmerge(l3,q)){
                                                                     merge(l3,q);
                                                                     hasmerge = 1;
                                                                     break;
                                                  }
                                                  q = q->right,l1 = l1->right,l2 = l2->right, l3 = l3->right;
                                   }
                                   if(hasmerge==0)
                                               break;
                          }
                          
                          vector<int> v;
                          while(head!=NULL){
                                            v.push_back(head->s.size());
                                            head = head->right;
                          }
                          cout << v.size() << " piles remaining:";
                          for(int i = 0; i < v.size(); i++)
                                  cout << " " << v[i];
                          
                          cout << endl;
    }
}
                                                  
                          
