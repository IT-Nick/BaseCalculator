class Saver{
public:
    string GetSave(int value) {
        return d[value];
    }
    void SetSave(const string& new_saveLastExpression) {
        saveLastExpression = new_saveLastExpression;
    }
    string GetLastExpr() const {
        return saveLastExpression;
    }
    void Insert(int choice) {
        d.insert(d.begin() + choice, saveLastExpression);
    }
private:
    string saveLastExpression;
    deque<string> d = {"nothing1", "nothing2", "nothing3", "nothing4"};
};