#include "Detachment.h"
#include <stdexcept>
using D = Detachment;


// Default constructor
// To call the default constructor, declare a variable of Detachment type
// Example:
//      Detachment d; // Sets a variable named d of type Detachment
D::Detachment() {
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
D::Detachment(std::string newUnitNumber, std::string newName, std::string newCity, std::string newState, std::string newRegion, std::string newSchool) {
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
void D::set_unitNumber(std::string newUnitNumber) {
    const uint8_t UNIT_NUM_SIZE = 3;
    for (char c : newUnitNumber) {
        if (!isdigit(c)) {
            throw std::runtime_error("Detachments can only have numerical values.\n");
        }
    }
    if (newUnitNumber.size() != UNIT_NUM_SIZE) {
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
void D::set_name(std::string newName) {
    const uint8_t MAX_SIZE = 100;
    if (newName.size() > MAX_SIZE) {
        throw std::runtime_error("Unit Names can only be up to 100 characters long.\n");
    }
    for (const char &c: newName) {
        if (ispunct(c) and c != '-') {
            throw std::runtime_error("The only punctuation allowed is a hypen ('-')\n");
        }
        if (isdigit(c)) {
            throw std::runtime_error("Names can only be alphabetical characters.\n");
        }
    }
    name = newName;
}
void set_city(std::string newCity);
void set_state(std::string newState);
void set_region(std::string newRegion);
void set_school(std::string newSchool);
void set_staff(std::vector<Cadre> newStaff);
void set_flight(std::vector<Flight> newFlight);
void set_cadets(std::vector<Cadet> newCadets);
void set_chainOfCommand(std::vector<Person> newChainOfCommand);

// Comparison
bool D::operator<(const Detachment &d) {
    return unitNumber < d.get_unitNumber();
}
bool D::operator==(const Detachment &d) {
    return unitNumber == d.get_unitNumber(); 
}

std::ostream& operator<<(std::ostream& outs, const Detachment &d) {
    // TODO: Continue with this
    return outs;
}
std::istream& operator>>(std::istream& ins, Detachment &d) {
    ins >> d.unitNumber >> d.name >> d.city >> d.state >> d.region >> d.school;
    return ins;
}

bool sort_on_unitNumber(const Detachment &d1, const Detachment &d2);
bool sort_on_region(const Detachment &d1, const Detachment &d2);
void print_Det_Info(const Detachment &d);
void print_cadre(const Detachment &d);
void print_CoC(const Detachment &d);
void print_flight(const Detachment &d);
void print_roster(const Detachment &d);



