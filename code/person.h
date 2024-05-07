#ifndef PERSON_H
#define PERSON_H

#include <string>

/// @class Person
/// @brief Abstrakti žmogaus klasė
class Person
{
protected:
    std::string name_, surname_;
    /// @brief Default konstruktorius
    Person() : name_(""), surname_(""){};
    /// @brief Žmogaus klasės konstruktorius
    /// @param name Vardas
    /// @param surname Pavardė
    Person(const std::string &name, const std::string &surname) : name_(name), surname_(surname){};
    /// @brief Žmogus klasės destruktorius
    virtual ~Person(){};

public:
    /// @brief Vardo gavimas
    /// @return Vardas
    inline std::string get_Name() const { return name_; }
    /// @brief Pavardės gavimas
    /// @return Pavardė
    inline std::string get_Surname() const { return surname_; }
    /// @brief Vardo nustatymas
    /// @param name 
    void set_Name(std::string name) { this->name_ = name; }
    /// @brief Pavardės nustatymas
    /// @param surname 
    void set_Surname(std::string surname) { this->surname_ = surname; }
};

#endif