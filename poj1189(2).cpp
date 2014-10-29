#include<iostream>
using namespace std;

long long a[51][51]; //��ʾ���ʵķ��� 
long long b[51][51]; //��ʾ���ʵķ�ĸ 

//��(i,j) ���ĸ��ʵ�1/2���ݵ�(i+1,t) 
void transmit(int i, int j, int t)
{
	long long temp = b[i][j]<<1;
	if(a[i+1][t])
	{
				if(b[i+1][t] != temp)
				{
					if(b[i+1][t] < temp)
					{
					 while(b[i+1][t] < temp)
					 {
					          a[i+1][t] <<= 1;
						  b[i+1][t] <<= 1;
					  }
					  a[i+1][t] += a[i][j];
					}
					else
					{
						long long temp_a = a[i][j];
						while(temp < b[i+1][j])
						{
							temp <<= 1;
							temp_a <<= 1;
						}
						a[i+1][t] += temp_a;
					}
				}
				else
				{
					a[i+1][t] += a[i][j];
				}
	}
	else
	{
			a[i+1][t]=a[i][j];
			b[i+1][t]=temp;
	}
}

long long gcd(long long a, long long b)
{
	long long temp;
	while(b != 0)
	{
		temp = a;
		a = b;
		b = temp % b;
	}
	return a;
}

int main()
{
	int n,m;
	char ch;
	//�������� 
	cin>>n>>m;
	
	//�������
	a[0][0]=1; 
	b[0][0]=1;
	for(int i=0; i<n; i++)
	 for(int j=0; j<=i; j++)
	 {
		cin>>ch;
		if(!a[i][j]) continue;
		if(ch=='*') // ������
		{	
			//����a[i+1][j] b[i+1][j] 
			transmit(i, j, j);
			
			//����a[i+1][j+1] b[i+1][j+1]
			transmit(i, j, j+1);
		}
		else //���Ӳ��� 
		{
			a[i+2][j+1]=a[i][j];
			b[i+2][j+1]=b[i][j];
		}
	 }
	 
	 long long temp_a = a[n][m];
	 long long temp_b = b[n][m];
	 if(!temp_a) cout<<"0/1"<<endl;
	 else
	 {
	  long g = gcd(temp_a, temp_b);
	  while(g != 1)
	  {
			temp_a /= g;
			temp_b /= g;
			g = gcd(temp_a, temp_b);
	  }
	  cout<<temp_a<<"/"<<temp_b<<endl;
	 } 
	system("pause");
	return 0;
}
