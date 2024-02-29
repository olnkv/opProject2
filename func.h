#ifndef FUNC_H
#define FUNC_H

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

const vector<string> nameList{"Nojus", "Domas", "Arvydas", "Rokas", "Vytautas", "Aurimas", "Joris", "Ramunas", "Povilas", "Mindaugas"};
const vector<string> surnameList{"Vaicekauskas", "Kateiva", "Kardauskas", "Zalionis", "Norkus", "Ozelis", "Stasiunas", "Oginskas", "Petrauskas", "Pakuckas"};
int paz, st; // generuojamu pazymiu ir studentu skaicius
string file; // failo pavadinimas

void SortChoice(vector<User> &stud);
int RandNumber();
void ReadFile(vector<User> &stud);
void ReadUser(vector<User> &stud);
void Result(vector<User> &stud);
double Average(User stud);
double Median(User stud);


#endif
