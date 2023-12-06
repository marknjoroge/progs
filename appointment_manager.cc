// AppointmentManager.cpp

#include "appointment_manager.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

void AppointmentManager::printSchedules()
{
    std::cout << "Handling ps command" << std::endl;
}

void AppointmentManager::printSchedulesAtMilitaryTime(std::string timeArg)
{
    std::cout << "Handling p with time argument: " << timeArg << std::endl;
}

void AppointmentManager::addAppointment(std::string data)
{
    std::cout << "Handling p with time argument: " << data << std::endl;
}

void AppointmentManager::deleteAppointment(std::string title)
{
    std::cout << "Handling dt with data type argument: " << title << std::endl;
}

void AppointmentManager::deleteAppointmentAtStandardTime(std::string standardTime)
{
    std::cout << "Handling a with appointment data argument: " << standardTime << std::endl;
}

void AppointmentManager::getAllAppointtments() {

    std::ifstream inputFile("agenda.txt");

    if (!inputFile.is_open())
    {
        std::cerr << "Unable to open the file." << std::endl;
        return;
    }

    std::vector<Appointment> appointments;

    std::string line;
    while (std::getline(inputFile, line))
    {
        if (!line.empty())
        {
            Appointment newAppointment(line);
            appointments.push_back(newAppointment);
        }
    }

    inputFile.close();

    // Print table header
    std::cout << std::setw(20) << "Title"
              << std::setw(12) << "Date"
              << std::setw(12) << "Time"
              << std::setw(15) << "Duration"
              << "\n";
    std::cout << std::setfill('-') << std::setw(60) << "-" << std::setfill(' ') << "\n";

    // Print appointments in a table
    for (Appointment &appointment : appointments)
    {
        std::cout << std::setw(20) << appointment.getTitle()
                  << std::setw(12) << appointment.getDate()
                  << std::setw(12) << appointment.getStandardTime()
                  << std::setw(15) << appointment.getDuration() << " minutes\n";
    }
}

