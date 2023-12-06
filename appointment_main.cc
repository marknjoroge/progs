// appointment_main.cc
#include "appointment.h"
#include <iostream>
 
int main() {
	// Test default constructor
	Appointment a1;
	std::cout << "Default constructor:\n";
	std::cout << "Title: " << a1.getTitle() << "\n";
	std::cout << "Date: " << a1.getDate() << "\n";
	std::cout << "Time: " << a1.getStandardTime() << "\n";
	std::cout << "Duration: " << a1.getDuration() << "\n";
 
	// Test parameterized constructor
	Appointment a2("   Meeting with Bob   | 2023 | 6 | 23 | 18:30 | 15");
	std::cout << "\nParameterized constructor:\n";
	std::cout << "Title: " << a2.getTitle() << "\n";
	std::cout << "Date: " << a2.getDate() << "\n";
	std::cout << "Time: " << a2.getStandardTime() << "\n";
	std::cout << "Duration: " << a2.getDuration() << "\n";
 
	// Test setters
	a2.setTitle("New Meeting");
	a2.setDate(2024, 7, 24);
	a2.setTime(2030);
	a2.setDuration(30);
	std::cout << "\nAfter using setters:\n";
	std::cout << "Title: " << a2.getTitle() << "\n";
	std::cout << "Date: " << a2.getDate() << "\n";
	std::cout << "Time: " << a2.getStandardTime() << "\n";
	std::cout << "Duration: " << a2.getDuration() << "\n";
 
	return 0;
}
