#include<stdio.h>
#include<stdlib.h>

int recieve(int f, long long int n)
{
	int rack,rf=0,j=0,rd[n];
		
	rack=rand()%2;
	//printf("%d \n",rack);
	
	if(rack!=f)
	{
		rf=f;
		rd[j]=f;
		j++;
		printf("\trecieve \t%d\n",f);
		return rack;		
	}
	else
	{
		printf("drop as rack is %d\n",rack);
		return rack;
	}
	
}


int send(int d[], long long int n)
{
	int i;
	int ack;
	
	for(i=0;i<n;i++)
	{
		ack=recieve(d[i],n);
		if(ack==d[i])
		{
			i--;
			continue;
		}	
	}
	
	
	
}

int main()
{
	long long int n;
	
	printf("Enter number of data bits\n");
	scanf("%lld",&n);
	
	int i,d[n];
	
	printf("Enter data\n");	
	for(i=0;i<n;i++)
	{
		scanf("%d",&d[i]);
	}
	
	send(d,n);
	
}
