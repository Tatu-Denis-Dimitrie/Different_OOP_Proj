#include <iostream>
#include <cmath>
#include <string>

class CutiePraline
{
protected:

    std::string aroma;
    std::string origine;

public:

    CutiePraline() :aroma(""), origine("") {}

    CutiePraline(std::string aroma, std::string origine) :aroma(aroma), origine(origine) {}

    virtual float getVolume() {
        return 0.0f;
    }

    virtual std::string toString()
    {
        return "Cutia " + origine + " are aroma " + aroma;
    }

    void setAroma(std::string arom)
    {
        aroma = arom;
    }

    void setOrigine(std::string orig)
    {
        origine = orig;
    }

};
class Lindt : public CutiePraline 
{
private:

    float length, width, height;

public:
    Lindt() :length(0), width(0), height(0) {}

    Lindt(std::string aroma, std::string origine, float lenght, float width, float height)
        :CutiePraline(aroma, origine), length(lenght), width(width), height(height) {}

    float getVolume()
    {
        return length * width * height;
    }

    std::string toString()
    {
        return CutiePraline::toString() + " si volumul " + std::to_string(getVolume());
    }
};
class Baravelli : public CutiePraline 
{
private:

    float radius, height;

public:
    Baravelli() :radius(0), height(0) {};

    Baravelli(std::string aroma, std::string origine, float radius, float height)
        :CutiePraline(aroma, origine), radius(radius), height(height) {}

    float getVolume()
    {
        return 3.14 * radius * height;
    }

    std::string toString()
    {
        return CutiePraline::toString() + " si volumul " + std::to_string(getVolume());
    }

};
class Rafaello : public CutiePraline
{
private:

    float lung;

public:
    Rafaello() : lung(0) {}

    Rafaello(std::string aroma, std::string origine, float lung)
        :CutiePraline(aroma, origine), lung(lung) {}

    float getVolume()
    {
        return lung * lung * lung;
    }

    std::string toString()
    {
        return CutiePraline::toString() + " cu volumul " + std::to_string(getVolume());
    }
};
int main()
{
    Lindt l("Cacao", "Lindt", 2.0f, 3.0f, 4.0f);
    Baravelli b("Vanilie", "Baravelli", 1.0f, 2.0f);
    Rafaello r("Caramel", "Rafaello", 1.0f);

    std::cout << b.toString() << std::endl;
    std::cout << r.toString() << std::endl;
    std::cout << l.toString();
    return 0;
}