#ifndef SINGLEEXAMINATION_H_INCLUDED
#define SINGLEEXAMINATION_H_INCLUDED
#include "MedicalExamination.h"

class SingleExamination : public MedicalExamination{
private:
    double minValue, maxValue;

    bool areCorrectValues(double min, double max){
        return max>min;
    }
public:
    SingleExamination(std::string _name, double _price, unsigned int _minutes, double _min, double _max):MedicalExamination(_name, _price, _minutes){
        while(!areCorrectValues(_min,_max)){
            std::cout<<"Maximum value should be larger than minimum value!\n";
            std::cout<<"Input minimum: "; std::cin>>_min;
            std::cout<<"Input maximum: "; std::cin>>_max;
        }
        minValue=_min;
        maxValue=_max;
    }

    virtual MedicalExamination* clone() const override{
        return new SingleExamination(*this);
    }

    double getMin()const {return minValue;}
    double getMax()const {return maxValue;}
};



#endif // SINGLEEXAMINATION_H_INCLUDED
