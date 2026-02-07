#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <exception>

using namespace std;

class NumberNotFoundException : public exception
{
    string msg;
public:
    NumberNotFoundException() : msg("Number is not found") {}
    void message()
    {
        cout << "FileNotFound" << msg << endl;
    }
};

class FileNotFoundException : public exception
{
    string msg = "FileNotFound";
public:
    FileNotFoundException(string s) : msg(s) {}
    void message()
    {
        cout << "FileNotFound" << msg << endl;
    }
};

vector<string> split(const string& s, char delim) {

    vector<string> result;
    size_t start = 0;
    size_t end;

    while ((end = s.find(delim, start)) != string::npos)
    {
        result.push_back(s.substr(start, end - start));
        start = end + 1;
    }
    result.push_back(s.substr(start));

    return result;
}

// Алгоритм 1
double Tfun(double u, double v, string text)
{
    cout << "Tfun called" << endl;
    ifstream inputFile("dat3.dat");
    double r = 1.0;

    // Перевірка на відкриття файлу
    try {
        if (!inputFile.is_open()) {
            throw FileNotFoundException("dat3.dat");
        }
    }
    catch (FileNotFoundException& e) {
        e.message();
        return 0.0;
    }

    vector <string> dat3_words;

    string word;
    while (inputFile >> word)
    {
        dat3_words.push_back(word);
    }
    inputFile.close();

    vector<string> text_words = split(text, ' ');

    // Пошук кожного слова з тексту в масиві слів з файлу
    for (int j = 0; j < text_words.size(); j++)
    {
        bool found = false;

        for (int i = 0; i < dat3_words.size(); i++)
        {
            if (dat3_words[i] == text_words[j])
            {
                // Слово знайдено в файлі
                found = true;
                cout << text_words[j] << " found at index " << i / 2 << endl;
                r = stof(dat3_words[i + 1]);
                cout << "r = " << r << endl;
                if (i + 1 < dat3_words.size()) {
                    try {
                        r = stof(dat3_words[i + 1]);
                    }
                    catch (NumberNotFoundException) {
                        r = 1.0; // числове значення відсутнє
                    }
                }
                break;
            }
            if (i % 2 == 1 && dat3_words[i] == "")
            {
                r = 1.0;
            }
        }

        // Слово не знайдено в файлі
        if (!found)
        {
            cout << text_words[j] << " was not found" << endl;
            r = 0.0;
            cout << "r = " << r << endl;
        }
    }

    return u * u + v * v - r * (u + v) + r * r;
}

double func(double u, double v, string text)
{
    cout << "func called" << endl;
    if (abs(u) <= 0.5)
    {
        return Tfun(0, v, text);
    }
    else if (abs(u) > 0.5 && u < v)
    {
        return Tfun(u, v, text);
    }
    else if (abs(u) > 0.5 && u > v)
    {
        return Tfun(u, 0, text); - Tfun(0, v, "set");
    }
}

double u = 1.5;
double v = 2.5;
string text = "bet hey get";

double rezult = func(u, v, text);

double U1(double x)
{
    cout << "U1 called" << endl;
    return atan(asin(sin(3 * x)));
}

double T1(double x)
{
    cout << "T1 called" << endl;
    return atan(acos(sin(2 * x)));
}

double Wnr1(double x, double y) 
{
    cout << "Wnr1 called" << endl;
    if (x > y) 
    {
        return T1(x) - 0.9 * U1(x) * U1(y);
    }
    else 
    {
        return 0.9 * T1(x) * T1(y) - U1(x);
    }
}

double U(double x)
{
    cout << "U called" << endl;
    ifstream inputFile("dat1.dat");

    try {
        if (!inputFile.is_open()) {
            throw FileNotFoundException("dat1.dat");
        }

        vector <string> dat1_words;

        string word;
        while (inputFile >> word)
        {
            dat1_words.push_back(word);
        }
        inputFile.close();

        map<double, double> Ux;

        for (int i = 0; i < dat1_words.size(); i += 2)
        {
            double key = stof(dat1_words[i]);
            double value = stof(dat1_words[i + 1]);
            Ux[key] = value;
        }
        if (Ux.find(x) != Ux.end())
        {
            return Ux[x];
        }
        else
        {
            throw NumberNotFoundException();
        }
    }

    catch (FileNotFoundException& e) {
        e.message();
        return 1.0;
    }

    catch (NumberNotFoundException& e) {
        e.message();
        return 1.0;
    }
}

