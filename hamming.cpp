#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int n,r=3,i,j,c=1;
	
	cout << "Enter length of data: ";
	cin >> n;
	int a[n+1],data[n+r+1],data1[n+r+1];
	cout << "Enter data to be transferred: \n" ;
	for(i=1;i<=n;i++)
		cin >> a[i];
		
	//Sender
	for(i=n+r;i>0;i--){
		if(i != pow(2,0) && i != pow(2,1) && i != pow(2,2))
		{
			data[i] = a[c];
			c+=1;
		}
		else
			data[i] = 0;
	
	}
	
	(data[3] ^ data[5] ^ data[7] == 0)?data[1] = 0:data[1] = 1;
	(data[3] ^ data[6] ^ data[7] == 0)?data[2] = 0:data[2] = 1;
	(data[5] ^ data[6] ^ data[7] == 0)?data[4] = 0:data[4] = 1;
		
	cout << "Data tranferred: ";
	for(i=n+r;i>0;i--)
		cout << data[i] << " ";
	cout << "\n";
	
	//data[1]=0;
	//Receiver
	
	cout << "Enter Received data: ";
	for(i=n+r;i>0;i--)
		cin >> data1[i];
	int p1,p2,p3;
	p1 = data1[1]^data1[3]^data1[5]^data1[7];
	p2 = data1[2]^data1[3]^data1[6]^data1[7];
	p3 = data1[4]^data1[5]^data1[6]^data1[7];
	
	if(p1^p2^p3 == 0)
	cout << "No error\n";
	else{
		int pos;
		pos = p1 * pow(2,0) + p2 * pow(2,1) + p3 * pow(2,2);
		cout << "Error at position: " << pos << "\n";
	}
	
}
