#include<iostream>

using namespace std;

// ========================defining a class vote========================

class vote{
	public:
		int d1, m1, y1;
		int d2, m2, y2;
	
	void getDate();
	void displayResult();
	
	//============================To calculate the days================================
	
	int date(int d, int m, int y){
	m = (m + 9) % 12;
	y = y - (m/10);
	return (365*y + y/4 - y/100 + y/400 + (m*306 + 5)/10 + (d - 1));
	}
	
};

//===============================Take the date from user input===============================
void vote :: getDate(void){
	cout << "Enter the current Date in the following format\n(DD,MM,YYYY) e.g (23, 9, 1999)" << endl ;
	cin >> d1 >> m1 >> y1;
	cout << endl << "Enter the Date of Birth in the following format\n(DD,MM,YYYY) e.g (23, 9, 1999)" << endl ;
	cin >> d2 >> m2 >> y2;
}

//==========================Display the days between two dates=================================

void vote :: displayResult(void){
	int result;
	result = date(d1, m1, y1) - date(d2, m2, y2);
	
	if(result>(18*365)){
		cout << "Eligible for voting. "<< endl;
	}
	else{
		cout << "Not eligible for voting. "<< endl;
	}
	
	
}

//==============================main function======================================

int main(){
	vote v;
	v.getDate();
	v.displayResult();
	
	return 0;
}
