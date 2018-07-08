#ifndef PACKAGEEXAMINATION_H_INCLUDED
#define PACKAGEEXAMINATION_H_INCLUDED
#include "MedicalExamination.h"
#include <vector>

class PackageExamination:public MedicalExamination
{
private:
    std::vector<MedicalExamination*> examinations;

    void del()
    {
        for (std::vector<MedicalExamination*>::iterator it = examinations.begin() ; it != examinations.end(); ++it)
        {
            delete (*it);
        }
        examinations.clear();
    }

public:
    PackageExamination(std::string _name, std::vector<MedicalExamination*>& arr):MedicalExamination(_name)
    {
        for(MedicalExamination* examination : arr)
            examinations.push_back(examination->clone());
    }

    PackageExamination(const PackageExamination& other):MedicalExamination(other)
    {
        for(MedicalExamination* examination : other.examinations)
            this->examinations.push_back(examination->clone());
    }

    PackageExamination& operator=(const PackageExamination& other)
    {
        if(this!=&other)
        {
            MedicalExamination::operator=(other);

            del();
            for(MedicalExamination* examination : other.examinations)
                this->examinations.push_back(examination->clone());
        }
        return * this;
    }

    virtual ~PackageExamination()
    {
        del();
    }


    MedicalExamination* clone() const
    {
        return new PackageExamination(*this);
    }

    double getPrice() const override
    {
        double pr=0;
        for(MedicalExamination* examination : examinations)
            pr+=examination->getPrice();
        return 0.9*pr;
    }

    unsigned int getTime() const override
    {
        unsigned int maxTime=0;
        for(MedicalExamination* examination : examinations)
            if(examination->getTime()>maxTime)
                maxTime=examination->getTime();
        return maxTime;
    }


};

#endif // PACKAGEEXAMINATION_H_INCLUDED
