#include "Detachment.h"
#include <fstream>
#include <set>
#include <stdexcept>
#include <sstream>
using D = Detachment;
//TODO: Finish Documenting the code -- next file Cadre.h

// Default constructor
// To call the default constructor, declare a variable of Detachment type
// Example:
//      Detachment d; // Sets a variable named d of type Detachment
D::Detachment() 
{
    unitNumber = "000";
    name = "Insert Name Here";
    city = "Insert City Here";
    state = "Insert State Here";
    region = "Insert Region Here";
    school = "Insert School Here";
}

// Multi-Parameter Constructor
// To call this constructor, pass parameters when declaring a variable of Detachment type
// Example:
//      Detachment d("123", "Spartans", "San Jose"); // Sets a variable of type D to have a unit number of 123, the name Spartans, and city San Jose
//  NOTE: The example only initializes unitNumber, name, and city. The remaining variables will default.
//  Use mutators to change any value
D::Detachment(std::string newUnitNumber, std::string newName, std::string newCity, std::string newState, std::string newRegion, std::string newSchool) 
{
    set_unitNumber(newUnitNumber);	
    set_name(newName);
    set_city(newCity);
    set_state(newState);
    set_region(newRegion);
    set_school(newSchool);
}

// Returns the unit number of a Detachment -- type std::string 
// Example:
//          Detachment d("035");
//          std::string s = d.get_unitNumber;
//          std::cout << "DET-" << s << std::endl;
//  Output: DET-035
std::string D::get_unitNumber() const { return unitNumber; }
// Returns the name of a Detachment -- type std::string
// Example:
//          Detachment d("035, "Flying Bulldogs");
//          std::string s = d.get_name();
//          std::cout << s << std::endl;
//  Output: Flying Bulldogs
std::string D::get_name() const { return name; }
// Returns the city the Detachment is located in -- type std::string 
// Example:
//          Detachment d("035", "Flying Bulldogs", "Fresno");
//          std::string s = d.get_city();
//          std::cout << s << std::endl;
//  Output: Fresno
std::string D::get_city() const { return city; }
// Returns the state the Detachment is located in -- type std::string
// Example:
//          Detachment d("035", "Flying Bulldogs", "Fresno", "California");
//          std::string s = d.get_state();
//          std::cout << s << std::endl;
//  Output: California
std::string D::get_state() const { return state; }
// Returns the region the Detachment is located in -- type std::string
// Example:
//          Detachment d("035", "Flying Bulldogs", "Fresno", "California", "South-West");
//          std::string s = d.get_region();
//          std::cout << s << std::endl;
//  Output: South-West
std::string D::get_region() const { return region; }
// Returns the school the Detachment is located in -- type std::string
// Example:
//          Detachment d("035", "Flying Bulldogs", "Fresno", "California"., "South-West", "Fresno State");
//          std::string s = d.get_school();
//          std::cout << s << std::endl;
//  Output: Fresno State
std::string D::get_school() const { return school; }
// Returns the staff (cadre) of the Detachment -- stored in a std::vector<Cadre>
// Example:
//          Detachment d;
//          std::vector<Cadre> c; // Assume this is filled with 2 Cadre whose names are "Davis" and "Smith"
//          d.set_staff(c);
//          for (const Cadre &c : d.get_staff()) {
//              std::cout << c.get_name() << " "; // Must #include "Cadre.cpp" to use c.get_name();
//          }
//          std::cout << std::endl;
//  Output: Davis Smith
std::vector<Cadre> D::get_staff() const { return staff; }
// Returns the flights of the Detachment -- stored in a std::vector<Flight>
// Example:
//          Detachment d;
//          std::vector<Flight> f; // Assume this is filled with 2 Flights whose names are "Alpha" and "Bravo"
//          d.set_flight(f);
//          for (const Flight &f : d.get_flight()) {
//              std::cout << f.get_name() << " "; // Must #include "Flight.cpp" to use f.get_name()
//          }
//          std::cout << std::endl;
//  Output: Alpha Bravo
std::vector<Flight> D::get_flight() const { return flights; }
// Returns the cadets in the Detachment -- stored in a std::vector<Cadet>
// Example:
//          Detachment d;
//          std::vector<Cadet> roster; // Assume this is filled with 3 cadets whose names are "Ruiz", "Johnson", and "Rodriguez"
//          d.set_cadets(roster);
//          for (const Cadet &c : d.get_cadets()) {
//              std::cout << "Cadet " << c.get_name() << std::endl; // Must #include "Cadet.cpp" to use c.get_name()
//          }
//  Output: Cadet Ruiz
//          Cadet Johnson
//          Cadet Rodriguez
std::vector<Cadet> D::get_cadets() const { return cadets; }
// Returns the chain of command of the Detachment -- stored in a std::vector<Person>
// Example:
//          Detachment d;
//          std::vector<Person> chain; // Assume this is filled with 3 people whose names are "Biden", "Brown", and "Klepper"
//          d.set_chainOfCommand(chain);
//          for (const Person &p: d.get_chainOfCommand()) {
//              std::cout << p.get_name() << std::endl; // Must #include "Person.cpp" to use p.get_name()
//          }
//  Output: Biden
//          Brown
//          Klepper
// NOTE: The program will automatically sort who the chain of command is inside of Person.cpp and Person.h
std::vector<Person> D::get_chainOfCommand() const { return chainOfCommand; }	

