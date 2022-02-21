class Converter{
public:
    Converter() {
        system = 10;
        isystem = 10;
    }
    void SetI(int new_isystem) {
        isystem = new_isystem;
    }
    void SetO(int new_osystem) {
        system = new_osystem;
    }
    template <typename T>
    string Convert(const T& number) const {
        char buffer[33];
        string result;
        stringstream ss;
        if(system != 10 && number <= 0){
            cout << "This CC does not display numbers after the decimal point" << endl;
            ss << number;
        }
        if(system != 10) {
            ss << (string)itoa(number, buffer, system); //2 - 36;
        } else {
            result = to_string(number);
        }
        ss >> result;
        return result;
    }
    //вводные данные только int
    int ConvertInput(const string& number) const {
        char *endptr;
        const char *cstr = number.c_str();
        return (int)strtol(cstr, &endptr, isystem);
    }
private:
    int system;
    int isystem;
};