double T(double x)
{
    cout << "T called" << endl;
    ifstream inputFile("dat2.dat");

    try {
        if (!inputFile.is_open()) {
            throw FileNotFoundException("dat2.dat");
        }

        vector <string> dat1_words;

        string word;
        while (inputFile >> word)
        {
            dat1_words.push_back(word);
        }
        inputFile.close();

        map<double, double> Ux;

        for (int i = 0; i < dat1_words.size(); i += 2)
        {
            double key = stof(dat1_words[i]);
            double value = stof(dat1_words[i + 1]);
            Ux[key] = value;
        }
        if (Ux.find(x) != Ux.end())
        {
            return Ux[x];
        }
        else
        {
            throw NumberNotFoundException();
        }
    }

    catch (FileNotFoundException& e) {
        e.message();
        return 1.0;
    }

    catch (NumberNotFoundException& e) {
        e.message();
        return 1.0;
    }
}

double U2(double x)
{
    ifstream inputfile("dat1.dat");
    if (!inputfile.is_open())
    {
        return 0.0;
    }

    map<double, double> table;

    double xi, yi;
    while (inputfile >> xi >> yi)
    {
        table[xi] = yi;
    }

    inputfile.close();

    if (table.empty())
    {
        return 0.0;
    }

    auto it = table.find(x);
    if (it != table.end())
    {
        return it->second;
    }

    auto it_right = table.lower_bound(x);

    if (it_right == table.begin() || it_right == table.end())
    {
        return 0.0; 
    }

    auto it_left = prev(it_right);

    double x1 = it_left->first;
    double y1 = it_left->second;
    double x2 = it_right->first;
    double y2 = it_right->second;

    //Лінійна інтерполяція
    double result = y1 + (y2 - y1) * (x - x1) / (x2 - x1);

    return result;
}

double T2(double x)
{
    ifstream inputfile("dat2.dat");
    if (!inputfile.is_open())
    {
        return 0.0;
    }

    map<double, double> table;
    double xi, yi;
    while (inputfile >> xi >> yi)
    {
        table[xi] = yi;
    }
    inputfile.close();
    
    if (table.empty())
        return 0.0;
    
    auto it = table.find(x);
    if (it != table.end())
    {
        return it->second;
    }
    
    auto it_right = table.lower_bound(x);
    if (it_right == table.begin() || it_right == table.end())
    {
        return 0.0; 
    }
    
    auto it_left = prev(it_right);
    double x1 = it_left->first;
    double y1 = it_left->second;
    double x2 = it_right->first;
    double y2 = it_right->second;
    
    //Лінійна інтерполяція
    double result = y1 + (y2 - y1) * (x - x1) / (x2 - x1);
    return result;
}

double Wnr2(double x, double y) 
{
    if (x > y) 
    {
		return 0.9 * T2(x) - U2(x) * U2(y);
    }
    else 
    {
        return 0.9 * T2(x) * T2(y) - 0.9*U2(x);
    }
}

double Wnk2(double x, double y)
{
    return 10 * Wnr2(x, y) - 3 * Wnr2(x, y);
}

double Gnk(double x, double y, double z) 
{
    if (x*x + y*y + z*z >= 0.001)
    {
        return x * Wnk2(x / sqrt(x * x + y * y + z * z), y / sqrt(x * x + y * y + z * z)) + 
            y * Wnk2(y / sqrt(x * x + y * y + z * z), x / sqrt(x * x + y * y + z * z)) + 
            z * Wnk2(z / sqrt(x * x + y * y + z * z), x / sqrt(x * x + y * y + z * z));
    }
    else 
    {
        return 0;
    }
}

double Wnr(double x, double y)
{
    if (x > y)
    {
        return T(x) - U(x) * U(y);
    }
    else
    {
		return T(x) * T(y) - U(x);
    }
}

double Wnk(double x, double y)
{
    cout << "Wnk called" << endl;
    ifstream inputFile("dat1.dat");
    if (!inputFile.is_open())
    {
        cout << "FileNotFound: dat1.dat" << endl;
        return 10 * Wnr1(2.5 * x, y) - 4 * Wnr1(x, 2.5 * y);
    }
    return 10.5 * Wnr(2*x, y) - 3.75 * Wnr(x, 2*y);
}

double Gnk(double x, double y, double z)
{
    return x * Wnk(x, y) + y * Wnk(y, x) + z * Wnk(z, x);
}

double gold(double x, double y, double z)
{
    return x * Gnk(x, y, z) + Gnk(y, z, x) * Gnk(z, x, y);
}

double v(double x, double y, double z) 
{
    return gold(x, y, 2 * z);
}

double Qnr(double x, double y, double z) 
{
	if (y == 0) return 0.0;
    if (x > y && 10 * pow(y, 4) - x >= 0 && y != 0) return x*x * sqrt(10 * pow(y, 4) - x);
    //if () 
	else return 0.0;
}

int main()
{
	double x, y, z;
	cout << "Enter x, y, z: ";
	cin >> x >> y >> z;
    string text;
    cout << "Enter text: ";
    cin >> text;
    return 0;
}
