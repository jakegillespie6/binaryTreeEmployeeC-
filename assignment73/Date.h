#include <iostream>
#pragma once
using namespace std;
#include <string>


class Date {


public:
	string day = "";
	int month;
	string year = "";
	//constructor
	Date() {
		day;
		month;
		year;
	};
	Date(int i, int j, int k) {
		day = 1;
		month = j;
		year = k;
	}
	//tostring fucntion for date output
	string toString()//Able to return date in the format January 1, 2018
	{
		string c = "";
		switch (this->month) {
		case 1: c = "January";break;
		case 2:c = "February";break;
		case 3:c = "March";break;
		case 4:c = "April";break;
		case 5:c = "May";break;
		case 6:c = "June";break;
		case 7:c = "July";break;
		case 8:c = "August";break;
		case 9:c = "September";break;
		case 10:c = "October";break;
		case 11:c = "November";break;
		case 12:c = "December";break;
		}
		//cout<<c<<","<<this.day<<", "<<this.year;
		return c + "," + this->day + this->year;
	}
};