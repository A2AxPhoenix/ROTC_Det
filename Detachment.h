#ifndef DETACHMENT_H
#define DETACHMENT_H

#include <iostream>
#include <vector>
#include "Cadre.cpp"
#include "Cadet.cpp"
#include "Flight.cpp"
#include "Person.cpp"

class Detachment {
	private:
        std::string unitNumber;
		std::string name;
		std::string city;
		std::string state;
		std::string region;
		std::string school;
		std::vector<Cadre> staff;
		std::vector<Flight> flights;
		std::vector<Cadet> cadets;
		std::vector<Person> chainOfCommand;	
	public:
		// Constructors
		Detachment();
		Detachment(std::string newUnitNumber, std::string newName, std::string newCity, std::string newState, std::string newRegion, std::string newSchool);

		// Accessors
        std::string get_unitNumber() const;
		std::string get_name() const;
		std::string get_city() const;
		std::string get_state() const;
		std::string get_region() const;
		std::string get_school() const;
		std::vector<Cadre> get_staff() const;
		std::vector<Flight> get_flight() const;
		std::vector<Cadet> get_cadets() const;
		std::vector<Person> get_chainOfCommand() const;	
		
		// Mutators
		void set_unitNumber(std::string newUnitNumber);
		void set_name(std::string newName);
		void set_city(std::string newCity);
		void set_state(std::string newState);
		void set_region(std::string newRegion);
		void set_school(std::string newSchool);
		void set_staff(std::vector<Cadre> newStaff);
		void set_flight(std::vector<Flight> newFlight);
		void set_cadets(std::vector<Cadet> newCadets);
		void set_chainOfCommand(std::vector<Person> newChainOfCommand);

		// Comparison
		bool operator<(const Detachment &d);
		bool operator==(const Detachment &d);
		
		friend std::ostream& operator<<(std::ostream& outs, const Detachment &d);
		friend std::istream& operator>>(std::istream& ins, Detachment &d);
};

	bool sort_on_unitNumber(const Detachment &d1, const Detachment &d2);
	bool sort_on_region(const Detachment &d1, const Detachment &d2);
	void print_Det_Info(const Detachment &d);
	void print_cadre(const Detachment &d);
	void print_CoC(const Detachment &d);
	void print_flight(const Detachment &d);
	void print_roster(const Detachment &d);
	


#endif
