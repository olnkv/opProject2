#ifndef func_h
#define func_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct User
{
    string name;       // vardas
    string surname;    // pavarde
    vector<int> hwRes; // namu darbu rezultatai
    int exRes;         // egzamino rezultatai
};

void SortChoice(vector<User> &stud);
int RandNumber(int size);
void ReadFile(vector<User> &stud);
void CreateFile();
void SortFile(vector<User> &stud);
void ReadUser(vector<User> &stud);
void Result(vector<User> &stud);
double Average(User stud);
double Median(User stud);

#endif
