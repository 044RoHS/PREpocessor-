#include <iostream>
#include <string>


class FigureCreationException : public std::runtime_error {
private:
    std::string figureType; 

public:
  
    FigureCreationException(const std::string& type, const std::string& message)
        : runtime_error(message), figureType(type) {
    }

   
    const std::string& getFigureType() const {
        return figureType;
    }
};
using namespace std;


class Figure {
protected:
    int sidesCount;
    double anglesSum;

public:
    Figure(int sides, double sumAngles)
        : sidesCount(sides), anglesSum(sumAngles) {
    }

    virtual void printInfo() const = 0; 
    virtual ~Figure() {}
};


class Triangle : public Figure {
protected:
    int a, b, c;
    double A, B, C;

public:
    
    Triangle(int a, int b, int c, double A, double B, double C)
        : Figure(3, 180), a(a), b(b), c(c), A(A), B(B), C(C) {
        if (a <= 0 || b <= 0 || c <= 0) {
            throw FigureCreationException("Треугольник", "Стороны треугольника должны быть положительными числами.");
        }
        if (A <= 0 || B <= 0 || C <= 0) {
            throw FigureCreationException("Треугольник", "Углы треугольника должны быть положительными числами.");
        }
        if (A + B + C != 180) {
            throw FigureCreationException("Треугольник", "Сумма углов треугольника должна быть равна 180°.");
        }
        if (!(a + b > c && a + c > b && b + c > a)) {
            throw FigureCreationException("Треугольник", "Нарушено неравенство треугольника.");
        }
    }

  
    void printInfo() const override {
        cout << "Треугольник создан:\n";
        cout << "Стороны: a=" << a << ", b=" << b << ", c=" << c << "\n";
        cout << "Углы: A=" << A << "°, B=" << B << "°, C=" << C << "°\n";
    }
};


class RightTriangle : public Triangle {
public:
   
    RightTriangle(int a, int b, int c, double A, double B)
        : Triangle(a, b, c, A, B, 90) 
    {

        if (A <= 0 || B <= 0 || A + B != 90) {
            throw FigureCreationException("Прямоугольный треугольник", "Углы A и B должны быть положительными и суммироваться до 90°.");
        }
    }

    
    void printInfo() const override {
        cout << "Прямоугольный треугольник создан:\n";
        cout << "Стороны: a=" << a << ", b=" << b << ", c=" << c << "\n";
        cout << "Углы: A=" << A << "°, B=" << B << "°, C=90°\n";
    }
};


class IsoscelesTriangle : public Triangle {
public:
    
    IsoscelesTriangle(int a, int b, double A, double B)
        : Triangle(a, a, b, A, B, A) {
        if (A <= 0 || B <= 0 || 2 * A + B != 180) {
            throw FigureCreationException("Равнобедренный треугольник", "Углы A и B должны быть положительными и удовлетворять условию 2A + B = 180°.");
        }
    }

   
    void printInfo() const override {
        cout << "Равнобедренный треугольник создан:\n";
        cout << "Стороны: a=" << a << ", b=" << a << ", c=" << b << "\n";
        cout << "Углы: A=" << A << "°, B=" << B << "°, C=" << A << "°\n";
    }
};


class EquilateralTriangle : public Triangle {
public:
 
    EquilateralTriangle(int a)
        : Triangle(a, a, a, 60, 60, 60) {
    }

  
    void printInfo() const override {
        cout << "Равносторонний треугольник создан:\n";
        cout << "Стороны: a=" << a << ", b=" << a << ", c=" << a << "\n";
        cout << "Углы: A=60°, B=60°, C=60°\n";
    }
};

class Quadrilateral : public Figure {
protected:
    int a, b, c, d;
    double A, B, C, D;

public:

