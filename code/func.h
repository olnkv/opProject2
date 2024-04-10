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
#include <list>
#include <iterator>
#include <deque>

using namespace std;
using namespace std::chrono;

struct User
{
    string name;       // vardas
    string surname;    // pavarde
    vector<int> hwRes; // namu darbu rezultatai
    int exRes;         // egzamino rezultatai
};

struct listUser
{
    string name;
    string surname;
    list<int> hwRes;
    int exRes;
};

struct dqUser
{
    string name;
    string surname;
    deque<int> hwRes;
    int exRes;
};

void SortChoice(vector<User> &stud);
void SortChoiceList(list<listUser> &stud);
void SortChoiceDq(deque<dqUser> &stud);
int RandNumber(int size);
void ReadFile(vector<User> &stud);
void ReadFileList(list<listUser> &stud);
void ReadFileDq(deque<dqUser> &stud);
void CreateFile();
void SortFile(vector<User> &stud);
void SortFileList(list<listUser> &stud);
void SortFileDq(deque<dqUser> &stud);
void ReadUser(vector<User> &stud);
void Result(vector<User> &stud);
double Average(User stud);
double AverageList(listUser stud);
double AverageDq(dqUser stud);
double Median(User stud);

#endif
