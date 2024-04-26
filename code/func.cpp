#include "func.h"
#include "person.h"

const std::vector<std::string> nameList{"Nojus", "Domas", "Arvydas", "Rokas", "Vytautas", "Aurimas", "Joris", "Ramunas", "Povilas", "Mindaugas"};
const std::vector<std::string> surnameList{"Vaicekauskas", "Kateiva", "Kardauskas", "Zalionis", "Norkus", "Ozelis", "Stasiunas", "Oginskas", "Petrauskas", "Pakuckas"};

Student::Student() : Person()
{
    hwRes_.clear();
    exRes_ = 0;
    avg_ = 0.0;
    med_ = 0.0;
}

Student::Student(const std::string name, const std::string surname) : Person(name, surname)
{
    hwRes_.clear();
    exRes_ = 0;
    avg_ = 0.0;
    med_ = 0.0;
}

Student::~Student()
{
    hwRes_.clear();
}

Student::Student(const Student &Student_) : Person(Student_.name_, Student_.surname_)
{
    hwRes_ = Student_.hwRes_;
    exRes_ = Student_.exRes_;
    avg_ = Student_.avg_;
    med_ = Student_.med_;
    std::cout << "Kopijavimo konstruktorius suveike" << std::endl;
}

Student::Student(Student &&Student_) noexcept : Person(std::move(Student_.name_), std::move(Student_.surname_))
{
    hwRes_ = std::move(Student_.hwRes_);
    exRes_ = std::move(Student_.exRes_);
    avg_ = std::move(Student_.avg_);
    med_ = std::move(Student_.med_);
    Student_.clear_All();
     std::cout << "Perkelimo konstruktorius suveike" << std::endl;
}

Student &Student::operator=(const Student &Student_)
{
    if (this != &Student_)
    {
        name_ = Student_.name_;
        surname_ = Student_.surname_;
        hwRes_ = Student_.hwRes_;
        exRes_ = Student_.exRes_;
        avg_ = Student_.avg_;
        med_ = Student_.med_;
    }
    std::cout << "Priskyrimo operatorius suveike" << std::endl;
    return *this;
}

Student &Student::operator=(Student &&Student_) noexcept
{
    name_ = std::move(Student_.name_);
    surname_ = std::move(Student_.surname_);
    hwRes_ = std::move(Student_.hwRes_);
    exRes_ = std::move(Student_.exRes_);
    avg_ = std::move(Student_.avg_);
    med_ = std::move(Student_.med_);
    Student_.clear_All();
    std::cout << "Perkelimo operatorius suveike" << std::endl;
    return *this;
}

std::istringstream &operator>>(std::istringstream &input, Student &Student_)
{
    std::string name, surname;
    if (!(input >> name >> surname))
        throw std::runtime_error("Nepavyko nuskaityti vardo ir pavardes");
    Student_.set_Name(name);
    Student_.set_Surname(surname);
    int hw;
    Student_.clear_Hw();
    while (input >> hw)
        Student_.set_Hw(hw);
    if (!Student_.hwRes_Empty())
    {
        Student_.set_ExRes(Student_.hw_Last());
        Student_.del_LastHw();
        Student_.hw_Sort();
        Student_.set_Avg(Student_.Average());
        Student_.set_Med(Student_.Median());
    }
    return input;
}

std::istream &operator>>(std::istream &input, Student &Student_)
{
    std::string name, surname;
    int hw, ex;
    std::cout << "Vardas: ";
    std::cin >> name;
    std::cout << "Pavarde: ";
    std::cin >> surname;
    Student_.set_Name(name);
    Student_.set_Surname(surname);
    Student_.clear_Hw();
    while (true)
    {
        std::cout << "Namu darbu pazymys (\"-1\", kad uzbaigti): ";
        std::cin >> hw;
        if (std::cin.fail())
            throw std::runtime_error("Klaidinga ivestis");
        if (hw < 0)
            break;
        Student_.set_Hw(hw);
    }
    std::cout << "Egzamino pazymys: ";
    std::cin >> ex;
    if (std::cin.fail())
        throw std::runtime_error("Klaidinga ivestis");
    Student_.set_ExRes(ex);
    Student_.set_Avg(Student_.Average());
    Student_.set_Med(Student_.Median());
    return input;
}

std::ostream &operator<<(std::ostream &output, const Student &Student_)
{
    output << std::left << std::setw(15) << Student_.get_Surname() << std::setw(15) << Student_.get_Name() << std::setw(20) << Student_.get_Avg() << std::setw(15) << Student_.get_Med() << std::endl;
    return output;
}

std::ofstream &operator<<(std::ofstream &output, const Student &Student_)
{
    std::stringstream out;
    out << std::left << std::setw(15) << Student_.get_Surname() << std::setw(15) << Student_.get_Name() << std::setw(20) << Student_.get_Avg() << std::setw(15) << Student_.get_Med() << std::endl;
    output << out.str();
    out.clear();
    return output;
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
    std::vector<int> hwRes = get_HwRes();
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
    std::string input = "Stud" + std::to_string(size) + ".txt";
    std::ofstream output(input);
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
    std::cout << "Failas: " << input << " sugeneruotas sekmingai :)" << std::endl;
}

