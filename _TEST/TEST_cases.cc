#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../appointment.h"
 
const int MAX_SCORE = 50;
static int score = 0;
 
TEST_CASE("Testing Appointment Class") {
    SECTION("Default Constructors") {
        Appointment a;
        REQUIRE("N/A" == a.getTitle());
    	score += 5;
	}
 
    SECTION("All Data Appointment Constructors") {
        Appointment a("   Meeting with Bob  |  2019 |4|29| 8:30 AM |15 ");
        a.setDate(2019, 4, 29);
        a.setTime(830);
        a.setDuration(15);
        REQUIRE("Meeting with Bob" == a.getTitle());
        REQUIRE("2019-04-29" == a.getDate().substr(0, 10));
        REQUIRE(830 == a.getTime());
        REQUIRE(15 == a.getDuration());
 
        Appointment b(" Meeting with Bob| 2019| 4| 29| 8:30 pM| 15");
        b.setDate(2019, 4, 29);
        b.setTime(2030);
        b.setDuration(15);
        REQUIRE("Meeting with Bob" == b.getTitle());
        REQUIRE("2019-04-29" == b.getDate());
        REQUIRE(2030 == b.getTime());
        REQUIRE(15 == b.getDuration());
    	score += 15;
	}
 
    SECTION("Getters and Setters") {
        Appointment a;
        a.setDate(2019, 6, 14);
        REQUIRE("2019-06-14" == a.getDate().substr(0, 10));  // Fix for getDate()
 
        a.setMonth(2);
        a.setYear(-2);
        a.setDay(13);
        REQUIRE(2019 == a.getYear());
    	REQUIRE(2 == a.getMonth());
        REQUIRE(13 == a.getDay());
 
        a.setTime(830);
        REQUIRE(830 == a.getTime());
        a.setDuration(30);
        a.setTitle("Appointment Today");
        REQUIRE("2019-02-13" == a.getDate().substr(0, 10));
        REQUIRE(830 == a.getTime());
        REQUIRE(30 == a.getDuration());
        REQUIRE("Appointment Today" == a.getTitle());
        REQUIRE("8:30AM" == a.getStandardTime());
 
        a.setTime(2030);
        REQUIRE("2019-02-13" == a.getDate().substr(0, 10));
        REQUIRE("8:30PM" == a.getStandardTime());
    	score += 10;
	}
 
    SECTION("Military to Standard Conversion") {
        Appointment a;
        REQUIRE("5:50PM" == a.militaryToStandard(1750));
        REQUIRE("5:40AM" == a.militaryToStandard(540));
        REQUIRE("12:00PM" == a.militaryToStandard(1200));
        REQUIRE("12:00AM" == a.militaryToStandard(0));
        REQUIRE("12:40AM" == a.militaryToStandard(40));
    	score += 10;
	}
 
    SECTION("Standard to Military") {
        Appointment a;
        REQUIRE(1900 == a.standardToMilitary("7:00 pM"));
        REQUIRE(540 == a.standardToMilitary("5:40aM"));
    	REQUIRE(0 == a.standardToMilitary("12:00aM"));
        REQUIRE(40 == a.standardToMilitary("12:40 AM"));
        REQUIRE(1200 == a.standardToMilitary("12:00pm"));
    	score += 10;
	}
 
    SECTION("Score") {
    	std::cout << "\033[1;35m" << "\n==========================================" << std::endl;
    	std::cout << "\033[1;33m" << " Score: " << score << "/" << MAX_SCORE << "\033[1;35m" << std::endl;
    	std::cout << "==========================================\n" << "\033[0m" << std::endl;
	}
}

