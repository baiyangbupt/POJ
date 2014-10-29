#include <stdio.h>
#include <string.h>

#define MAXLEN  20
typedef struct st_expression expression ;
typedef struct st_metadata metadata;

// 子元素，既可以是整数，也是一个语句
char g_sigchange[]={'+','-','*'};
struct st_metadata
{
	int			nType ;
	int			n ;
	expression *e ;
	st_metadata()
	{
		nType = n = 0 ;
		e = NULL ;
	}
};

struct st_expression
{
	int				nLen ;
	metadata		Op[MAXLEN] ;
	char			csigh[MAXLEN];	
	st_expression(){nLen = 0;}
	~st_expression()
	{
		int i ;
		for (i = 0 ;i < nLen; i ++)
		{
			if( Op[i].nType == 1 && Op[i].e != NULL)
			{
				delete Op[i].e ;
				Op[i].e = NULL ;
			}
		}
	};
	int getOpCount() {
		int i ,nCount = 0;
		for( i = 0 ;i < nLen; i ++ )
		{
			if( Op[i].nType == 1)
				nCount += Op[i].e->getOpCount() ;
			else
				nCount ++ ;
		}
		return nCount ;
	} ;
	int Caculate(char sigh[], int &singindex)
	{
		int nRes = 0 , i ;
		if( nLen <= 0 )
			return 0 ;
		nRes = Op[0].nType == 0?Op[0].n:Op[0].e->Caculate(sigh,singindex) ;
		for( i = 1 ;i < nLen ;i ++ )
		{
			switch(csigh[i-1] = sigh[singindex++])
			{
			case 0:
				nRes += (Op[i].nType == 0?Op[i].n:Op[i].e->Caculate(sigh,singindex) );
				break ;
			case 1:
				nRes -= (Op[i].nType == 0?Op[i].n:Op[i].e->Caculate(sigh,singindex) );
				break ;
			case 2:
				nRes *= (Op[i].nType == 0?Op[i].n:Op[i].e->Caculate(sigh,singindex) );
				break ;
			}
				
		}
		return nRes ;
	}
	void print( int nlevel)
	{
		int i ;
		if( nlevel > 0)
			printf("(") ;
		for( i = 0; i < nLen; i ++ )
		{
			if( Op[i].nType == 0)
				printf("%d",Op[i].n) ;
			else
			{
				Op[i].e->print(nlevel + 1) ;
			}
			if( i != nLen - 1)
				printf("%c",g_sigchange[csigh[i]]) ;
		}
		if( nlevel > 0)
			printf(")") ;
	}
	
};

class CDreisamEquations
{
public:
	CDreisamEquations(){m_nCount=1 ;m_exp=NULL ;}
	int Input() ;
	void Reset() ;
	int IsNum(char ch ){ return ch >='0' && ch <= '9';};
	int Parse(char * str,expression * e);
	int solve() ;
	void print() ;
public:
	expression		* m_exp ;
	int				m_nSum ;
	int				m_nCount ;
	int             m_bFind ;
	int				m_SignCount ;
};

void CDreisamEquations::Reset() 
{
	if( NULL != m_exp)
	{
		delete m_exp ;
		m_exp = NULL ;
	}
	m_bFind = 0 ;
	
}
int CDreisamEquations::Input() 
{
	int i , nCount = 0 ;
	char buffer[100];
	Reset() ;
	m_exp = new expression() ;
	m_nSum = 0 ;
	
	buffer[0] = getchar() ;
	if( buffer[0] == '0')
		return 0 ;
	nCount = 1 ;
	do 
	{
		buffer[nCount++] = getchar() ;
	} while (buffer[nCount-1] != '\n');
	if( buffer[nCount-2] == '\r')
		nCount -- ;
	buffer[--nCount] = '\0' ;
	for( i = 0 ;i < nCount ; i ++)
	{
		if( IsNum(buffer[i]))
			m_nSum = m_nSum * 10 + buffer[i] - '0';
		else if( buffer[i] == '=')
			break;
	}
	Parse(buffer+i+1,m_exp) ;
	return 1 ;
}

int CDreisamEquations::Parse(char * str,expression * e)
{
	int i , nlen , start = 0;
	nlen = strlen(str) ;
	i = 0 ;
	// 忽略空格
	while(str[i]==' ' && i < nlen) i ++ ;
	for(  ;i < nlen ;i ++ )
	{
		
		if( i >= nlen)
			break ;
		if( IsNum(str[i]))
		{
			e->Op[e->nLen].n = e->Op[e->nLen].n * 10 + str[i] - '0' ;
			start = 1 ;
		}else if( str[i] == ' ')
		{
			if( start == 1)
			{
				e->nLen ++ ;
				start = 0 ;
			}
		}
		else if( str[i] == '(')
		{
			if( start == 1)
			{
				e->nLen ++ ;
				start = 0 ;
			}
			e->Op[e->nLen].nType = 1 ;
			e->Op[e->nLen].e = new expression() ;
			i += (1 + Parse(str+i+1,e->Op[e->nLen].e));
			e->nLen ++;
		}else if( str[i] == ')')
		{
			break ;
		}
	}
	if( start == 1)
	{
		e->nLen ++ ;
	}
	return i ;
	
}
int CDreisamEquations::solve() 
{
	int j,sighindex; 
	char sigh[50] ;
	m_SignCount = m_exp->getOpCount() - 1;;
	memset(sigh,0,sizeof(sigh)) ;
	sighindex = 0 ;
	if( m_SignCount < 0)
		return 0 ;
	if( m_SignCount == 0)
	{
		if( m_exp->Caculate(sigh,sighindex) == m_nSum)
			return m_bFind = 1;
	}
	
#if 1 // 暴力枚举两种方法
	while(1)
	{
		sighindex = 0 ;
		if( m_exp->Caculate(sigh,sighindex) == m_nSum)
			return m_bFind = 1;
		if( m_SignCount <= 0 )
			break  ;
		sigh[m_SignCount - 1] ++ ;
		for( j = m_SignCount - 1 ; j >= 0 ; j -- )
		{
			if( sigh[0] >= 3)
			{
				return 0 ;
			}
			else if( sigh[j] >= 3)
			{
				sigh[j] = 0 ;
				sigh[j-1] ++ ;
			}else
				break ;
		}
	}
#else
	int i , tmp ,v;
	v = VPow(3,m_SignCount) ;
	for( i = 0 ;i < v  &&!m_bFind ;i ++ )
	{
		tmp = i ;
		for( j = m_SignCount - 1; j >= 0 ; j --)
		{
			if( tmp == 0)
			{
				sigh[j] = 0 ;
				continue;
			}
			sigh[j] = tmp % 3 ;
			tmp /= 3 ;
		}
		sighindex = 0 ;
		if( m_exp->Caculate(sigh,sighindex) == m_nSum)
			return m_bFind = 1;
	}	
#endif
	return 0 ;
}
void CDreisamEquations::print() 
{
	printf("Equation #%d:\n",m_nCount++) ;
	if( !m_bFind)
	{
		printf("Impossible\n\n") ;
		return ;
	}
	printf("%d=",m_nSum) ;
	m_exp->print(0) ;
	printf("\n\n");
}
int main( )
{
	CDreisamEquations s ;
	while(s.Input())
	{
		s.solve();
		s.print() ;
	}
	return 0 ;
}
