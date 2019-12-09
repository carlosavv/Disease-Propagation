#include <iostream>
#include <vector>
#include <random>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::cin;

class Person{

	public:
		string status;
		int days_infected;
		Person(){
			int count_days=0;
			status = "susceptible";
		}
		void setStatus(string new_status) {
		    status = new_status;
		}
		int getPDaysInf() {
			return days_infected;
		}
		int infect(int n){
			//cout << "Hello" << endl;
			if (status == "susceptible"){
				status = "infected";
				days_infected = n;
			}
			return 0;
		}
		
		void update(){
			//n++;
			//cout << n << endl;
			if(status == "infected"){
				if(days_infected - 1 == 0){
					status = "recovered";
				}
				else{
					days_infected--;
				}
				
			}
		}
		
		//status_string(): returns a description of the person’s state as a string;
		string status_string(){
			return status;	
		}
		bool is_stable(){
			if ( status == "recovered" || status == "vaccinated"){
				return true;
			}
			else{
				return false;
			}
	    }
};

#include <algorithm>

using std::vector;
using std::find;

class Population{
	public:
		int days_inf;
		int size;
		//vector<Person> population;
		
		population[size][size];
		float probability;
		
		Population(int nppl){
			size = nppl;
			days_inf = 0;
			Person person1;
			Person person2;
			for i in size(pop):
			    populationVec1 = vector<Person>(size,person);
			    
			populationVec2 = vector<Person>(size,person);

			for(int i = 0; i<size;i++){
			    for(int j = 0; j<i;j++){
			        population[size][size] = {populationVec[i][j]};
		        }
			}
		float probability_of_transfer(float p){
			float probability = p;
			return probability;
		}
		int getDaysInf() {
			return days_inf;
		}
		
		void interact(int i, int j,float p) {
		Person p1 = population[i];
		Person p2 = population[j];
		    	if(p1.status_string() == "susceptible" || p2.status_string() == "susceptible") {
				int prob = 1 + (rand() % 100);
				if(prob < probability_of_transfer(p) * 100) {
					if(p1.status_string() == "infected") {
						p2.infect(getDaysInf());
					}
					else if(p2.status_string() == "infected") {
						p1.infect(getDaysInf());
					}
				}
			}	
		population[i] = p1;
		population[j] = p2;
	    }

		int random_infection(int x) {
			int random = rand() % size;
			Person person = population[random];
			while(person.status_string() == "inoculated") {
				random = rand() % size;
				person = population[random];
			}
			person.infect(x);
			population[random] = person;
			return 0;
	    }
		
		void random_inoculation(float j) {
	    	vector<int> inoculatedVec((int)(size * j), 0);
			for(int i = 0; i < (int)(size * j); i++) {
				int random = rand() % size;
				while(find(inoculatedVec.begin(), inoculatedVec.end(), random) != inoculatedVec.end()) {
		    		random = rand() % size;
				}
				inoculatedVec.push_back(random);
				population[random].setStatus("inoculated");
		    }
	    }
		
		//returns person's element in matrix
		Person getPelement(int i){
			return population[i];
		}
		
		int count_susceptible() {
		int num_susc = 0;
		for (int i = 0; i < size; i++) {
			if(population[i].status_string() == "susceptible") {
				num_susc++;
			}
		}
		return num_susc;
	}
		int count_infected() {
		    int num_inf = 0;
		    for(int i = 0; i < size; i++) {
			    if(population[i].status_string() == "infected") {
				    num_inf++;
			    }
		    }
		    return num_inf;
	    }
		//counts how many people are infected
		
		//updates all persons in the population
		
		void update() {
	    	days_inf++;
	    	for(int i = 0; i < population.size(); i++) {
	    		population[i].update();
	    	}
	    
	    }
			
		string population_status(){
			for (int i = 0; i<population.size();i++)
			   {
				if (population[i].status_string() == "susceptible")
				{
				  cout<<"?"<<" ";
				}
				else if (population[i].status_string() == "infected" )
				{
				  cout<<"+"<<" ";
				}
				else if (population[i].status_string() == "inoculated" || population[i].status_string() == "recovered")
				{
				  cout<<"-"<<" ";
				}
			}
			return "";
		}		
};


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
		cout << population.population_status() << endl;
		cout << "On Day " << population.getDaysInf() << ": Number of Infected =  " << population.count_infected() << endl;
		cout << "" << endl;
		numinf = population.count_infected();
		
		for(int i = 0; i < popsize; i++) {
			if(population.getPelement(i).status_string() == "infected" && population.getPelement(i).getPDaysInf() != time_of_disease) {
				for(int j = 0; j < interactions; j++) {
					int x = i;
					int y = rand() % popsize;
					population.interact(x, y,probability);
				}
			}
		}
		population.update();
	}

	cout << "Disease has been eradicated in " << day_count << " days." << endl;
	cout << "Number of people untouched: " << population.count_susceptible() << "." <<  endl;
}


