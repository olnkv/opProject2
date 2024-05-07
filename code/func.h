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
#include "person.h"

/// @class Student
/// @brief Studento klasė
class Student : public Person
{
private:
    double exRes_;
    std::vector<int> hwRes_;
    double avg_, med_;

public:
    /// @brief Default konstruktorius
    Student();
    /// @brief Studento klasės konstruktorius
    /// @param name Studento vardas
    /// @param surname Studento pavardė
    Student(const std::string name, const std::string surname);
    /// @brief Namų darbų gavimas
    /// @return Namų darbų vektorius
    std::vector<int> get_HwRes() const { return hwRes_; }
    /// @brief Egzamino rezultato gavimas
    /// @return Egzamino rezultatas
    double get_exRes() const { return exRes_; }
    /// @brief Galutinio pagal vidurkį gavimas
    /// @return Galutinis pagal vidurkį
    double get_Avg() const { return avg_; }
    /// @brief Galutinio pagal medianą gavimas
    /// @return Galutinis pagal medianą
    double get_Med() const { return med_; }
    /// @brief Patikrinimas ar namų darbų vektorius yra tuščias
    /// @retval TRUE vektorius tuščias
    /// @retval FALSE vektorius turi elementų
    bool hwRes_Empty() const { return hwRes_.empty(); }
    /// @brief Namų darbų vektoriaus didžio gavimas
    /// @return Namų darbų vektoriaus dydis
    int hwRes_Size() const { return hwRes_.size(); }
    /// @brief Namų darbų rūšiavimas didėjimo tvarka
    void hw_Sort() { sort(hwRes_.begin(), hwRes_.end()); }
    /// @brief Namų darbų sumos apskaičiavimas
    /// @return Namų darbų elementų suma
    int hw_Sum() { return std::accumulate(hwRes_.begin(), hwRes_.end(), 0); }
    /// @brief Paskutinio namų darbų elemento gavimas
    /// @return Paskutinis namų darbų elementas
    int hw_Last() { return hwRes_.back(); }
    /// @brief Studento klasės destruktorius
    ~Student();

    /// @brief Egzamino rezultato priskyrimas
    /// @param exRes Egzamino rezultatas
    void set_ExRes(double exRes) { this->exRes_ = exRes; }
    /// @brief Galutnio pagal vidurkį priskyrimas
    /// @param avg Vidurkis 
    void set_Avg(double avg) { this->avg_ = avg; }
    /// @brief Galutinio pagal medianą priskyrimas
    /// @param med Mediana
    void set_Med(double med) { this->med_ = med; }
    /// @brief Pažymio pridėjimas į namų darbų vektoriu
    /// @param hw Pažymys
    void set_Hw(int hw) { this->hwRes_.push_back(hw); }
    /// @brief Paskutinio namų darbų elemento ištrynimas
    void del_LastHw() { this->hwRes_.pop_back(); }
    /// @brief Namų darbų vektoriaus išvalymas
    void clear_Hw() { this->hwRes_.clear(); }
    /// @brief Viso studento išvalymas
    void clear_All()
    {
        this->name_.clear();
        this->surname_.clear();
        this->hwRes_.clear();
        this->exRes_ = 0;
        this->avg_ = 0.0;
        this->med_ = 0.0;
    }
    /// @brief Galutinio pagal vidurkį skaičiavimas
    /// @return Galutinis pagal vidurkį
    double Average();
    /// @brief Galutinio pagal medianą skaičiavimas
    /// @return Galutinis pagal mediana
    double Median();

