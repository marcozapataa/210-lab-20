#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 3;

class Chair {
private:
	int legs;
	double * prices;
public:
	// constructors
	Chair() {
		prices = new double[SIZE];
		legs = rand() % 2 + 3;
		for (int i = 0; i < SIZE; i++)
			prices[i] = (rand() % (99999 - 10000 + 1) + 10000) / 100.0;
	}
	Chair(int l, double p[3]) {
		prices = new double[SIZE];
		legs = l;
		for (int i = 0; i < SIZE; i++)
			prices[i] = p[i];
	}
	
    // destuctor
    ~Chair() {
        delete[] prices;
    }
	// setters and getters
	void setLegs(int l) {
		legs = l;
	}
	
	int getLegs() {
		return legs;
	}
	
	void setPrices(double p1, double p2, double p3) {
		prices[0] = p1;
		prices[1] = p2;
		prices[2] = p3;
	}
	
	double getAveragePrices() {
		double sum = 0;
		for (int i = 0; i < SIZE; i++)
			sum += prices[i];
		return sum / SIZE;
	}
	
	void print() {
		cout << "CHAIR DATA - legs: " << legs << endl;
		cout << "Price history: " ;
		for (int i = 0; i < SIZE; i++)
			cout << prices[i] << " ";
		cout << endl << "Historical avg price: " << getAveragePrices();
		cout << endl << endl;
	}
};

int main() {

    srand(time(0));
	
	cout << fixed << setprecision(2);
	
    cout << "==== FIRST CHAIR ====\n";
	//creating pointer to first chair object
	Chair *chairPtr = new Chair;
	chairPtr->setLegs(4);
	chairPtr->setPrices(121.21, 232.32, 414.14);
	chairPtr->print();
    delete chairPtr;
    chairPtr = nullptr;

    double livingPrices[3] = {525.25, 434.34, 252.52};

    cout << "==== LIVING CHAIR ====\n";
	//creating dynamic chair object with constructor
	Chair *livingChair = new Chair(3, livingPrices);
	livingChair->print();
	delete livingChair;
	livingChair = nullptr;
	
    cout << "==== CHAIR COLLECTION ====\n";
	//creating dynamic array of chair objects
	Chair *collection = new Chair[SIZE];
	
	for (int i = 0; i < SIZE; i++) {
        cout << "--- Chair: " << i + 1 << " ---" << endl;
        collection[i].print();

    }
    delete[] collection;
    collection = nullptr;
	
	return 0;
}