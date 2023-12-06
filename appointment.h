// appointment.h
#pragma once  // Include guard to prevent multiple inclusion
 
#include <string>
#include <iostream>
 
class Appointment {
private:
	std::string title;
	int year;
	int month;
	int day;
	int time; // military time
	int duration;
 
public:
	// Constructors
	Appointment();
	Appointment(std::string appData);
 
	// Getter functions
	std::string getTitle();
	int getYear();
	int getMonth();
	int getDay();
	int getTime();
	int getDuration();
	std::string getDate();
	std::string getStandardTime();
 
	// Setter functions
	void setTitle(std::string newTitle);
	void setYear(int newYear);
	void setMonth(int newMonth);
	void setDay(int newDay);
	void setTime(int newTime);
	void setDuration(int newDuration);
	void setDate(int newYear, int newMonth, int newDay);
 
	// Conversion functions
	std::string militaryToStandard(int time);
	int standardToMilitary(std::string time);
};


