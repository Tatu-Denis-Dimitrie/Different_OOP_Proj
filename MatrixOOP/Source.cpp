#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
class Matrice {
private:
    int ordin;
    double** elemente;
    void alocare_memorie(int n) {
        ordin = n;
        elemente = new double* [ordin];
        for (int i = 0; i < ordin; ++i) {
            elemente[i] = new double[ordin];
        }
    }
    void eliberare_memorie() {
        for (int i = 0; i < ordin; ++i) {
            delete[] elemente[i];
        }
        delete[] elemente;
    }
public:
    Matrice(int n = 0) {
        if (n > 0) {
            alocare_memorie(n);
        }
        else {
            ordin = 0;
            elemente = nullptr;
        }
    }
    Matrice(const Matrice& other) {
        alocare_memorie(other.ordin);
        for (int i = 0; i < ordin; ++i) {
            for (int j = 0; j < ordin; ++j) {
                elemente[i][j] = other.elemente[i][j];
            }
        }
    }
    ~Matrice() {
        eliberare_memorie();
    }
    Matrice& operator=(const Matrice& other) {
        if (this == &other) {
            return *this;
        }
        eliberare_memorie();
        alocare_memorie(other.ordin);
        for (int i = 0; i < ordin; ++i) {
            for (int j = 0; j < ordin; ++j) {
                elemente[i][j] = other.elemente[i][j];
            }
        }
        return *this;
    }
    friend std::istream& operator>>(std::istream& in, Matrice& mat) {
        for (int i = 0; i < mat.ordin; ++i) {
            for (int j = 0; j < mat.ordin; ++j) {
                in >> mat.elemente[i][j];
            }
        }
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, const Matrice& mat) {
        for (int i = 0; i < mat.ordin; ++i) {
            for (int j = 0; j < mat.ordin; ++j) {
                out << mat.elemente[i][j] << " ";
            }
            out << std::endl;
        }
        return out;
    }
    bool operator==(const Matrice& other) const {
        if (ordin != other.ordin) {
            return false;
        }
        for (int i = 0; i < ordin; ++i) {
            for (int j = 0; j < ordin; ++j) {
                if (elemente[i][j] != other.elemente[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool operator!=(const Matrice& other) const {
        return !(*this == other);
    }
    double* operator[](int index) const {
        if (index < 0 || index >= ordin) {
            throw std::out_of_range("Index out of range");
        }
        return elemente[index];
    }
    Matrice operator+(const Matrice& other) const {
        if (ordin != other.ordin) {
            throw std::invalid_argument("Matrices must be of the same size");
        }
        Matrice result(ordin);
        for (int i = 0; i < ordin; ++i) {
            for (int j = 0; j < ordin; ++j) {
                result.elemente[i][j] = elemente[i][j] + other.elemente[i][j];
            }
        }
        return result;
    }
    Matrice operator-(const Matrice& other) const {
        if (ordin != other.ordin) {
            throw std::invalid_argument("Matrices must be of the same size");
        }
        Matrice result(ordin);
        for (int i = 0; i < ordin; ++i) {
            for (int j = 0; j < ordin; ++j) {
                result.elemente[i][j] = elemente[i][j] - other.elemente[i][j];
            }
        }
        return result;
    }
    Matrice operator*(const Matrice& other) const {
        if (ordin != other.ordin) {
            throw std::invalid_argument("Matrices must be of the same size");
        }
        Matrice result(ordin);
        for (int i = 0; i < ordin; ++i) {
            for (int j = 0; j < ordin; ++j) {
                result.elemente[i][j] = 0;
                for (int k = 0; k < ordin; ++k) {
                    result.elemente[i][j] += elemente[i][k] * other.elemente[k][j];
                }
            }
        }
        return result;
    }
    Matrice& operator+=(const Matrice& other) {
        if (ordin != other.ordin) {
            throw std::invalid_argument("Matrices must be of the same size");
        }
        for (int i = 0; i < ordin; ++i) {
            for (int j = 0; j < ordin; ++j) {
                elemente[i][j] += other.elemente[i][j];
            }
        }
        return *this;
    }
    Matrice& operator-=(const Matrice& other) {
        if (ordin != other.ordin) {
            throw std::invalid_argument("Matrices must be of the same size");
        }
        for (int i = 0; i < ordin; ++i) {
            for (int j = 0; j < ordin; ++j) {
                elemente[i][j] -= other.elemente[i][j];
            }
        }
        return *this;
    }
    Matrice& operator*=(const Matrice& other) {
        *this = *this * other;
        return *this;
    }
    double determinant() const {
        if (ordin == 0) {
            throw std::invalid_argument("Matrix must have positive size");
        }
        if (ordin == 1) {
            return elemente[0][0];
        }
        if (ordin == 2) {
            return elemente[0][0] * elemente[1][1] - elemente[0][1] * elemente[1][0];
        }
        double det = 0;
        for (int p = 0; p < ordin; ++p) {
            Matrice submat(ordin - 1);
            for (int i = 1; i < ordin; ++i) {
                int sub_j = 0;
                for (int j = 0; j < ordin; ++j) {
                    if (j == p) continue;
                    submat.elemente[i - 1][sub_j] = elemente[i][j];
                    sub_j++;
                }
            }
            det += (p % 2 == 0 ? 1 : -1) * elemente[0][p] * submat.determinant();
        }
        return det;
    }
    double operator!() const {
        return determinant();
    }
    Matrice operator^(int power) const {
        if (power < 0) {
            throw std::invalid_argument("Power must be non-negative");
        }
        Matrice result(ordin);
        Matrice base = *this;
        for (int i = 0; i < ordin; ++i) {
            for (int j = 0; j < ordin; ++j) {
                result.elemente[i][j] = (i == j) ? 1 : 0;
            }
        }
        while (power) {
            if (power % 2 == 1) {
                result *= base;
            }
            base *= base;
            power /= 2;
        }
        return result;
    }
    Matrice operator~() const {
        Matrice result(ordin);
        for (int i = 0; i < ordin; ++i) {
            for (int j = 0; j < ordin; ++j) {
                result.elemente[j][i] = elemente[i][j];
            }
        }
        return result;
    }
};

void afiseaza_meniu() {
    std::cout << "Meniu:" << std::endl;
    std::cout << "1. Introducere matrice" << std::endl;
    std::cout << "2. Afisare matrice" << std::endl;
    std::cout << "3. Calculare transpusa" << std::endl;
    std::cout << "4. Adunare matrici" << std::endl;
    std::cout << "5. Inmultire matrici" << std::endl;
    std::cout << "6. Iesire" << std::endl;
    std::cout << "Alege o optiune: ";
}

int main() {
    int n, optiune;
    Matrice mat1, mat2, rezultat;

    do {
        afiseaza_meniu();
        std::cin >> optiune;

        switch (optiune) {
        case 1:
            std::cout << "Introduceti ordinul matricei: ";
            std::cin >> n;
            mat1 = Matrice(n);
            std::cout << "Introduceti elementele matricei:" << std::endl;
            std::cin >> mat1;
            break;

        case 2:
            std::cout << "Matricea actuala:" << std::endl;
            std::cout << mat1;
            break;

        case 3:
            std::cout << "Transpusa matricei:" << std::endl;
            std::cout << ~mat1;
            break;

        case 4:
            std::cout << "Introduceti a doua matrice pentru adunare:" << std::endl;
            mat2 = Matrice(n);
            std::cin >> mat2;
            rezultat = mat1 + mat2;
            std::cout << "Rezultatul adunarii:" << std::endl;
            std::cout << rezultat;
            break;

        case 5:
            std::cout << "Introduceti a doua matrice pentru inmultire:" << std::endl;
            mat2 = Matrice(n);
            std::cin >> mat2;
            rezultat = mat1 * mat2;
            std::cout << "Rezultatul inmultirii:" << std::endl;
            std::cout << rezultat;
            break;

        case 6:
            std::cout << "Iesire..." << std::endl;
            break;

        default:
            std::cout << "Optiune invalida. Incercati din nou." << std::endl;
        }
    } while (optiune != 6);

    return 0;
}
