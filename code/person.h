#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
protected:
    std::string name_, surname_;
    Person() : name_(""), surname_(""){};
    Person(const std::string &name, const std::string &surname) : name_(name), surname_(surname){};
    virtual ~Person(){};

public:
    inline std::string get_Name() const { return name_; }
    inline std::string get_Surname() const { return surname_; }
    void set_Name(std::string name) { this->name_ = name; }
    void set_Surname(std::string surname) { this->surname_ = surname; }
    //virtual void Print() const = 0;
};

#endif