#include<iostream>
using namespace std;

// Using friend keyword

class Person{
private:
    string name;
    long long contact;
    int age;
    char marritial_status;
    string city;

public:

    void set_info(string name, long long contact){
        this->name = name;
        this->contact = contact;
    }

    void get_info(void){
        cout<<"\nName: "<<name;
        cout<<"\nContact: "<<contact;

    }
};


int main(){
    Person p1, p2;
    p1.set_info("Anish", 9911647766);
    p2.set_info("Ram", 9632587410);

    p1.get_info();
    p2.get_info();

    return 0;
}