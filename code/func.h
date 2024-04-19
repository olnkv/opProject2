#ifndef func_h
#define func_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <random>
#include <string>
#include <chrono>

class Student
{
private:
    std::string name_;
    std::string surname_;
    double exRes_;
    std::vector<int> hwRes_;
    double avg_, med_;

public:
    Student();
    Student(std::string name, std::string surname);
    inline std::string get_Name() const { return name_; }
    inline std::string get_Surname() const { return surname_; }
    std::vector<int> get_HwRes() const { return hwRes_; }
    double get_exRes() const { return exRes_; }
    double get_Avg() const { return avg_; }
    double get_Med() const { return med_; }
    bool hwRes_Empty() const { return hwRes_.empty(); }
    int hwRes_Size() const { return hwRes_.size(); }
    void hw_Sort() { sort(hwRes_.begin(), hwRes_.end()); }
    int hw_Sum() { return std::accumulate(hwRes_.begin(), hwRes_.end(), 0); }
    int hw_Last() { return hwRes_.back(); }
    ~Student();

    void set_Name(std::string name) { this->name_ = name; }
    void set_Surname(std::string surname) { this->surname_ = surname; }
    void set_ExRes(double exRes) { this->exRes_ = exRes; }
    void set_Avg(double avg) { this->avg_ = avg; }
    void set_Med(double med) { this->med_ = med; }
    void set_Hw(int hw) { this->hwRes_.push_back(hw); }
    void del_LastHw() { this->hwRes_.pop_back(); }
    void clear_Hw() { this->hwRes_.clear(); }
    double Average();
    double Median();
};

bool compareName(const Student &a, const Student &b);
bool compareSurname(const Student &a, const Student &b);
bool compareAvg(const Student &a, const Student &b);
bool compareMed(const Student &a, const Student &b);
int RandGrade();
void CinError();
void GenFile(int size, int hw);
void ReadFile(std::vector<Student> &studVector);
void Selection(std::vector<Student> &studVector, int choice);
void Results(std::vector<Student> studVector);
void ReadUser(std::vector<Student> &studVector);
void GenUser(std::vector<Student> &studVector, int size, int hw);

#endif
