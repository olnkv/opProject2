#include "func.h"

Student::Student() : hwRes_({0})
{
    name_ = "NeraVardo";
    surname_ = "NeraPavardes";
    exRes_ = 0;
    avg_ = 0.0;
    med_ = 0.0;
}

Student::Student(std::string name, std::string surname) : hwRes_({0})
{
    name_ = name;
    surname_ = surname;
    exRes_ = 0;
    avg_ = 0.0;
    med_ = 0.0;
}

Student::~Student()
{
    hwRes_.clear();
}

double Student::Average()
{
    if (hwRes_Size() > 0)
        return 0.4 * hw_Sum() / hwRes_Size() + 0.6 * get_exRes();
    else
        return 0.6 * get_exRes();
}

double Student::Median()
{
    std::vector<double> hwRes = get_HwRes();
    int size = hwRes_Size();
    if (size % 2 == 0 && size > 0)
        return (hwRes[size / 2 - 1] + hwRes[size / 2]) / 2.0 * 0.4 + 0.6 * get_exRes();
    else if (size % 2 != 0 && size > 0)
        return hwRes[size / 2] * 0.4 + 0.6 * get_exRes();
    else
        return 0.6 * get_exRes();
}

bool compareName(const Student &a, const Student &b)
{
    return a.get_Name() < b.get_Name();
}

bool compareSurname(const Student &a, const Student &b)
{
    return a.get_Surname() < b.get_Surname();
}

bool compareAvg(const Student &a, const Student &b)
{
    return a.get_Avg() < b.get_Avg();
}

bool compareMed(const Student &a, const Student &b)
{
    return a.get_Med() < b.get_Med();
}

int RandGrade()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);
    return dis(gen);
}

void GenFile(int size, int hw)
{
    std::string fileName = "Stud" + std::to_string(size) + ".txt";
    std::ofstream output(fileName);
    std::stringstream out;

    out << std::left << std::setw(25) << "Vardas" << std::setw(25) << "Pavarde";
    for (int i = 1; i <= hw; i++)
        out << std::left << std::setw(10) << "ND" + std::to_string(i) << " ";
    out << std::left << std::setw(10) << "Egz." << std::endl;
    for (int i = 1; i <= size; i++)
    {
        out << std::left << std::setw(25) << "Vardas" + std::to_string(i) << std::setw(25) << "Pavarde" + std::to_string(i);
        for (int j = 0; j < hw; j++)
            out << std::left << std::setw(10) << RandGrade() << " ";
        out << std::left << std::setw(10) << RandGrade() << std::endl;
    }

    output << out.str();
    out.clear();
    output.close();
    std::cout << "Failas: " << fileName << " sugeneruotas sekmingai :)" << std::endl;
}