    Quadrilateral(int a, int b, int c, int d, double A, double B, double C, double D)
        : Figure(4, 360), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
        if (a <= 0 || b <= 0 || c <= 0 || d <= 0) {
            throw FigureCreationException("Четырёхугольник", "Стороны четырёхугольника должны быть положительными числами.");
        }
        if (A <= 0 || B <= 0 || C <= 0 || D <= 0) {
            throw FigureCreationException("Четырёхугольник", "Углы четырёхугольника должны быть положительными числами.");
        }
        if (A + B + C + D != 360) {
            throw FigureCreationException("Четырёхугольник", "Сумма углов четырёхугольника должна быть равна 360°.");
        }
    }


    void printInfo() const override {
        cout << "Четырёхугольник создан:\n";
        cout << "Стороны: a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << "\n";
        cout << "Углы: A=" << A << "°, B=" << B << "°, C=" << C << "°, D=" << D << "°\n";
    }
};


class Rectangle : public Quadrilateral {
public:
 
    Rectangle(int a, int b)
        : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {
    }

 
    void printInfo() const override {
        cout << "Прямоугольник создан:\n";
        cout << "Стороны: a=" << a << ", b=" << b << ", c=" << a << ", d=" << b << "\n";
        cout << "Углы: A=90°, B=90°, C=90°, D=90°\n";
    }
};


class Square : public Quadrilateral {
public:

    Square(int a)
        : Quadrilateral(a, a, a, a, 90, 90, 90, 90) {
    }


    void printInfo() const override {
        cout << "Квадрат создан:\n";
        cout << "Стороны: a=" << a << ", b=" << a << ", c=" << a << ", d=" << a << "\n";
        cout << "Углы: A=90°, B=90°, C=90°, D=90°\n";
    }
};


class Parallelogram : public Quadrilateral {
public:

    Parallelogram(int a, int b, double A, double B)
        : Quadrilateral(a, b, a, b, A, B, A, B) {
        if (A <= 0 || B <= 0 || A + B != 180) {
            throw FigureCreationException("Параллелограмм", "Углы A и B должны быть положительными и удовлетворять условию A + B = 180°.");
        }
    }


    void printInfo() const override {
        cout << "Параллелограмм создан:\n";
        cout << "Стороны: a=" << a << ", b=" << b << ", c=" << a << ", d=" << b << "\n";
        cout << "Углы: A=" << A << "°, B=" << B << "°, C=" << A << "°, D=" << B << "°\n";
    }
};


class Rhombus : public Parallelogram {
public:

    Rhombus(int a, double A, double B)
        : Parallelogram(a, a, A, B) {
    }


    void printInfo() const override {
        cout << "Ромб создан:\n";
        cout << "Стороны: a=" << a << ", b=" << a << ", c=" << a << ", d=" << a << "\n";
        cout << "Углы: A=" << A << "°, B=" << B << "°, C=" << A << "°, D=" << B << "°\n";
    }
};




int main() {
    try {
        setlocale(LC_ALL, "Ru");
        Triangle triangle(3, 4, 5, 50, 60, 70);
        triangle.printInfo();

        RightTriangle rightTriangle(3, 4, 5, 30, 60);
        rightTriangle.printInfo();

        IsoscelesTriangle isoscelesTriangle(5, 8, 50, 80);
        isoscelesTriangle.printInfo();

        EquilateralTriangle equilateralTriangle(6);
        equilateralTriangle.printInfo();

        Quadrilateral quadrilateral(2, 3, 4, 5, 60, 120, 80, 100);
        quadrilateral.printInfo();

        Rectangle rectangle(4, 6);
        rectangle.printInfo();

        Square square(5);
        square.printInfo();

        Parallelogram parallelogram(4, 6, 60, 120);
        parallelogram.printInfo();

        Rhombus rhombus(5, 60, 120);
        rhombus.printInfo();

    }
    catch (const FigureCreationException& e) {
        
        cout << "Ошибка создания фигуры \"" << e.getFigureType() << "\": " << e.what() << "\n";
    }
    catch (const exception& e) {
        
        cout << "Произошла ошибка: " << e.what() << "\n";
    }

    return 0;
}