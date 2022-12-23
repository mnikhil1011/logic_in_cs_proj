#include<bits/stdc++.h>

using namespace std;


/// this global variable stores all the statements(the main function divides input into rule and statement)
char valid[15][30];

///This checks and introduction rule
///
///in this function we make an other character array which is a statement which is formed from 
///using the rule if it matches the statement provided then we return 1
/// @param  x this shows what the first statement line number in the and rule is
/// @param  y this shows what the second statement line number in the and rule is
///@param z this is the line number of the statement in which this rule is used
///@returns this returns 0/1 , 0 if statement is valid, 1 if statement is not valid
///@warning  for this function to be called the rule should be ^i/line1/line2
/// ### example input
///~~~~~~~~~~~~~~~~~~~~~~~.cpp
///(a^b)/^i/1/2
///~~~~~~~~~~~~~~~~~~~~~~~

int andintro (int x,int y,int z)
{
	int i=0;
	
	char check[30];
	for(int l=0;l<=30;l++)
		{
			check[l]=' ';
		}
	
		
	i=0;
	check[0]='(';
	while(valid[x][i] !=' ')
	{
		check[i+1]=valid[x][i];
		i++;
	}
	check[i+1]='^';
	int k=0;
	i++;
	while(valid[y][k] !=' ')
	{
		check[i+1]=valid[y][k];
		i++;k++; 
	}
	check[i+1]=')';

	int see=1;
	i=0;
	while(valid[z][i] !=' ' || check[i] !=' ')
	{
		if(check[i] != valid[z][i])
		{
			see=0;
			break;
		}
		i++;
	}
	return see;
	
	
	
}


///This checks and elemination rule
///
///in this function we make an other character array which is a statement which is formed from 
///using the rule if it matches the statement provided then we return 1
/// @param  y this shows what elemination rule this is
/// @param  x this shows us which line number this rule being performed on 
///@param z this is the line number of the statement in which this rule is used
///@returns this returns 0/1 , 0 if statement is valid, 1 if statement is not valid
///@warning  for this function to be called the rule should be ^en/line2
/// ### example input
///~~~~~~~~~~~~~~~~~~~~~~~.cpp
///(a^b)/p
///a/^e1/1
///~~~~~~~~~~~~~~~~~~~~~~~
int andelem (int x,int y, int z)
{
	int i=0;
	char check[30];
	for(int l=0;l<=30;l++)
	{
		check[l]=' ';
	}
	i=1;
	int ck=0;
	int see=0;
	while(valid[x][i] !=' ')
	{
		if(valid[x][i]=='(')
		ck++;
		
		else if(valid[x][i]==')')
		ck--;
		
		if(ck==0 && valid[x][i]=='^')
		{
			see=1;
			break;
		}
		i++;	
		
	}
	if(see==0)
	{
		return 0;
	}
	
	
	if(y==1)
	{
		for(int k=0;k<i-1;k++)
			check[k]=valid[x][k+1];
	}
	
	else
	{
		int k=0;
		i++;
		while(valid[x][i] != ' ')
		{
		
			check[k] =valid[x][i];
			i++;k++;
		}
		check[k-1]=' ';
	} 
	
	int ok=1;
	i=0;
	while(valid[z][i] !=' ' || check[i] !=' ')
	{
		if(check[i] != valid[z][i])
		{
			ok=0;
			break;
		}
		i++;
	}
	return ok;
	
}

///This checks or intro rule
///
///in this function we check if the brackets are there and we check if the statement after(if y=2) the | is same
/// or before(if y=1) | is same
/// @param  y this shows what |introduction rule this is
/// @param  x this shows us which line number this rule being performed on 
///@param z this is the line number of the statement in which this rule is used
///@returns this returns 0/1 , 0 if statement is valid, 1 if statement is not valid
///@warning  for this function to be called the rule should be |in/l
/// ### example input
///~~~~~~~~~~~~~~~~~~~~~~~.cpp
///a/p
///(a|b)/|i1/1
///~~~~~~~~~~~~~~~~~~~~~~~	
int orintro(int x,int y,int z)	
{

	int i=1;
	int ck=0;
	int see=0;
	while(valid[z][i] !=' ')
	{
		if(valid[z][i]=='(')
		ck++;
		
		else if(valid[z][i]==')')
		ck--;
		
		if(ck==0 && valid[z][i]=='|')
		{
			see=1;
			break;
		}
		i++;	
		
	}
	int here=i;
	if(see==0)
	{
		return 0;
	}

	if(x==2)
	{
		int j=0;
		while(valid[y][j] != ' ' || valid[z][j+here+1] !=')')
		{

			if(valid[y][j] != valid[z][j+here+1])	
			{
				return 0;
			}
			j++;
		}
		
	}
	
	if(x==1)
	{
		int j=0;
		while(valid[y][j] != ' ' || valid[z][j+1] !='|')
		{
			 			

			if(valid[y][j] != valid[z][j+1])	
			{
				return 0;
			}
			j++;
		}
		
	}
	
	
	return 1;
	
		
}	


