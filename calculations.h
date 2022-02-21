int BasicOperations(const int& a, const char& o, const int& b) {
    int result = 0;
    if (o == '+') {
        result = a + b;
    }
    if (o == '-') {
        result = a - b;
    }
    if (o == '*') {
        result = a * b;
    }
    if (o == '/') {
        if(b == 0) throw runtime_error("Division by zero");
        result = a / b;
    }
    return result;
}
double TriangleOperations(const string& o, const double& x) {
    double result;
    if(o == "sin") {
        result = sin(x);
    }
    if(o == "cos") {
        result = cos(x);
    }
    return result;
}
int BitOperations(const int& x, const int& y, const char& o) {
    int result = 0;
    if (o == '^') {
        result = x ^ y;
    }

    if (o == '&') {
        result = x & y;
    }

    if (o == '|') {
        result = x | y;
    }
    return result;
}
int NOD(int a, int b) {
    // пока оба числа положительны, будем их уменьшать, не меняя их НОД
    while (a > 0 && b > 0) {

        // возьмём большее из чисел и заменим его остатком от деления на второе
        // действительно, если a и b делятся на x, то a - b и b делятся на x
        // тогда и a % b и b делятся на x, так что можно a заменить на a % b
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }

    }

    // если одно из чисел оказалось равно нулю, значит, на последней итерации
    // большее число разделилось на меньшее
    return a + b;
}
int NOK(int a, int b) {
    while(a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return (a * b) / a;
}
int Factorial(int x) {
    int result = 1;
    for (int i = 2; i <= x; ++i) {
        result *= i;
    }
    return result;
}
double Triangle(double r, double n){
    // Сторона и радиус не могут быть отрицательными
    if (r < 0 && n < 0)
        return -1;
    // Площадь
    // градусы преобразованы в радианы
    return ((r * r * n) * sin((360 / n) * 3.14159 / 180)) / 2;
}
void Equation(double A, double B, double C, Saver& s) {
    // найдём дискриминант
    double D = B * B - 4 * A * C;
    // если A равно нулю, то уравнение линейное: Bx + C = 0
    if (A == 0) {
        // Bx = -C => x = -C / B
        if (B != 0) {
            cout << to_string(-C / B) << endl;
            s.SetSave(to_string(-C / B));
            return;
        }
        // если B равно нулю, корней нет
    } else if (D == 0) {  // случай с нулевым дискриминантом
        // корень ровно один
        cout << to_string(-B / (2 * A)) << endl;
        s.SetSave(to_string(-B / (2 * A)));
        return;
    } else if (D > 0) {  // в случае с положительным дискриминантом корня два
        double r1 = (-B + sqrt(D)) / (2 * A);
        double r2 = (-B - sqrt(D)) / (2 * A);
        cout << to_string(r1) << " " << to_string(r2) << endl;
        s.SetSave(to_string(r1));
        return;
    }
    // если дискриминант отрицателен, действительных корней нет
    cout << "no roots" << endl;
}