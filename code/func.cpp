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

void ReadFile(std::vector<Student> &studVector)
{
    try
    {
        std::cout << "Jusu failai: " << std::endl;
        system("dir *.txt");
        std::string fileName;
        std::cout << "Irasykite failo pavadinima (\"exit\", kad baigti darba): ";
        std::cin >> fileName;
        if (fileName == "exit")
            return;

        std::ifstream input(fileName);
        if (!input.is_open())
            throw std::runtime_error("Nepavyko atidaryti failo! :(");

        const auto start = std::chrono::high_resolution_clock::now();

        Student stud;
        std::string line;
        input.ignore(1000, '\n');
        while (std::getline(input, line))
        {
            std::istringstream iss(line);
            std::string name, surname;
            if (!(iss >> name >> surname))
                throw std::runtime_error("Nepavyko nuskaityti failo! :(");
            stud.set_Name(name);
            stud.set_Surame(surname);
            int hw;
            stud.clear_Hw();
            while (iss >> hw)
                stud.set_Hw(hw);
            if (!stud.hwRes_Empty())
            {
                stud.set_ExRes(stud.hw_Last());
                stud.del_LastHw();
                stud.hw_Sort();
                stud.set_Avg(stud.Average());
                stud.set_Med(stud.Median());
            }
            studVector.push_back(stud);
        }

        input.close();
        std::cout << "Failas sekmingai nuskaitytas :)" << std::endl;
        studVector.shrink_to_fit();
        const auto end = std::chrono::high_resolution_clock::now();
        const std::chrono::duration<double> diff = end - start;
        std::cout << "Failo nuskaitymo laikas: " << diff.count() << " sekundes" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Klaida: " << e.what() << '\n';
    }
}

void Selection(std::vector<Student> &studVector, int choice)
{
    try
    {
        if (choice == 1)
        {
            auto best = std::find_if(studVector.begin(), studVector.end(), [](const Student &stud)
                                     { return stud.get_Avg() >= 5.0; });
            if (best != studVector.end())
                studVector.erase(best, studVector.end());
            else
                throw std::runtime_error("Nera studento su vidurkiu >= 5.0");
        }
        if (choice == 2)
        {
            auto best = std::find_if(studVector.begin(), studVector.end(), [](const Student &stud)
                                     { return stud.get_Med() >= 5.0; });
            if (best != studVector.end())
                studVector.erase(best, studVector.end());
            else
                throw std::runtime_error("Nera studento su mediana >= 5.0");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

