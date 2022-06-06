// Md.Abdul Raheem // BT19CSE067 // CPL // Assignment 2
#include<stdio.h>
#include<string.h>
int ADD(char st1[],char st2[],char add[])
{
	int a,b,big,carry=0,flag=1;
	char ch;
	a=strlen(st1);
	b=strlen(st2);
	big=(a >= b ? a : b);
	int i=a-1,j=b-1,k=big;
	while(flag==1)
	{
		ch=st1[i]+st2[j]+carry-48; 
		if(ch>57)
		{
			carry=1;
			ch=ch-10;
		}
		else
		{
			carry=0;
		}
		add[k]=ch;
		i=i-1;
		j=j-1;
		k=k-1;
		if(i==-1||j==-1)
		{
			flag=0;
		}
	}
	if(a==b)
	{
		add[0]=carry+48;
	}
	else
	{
		if(j==-1)
		{
			while(i>=0)
			{
				ch=st1[i]+carry;
				if(ch>57)
				{
					carry=1;
					ch=ch-10;
				}
				else
				{
					carry=0;
				}
				add[k]=ch;
				i=i-1;
			}
			add[0]=carry+48;
		}
		else if(i==-1)
		{
				while(j>=0)
				{
					ch=st2[j]+carry;
					if(ch>57)
					{
						carry=1;
						ch=ch-10;
					}
					else
					{
						carry=0;
					}
					add[k]=ch;
					j=j-1;
				}
				add[0]=carry+48;
		}
    }
    return carry;
}

int SUB(char st1[],char st2[],int f,char sub[])
{
	int a,b,i;
	a=strlen(st1);
	b=strlen(st2);
	char st3[b],comp[300]; 
	for(i=0;i<b;i++)
	{
		st3[i]='9'-st2[i]+'0';
	}
	st3[i]='\0';
	int k=0;
	for(i=0;st3[k]!='\0';i++)
	{
		if(i<a-b)
		{
			comp[i]='9';
		}
		else
		{
			comp[i]=st3[k];
			k++;
		}
	}
	comp[i]='\0';
	
	char add[300];	
	int c=ADD(st1,comp,add);
	if(c==1)  
	{
		char str[300],car[299];
		int i;
        for(i=0;add[i]!='\0';i++)
        {
              car[i]=add[i+1];
        }
        strcpy(str,car);
        ADD(str,"1",add);
		for(i=0;add[i]!='\0' && f==0;i++)
		{
			printf("%c",add[i]);
		}	
	}
	else if(c==0)
	{
		    int k;
		    if(f==0)
		    {
            	printf("\n-");
        	}
            for(k=1;add[k]!='\0'&& f==0;k++)
            {
            	if(add[k]<='9' && add[k]>='0')
            	{
                	printf("%c",'9'-add[k]+48);
            	}
            }
	}
	strcpy(sub,add);
	return c;
}
int isStringZero(char st[])
{
	int i;
	int status=1;
	for(i=0;st[i]!='\0'&& status==1;i++)
	{
		if(st[i])
		{
			status=1;
		}
	}
	return status;
}
void MULTIPLY(char st1[],char st2[])
{
	char null[300],ch,sub[300];
	int p;
	strcpy(null,st1);
	int c=1;
	while((!isStringZero(st2)) && c==1)
	{
		int a=strlen(st1);
		int b=strlen(null);
		int flag=1,carry=0;
		int i=a-1,j=b-1;
		while(flag==1)
		{
			ch=st1[i]+st2[j]+carry-48;
			if(ch>57)
			{
				carry=1;
				ch=ch-10;
			}
			else
			{
				carry=0;
			}
			null[j]=ch;
			i=i-1;
			j=j-1;
			if(i==-1||j==-1)
			{
				flag=0;
			}
		}
		if(a==b)
		{
			null[0]=carry+48;
		}
		else
		{
			if(j==-1)
			{
				while(i>=0)
				{
					ch=st1[i]+carry;
					if(ch>57)
					{
						carry=1;
						ch=ch-10;
					}
					else
					{
						carry=0;
					}
					null[j]=ch;
					i=i-1;
				}
				null[0]=carry+48;
			}
			else if(i==-1)
			{
				while(j>=0)
				{
					ch=st2[j]+carry;
					if(ch>57)
					{
						carry=1;
						ch=ch-10;
					}
					else
					{
						carry=0;
					}
					null[j]=ch;
					j=j-1;
				}
				null[0]=carry+48;
			}
		}
		c=SUB(st2,"1",1,sub); 
		strcpy(st2,sub);
	}
    int q;
    for(q=0;null[q]!='\0';q++)
    {
    	printf("%c",null[q]);
	}
}
void main()
{
	char s[300],s1[300],add[300],sub[300];
	int i,j;
	gets(s);
	gets(s1);
	for(i=0;i<300;i++)
	{
		add[i]='\0';
	}
	ADD(s,s1,add);
    for(i=0;add[i]!='\0';i++)
    {
    	printf("%c",add[i]);
	}
	printf("\n");
	SUB(s,s1,0,sub);
	printf("\n");
	MULTIPLY(s,s1);
}
	
