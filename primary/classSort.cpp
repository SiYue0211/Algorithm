//
// Created by Dawn on 2018/5/6.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
using  namespace std;
class Student{
public:
    Student(std::string name, int id, int age)
            :name(name)
            ,id(id)
            ,age(age){}
    std::string name;
    int id;
    int age;

};

bool IdAscendingComparator(Student a, Student b)
{
    return b.id < a.id;
}

bool AgeDescendingComparator(Student a, Student b)
{
    return a.age < b.age;
}

void print(Student student[], int len)
{
    for(int i=0; i<len; i++)
    {
        Student s = student[i];
        std::cout << "Name: "<<s.name<< " ,Id: "<<s.id <<" , Age: "<< s.age<< std::endl;
    }
}

int main()
{
//    Student* A = new Student("AA", 1, 1);
    Student A("AA", 1000, 21);
    Student B("BB", 1001, 21);
    Student C("CC", 1002, 22);
    Student student[] = {A, B, C};
    print(student, 3);
    sort(student, student+3, AgeDescendingComparator);
    print(student, 3);
}