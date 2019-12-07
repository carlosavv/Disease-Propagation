#include <iostream>
#include <vector>
#include <random>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Person{
	private: 
		string status;
		int days_infected,n;
		int count_days;
	public:
		Person(){
			int count_days=0;
			status = "susceptible";
			
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
			count_days++;

			if (days_infected != 1 && status == "infected")
				days_infected--;
			else if(status == "infected" && days_infected == 1){
				status = "recovered";
			}
		}
		
		
		//status_string(): returns a description of the person’s state as a string;
		string status_string(){
			cout << status;
			if(status == "infected"){
				cout << " ("<< days_infected << " to go)";
			}
			
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
	int n = 5;
	int count = 0;
	
	for (; ; idx++){
		Joe.update();
		float bad_luck = (float)rand()/(float)RAND_MAX;
		if (bad_luck>0.95){
			Joe.infect(n);
		}
		
		cout << "On day " << idx << ", Joe is ";
		Joe.status_string();
		cout << endl;
		

		if(Joe.is_stable()){
			break;
		}

	}	
}
