#include<iostream>
#include<cmath>

using namespace std;

//=======================defining a parent class Date=======================

class Date{
	public:
		int d1, m1, y1;
		int d2, m2, y2;
	
	void getDate();
	int date(int, int, int, int, int, int);
	void displayResult();

};

//===============================Take the date from user input===============================

void Date :: getDate(void){
	cout << "Enter the first Date in the following format\n(DD,MM,YYYY)\ne.g (23, 9, 1999)" << endl ;
	cin >> d1 >> m1 >> y1;
	cout << endl << "Enter the second Date in the following format\n(DD,MM,YYYY)\ne.g (23, 9, 1999)" << endl ;
	cin >> d2 >> m2 >> y2;
}



//============================To calculate the days================================
	
int Date :: date(int d1, int m1, int y1, int d2, int m2, int y2){
	
	int sy, sm, sd, by, bm, bd; // s for smaller and b for bigger
	
	int noOfYear = abs(y1-y2)-1; // difference between bigger and smaller year
	
	if(y1<y2){
		sy = y1;
		sm = m1;
		sd = d1;
		by = y2;
		bm = m2;
		bd = d2;
	}
	else{
		sy = y2;
		sm = m2;
		sd = d2;
		by = y1;
		bm = m1;
		bd = d1;
	}
	
	int yearsIntoDays = noOfYear*365;
	
	for(int i = sy; i < by; i++){
		
		if(i%4==0){
			yearsIntoDays += 1;
		}
	}
	
	int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if(sy%4==0 || (sy%100==0 && sy%400==0)){
		monthDays[1]+1;
	}
	
	int prevDays = 0;
	
	for(int j = sm; j < 12; j++){
		prevDays += monthDays[j]; 
	}
	
	prevDays += monthDays[sm-1] - sd;

	if(by%4==0 || (by%100==0 && by%400==0)){
		monthDays[1]-1;
	}
	if(bm != 1){
		for(int j = 1; j < bm; j++){
		prevDays += monthDays[j-1]; 
		}
		prevDays += bd;
	}
	else{
		prevDays += bd;
	}
	
	
	
	return (yearsIntoDays + prevDays);
}



//==========================Display the days between two dates=================================

void Date :: displayResult(void){
	int result;
	result = date(d1, m1, y1, d2, m2, y2);
	
	cout << result << endl;
	
}

//==============================main function======================================

int main(){
	int d1, m1, y1, d2, m2, y2;
	Date mydate;
	mydate.getDate();
	mydate.date(d1, m1, y1, d2, m2, y2);
	mydate.displayResult();
	
	return 0;
}
