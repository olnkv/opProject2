// Kompiliavimo komanda mac'ui: clang++ -std=c++11 -stdlib=libc++ -o prog mainV.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include "func.h"
#include "user.h"

using namespace std;
using namespace std::chrono;

int main()
{
    vector<User> stud;
    int choice;
    cout << "Sveiki!\nProgramos eigos pasirinkimas - (\"1\" - skaitymas is failu; \"2\" - ivedimas ranka / generavimas; \"3\" - baigti darba)";
    cin >> choice;

    if (choice == 3)
        exit(0);
    if (choice == 2)
    {
        ReadUser(stud);
        SortChoice(stud);
        Result(stud);
    }
    if (choice == 1)
    {
        int avgTime = 0;
        int count = 1;
        string fileName;
        while (true)
        {
            cout << "Irasykite failo varda (\"exit\", kad pereiti prie rusiavimo): ";
            cin >> fileName;
            if (fileName == "exit")
                break;
            else
                file = fileName;
            auto start = high_resolution_clock::now();
            ReadFile(stud);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Nuskaitymo laikas: "
                 << duration.count() << " mikrosekundes" << endl;
            avgTime += (int)duration.count();
            cout << "Laiku vidurkis: " << avgTime / count << " mikrosekundes" << endl;
            count++;
        }
        SortChoice(stud);
        Result(stud);
    }

    return 0;
}