    /// @brief Kopijavimo konstruktorius
    /// @param Student_ Kopijuojamas objektas
    Student(const Student &Student_);
    /// @brief Perkėlimo konstruktorius
    /// @param Student_ Perkialamas objektas
    Student(Student &&Student_) noexcept;
    /// @brief Kopijavimo priskyrimo operatorius
    /// @param Student_ Kopijuojamas objektas
    Student &operator=(const Student &Student_);
    /// @brief Perkėlimo priskyrimo operatorius
    /// @param Student_ Perkeliamas objektas
    Student &operator=(Student &&Student_) noexcept;
    /// @brief Įvesties operatorius darbui su failais
    /// @param input Įvesties objektas
    /// @param Student_ Objektas, į kurį skaitomi duomenys
    /// @return Įvesties istringstream objektas
    friend std::istringstream &operator>>(std::istringstream &input, Student &Student_);
    /// @brief Įvesties operatorius darbui su vartotoju per konsolę
    /// @param input Įvesties objektas
    /// @param Student_ Objektas, į kurį skaitomi duomenys
    /// @return Įvesties istream objektas
    friend std::istream &operator>>(std::istream &input, Student &Student_);
    /// @brief Išvesties operatorius į konsolę
    /// @param output Išvesties objektas
    /// @param Student_ Išvedamas objektas
    /// @return Išvesties ostream objektas
    friend std::ostream &operator<<(std::ostream &output, const Student &Student_);
    /// @brief Išvesties operatorius į failą
    /// @param output Išvesties objektas
    /// @param Student_ Išvedamas objektas
    /// @return Išvesties ofstream objektas
    friend std::ofstream &operator<<(std::ofstream &output, const Student &Student_);
};

/// @brief Studentų palyginimas pagal vardą
/// @param a Pirmasis studentas
/// @param b Antrasis studentas
/// @retval TRUE A studento vardas yra žemiau pagal abecėlę nei studento B 
/// @retval FALSE atvirkščiai
bool compareName(const Student &a, const Student &b);
/// @brief Studentų palyginimas pagal pavardę
/// @param a Pirmasis studentas
/// @param b Antrasis studentas
/// @retval TRUE A studento pavardė yra žemiau pagal abecėlę nei studento B
/// @retval FALSE atvirkščiai
bool compareSurname(const Student &a, const Student &b);
/// @brief Studentų palyginimas pagal galutinio vidurkį
/// @param a Pirmasis studentas
/// @param b Antrasis studentas
/// @retval TRUE A studento galutinis balas pagal vidurkį yra mažesnis nei studento B
/// @retval FALSE atvirkščiai
bool compareAvg(const Student &a, const Student &b);
/// @brief Studentų palyginimas pagal galutinio medianą
/// @param a Pirmasis studentas
/// @param b Antrasis studentas
/// @retval TRUE A studento galutinis balas pagal medianą yra mažesnis nei studento B
/// @retval FALSE atvirkščiai
bool compareMed(const Student &a, const Student &b);
/// @brief Atsitiktinio skaičiaus [1;10] intervale generavimas
/// @return Atsitiktinis skaičius [1;10] intervale
int RandGrade();
/// @brief Cin operatoriaus valymas ir klaidos metimas
void CinError();
/// @brief Failo su studentais generavimas
/// @param size Generuojamų studentų skaičius
/// @param hw Generuojamų namų darbų skaičius
void GenFile(int size, int hw);
/// @brief Skaitymas iš failo į vektorių
/// @param studVector Studentų vektorius
void ReadFile(std::vector<Student> &studVector);
/// @brief Studentų skirstymas į geresnių ir blogesnių grupes ir išvedimas į failą
/// @param studVector Studentų vektorius
/// @param best Geresnių studentų vektorius
/// @param choice Skirstymo tipo pasirinkimas (pagal vidurkį/medianą)
void Selection(std::vector<Student> &studVector, std::vector<Student> &best, int choice);
/// @brief Studentų vektoriaus išvedimas į ekraną
/// @param studVector Studentų vektorius
void Results(std::vector<Student> studVector);
/// @brief Studentų įvedimas ranka
/// @param studVector Studentų vektorius
void ReadUser(std::vector<Student> &studVector);
/// @brief Studentų generavimas į vektorių
/// @param studVector Studentų vektorius
/// @param size Studentų skaičius
/// @param hw Namų darbų skaičius
void GenUser(std::vector<Student> &studVector, int size, int hw);

#endif