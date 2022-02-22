class Saver{
public:
    string GetSave(int value) {
        return v[value];
    }
    void SetSave(const string& new_saveLastExpression) {
        saveLastExpression = new_saveLastExpression;
    }
    string GetLastExpr() const {
        return saveLastExpression;
    }
    void Insert(int choice) {
        v.insert(v.begin() + choice, saveLastExpression);
    }
private:
    string saveLastExpression;
    deque<string> v = {"nothing1", "nothing2", "nothing3", "nothing4"};
};