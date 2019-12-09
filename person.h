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
