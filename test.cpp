#include <iostream>
#include <vector>
#include <random>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Person{
	private: 
		int days_infected;
		string status;
	public:
		Person(){
			int days_infected;
			string status = "susceptible";
		}
		int infect(int n){
			if (status == "susceptible"){
				status = "infected";
				days_infected = n;
			}
			return 0;
		}
		
		//status_string(): returns a description of the person’s state as astring;
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

int main() {
	Person Joe;
	int idx = 1;
	for (; ; idx++){
		Joe.update();
		float bad_luck = (float)rand()/(float)RAND_MAX;
		if (bad_luck>0.95){
			Joe.infect(5);
		}
	}
}