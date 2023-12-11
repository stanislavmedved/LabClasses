#include <iostream>
#include <vector>

class Truck: Vehicle {
private:
	int mass;
	int wheelCount;
	int cargoCapacity;
public:
	int getMass() { return this->mass; }
	int getWheelCount() { return this->wheelCount; }
	int getCargoCapacity() { return this->cargoCapacity; }

	Truck() : Vehicle(), mass{ 1000 }, wheelCount { 4 }, cargoCapacity{ 1000 } {}

	Truck(int _mass, int _wheelCount, int _cargoCap, std::string _model, int _year, int _power, std::string _reg)
		: Vehicle(_year, _power, _model, _reg), mass{_mass}, wheelCount{_wheelCount},cargoCapacity{_cargoCap}{}

	Truck(int _mass, int _wheelCount, int _cargoCap, std::string _model, int _year, int _power)
		: Vehicle(_year, _power, _model), mass{ _mass }, wheelCount{ _wheelCount }, cargoCapacity{ _cargoCap } {}
};

class Car: Vehicle {
private:
	std::string transmission;
	int seatCount;
	std::string layout;
public:
	std::string getTransmission() { return this->transmission; }
	int getSeatCount() { return this->seatCount; }
	std::string getLayout(){ return this->layout; }

	Car() : Vehicle(), seatCount{4}, layout{"FF"}{}

	Car(int _seatCount, std::string _layout, std::string _model, int _year, int _power, std::string _reg)
		: Vehicle(_year, _power, _model, _reg), seatCount{_seatCount}, layout{_layout} {}

	Car(std::string _tr, int _seatCount, std::string _layout, std::string _model, int _year, int _power, std::string _reg)
		: Vehicle(_year, _power, _model, _reg), seatCount{ _seatCount }, layout{ _layout }, transmission{ _tr } {}
};

class Employee {
private:
	std::string position;
	std::string name;
	std::vector<Vehicle> vehicles;
	int salary;
public:
	void drive(Vehicle vehicle) {
		this->vehicles.push_back(vehicle);
		printf("vroom vroom\nRegistration number: %s\n", this->vehicle.getRegistation());
	}
	Vehicle getVehicle() { return this->vehicle; }

	void setName(std::string name) { this->name = name; }
	std::string getName() { return this->name; }

	void setPosition(std::string position) { this->position = position; }
	std::string getPosition() { return this->position; }

	void setSalary(int salary) { this->salary = salary; }
	int getSalary() { return this->salary; }

	Employee() {
		this->name = "Jane Doe";
		this->position = "Unemployed";
		this->vehicle = Vehicle();
		this->salary = 0;
	}

	Employee(std::string _name, std::string _position, int _salary, Vehicle _vehicle)
		: name{ _name }, position{ _position }, salary{ _salary }, vehicle{ _vehicle } {}
};

class Vehicle {
protected:
	int assemblyYear;
	int horsepowers;
	std::string model;
	std::string registrationNumber;
public:
	std::string getRegistation() { return this->registrationNumber; }
	int getAssemblyYear() { return this->assemblyYear; }
	int getEnginePower() { return horsepowers; }
	std::string getModel() { return this->model; }

	Vehicle()
		:horsepowers{ 1 }, assemblyYear{ 2000 }, model{ "жигуль или типа того" }, registrationNumber{ "00ОАО000-00" } {}
		
	Vehicle(int _power, int _year, std::string _model, std::string _reg) 
		: horsepowers{ _power }, assemblyYear{ _year }, model{ _model }, registrationNumber{ _reg } {}

	Vehicle(int _year, int _power, std::string _model) : model{ _model }, assemblyYear{ _year }, horsepowers{ _power } {}

	Vehicle(std::string _model) : model{ _model }, assemblyYear{ 2000 }, horsepowers{1} {}
};

class Company {
private:
	std::vector<Employee> employees;
	std::vector<Vehicle> vehicles;
	std::string name;
	Employee director;
	int capital;
public:
	void employPerson(Employee employee) {
		this->employees.push_back(employee);
	}
	std::vector<Employee> getEmployees() { return this->employees; }

	void hireDirector(Employee newDirector) { this->director = newDirector; }
	Employee getDirector() { return this->director; }

	void hireVehicle(Vehicle vehicle) {	this->vehicles.push_back(vehicle); }

	void setName(std::string name) { this->name = name; }
	std::string getName() { return this->name; }

	void setCapital(int capital) { this->capital = capital; }
	int getCapital(){ return this->capital; }

	Company() {
		this->director = Employee();
		this->capital = 0;
		this->name = "Шаблон компании";
		this->employees = std::vector<Employee>();
		this->vehicles = std::vector<Vehicle>();
	}
	Company(Employee _director, int _startCapital, std::string _name, std::vector<Employee> _employees, std::vector<Vehicle> _vehicles)
		:director{ _director }, capital{ _startCapital }, name{ _name }, employees{ _employees }, vehicles{ _vehicles } {}
};

int main()
{
	return 0;
} 