void ReadFile(std::vector<Student> &studVector)
{
    try
    {
        std::cout << "Jusu failai: " << std::endl;
        system("ls *.txt");
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
            iss >> stud;
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
        std::cerr << e.what() << '\n';
    }
}

void Selection(std::vector<Student> &studVector, std::vector<Student> &best, int choice)
{
    try
    {
        if (choice == 1)
        {
            const auto start1 = std::chrono::high_resolution_clock::now();
            for (auto it = studVector.begin(); it != studVector.end();)
            {
                if (it->get_Avg() >= 5.0)
                {
                    best.push_back(std::move(*it));
                    it = studVector.erase(it);
                }
                else
                    ++it;
            }
            studVector.shrink_to_fit();
            best.shrink_to_fit();
            if (best.empty())
                throw std::runtime_error("Nera studento su vidurkiu >= 5.0");
            const auto end1 = std::chrono::high_resolution_clock::now();
            const std::chrono::duration<double> diff1 = end1 - start1;
            std::cout << "Studentu atrankos laikas: " << diff1.count() << " sekundes" << std::endl;

            const auto start2 = std::chrono::high_resolution_clock::now();
            std::ofstream output1("Kieti.txt");
            output1 << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << std::setw(15) << "Galutinis (Med.)" << std::endl;
            output1 << "------------------------------------------------------------------" << std::endl;
            output1 << std::fixed << std::setprecision(2);
            for (const auto &i : best)
                output1 << i << std::endl;
            output1.close();
            std::ofstream output2("Vargsiukai.txt");
            output2 << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << std::setw(15) << "Galutinis (Med.)" << std::endl;
            output2 << "------------------------------------------------------------------" << std::endl;
            output2 << std::fixed << std::setprecision(2);
            for (const auto &i : studVector)
                output2 << i << std::endl;
            output2.close();
            const auto end2 = std::chrono::high_resolution_clock::now();
            const std::chrono::duration<double> diff2 = end2 - start2;
            std::cout << "Atrinktu studentu irasymo i failus laikas: " << diff2.count() << " sekundes" << std::endl;
        }
        if (choice == 2)
        {
            const auto start1 = std::chrono::high_resolution_clock::now();
            for (auto it = studVector.begin(); it != studVector.end();)
            {
                if (it->get_Med() >= 5.0)
                {
                    best.push_back(std::move(*it));
                    it = studVector.erase(it);
                }
                else
                    ++it;
            }
            studVector.shrink_to_fit();
            best.shrink_to_fit();
            if (best.empty())
                throw std::runtime_error("Nera studento su mediana >= 5.0");
            const auto end1 = std::chrono::high_resolution_clock::now();
            const std::chrono::duration<double> diff1 = end1 - start1;
            std::cout << "Studentu atrankos laikas: " << diff1.count() << " sekundes" << std::endl;

            const auto start2 = std::chrono::high_resolution_clock::now();
            std::ofstream output1("Kieti.txt");
            output1 << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << std::setw(15) << "Galutinis (Med.)" << std::endl;
            output1 << "------------------------------------------------------------------" << std::endl;
            output1 << std::fixed << std::setprecision(2);
            for (const auto &i : best)
                output1 << i << std::endl;
            output1.close();
            std::ofstream output2("Vargsiukai.txt");
            output2 << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << std::setw(15) << "Galutinis (Med.)" << std::endl;
            output2 << "------------------------------------------------------------------" << std::endl;
            output2 << std::fixed << std::setprecision(2);
            for (const auto &i : studVector)
                output2 << i << std::endl;
            output2.close();
            const auto end2 = std::chrono::high_resolution_clock::now();
            const std::chrono::duration<double> diff2 = end2 - start2;
            std::cout << "Atrinktu studentu irasymo i failus laikas: " << diff2.count() << " sekundes" << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Results(std::vector<Student> studVector)
{
    try
    {
        if (studVector.size() < 1)
            throw std::runtime_error("Nera duomenu vektoriaus masyve!");
        std::cout << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << std::setw(15) << "Galutinis (Med.)" << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
        std::cout << std::fixed << std::setprecision(2);
        for (const auto &i : studVector)
            std::cout << i << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void ReadUser(std::vector<Student> &studVector)
{
    try
    {
        Student temp;
        std::cin >> temp;
        studVector.push_back(temp);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void GenUser(std::vector<Student> &studVector, int size, int hw)
{
    for (int i = 0; i < size; i++)
    {
        Student temp;
        temp.set_Name(nameList[RandGrade() - 1]);
        temp.set_Surname(surnameList[RandGrade() - 1]);
        temp.clear_Hw();
        for (int j = 0; j < hw; j++)
            temp.set_Hw(RandGrade());
        temp.set_ExRes(RandGrade());
        temp.set_Avg(temp.Average());
        temp.set_Med(temp.Median());
        studVector.push_back(temp);
    }
}

void CinError()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    throw std::runtime_error("Klaidinga ivestis");
}
