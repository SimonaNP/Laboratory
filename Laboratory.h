#ifndef LABORATORY_H_INCLUDED
#define LABORATORY_H_INCLUDED

#include <queue>

#include "MedicalExamination.h"

class Laboratory{
private:
    std::string name;
    std::queue<MedicalExamination*> examinationList;

    void copy(const Laboratory& other){
        name=other.name;

        examinationList=other.examinationList;
    }

    void clear(){
        while(!examinationList.empty()){
            examinationList.pop();
        }
    }
public:
    Laboratory(std::string _name, std::queue<MedicalExamination*> lst){
        while(_name.empty()){
            std::cout<<"Name should not be empty! Please input name!\n";
            std::cin>>_name;
        }
        name=_name;

        while(!lst.empty()){
            examinationList.push(lst.front());
            lst.pop();
        }
    }

    Laboratory(const Laboratory& other){
        copy(other);
    }

    Laboratory& operator=(const Laboratory& other){
        if(this!=&other){
            clear();
            copy(other);
        }
        return *this;
    }

    ~Laboratory(){
        clear();
    }

    void addExamination(const MedicalExamination& newElem){
        examinationList.push(newElem.clone());
    }

    void removeExamination(){
        if(examinationList.empty())
            std::cout<<"All examinations are completed\n";
        else{

            examinationList.pop();
        }
    }

    double getPrice() const{
        double pr=0;
        std::queue<MedicalExamination*> copy = examinationList;
        while(!copy.empty()){
            pr+=copy.front()->getPrice();
            copy.pop();
        }

        return pr;
    }

    MedicalExamination* firstToBeCompleted(){
        unsigned int minTime = 0;
        MedicalExamination* fastest=nullptr;
        std::queue<MedicalExamination*> copy = examinationList;
        while(!copy.empty()){
            if(minTime>copy.front()->getTime()){
                minTime = copy.front()->getTime();
                fastest = copy.front();
            }
            copy.pop();
        }
        return fastest;

    }

};

#endif // LABORATORY_H_INCLUDED
