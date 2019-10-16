#include<iostream>
#define MAX 50
using namespace std;

int main(){
     int i,j,a[MAX],n,new_n,new1_n,count=0;
     cout << "Enter length of msg: ";
     cin >> n;
     for(i=0;i<n;i++)
          cin >> a[i];
     
     //Stuffing     
     new_n=n;
     for(i=0;i<=MAX;i++){
          if(a[i]==0 && i+7 < new_n){
               if(a[i+1] == a[i+2] == a[i+3] == a[i+4] == a[i+5] == a[i+6] == 1 && a[i+7]==0) {
                    new_n++;
                    
                    for(j=new_n-1;j>i+6;j--){
                         a[j] = a[j-1];                 
                    }
                   
                    a[i+6] = 0;
                    i=i+8;
                    //count++;
               }     
          }
    
     }  
     cout << "Stuffed data" << endl;
     for(i=0;i<new_n;i++)
          cout <<  a[i] << " ";
     cout << endl;
     
     //Destuffing
     new1_n = new_n;
     for(i=0;i<=MAX;i++){
          if(a[i]==0 && i+7 < new_n){
               if(a[i+1] == a[i+2] == a[i+3] == a[i+4] == a[i+5] == a[i+7] == 1 && a[i+6]==0) {

                    
                    for(j=i+6;j<new1_n;j++){
                         a[j] = a[j+1];                 
                    }
                   
                    new1_n--;
                    i=i+6;
               }     
          }
    
     }
     
     cout << "DeStuffed data" << endl;
     for(i=0;i<new1_n;i++)
          cout <<  a[i] << " ";
     cout << endl;
     
     //Appending
     
     int final_n = n+16;
     int msg[final_n];
     for(i=0;i<final_n;i++)
     {
     
         if(i<7 && i>0)
            msg[i]=1;      
         if(i<final_n && i>final_n-8)
            msg[i]=1;
     }
     j=8;
     for(i=0;i<n;i++)
     {
        msg[j] = a[i];
        j++;
     }
     msg[0]=msg[7]=msg[final_n-1]=msg[final_n-8]=0;
     cout << "Appended" << endl;
     for(i=0;i<final_n;i++)
          cout <<  msg[i] << " ";
     cout << endl;
     
     
}
