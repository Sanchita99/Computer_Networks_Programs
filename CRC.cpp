#include<stdio.h>
#include<string.h>

int main()
{
	int i,j,n,m,k,z,c;
	
	printf("Enter no. of bits in data\n");
	scanf("%d",&n);
	
	printf("Enter no. of bits in generator\n");
	scanf("%d",&m);
	
	char d[n+m-1],g[m],dc[n+m-1],gc[m],r[m],dr[n+m],drc[n+m],rc[m-1];
	
	printf("Enter data\n");
	scanf("%s",d);
	strcpy(dc,d);
	
	printf("Enter generator\n");
	scanf("%s",g);
	strcpy(gc,g);
	
	for(i=n;i<m+n-1;i++)
	{
		d[i]='0';
	}
	d[i]='\0';
	//printf("initial %s\n",d);
	
	for(i=0,j=0,k=0;i<n+m-1;)
	{
		if(d[i]==g[j])
		{
			d[i]='0';
			r[k]='0';
			i++;
			j++;
			k++;
		}
		else
		{
			d[i]='1';
			r[k]='1';
			i++;
			j++;
			k++;
		}
		
		if(k==m)
		{
			c=strcmp(r,gc);
			//printf("d:%s\nr:%s\nc:%d\n",d,r,c);
	
			if(c<0)
			{
				for(j=0;j<n;j++)
				{
					g[j]='0';
				}
			}
			else
			{
				strcpy(g,gc);
			}
			//printf("%s\n",g);			
			k=0;
			j=0;
			for(z=0;z<n+m-1;z++)
			{
				if(d[z]=='1')
				{
					if(z==n+1)
						break;
					i=z;
					//printf("i=%d\n",i);
					break;
				}
			}
		}	
	}
	
	printf("final remainder at sender:%s\n",r);
	
	for(i=0;i<m-1;i++)
		rc[i]=r[i+1];
		
	printf("Code Word:%s\n",rc);
	
	strcpy(dr,dc);
	strcat(dr,rc);
	//printf("%s",dr);
	strcpy(g,gc);
	
	for(i=0,j=0,k=0;i<n+m-1;)
	{
		if(dr[i]==g[j])
		{
			dr[i]='0';
			r[k]='0';
			i++;
			j++;
			k++;
		}
		else
		{
			dr[i]='1';
			r[k]='1';
			i++;
			j++;
			k++;
		}
		
		if(k==m)
		{
			c=strcmp(r,gc);
			//printf("d:%s\nr:%s\nc:%d\n",d,r,c);
	
			if(c<0)
			{
				for(j=0;j<n;j++)
				{
					g[j]='0';
				}
			}
			else
			{
				strcpy(g,gc);
			}
			//printf("%s\n",g);			
			k=0;
			j=0;
			for(z=0;z<n+m-1;z++)
			{
				if(dr[z]=='1')
				{
					if(z==n+1)
						break;
					i=z;
					//printf("i=%d\n",i);
					break;
				}
			}
		}	
	}
	
	printf("final remainder at reciever:%s\n",r);
	
	int count=0;
	for(i=0;i<m;i++)
	{
		if(r[i]=='0')
			count++;
	}
	
	if(count==m)
		printf("Correct data recieved\n");
	
	return 0;
}
