enum class RequestType {
    BASIC,
    TRIGONOMETRIC,
    BINARY,
    NOD,
    NOK,
    FACTORIAl,
    POW,
    LOG,
    SQRT,
    RAND,
    TRIANGLE,
    EQUATION
};

void Calculator(const Converter& c, const RequestType& request_type, const string& value, Saver& saver) {
    switch (request_type) {
        case RequestType::BASIC: {
            string sa, sb;
            char o;
            if(value.empty()) {
                cout << "Enter the expression: " << endl;
                cin >> sa >> o >> sb;
            } else {
                cout << "Enter the expression (saved value included: " << value << "): * 5 " << endl;
                sa = value;
                cin >> o >> sb;
            }
            int a = c.ConvertInput(sa);
            int b = c.ConvertInput(sb);
            int basicResult = BasicOperations(a, o, b);
            cout << c.Convert(basicResult) << endl;
            saver.SetSave(c.Convert(basicResult));
            break;
        }
        case RequestType::TRIGONOMETRIC: {
            string op;
            string sx;
            if(value.empty()) {
                cout << "Enter the expression. Example sin 5" << endl;
                cin >> op >> sx;
            } else {
                cout << "Enter the expression (saved value included: " << value << "): sin or cos " << endl;
                sx = value;
                cin >> op;
            }
            double x = c.ConvertInput(sx);
            double triangleResult = TriangleOperations(op, x);
            cout << c.Convert(triangleResult) << endl;
            saver.SetSave(c.Convert(triangleResult));
            break;
        }
        case RequestType::BINARY: {
            string sx, sy;
            char o;
            if(value.empty()) {
                cout << "Enter the expression. Example 5 | 6" << endl;
                cin >> sx >> o >> sy;
            } else {
                cout << "Enter the expression (saved value included: " << value << "): | 6 " << endl;
                sx = value;
                cin >> o >> sy;
            }
            int x = c.ConvertInput(sx);
            int y = c.ConvertInput(sy);
            int bitResult = BitOperations(x, y, o);
            cout << c.Convert(bitResult) << endl;
            saver.SetSave(c.Convert(bitResult));

            break;
        }
        case RequestType::NOD: {
            string sa, sb;
            if(value.empty()) {
                cout << "Enter the expression. Example a b" << endl;
                cin >> sa >> sb;
            } else {
                cout << "Enter the expression (saved value included: " << value << "): b " << endl;
                sa = value;
                cin >> sb;
            }
            int a = c.ConvertInput(sa);
            int b = c.ConvertInput(sb);
            int nodResult = NOD(a, b);
            cout << c.Convert(nodResult) << endl;
            saver.SetSave(c.Convert(nodResult));
            break;
        }
        case RequestType::NOK: {
            string sa, sb;
            if(value.empty()) {
                cout << "Enter the expression. Example a b" << endl;
                cin >> sa >> sb;
            } else {
                cout << "Enter the expression (saved value included: " << value << "): b " << endl;
                sa = value;
                cin >> sb;
            }
            int a = c.ConvertInput(sa);
            int b = c.ConvertInput(sb);
            int nokResult = NOK(a, b);
            cout << c.Convert(nokResult) << endl;
            saver.SetSave(c.Convert(nokResult));
            break;
        }
        case RequestType::FACTORIAl: {
            string sx;
            if(value.empty()) {
                cout << "Enter the expression. Example 5" << endl;
                cin >> sx;
            } else {
                cout << "Factorial " << value << "(saved) is equal: " << endl;
                sx = value;
            }
            int x = c.ConvertInput(sx);
            int factResult = Factorial(x);
            cout << c.Convert(factResult) << endl;
            saver.SetSave(c.Convert(factResult));
            break;
        }
        case RequestType::POW: {
            string sx, sy;
            if(value.empty()) {
                cout << "Enter the expression. Example 5 2" << endl;
                cin >> sx >> sy;
            } else {
                cout << "Enter the expression (saved value included: " << value << "): 2 " << endl;
                sx = value;
                cin >> sy;
            }
            double x = c.ConvertInput(sx);
            double y = c.ConvertInput(sy);
            double powResult = pow(x, y);
            cout << c.Convert(powResult) << endl;
            saver.SetSave(c.Convert(powResult));
            break;
        }
        case RequestType::LOG: {
            string sx;
            if(value.empty()) {
                cout << "Enter the expression. Example 5" << endl;
                cin >> sx;
            } else {
                cout << "Log " << value << "(saved) is equal: " << endl;
                sx = value;
            }
            double x = c.ConvertInput(sx);
            double logResult = log(x);
            cout << c.Convert(logResult) << endl;
            saver.SetSave(c.Convert(logResult));
            break;
        }
        case RequestType::SQRT: {
            string sx;
            if(value.empty()) {
                cout << "Enter the expression. Example 5" << endl;
                cin >> sx;
            } else {
                cout << "Sqrt " << value << "(saved) is equal: " << endl;
                sx = value;
            }
            double x = c.ConvertInput(sx);
            double sqrtResult = sqrt(x);
            cout << c.Convert(sqrtResult) << endl;
            saver.SetSave(c.Convert(sqrtResult));
            break;
        }
        case RequestType::RAND: {
            string sx, sy;
            //для инициализации ГСЧ значением текущего времени
            srand(time(0));
            if(value.empty()) {
                cout << "Enter the expression. Example 10 100" << endl;
                cin >> sx >> sy;
            } else {
                cout << "Enter the expression (saved value included: " << value << "): 100 " << endl;
                sx = value;
                cin >> sy;
            }
            int x = c.ConvertInput(sx);
            int y = c.ConvertInput(sy);
            if(x >= y) throw runtime_error("Invalid arguments! Enter only x > y");
            int randResult = x + rand() % (y - x + 1);
            cout << c.Convert(randResult) << endl;
            saver.SetSave(c.Convert(randResult));
            break;
        }
        case RequestType::TRIANGLE: {
            string sr, sn;
            if(value.empty()) {
                cout << "Enter the r n. Example 9 6" << endl;
                cin >> sr >> sn;
            } else {
                cout << "Enter the r (saved value included: " << value << "): 9 " << endl;
                sn = value;
                cin >> sr;
            }
            double r = c.ConvertInput(sr);
            double n = c.ConvertInput(sn);
            double triangResult = Triangle(r, n);
            cout << c.Convert(triangResult) << endl;
            saver.SetSave(c.Convert(triangResult));
            break;
        }
        case RequestType::EQUATION: {
            string sa, sb, sz;
            if(value.empty()) {
                cout << "Enter the a, b, c. Example 2 5 2" << endl;
                cin >> sa >> sb >> sz;
            } else {
                cout << "Enter the " << "(with saved)" << value << " b, c. Example 5 2" << endl;
                sa = value;
                cin >> sb >> sz;
            }
            int a = c.ConvertInput(sa);
            int b = c.ConvertInput(sb);
            int z = c.ConvertInput(sz);
            Equation(a, b, z, saver);
            break;
        }
        default:
            cout << "Unknown request" << endl;
    }
}
