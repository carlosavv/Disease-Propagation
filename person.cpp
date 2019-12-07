#include <iostream>

using std::string;
using std::cout;
using std::endl;

class person{
    private:
        int infect_days, count_days, n;
        string status;
    public:
        person(){
            status = "susceptible";
            count_days = 0;
        }
        string get_status(){
            return status;
        }
        void set_status(string cond){
            status = cond;
        }
        void infect(int n){
            if(status == "susceptible"){
                status = "sick";
                infect_days = n;
            }
        }
        void update(){
            count_days++;
            if (status == "sick" && infect_days != 1){
                infect_days --;
            }
            else if(status == "sick" && infect_days == 1){
                status = "recovered";
            }
        }
        void status_string(){
            cout << status;
            if (status == "sick"){
                cout << " (" <<  infect_days << " to go)";   
            }
            //return status;
            
        }
        bool is_stable(){
            if (status == "recovered" || status == "innoculated"){
                return true;
            }
            else{
                return false;
            }
        }
    
};

int main(){
    float tolerance = 0.95;
    //cout << "Default probabilty of infection is " << tolerance << endl;
    int day = 0;
    person joe;
    joe = person();
    while(joe.is_stable() != true){
        day++;
        joe.update();
        float bad_luck = (float) rand()/(float)RAND_MAX;
        if (tolerance < bad_luck){
            joe.infect(5);
            cout << "On day " << day <<  " Joe is ";
            //cout << endl;
            joe.status_string();
            cout << endl;

        }
        else{
            cout << "On day " << day <<  " Joe is ";
            joe.status_string();
            cout << endl;
        }   
    }

    return 0;
}
