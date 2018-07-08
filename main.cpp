#include <iostream>
#include <string>
#include "MedicalExamination.h"
#include "SingleExamination.h"
#include "PackageExamination.h"
#include "Laboratory.h"

int main()
{
    SingleExamination s1("Blood", 1.0, 30,20.5, 32.5);
    SingleExamination s2("Urine", 3.0, 90,0.100, 0.135);
    SingleExamination s3("Liver", 15.0, 800, 50,100);
    SingleExamination s4("Blood", 1.0, 30,20.5, 32.5 );
    SingleExamination s5("Urine", 1.5, 90,0.100, 0.135);
    SingleExamination s6("Heart", 95.5, 400, 65, 110);
    SingleExamination s7("Blood", 1.5, 30,20.5, 32.5);
    SingleExamination s8("Lungs", 65.5, 640, 100, 150);

    std::vector<MedicalExamination*> vect1, vect2;

    vect1.push_back(s2.clone());
    vect1.push_back(s3.clone());
    PackageExamination p1("Liver and Urine", vect1);

    vect1.push_back(s1.clone());
    vect1.push_back(s6.clone());

    PackageExamination p2("Heart and Blood", vect2);

    std::queue<MedicalExamination*> lab;
    lab.push(s3.clone());
    lab.push(s4.clone());
    lab.push(s5.clone());
    lab.push(s7.clone());
    lab.push(s8.clone());
    lab.push(p1.clone());
    lab.push(p2.clone());

    Laboratory laboratory("X", lab);

    std::cout<<laboratory.firstToBeCompleted()->getName()<<std::endl;

    return 0;
}