// Mutators
// A detachment's unit number has only 3 digits.
//  Example: 
//          Detachment d;
//          d.set_unitNumber("035"); // Sets d's unitNumber to 035
//  Handled Cases:
//          DET-002 is valid
//          DET-0034 is invalid
//          DET-ABC is invalid
//          DET-!@# is invalid
void D::set_unitNumber(std::string newUnitNumber) 
{
    const uint8_t UNIT_NUM_SIZE = 3;
    for (char c : newUnitNumber) 
	{
        if (!isdigit(c)) 
		{
            throw std::runtime_error("Detachments can only have numerical values.\n");
        }
    }
    if (newUnitNumber.size() != UNIT_NUM_SIZE) 
	{
        throw std::runtime_error("Unit Numbers for Detachments can only be values from 000 to 999.\n");
    }
    unitNumber = newUnitNumber;
}
// A detachment's name can only be up to 100 characters long.
// Punctuation is not allowed other than to hypenate two words
//  Example: 
//          Detachment d;
//          d.set_name("Flying Bulldogs"); // Sets d's name to Flying Bulldogs
//  Handled Cases:
//          Flying Bulldogs is valid
//          !Flying Bulldogs is invalid
//          Flying-Bulldogs is valid
//          Fl1y1ng Bulldog5 is invalid
void D::set_name(std::string newName) 
{
    const uint8_t MAX_SIZE = 100;
    if (newName.size() > MAX_SIZE) 
	{
        throw std::runtime_error("Unit Names can only be up to 100 characters long.\n");
    }
    for (const char &c: newName) 
	{
        if (ispunct(c) and c != '-') 
		{
            throw std::runtime_error("The only punctuation allowed is a hypen ('-')\n");
        }
        if (isdigit(c)) 
		{
            throw std::runtime_error("Names can only be alphabetical characters.\n");
        }
    }
    name = newName;
}
// A detachment's city can only be a city in the United States.
// The file cities.txt keeps an updated list of every city in the United States and its territories.
//  Example:
//          Detachment d;
//          d.set_city("New York");
//  Handled Cases:
//          New York City is invalid (New York City City would be redundant)
//          London is invalid is not in the United States
//          Portland is valid since it is in the United States
void D::set_city(std::string newCity) 
{
	std::fstream file("cities.txt");
	if (!file) 
	{
		throw std::runtime_error("This file does not exist.\n");
	}
	std::set<std::string> cities;
	while (file) 
	{
		std::string line;
		getline(file, line);
		std::stringstream read(line);
		std::string cityData;
	getline(read, cityData, '\n');
		if (!file) 
		{
			break;
		}
		cities.insert(cityData);
	}
	auto search = cities.find(newCity);
	if (search == cities.end()) 
	{
		throw std::runtime_error("This city does not exist in the United States or its territories.\n");
	}
	city = newCity;
}
// A detachment's state can only be one of the valid 50 states plus DC.
// The file states.txt keeps an updated list of every state in the United States and its territories.
//  Example:
//          Detachment d;
//          d.set_state("Oregon");
//  Handled Cases:
//          California is valid
//          District of Columbia is valid
//          DC is invalid (No abbreviations)
//          Puerto Rico is invalid (Territories are not valid)
void D::set_state(std::string newState) 
{
	std::fstream file("states.txt");
	if (!file) 
	{
		throw std::runtime_error("This file does not exist.\n");
	}
	std::set<std::string> states;
	while (file) 
	{
		std::string line;
		getline(file, line);
		std::stringstream read(line);
		std::string stateData;
		getline(read, stateData, '\n');
		if (!file) 
		{
			break;
		}
		states.insert(stateData);
	}
	auto search = states.find(newState);
	if (search == states.end()) 
	{
		throw std::runtime_error("This state does not exist in the United States or its territories.\n");
	}
	state = newState;
}
// A detachment's region can only be one of the four valid regions
// The Regions are: Southwest, Northwest, Northeast, Southeast
//  Example:
//          Detachment d;
//          d.set_region("Southwest");
//  Handled Cases:
//          Southwest is valid
//          South-West is invalid (No hypenated regions)
//          SW is invalid (No abbreviations)
//          Midwest is invalid (Invalid Region)
void D::set_region(std::string newRegion) 
{
    const std::string SW = "Southwest";
    const std::string NW = "Northwest";
    const std::string SE = "Southeast";
    const std::string NE = "Northeast";
    if (newRegion != SW or newRegion != NW or newRegion != SE or newRegion != NE) 
    {
        throw std::runtime_error("The only valid options for regions are:\n1. Southwest\n2.Southeast\n3.Northwest\n4.Northeast\n");
    }
	region = newRegion;	
}
// A detachment's school can only be a string of characters of max size 255.
// Schools currently are allowed to be abbreviated or non-accredited.
//  Example:
//          Detachment d;
//          d.set_school("Fresno State");
//  Handled Cases:
//          Fresno State is valid
//          California State University, Fresno is valid
//          University of California, Los Angeles is valid
//          Any string greater than or eaual to 255 characters is invalid
void D::set_school(std::string newSchool) 
{
    if (newSchool.size() >= std::numeric_limits<uint8_t>::max()) 
    {
        throw std::runtime_error("Maximum character size cannot exceed 255 characters.\n");
    }
    school = newSchool;
}
// A detachment's staff can be a vector of any number of Cadre.
// To utilize this, you will need to have Cadre.h and Cadre.cpp in your directory
//  Example:
//          Detachment d;
//          d.set_staff(det_035); // Assume det_035 is an initialized vector with 4 names
//  Handled Cases are handled within Cadre.cpp and Cadre.h        
void D::set_staff(std::vector<Cadre> newStaff) 
{
    staff = newStaff;
}
// A detachment's flight can be a vector of any number of flights.
// To utilize this, you will need to have Flight.h and Flight.cpp in your directory
//  Example:
//          Detachment d;
//          d.set_flight(detFlights); // Assume detFlights is an initialized vector with 4 flights
//  Handled Cases are handled within Flight.cpp and Flight.h        
void D::set_flight(std::vector<Flight> newFlight) 
{
    flights = newFlight;
}
// A detachment's cadets can be a vector of any number of Cadets.
// To utilize this, you will need to have Cadet.h and Cadet.cpp in your directory
//  Example:
//          Detachment d;
//          d.set_cadets(detRoster); // Assume detRoster is an initialized vector with 30 names
//  Handled Cases are handled within Cadet.cpp and Cadet.h        
void D::set_cadets(std::vector<Cadet> newCadets) 
{
    cadets = newCadets;
}
// A detachment's chain of command can be a vector of specified number of Persons.
// To utilize this, you will need to have Person.h and Person.cpp in your directory
// Person.h and Person.cpp will handle the comparisons of the chain of command
//  Example:
//          Detachment d;
//          d.set_chain(det_chain); // Assume det_chain is an initialized vector with 4 names
//  Handled Cases are handled within Person.cpp and Person.h        
void D::set_chainOfCommand(std::vector<Person> newChainOfCommand) 
{
    chainOfCommand = newChainOfCommand;
}
// When comparing two detachments, it utilizes the unit number as the key
// Example: 
//          Detachment d1("000");
//          Detachment d2("001);
//          if (d1 < d2) std::cout << "d1 is less than d2\n";
//          else std::cout << "d2 is less than d1\n";
bool D::operator<(const Detachment &d) 
{
    return unitNumber < d.get_unitNumber();
}
// When comparing if two detachments are equal to each other, it will use the unit number as the key
//  Example:
//          Detachment d1("000");
//          Detachment d2("000");
//          if (d1 == d2) std::cout << "These detachments are similar.\n";
//          else std::cout << "These detachments are different.\n";
bool D::operator==(const Detachment &d) 
{
    return unitNumber == d.get_unitNumber(); 
}

