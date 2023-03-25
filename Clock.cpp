#include<iostream>
#include"Clock.h"
using namespace std;
//Clock::表示该函数是类中的成员函数，并不是全局函数
void Clock::Init(int hour, int minute, int second){
	assert(hour <= 23 && minute <= 59 && second <= 59);
	hour_ = hour;
	minute_ = minute;
	second_ = second;
}
void Clock::Display(){
	cout << hour_ << ":" << minute_ << ":" << second_ << endl;
}
void Clock::Update(){
	second_++;
	if (second_ == 60){
		minute_++;
		second_ = 0;
	}
	if (minute_ == 60){
		hour_++;
		minute_ = 0;
	}
	if (hour_ == 24){
		hour_ = 0;
	}
}
int Clock::GetHour(){
	return hour_;
}
int Clock::GetMinute(){
	return minute_;
}
int Clock::GetSecond(){
	return second_;
}
void Clock::SetHour(int hour){
	assert(hour <= 23);
	hour_ = hour;
}
void Clock::SetMinute(int minute){
	assert(minute <= 59);
	minute_ = minute;
}
void Clock::SetSecond(int second){
	assert(second <= 59);
	second_ = second;
}
