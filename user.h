#ifndef USER_H
#define USER_H

#include <vector>
#include <string>

using namespace std;

struct User
{
    string name;       // vardas
    string surname;    // pavarde
    vector<int> hwRes; // namu darbu rezultatai
    int exRes;         // egzamino rezultatai
};

#endif