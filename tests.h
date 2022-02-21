//Тесты из 10 в N систему (результаты вычислений)
void TestConvert(Converter c) {
    c.SetO(2);
    assert(c.Convert(5) == "101");
    c.SetO(2);
    assert(c.Convert(123524623) == "111010111001101011000001111");
    c.SetO(8);
    assert(c.Convert(32) == "40");
    c.SetO(16);
    assert(c.Convert(21343) == "535f");
    c.SetO(3);
    assert(c.Convert(9821) == "111110202");
    c.SetO(12);
    assert(c.Convert(31521) == "162a9");
    cout << "TestConvert OK" << endl;
}
//Тесты из N в 10 систему (входные данные)
void TestConvertInput(Converter c) {
    c.SetI(2);
    assert(c.ConvertInput("101") == 5);
    c.SetI(2);
    assert(c.ConvertInput("111010111001101011000001111") == 123524623);
    c.SetI(8);
    assert(c.ConvertInput("40") == 32);
    c.SetI(16);
    assert(c.ConvertInput("535f") == 21343);
    c.SetI(3);
    assert(c.ConvertInput("111110202") == 9821);
    c.SetI(12);
    assert(c.ConvertInput("162a9") == 31521);
    cout << "TestConvertInput OK" << endl;
}

void TestBasicOperations() {
    assert(BasicOperations(2, '+', 3) == 5);
    assert(BasicOperations(-2, '+', -3) == -5);
    assert(BasicOperations(-2, '+', 0) == -2);
    assert(BasicOperations(-2, '+', 2) == 0);

    assert(BasicOperations(2, '-', 3) == -1);
    assert(BasicOperations(-2, '-', -3) == 1);
    assert(BasicOperations(-2, '-', 0) == -2);
    assert(BasicOperations(-2, '-', 2) == -4);

    assert(BasicOperations(2, '*', 3) == 6);
    assert(BasicOperations(-2, '*', -3) == 6);
    assert(BasicOperations(-2, '*', 0) == 0);
    assert(BasicOperations(-2, '*', 2) == -4);

    assert(BasicOperations(2, '/', 3) == 0);//0.66
    assert(BasicOperations(-2, '/', -3) == 0);//0.66
    //assert(BasicOperations(-2, '/', 0) == 0);
    assert(BasicOperations(-2, '/', 2) == -1);
    cout << "TestBasicOperations OK" << endl;
}

void TestTriangleOperations() {
    assert(TriangleOperations("sin", 60) == -0.30481062110221668);
    assert(TriangleOperations("cos", 60) == -0.95241298041515632);
    cout << "TestTriangleOperations OK" << endl;
}

void TestBitOperations() {
    assert(BitOperations(3, 5, '|') == 7);
    assert(BitOperations(3, 5, '&') == 1);
    assert(BitOperations(3, 5, '^') == 6);
    cout << "TestBitOperations OK" << endl;
}

void TestNOD() {
    assert(NOD(3, 5) == 1);
    assert(NOD(15, 12) == 3);
    assert(NOD(180, 150) == 30);
    assert(NOD(123456789000, 432198765000) == 2147483647);//9000
    cout << "TestBitOperations OK" << endl;
}

void TestAll() {
    Converter testC;
    TestConvert(testC);
    TestConvertInput(testC);
    TestBasicOperations();
    TestTriangleOperations();
    TestBitOperations();
    //TestNOD();
}