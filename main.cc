#include <string>
#include "appointment_manager.h"

int main(int argc, char *argv[])  {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <command> [args...]" << std::endl;
        return 1; // Indicate an error
    }

    AppointmentManager appointmentManager;

    std::string command(argv[1]);

    if (command == "-ps") {
        appointmentManager.printSchedules();
    }
    else if (command == "-p" && argc >= 3) {
        std::string timeArg(argv[2]);
        appointmentManager.printSchedulesAtMilitaryTime(timeArg);
    }
    else if (command == "-a" && argc >= 3) {
        std::string appointmentDataArg(argv[2]);
        appointmentManager.addAppointment(appointmentDataArg);
    }
    else if (command == "-dt" && argc >= 3) {
        std::string dataTypeArg(argv[2]);
        appointmentManager.deleteAppointment(dataTypeArg);
    }
    else if (command == "-dt" && argc >= 3) {
        std::string dataTypeArg(argv[2]);
        appointmentManager.deleteAppointment(dataTypeArg);
    }
    else {
        std::cerr << "Invalid command or missing arguments." << std::endl;
        return 1;
    }

    return 0;
}