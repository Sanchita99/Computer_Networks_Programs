#include<iostream>
#include<cstdlib>
#define MAX 30

using namespace std;

int main(){
	int i,j,no,n,k,a[MAX],b[MAX];
	cout << "Enter no. of frames: ";
	cin >> no;
	cout << "Enter window size: ";
	cin >> n;
	//cout << "Enter data to be transmitted: ";
	//for(i=0;i<no;i++)
		//cin >> a[i];
	
	k=0;
	l:
	for(j=k;j<k+n && j<no;j++){
		cout << "Frame "  << j+1 << " Transmitting\n" ;
	}
	for(j=k;j<k+n && j<no;j++){
		b[j]=rand() % 2;
		if(b[j] == 0){
			cout << "Frame " << j+1 << " Transmitted\n";
		}
			
		else{
			cout << "Frame " << j+1 << " not transmitted Going back to " << j+1 << endl;
			k=j;
			goto l;
		}
	}
	
}
