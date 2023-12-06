// appointment.cc
#include "appointment.h"
#include <sstream>
#include <iomanip>
#include <iostream>
 
using namespace std;
 
// Helper function to trim spaces
std::string trim(const std::string& str) {
	size_t first = str.find_first_not_of(' ');
	if (std::string::npos == first) {
    	return str;
	}
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}
 
Appointment::Appointment() {
	// Initialize default values
	title = "N/A";
	year = 1;
	month = 1;
	day = 1;
	time = 0;
	duration = 1;
}
 
Appointment::Appointment(std::string appData) {
	// Parse appointment data from a string
	std::istringstream ss(appData);
	std::string token;
 
	std::getline(ss, title, '|');
	title = trim(title);
	ss >> year >> month >> day;
 
	// Validate date components
	if (year <= 0 || month < 1 || month > 12 || day < 1 || day > 31) {
    	cerr << "Error: Invalid date components in appointment data.\n";
    	return;
	}
 
	std::getline(ss, token, '|');
	time = standardToMilitary(token);
	ss >> duration;
 
	// Validate time and duration
	if (time < 0 || time > 2359 || duration <= 0) {
    	cerr << "Error: Invalid time or duration in appointment data.\n";
    	return;
	}
}
 
std::string Appointment::getTitle() {
	return title;
}
 
int Appointment::getYear() {
	return year;
}
 
int Appointment::getMonth() {
	return month;
}
 
int Appointment::getDay() {
	return day;
}
 
int Appointment::getTime() {
	return time;
}
 
int Appointment::getDuration() {
	return duration;
}
 
std::string Appointment::getDate() {

	// Format date as "YYYY-MM-DD"
	std::ostringstream ss;
	ss << std::setfill('0') << std::setw(4) << year << "-"
   	<< std::setw(2) << std::setfill('0') << month << "-"
   	<< std::setw(2) << std::setfill('1') << day;
	return ss.str();
}
 
std::string Appointment::getStandardTime() {
	// Convert military time to standard time
	return militaryToStandard(time);
}
 
void Appointment::setTitle(std::string newTitle) {
	// Trim and set the title
	title = trim(newTitle);
}
 
void Appointment::setYear(int newYear) {
	// Set the year if it's positive
	if (newYear > 0) {
    	year = newYear;
	}
}
 
void Appointment::setMonth(int newMonth) {
	// Set the month if it's between 1 and 12
	if (newMonth >= 1 && newMonth <= 12) {
    	month = newMonth;
	}
}
 
void Appointment::setDay(int newDay) {
	// Set the day if it's between 1 and 31
	if (newDay >= 1 && newDay <= 31) {
    	day = newDay;
	}
}
 
void Appointment::setTime(int newTime) {
	// Set the time if it's a valid military time
	if (newTime >= 0 && newTime <= 2359 && newTime % 100 < 60) {
    	time = newTime;
	}
}
 
void Appointment::setDuration(int newDuration) {
	// Set the duration if it's positive
	if (newDuration > 0) {
    	duration = newDuration;
	}
}
 
void Appointment::setDate(int newYear, int newMonth, int newDay) {
	// Set the date using the provided year, month, and day
	setYear(newYear);
	setMonth(newMonth);
	setDay(newDay);
}
 
std::string Appointment::militaryToStandard(int time) {
	// Convert military time to standard time
	int hour = time / 100;
	int minute = time % 100;
	std::string period = (hour < 12) ? "AM" : "PM";
 
	if (hour > 12) hour -= 12;
	if (hour == 0) hour = 12;
 
	std::ostringstream ss;
	ss << hour << ":" << std::setfill('0') << std::setw(2) << minute << period;
	return ss.str();
}
 
int Appointment::standardToMilitary(std::string time) {
	// Convert standard time to military time
	std::istringstream ss(time);
	int hour, minute;
	std::string period;
 
	ss >> hour;
	ss.ignore();  // Ignore the separator (':' or ' ')
	ss >> minute;
	ss >> period;
 
	if ((period == "PM" || period == "pm" || period == "pM") && hour != 12) hour += 12;
	if ((period == "AM" || period == "am" || period == "aM") && hour == 12) hour = 0;
 
	return hour * 100 + minute;
}