std::ostream& operator<<(std::ostream& outs, const Detachment &d) 
{
    outs << "Det-" << d.get_unitNumber() << " - ";
    outs << d.get_name() << std::endl;
    outs << d.get_school() << ", " << d.get_region() << std::endl;
    outs << d.get_city() << ", " << d.get_state() << std::endl;
    return outs;
}

std::istream& operator>>(std::istream& ins, Detachment &d) 
{
    ins >> d.unitNumber >> d.name >> d.city >> d.state >> d.region >> d.school;
    return ins;
}
// Sorts based on unit number.
//  Example:
//          vector<Detachment> detachments;
//          Detachment d1("000");
//          Detachment d2("035");
//          detachments.push_back(d1);
//          detachments.push_back(d2);
//          sort(detachments.begin(), detachments.end(), sort_on_unitNumber);
bool sort_on_unitNumber(const Detachment &d1, const Detachment &d2) 
{ 
	return d1.get_unitNumber() < d2.get_unitNumber();
}
// Sorts based on region. If the regions are similar, sort on unit number
// Example:
//          Detachment d1("001");
//          Detachment d2("002");
//          Detachment d3("035");
//          Detachment d4("090");
//          vector<Detachment> detachments;
//          detachments.push_back(d1);
//          detachments.push_back(d2);
//          detachments.push_back(d3);
//          detachments.push_back(d4);
//          d1.set_region("Southwest");
//          d2.set_region("Northwest");
//          d3.set_region("Southwest");
//          d4.set_region("Northwest");
//          sort(detachments.begin(), detachments.end(), sort_on_region);
bool sort_on_region(const Detachment &d1, const Detachment &d2) 
{
    if (d1.get_region() == d2.get_region()) 
    {
        return d1.get_unitNumber() < d2.get_unitNumber();
    }
	return d1.get_region() < d2.get_region();
}

