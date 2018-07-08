#ifndef MEDICALEXAMINATION_H_INCLUDED
#define MEDICALEXAMINATION_H_INCLUDED
#include <string>

class MedicalExamination{
private:
    std::string name;
    double price;
    unsigned int minutes;
public:
    MedicalExamination(std::string _name, double _price=0.0, unsigned int _minutes = 0):  price(_price), minutes(_minutes){
        while(_name.empty()){
            std::cout<<"Name should not be empty! Please input name!\n";
            std::cin>>_name;
        }
        name=_name;
    }

    virtual ~MedicalExamination(){}

    virtual MedicalExamination* clone() const =0;

    void setName(const std::string _name){
        name=_name;
    }

    std::string getName() const {return name;}
    virtual double getPrice() const {return price;}
    virtual unsigned int getTime() const {return minutes;}
};

#endif // MEDICALEXAMINATION_H_INCLUDED
