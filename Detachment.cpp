#include "Detachment.h"
#include <stdexcept>
using D = Detachment;


// Constructors
D::Detachment() {
    unitNumber = "000";
    name = "Insert Name Here";
    city = "Insert City Here";
    state = "Insert State Here";
    region = "Insert Region Here";
    school = "Insert School Here";
}

D::Detachment(std::string newUnitNumber, std::string newName, std::string newCity, std::string newState, std::string newRegion, std::string newSchool) {
    set_unitNumber(newUnitNumber);	
    set_name(newName);
    set_city(newCity);
    set_state(newState);
    set_region(newRegion);
    set_school(newSchool);
}

// Returns a unitNumber of type std::string
// Example:
//          Detachment d("123");
//          string s = d.get_unitNumber;
//          std::cout << "DET-" << s << std::endl;
//  Output: DET-123
std::string D::get_unitNumber() const { return unitNumber; }
std::string D::get_name() const { return name; }
std::string D::get_city() const { return city; }
std::string D::get_state() const { return state; }
std::string D::get_region() const { return region; }
std::string D::get_school() const { return school; }
std::vector<Cadre> D::get_staff() const { return staff; }
std::vector<Flight> D::get_flight() const { return flights; }
std::vector<Cadet> D::get_cadets() const { return cadets; }
std::vector<Person> D::get_chainOfCommand() const { return chainOfCommand; }	

// Mutators
// A detachment's unit number has only 3 digits.
// Example: DET-002 is valid
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
// Example: Flying Bulldogs is valid
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
void set_chainofCommand(std::vector<Person> newChainOfCommand);

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



