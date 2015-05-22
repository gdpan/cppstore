///////////////////////////////////////////////////////////////////////////////
// Implementation of Car, SUV, Sedan

#include "car.hh"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// Class car

using namespace Test;

Car::Car(const Car& c) {
	id = c.id;
	plate = c.plate;
	brand = c.brand;
	capacity = c.capacity;	
}

Car::Car(Car&& c) {
	swap(c);
	clear(c);
}

Car& Car::operator= (const Car& c) {
	Car tmp(c);
	*this = move(tmp);
	return *this;
}

Car& Car::operator= (Car&& c) {
	swap(c);
	clear(c);
	return *this;
}

void Car::swap(Car& c) {
	std::swap(id, c.id);
	std::swap(plate, c.plate);
	std::swap(brand, c.brand);
	std::swap(capacity, c.capacity);
}

void Car::clear(Car& c) {
	c.id = 0;
	c.plate = "";
	c.brand = "";
	c.capacity = 0;
}

///////////////////////////////////////////////////////////////////////////////
// class SUV
SUV& SUV::operator= (const SUV& s) {
	Car::operator=(s);
	hasThirdRowSeat = s.hasThirdRowSeat;
	return *this;
}

SUV& SUV::operator= (SUV&& s) {
	Car::operator=(move(s));
	hasThirdRowSeat = s.hasThirdRowSeat;
	clear(s);
	return *this;
}

void SUV::swap(SUV& s) {
	Car::swap(s);
	std::swap(hasThirdRowSeat, s.hasThirdRowSeat);
}

void SUV::clear(SUV& s){
	Car::clear(s);
	s.hasThirdRowSeat = false;
}

///////////////////////////////////////////////////////////////////////////////
// class Sedan

Sedan& Sedan::operator= (const Sedan& s) {
	Car::operator=(s);
	hasSportPackage = s.hasSportPackage;
	return *this;
}

Sedan& Sedan::operator= (Sedan&& s) {
	Car::operator=(move(s));
	hasSportPackage = s.hasSportPackage;
	clear(s);
	return *this;
}

void Sedan::swap(Sedan& s) {
	Car::swap(s);
	std::swap(hasSportPackage, s.hasSportPackage);
}

void Sedan::clear(Sedan& s){
	Car::clear(s);
	s.hasSportPackage = false;
}

