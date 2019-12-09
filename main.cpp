
#include "person.h"
#include "population.h"
using std::cout;
using std::endl;
using std::cin;

int main() {
	
	float probability;
	int popsize;
	int interactions;
	int time_of_disease;
	float inoculationPercentage;
	int numinf;

	cout << "Infection probability (0 <= p <= 1) : ";
	cin >> probability;
	cout << "Inoculation Percentage: ";
	cin >> inoculationPercentage; 
	cout << "Disease Duration: ";
	cin >> time_of_disease;
	cout << "Population Size: ";
	cin >> popsize;
	cout << "Number of Interactions: ";
	cin >> interactions;

	Population population(popsize);	
	
	population.random_inoculation(inoculationPercentage);
	population.random_infection(time_of_disease);
	numinf = population.count_infected();
	
	int day_count = 0;
	while(numinf > 0) {
		day_count++;
		cout << "Day " << population.getDaysInf() << ": " << numinf << " infected." << endl;
		numinf = population.count_infected();
		for(int i = 0; i < popsize; i++) {
			if(population.getPelement(i).status_string() == "infected" && population.getPelement(i).getPDaysInf() != time_of_disease) {
				for(int j = 0; j < interactions; j++) {
					int r1 = i;
					int r2 = rand() % popsize;
					population.interact(r1, r2,probability);
				}
			}
		}
		population.update();
		cout << population.population_status() << endl;
	}

	cout << "Disease has been eradicated " << day_count << " days." << endl;
	cout << "Number of people untouched: " << population.count_susceptible() << "." <<  endl;
}
