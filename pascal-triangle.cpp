#include<iostream>

using namespace std;

int main ()
{
	int i,j,n,k;
	for (n=1;n<=6;n++){
	
		for(i=0;i<6-n;i++){
			cout << " ";
		}
		for(j=1; j<=n; j++){
			cout << j ;
		}
		for(k=j-2; k>0; k--){
			cout << k ;
		}
		cout << "\n";
}}
