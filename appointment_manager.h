#include <string>
#include <vector>
#include "appointment.h"

class AppointmentManager
{
private:
    std::vector<Appointment> appointments;

public:
    void printSchedules();
    void printSchedulesAtMilitaryTime(std::string militaryTime);
    void addAppointment(std::string data);
    void deleteAppointmentAtStandardTime(std::string standardTime);
    void deleteAppointment(std::string title);

    void getAllAppointtments();
};