///This checks implication elemination rule
///
///in this function we check if (line z>line y) is same as line x
/// @param  y this shows what the statement number before the implies line is same as
/// @param  x this shows us which line number of the implies statement is in 
///@param z this is the line number of the statement in which this rule is used
///@returns this returns 0/1 , 0 if statement is valid, 1 if statement is not valid
///@warning  for this function to be called the rule should be >e/x/y
/// ### example input
///~~~~~~~~~~~~~~~~~~~~~~~.cpp
///a/p
///(a>b)/p
///b />e/2/1
///~~~~~~~~~~~~~~~~~~~~~~~	
 
int implelem(int x, int y, int z)
{
	

	int i=0;
	
	while(valid[x][i+1] !='>' || valid[y][i] !=' ')
	{
		if(valid[x][i+1] != valid[y][i])	
			{
				return 0;
			}
			i++;
	}
	i++;int k=0;
	
	while(valid[x][i+1] !=')' || valid[z][k] !=' ')
	{
		if(valid[x][i+1] != valid[z][k])	
			{
				return 0;
			}
			i++;
			k++;
	}
	
	return 1;
	
}

///This checks MT rule
///
///in this function we check if statement y without ~ is same as  the part of statement x before implies symbol 
/// then we check if the statement after > is same as statment z without ~ symbol
/// @param  y this shows what the the statement whis is same as the implies statement without ~
/// @param  x this shows us which line number this rule being performed on (implies statement) 
///@param z this is the line number of the statement in which this rule is used
///@returns this returns 0/1 , 0 if statement is valid, 1 if statement is not valid
///@warning  for this function to be called the rule should be mt/x/y
/// ### example input
///~~~~~~~~~~~~~~~~~~~~~~~.cpp
///~b/p
///(a>b)/p
///~a/mt/2/1
///~~~~~~~~~~~~~~~~~~~~~~~

int mt(int x, int y, int z)
{
	int i=1;
	if(valid[z][0] !='~')
	{
		return 0;
	}
	int j=1	;
	i=1;

	if(valid[z][2] =='~')
	{
		if(valid[z][1] !='(')
		{
			return 0;
		}	
		else
		{
			while(valid[x][i] !='>' || valid[z][i+1] !=')')
			{
				
				if(valid[x][i] != valid[z][i+1])	
					{
						return 0;
					}
					i++;
			}
			i++;
	
		}
				
	}	
	
	else
	{
					
		
		while(valid[x][i] !='>' || valid[z][i] !=' ')
		{
			
			if(valid[x][i] != valid[z][i])	
				{
					return 0;
				}
				i++;
		}
	
		
		i++;
	
	}
	if(valid[y][0] !='~')
	{
			return 0;
	}
	
	if(valid[y][2] =='~')
	{
		if(valid[y][1] !='(')
		{
			return 0;
		}	
		else
		{
		

			int k=2;
		
			while(valid[x][i] !=')' || valid [y][k] !=')')
			{
				if(valid[x][i] != valid[y][k])	
				{
					return 0;
				}
				i++;
				k++;
			}
		
		}
				
	}	
	else
	{
	

		int k=1;
		
		while(valid[x][i] !=')' || valid [y][k] !=' ')
		{
					
			if(valid[x][i] != valid[y][k])	
			{
				return 0;
			}
			i++;
			k++;
		}
		
	}
	
	return 1;
}


/// this is the main() function
///
///we first take input of no of lines then we keep taking the imputs
///input is divided into two parts rule and statement
///the statement is stored in a global variable
/// and functions based on rules are called
///in the end if all statements are valid it displays that proof is valid otherwise proof is incalid
int main()
{
		for(int l=0;l<=15;l++)
		{
			for(int i=0;i<=30;i++)
				valid[l][i]=' ';
		}
	char b[15][30];
	int m;
	cin>>m;
	cin.getline(b[0],30);

	int final=0;
	for(int i=1;i<=m;i++)
	{
		for(int l=0;l<=30;l++)
		{
			b[i][l]=' ';
		}
		cin.getline(b[i],30);
		
		int k=0,siz=0;
		while(b[i][k] != '/')
		{
			k++;
			siz++;
		}
		siz++;
		while(b[i][siz] != ' ')
		{
			siz++;
		}
		char stat[k-1];
		int u=k-1;
		int z=siz-(k+2);
		char rule[z];
		
		
		k=0;
		while(b[i][k] != '/')
		{
			stat[k]=b[i][k];
			valid[i][k]=b[i][k];
			k++;
		}
		k=k+1;
		int j=0;
		while(b[i][k] != ' ')
		{
			rule[j]=b[i][k];
			
			k++;
			j++;
		}
		int q=0;
		if(rule[0]=='p')
		{
			q=1;
		}
		
		else if(rule[0]=='^' && rule[1]=='i')
		{
			q=andintro(rule[3]-48,rule[5]-48,i);
		}
		
		else if(rule[0]=='^' && rule[1]=='e')
		{
			 q=andelem(rule[4]-48,rule[2]-48,i);
		}
		
		
		else if(rule[0]=='|' && rule[1]=='i')
		{
			 q=orintro(rule[2]-48,rule[4]-48,i);
		}
	
		else if(rule[0]=='>')
		{
			 q=implelem(rule[3]-48,rule[5]-48,i);
		}
		else if(rule[0]=='m' && rule[1]=='t')
		{
			 q=mt(rule[3]-48,rule[5]-48,i);
		}
		
		if(q==0)
		{
			final++;			
		}			
	}
 	
	if(final==0)
	{
		cout<<"valid proof";
	}
	else
	{
		cout<<"invalid proof";
	}
}
