#include <iostream>
#include <string>
using namespace std;

class Vehicle{
private:

    int tyres;
    int windows;
    int seats;
    string engine_type;
    long int chasis_number;
    string fuel_type;
    static int life_span;

public:
    // Friend Function Declaration
    friend int total_tyres(Vehicle ob1, Vehicle ob2);
    
    // Conctructors
    
    // Default Constructor
    Vehicle(){
        cout<<"\nA new vehicle is enrolled."<<endl;
    }
    // Paramaterized constructor
    Vehicle(int name){
        cout<<"This vehicle is called "<<name<<endl;
    }
    // Copy Constructor
    Vehicle(Vehicle &vech){
        cout<<"Copy Constructor called"<<endl;
        this->tyres = vech.tyres;
        this->windows = vech.windows;
        this->seats = vech.seats;
        this->engine_type = vech.engine_type;
        this->chasis_number = vech.chasis_number;
    }


    // Setters
    void set_tyres(int tyres){
        this->tyres = tyres;
    }
    void set_windows(int windows){
        this->windows = windows;
    }
    void set_seats(int seats){
        this->seats = seats;
    }
    void set_engine_type(string engine_type){
        this->engine_type = engine_type;
    }
    void set_chasis_number(long int chasis_number){
        this->chasis_number = chasis_number;
    }
    void set_fuel_type(string fuel_type){
        this->fuel_type = fuel_type;
    }

    void print_vehicle_details(){
        cout<<"\nEngine Type: "<<this->engine_type<<endl;
        cout<<"Chasis Number: "<<this->chasis_number<<endl;
        cout<<"Seats: "<<this->seats<<endl;
        cout<<"Windows: "<<this->windows<<endl;
        cout<<"Tyres: "<<this->tyres<<endl;
        cout<<"Fuel Type: "<<this->fuel_type<<endl;
        cout<<"Life Span: "<<life_span<<" Years"<<endl;
    }

    static int vechicle_life(string fuel_type){
        if(fuel_type == "Petrol")
            life_span = 15;
        else
            life_span = 10;
    }

    // Getters
    int get_tyres(){
        return tyres;
    }
    int get_windows(){
        return windows;
    }
    int get_seats(){
        return seats;
    }
    string get_engine_type(){
        return engine_type;
    }
    long int get_chasis_number(){
        return chasis_number;
    }
    string get_fuel_type(){
        return fuel_type;
    }

    // Destructor
    // ~Vehicle(){
    //     cout<<"Destructor is called"<<endl;
    // }

    void operator- (Vehicle& obj){
        cout<<"Windows per seat are: "<<this->seats/obj.windows<<endl;
    }

};

int Vehicle::life_span = 0;

// Frient Function

int total_tyres(Vehicle ob1, Vehicle ob2){
    return ob1.tyres + ob2.tyres; 
}

int main(){
    // Static Allocation
    Vehicle car;

    car.set_engine_type("Twin Turbo");
    car.set_seats(4);
    car.set_tyres(4);
    car.set_windows(2);
    car.set_chasis_number(567765);
    car.set_fuel_type("Diesel");
    Vehicle::vechicle_life(car.get_fuel_type());

    car.print_vehicle_details();
    
    // Dynamic Allocation
    Vehicle *bike = new Vehicle;

    bike->set_engine_type("Two-Cylinder");
    bike->set_seats(2);
    bike->set_tyres(2);
    bike->set_windows(0);
    bike->set_chasis_number(472332);
    bike->set_fuel_type("Petrol");
    Vehicle::vechicle_life(bike->get_fuel_type());

    bike->print_vehicle_details();

    cout<<"Total "<<total_tyres(car, *bike)<<" tyres are required."<<endl;
    // For dynamically created object we have to call the desctructor explicitly.
    delete bike;

    
    return 0;
}