void print_Det_Info(const Detachment &d) 
{
    std::cout << "Det-" << d.get_unitNumber() << " - ";
    std::cout << d.get_name() << std::endl;
    std::cout << d.get_school() << ", " << d.get_region() << std::endl;
    std::cout << d.get_city() << ", " << d.get_state() << std::endl;
}
// TODO: Get this functions working by completing the correct files.
void print_cadre(const Detachment &d) 
{
    std::cout << "============   CADRE   ============\n";
    for (const Cadre &c : d.get_staff())
    {
//        std::cout << c.get_name() << std::endl;
    }
}

// TODO: Get this functions working by completing the correct files.
void print_CoC(const Detachment &d) 
{
    std::cout << "============   CHAIN OF COMMAND   ============\n";
    for (const Person &p : d.get_chainOfCommand())
    {
  //      std::cout << p.get_name() << ": " << p.get_rank() << std::endl;
    }
}

// TODO: Get this functions working by completing the correct files.
void print_flight(const Detachment &d) 
{
    std::cout << "============   FLIGHTS   ============\n";
    for (const Flight &f : d.get_flight()) 
    {
    //    std::cout << "======   " << f.get_name() << " FLIGHT   ======\n";
      //  for (const Cadet &c : f.get_cadets()) 
        {
        //    std::cout << c.get_name() << ": " << c.get_class() << std::endl;
        }
    }
}

// TODO: Get this functions working by completing the correct files.
void print_roster(const Detachment &d) 
{
    std::cout << "============   ROSTER   ============\n";
    for (const Cadet &c : d.get_cadets())
    {
        //std::cout << c.get_rank() << " " << c.get_name() << ": " << c.get_class() << std::endl;
    }
}
