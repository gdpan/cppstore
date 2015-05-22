#ifndef __CAR__HH__
#define __CAR__HH__
///////////////////////////////////////////////////////////////////////////////
// Car class

#include <string>
#include <iostream>

using namespace std;

namespace Test {

class Car 
{
	public:
		Car():id(0),
			  plate(""),
			  brand(""),
			  capacity(0){}
		Car(const int id,
			const string plate,
			const string brand,
			const unsigned capacity):id(id), plate(plate), 
									brand(brand), capacity(capacity){}
		Car(const Car& c);
		Car(Car&& c);
		Car& operator= (const Car& c);
		Car& operator= (Car&& c);
		void swap(Car& c);
		void clear(Car& c);

		virtual ~Car(){}

	public:
		int getId() 		const {return id;}
		string getPlate() 	const {return plate;}
		string getBrand() 	const {return brand;}

		virtual unsigned getCapacity() const{return capacity;};

		void setId(const int id) {this->id = id;}
		void setPlate(const string plate) {this->plate = plate;}
		void setBrand(const string brand) {this->brand = brand;}
		void setCapacity(const unsigned capacity) {this->capacity = capacity;}
	protected:
		int id;
		string plate;
		string brand;
		unsigned capacity;

	private:
		friend ostream& operator<< (ostream& os, const Car& c) {
			os << "Id " 	<< c.id 	<< " plate " 	<< c.plate
			   << " brand " << c.brand 	<< " capacity " << c.capacity 
			   << endl;
		   return os;	
		}
};

///////////////////////////////////////////////////////////////////////////////
// SUV class

class SUV : public Car
{
	public:
		SUV():	Car(),
				hasThirdRowSeat(false) {}
		SUV(const int id,
			const string plate,
			const string brand,
			const unsigned capacity,
			const bool hasThirdRowSeat):Car(id, plate, brand, capacity),
										hasThirdRowSeat(hasThirdRowSeat){}
		SUV(const SUV& s):Car(s) {hasThirdRowSeat=s.hasThirdRowSeat;}
		SUV(SUV&& s):Car(move(s)) {
			hasThirdRowSeat = s.hasThirdRowSeat;
			clear(s);
		}
		SUV& operator= (const SUV& s);
		SUV& operator= (SUV&& s);
		void swap(SUV& s);
		void clear(SUV& s);

		virtual ~SUV(){}
	
	protected:
		bool hasThirdRowSeat;

	private:		
		friend ostream& operator<< (ostream& os, const SUV& c) {
			os << "Id " 	<< c.id 	<< " plate " 	<< c.plate
			   << " brand " << c.brand 	<< " capacity " << c.capacity 
			   << " hasThirdRowSeat " << (c.hasThirdRowSeat ? "Yes": "No")
			   << endl;
		   return os;	
		}
};

///////////////////////////////////////////////////////////////////////////////
// Sedan class

class Sedan : public Car
{
	public:
		Sedan():Car(),
	   			hasSportPackage(false)	{}
		Sedan(const int id,
			  const string plate,
			  const string brand,
			  const unsigned capacity,
			  const bool hasSportPackage):Car(id, plate, brand, capacity),
	   									  hasSportPackage(hasSportPackage) {}	
		Sedan(const Sedan& s):Car(s) {hasSportPackage = s.hasSportPackage;}
		Sedan(Sedan&& s):Car(move(s)) {
			hasSportPackage = s.hasSportPackage;
			clear(s);
		}
		Sedan& operator= (const Sedan& c);
		Sedan& operator= (Sedan&& c);
		void swap(Sedan& c);
		void clear(Sedan& c);

		virtual ~Sedan(){}

	public:
		bool withSportPackage() const { return hasSportPackage;}
		void setSportPackage(bool has) {hasSportPackage = has;}
	
	protected:
		bool hasSportPackage;

	private:		
		friend ostream& operator<< (ostream& os, const Sedan& c) {
			os << "Id " 	<< c.id 	<< " plate " 	<< c.plate
			   << " brand " << c.brand 	<< " capacity " << c.capacity 
			   << " hasSportPackage " << (c.hasSportPackage ? "Yes": "No")
			   << endl;
		   return os;	
		}

};
}
#endif 
