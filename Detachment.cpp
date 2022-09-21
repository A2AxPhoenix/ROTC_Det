#include "Detachment.h"
using D = Detachment;
	// Constructors
	D::Detachment() {
		unitNumber = 0;
		name = "Insert Name Here";
		city = "Insert City Here";
		state = "Insert State Here";
		region = "Insert Region Here";
		school = "Insert School Here";
	}

	D::Detachment(uint32_t newUnitNumber, std::string newName, std::string newCity, std::string newState, std::string newRegion, std::string newSchool) {
		set_unitNumber(newUnitNumber);	
		set_name(newName);
		set_city(newCity);
		set_state(newState);
		set_region(newRegion);
		set_school(newSchool);
	}

		// Accessors
		uint32_t D::get_unitNumber() const { return unitNumber; }
		std::string D::get_name() const { return name; }
		std::string get_city() const;
		std::string get_state() const;
		std::string get_region() const;
		std::string get_school() const;
		std::vector<Cadre> get_staff() const;
		std::vector<Flight> get_flight() const;
		std::vector<Cadet> get_cadets() const;
		std::vector<Person> get_chainOfCommand() const;	
		
		// Mutators
		void set_unitNumber(uint32_t newUnitNumber);
		void set_name(std::string newName);
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
			return 
		}
		
		friend std::ostream& operator<<(std::ostream& outs, const Detachment &d);
		std::istream& operator>>(std::istream& ins, Detachment &d) {
			ins >> d.unitNumber >> d.name >> d.city >> d.state >> d.region >> d.school;
			return ins;
		}
};

	bool sort_on_unitNumber(const Detachment &d1, const Detachment &d2);
	bool sort_on_region(const Detachment &d1, const Detachment &d2);
	void print_Det_Info(const Detachment &d);
	void print_cadre(const Detachment &d);
	void print_CoC(const Detachment &d);
	void print_flight(const Detachment &d);
	void print_roster(const Detachment &d);
	


#endif
