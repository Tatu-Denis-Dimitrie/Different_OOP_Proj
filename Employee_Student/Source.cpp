#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
class Persoana {
protected:

    std::string nume;
    std::string prenume;
    int varsta;

public:
    Persoana(const std::string nume = "", const std::string prenume = "", int varsta = 0)
        : nume(nume), prenume(prenume), varsta(varsta) {}

    bool operator<(const Persoana& other) const 
    {
        return nume < other.nume;
    }

    friend std::istream& operator>>(std::istream& is, Persoana& persoana) 
    {
        std::cout << "Nume: ";
        is >> persoana.nume;
        std::cout << "Prenume: ";
        is >> persoana.prenume;
        std::cout << "Varsta: ";
        is >> persoana.varsta;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Persoana& persoana) 
    {
        os << "Nume: " << persoana.nume << ", Prenume: " << persoana.prenume << ", Varsta: " << persoana.varsta;
        return os;
    }
};
class Angajat : public Persoana 
{
private:

    float salariu;

public:
    Angajat(const std::string& nume = "", const std::string& prenume = "", int varsta = 0, float salariu = 0.0f)
        : Persoana(nume, prenume, varsta), salariu(salariu) {}

    friend std::istream& operator>>(std::istream& is, Angajat& angajat) 
    {
        is >> static_cast<Persoana&>(angajat);
        std::cout << "Salariu: ";
        is >> angajat.salariu;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Angajat& angajat) 
    {

        os << static_cast<const Persoana&>(angajat) << ", Salariu: " << angajat.salariu;
        return os;
    }

    void crestereSalariu(float procent) 
    {
        salariu *= (1 + procent / 100);
    }
};

class Student : public Persoana 
{
private:

    float medie;

public:
    Student(const std::string& nume = "", const std::string& prenume = "", int varsta = 0, float medie = 0.0f)
        : Persoana(nume, prenume, varsta), medie(medie) {}

    friend std::istream& operator>>(std::istream& is, Student& student) 
    {
        is >> static_cast<Persoana&>(student);
        std::cout << "Medie: ";
        is >> student.medie;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Student& student) 
    {

        os << static_cast<const Persoana&>(student) << ", Medie: " << student.medie;
        return os;
    }
};
int main() {

    std::vector<Student> stud;
    std::vector<Angajat> ang;

    int n;
    std::cout << "Introduceti numarul de persoane: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) 
    {
        char tip;
        std::cout << "Introduceti tipul persoanei (a pentru angajat, s pentru student): ";
        std::cin >> tip;

        if (tip == 'a') 
        {
            Angajat a;
            std::cin >> a;
            ang.push_back(a);
        }
        else if (tip == 's') 
        {
            Student s;
            std::cin >> s;
            stud.push_back(s);
        }
        else {
            std::cerr << "Tip invalid de persoana." << std::endl;
        }
    }

    std::sort(ang.begin(), ang.end());
    std::sort(stud.begin(), stud.end());

    for (const auto& persoana : ang) 
    {
        std::cout << persoana << std::endl;
    }
    for (const auto& persoana : stud) 
    {
        std::cout << persoana << std::endl;
    }
    return 0;
}