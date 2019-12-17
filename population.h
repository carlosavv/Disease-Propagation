#include "person.h"
#include <algorithm>

using std::vector;
using std::find;

class Population{
	public:
		int days_inf;
		int size;
		vector<Person> population;
		float probability;
		
		Population(int nppl){
			size = nppl;
			days_inf = 0;
			Person person;
			population = vector<Person>(size,person);
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
