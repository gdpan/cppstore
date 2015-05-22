#ifndef __CARRENTAL__HH__
#define __CARRENTAL__HH__

///////////////////////////////////////////////////////////////////////////////
// Class CarRental

#include <deque>
#include "car.hh"
#include <memory>

using namespace std;

namespace Test {

class CarRental
{
	public:
		CarRental(){}
		virtual ~CarRental(){}


	public:
		void addCar(const Car& c) {
			shared_ptr<Car> cp(new Car(c));
			carBook.push_back(cp);
		}
		void deleteCar(const Car& c) {
			for(auto i=carBook.begin(); i!=carBook.end();i++) {
				if (c.getId() == (*i)->getId()) {
					carBook.erase(i);
					return;
				}	
			}
		}

		void listBook() {
			for(auto i=carBook.begin(); i!=carBook.end();i++) {
				cout << **i << endl;
			}
		}
		bool retrieve(unsigned id, Car& c) {
			for(auto i=carBook.begin(); i!=carBook.end();i++) {
				if (id == (*i)->getId()) {
					c = **i;
					return true;
				}	
			}
			return false;
		}
		unsigned checkCapacity(const Car& c) {
			return c.getCapacity();
		}

	protected:
		deque<shared_ptr<Car> > carBook;
};

};

#endif
