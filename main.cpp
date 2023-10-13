#include <iostream>
#include <string>

class Parallelepiped {
private:
    double length;
    double width;
    double height;

public:
    // Конструктор
    Parallelepiped() {
        length = 0.0;
        width = 0.0;
        height = 0.0;
    }

    // Перевантажений конструктор з параметрами
    Parallelepiped(double l, double w, double h) {
        length = l;
        width = w;
        height = h;
    }

    // Деструктор
    ~Parallelepiped() {
        std::cout << "Об'єкт Parallelepiped був знищений." << std::endl;
    }

    // Set-методи
    void setLength(double l) {
        length = l;
    }

    void setWidth(double w) {
        width = w;
    }

    void setHeight(double h) {
        height = h;
    }

    // Get-методи
    double getLength() const {
        return length;
    }

    double getWidth() const {
        return width;
    }

    double getHeight() const {
        return height;
    }

    // Метод обчислення площі поверхні
    double calculateSurfaceArea() const {
        return 2 * (length * width + length * height + width * height);
    }

    // Метод обчислення суми довжин всіх ребер паралелепіпеда
    double calculateSumOfEdges() const {
        return 4 * (length + width + height);
    }

    // Функція для виводу інформації про об'єкт
    void printInfo() const {
        std::cout << "Довжина: " << length << " ширина: " << width << " висота: " << height << std::endl;
        std::cout << "Площа поверхні: " << calculateSurfaceArea() << std::endl;
        std::cout << "Сума довжин ребер: " << calculateSumOfEdges() << std::endl;
    }
};

class RectangularBeam : public Parallelepiped {
private:
    double specificWeight;
    int numberOfPieces;

public:
    // Конструктор для класу-нащадка
    RectangularBeam(double l, double w, double h, double sw, int n) : Parallelepiped(l, w, h) {
        specificWeight = sw;
        numberOfPieces = n;
    }

    // Метод обробки даних для класу-нащадка
    double calculatePieceSurfaceArea() const {
        double surfaceArea = calculateSurfaceArea();
        return surfaceArea / numberOfPieces;
    }
    //метод обчислення маси розпиляної балки
    double calculatePieceWeight() const {
        double pieceSurfaceArea = calculatePieceSurfaceArea();
        return pieceSurfaceArea * specificWeight;
    }

    // інформації про об'єкт
    std::string getInfoString() const {
        std::string info = "Ширина: " + std::to_string(getWidth()) +
                          " Висота: " + std::to_string(getHeight()) +
                          " Довжина: " + std::to_string(getLength()) +
                          " Площа поверхні кожної частини: " + std::to_string(calculatePieceSurfaceArea()) +
                          " Вага кожної частини: " + std::to_string(calculatePieceWeight());
        return info;
    }
};

int main() {
    RectangularBeam beam(10.0, 2.0, 1.0, 5.0, 5);

    // Виведення інформації про об'єкт класу-нащадка
    std::cout << "Інформація про балку:" << std::endl;
    std::cout << beam.getInfoString() << std::endl;

    return 0;
}
