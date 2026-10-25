#include <iostream>
#include <string>

class Triangle {
    private:
        double totalAngle, acuteAngle, obtuseAngle, rightAngle, angleA, angleB, angleC;

    public:
        Triangle(double A, double B, double C);
        void setAngles(double A, double B, double C);
        double getArea(double A, double B, double C);
        double getPerimeter(double A, double B, double C);
        std::string getTriangleType();
        const bool validateTriangle();
};

    Triangle::Triangle(double A, double B, double C) {
        angleA = A;
        angleB = B;
        angleC = C;
        totalAngle = A+B+C;
    }

    void Triangle::setAngles(double A, double B, double C) {
        angleA = A;
        angleB = B;
        angleC = C;
        totalAngle = A+B+C;
    }

    double Triangle::getArea(double A, double B, double C) {
        double s = (A+B+C) / 2;
        return sqrt(s *(s-A)*(s-B)*(s-C));
    }

    double Triangle::getPerimeter(double A, double B, double C) {
        return A+B+C;
    }

    const bool Triangle::validateTriangle() {
        return (totalAngle == 180 && angleA > 0 && angleB > 0 && angleC > 0);
    }

    std::string Triangle::getTriangleType() {
        if (!validateTriangle()) {
                return "Not a Valid Triangle.";
            } else if (angleA == 90 || angleB == 90 || angleC == 90) {
                return "Right Triangle";
            } else if (angleA > 90 || angleB > 90 || angleC > 90) {
                return "Obtuse Angle";
            } else {
                return "Acute Angle";
            }
    }

int main() {
    //driver code
    Triangle set1(40, 30, 110);
    if(set1.validateTriangle()) {
        std::cout << "The shape is a valid triangle.\n";
        std::cout << "Type of triangle: " << set1.getTriangleType() << std::endl;
    } else {
        std::cout << "The shape is NOT a valid triangle.\n";
    }

    return 0;
}