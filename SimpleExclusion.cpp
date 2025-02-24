#include <iostream>
#include <string>
using namespace std;


class bad_length : public exception {
public:
    const char* what() const override {
        return "Вы ввели слово запретной длины! До свидания";
    }
};


int function(const string& str, int forbidden_length) {
    if (str.size() == forbidden_length) {
        throw bad_length();
    }
    return str.size();
}

int main() {
    setlocale(LC_ALL,"Ru");
    int forbidden_length;


    cout << "Введите запретную длину: ";
    cin >> forbidden_length;



    string word;
    while (1)
    {
        cout << "Введите слово: ";
        cin >> word;

        try 
        {

            int length = function(word, forbidden_length);
            cout << "Длина слова \"" << word << "\" равна " << length << "\n";
        }
        catch (const bad_length& e)
        {
            cout << e.what() << "\n";
            break;
        }
    }

}
