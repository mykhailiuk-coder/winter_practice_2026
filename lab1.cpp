#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <exception>

using namespace std;

/* ==== ПРОТОТИПИ ФУНКЦІЙ ==== */
double Wnr(double x, double y);
double Qnr1(double x, double y);
double Qnk(double x, double y);
double Rnk(double x, double y, double z);
/* ========================== */

class NumberNotFoundException : public exception
{
    string msg;
public:
    NumberNotFoundException() : msg("Number is not found") {}
    void message()
    {
        cout << "NumberNotFound: " << msg << endl;
    }
};

class FileNotFoundException : public exception
{
    string msg;
public:
    FileNotFoundException(string s) : msg(s) {}
    void message()
    {
        cout << "FileNotFound: " << msg << endl;
    }
};

class InvalidArgumentException : public exception
{
    string msg;
public:
    InvalidArgumentException(string s) : msg(s) {}
    void message()
    {
        cout << "InvalidArgument: " << msg << endl;
    }
};

vector<string> split(const string& s, char delim)
{
    vector<string> result;
    size_t start = 0, end;
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
    ifstream inputFile("dat3.dat");
    double r = 1.0;

    if (!inputFile.is_open())
    {
        FileNotFoundException e("dat3.dat");
        e.message();
        return 0.0;
    }

    vector<string> dat3_words;
    string word;
    while (inputFile >> word)
        dat3_words.push_back(word);

    vector<string> text_words = split(text, ' ');

    for (int j = 0; j < text_words.size(); j++)
    {
        bool found = false;
        for (int i = 0; i + 1 < dat3_words.size(); i++)
        {
            if (dat3_words[i] == text_words[j])
            {
                found = true;
                r = stod(dat3_words[i + 1]);
                break;
            }
        }
        if (!found) r = 0.0;
    }

    return u * u + v * v - r * (u + v) + r * r;
}

double func(double u, double v, string text)
{
    if (abs(u) <= 0.5)
        return Tfun(0, v, text);
    else if (abs(u) > 0.5 && u < v)
        return Tfun(u, v, text);
    else if (abs(u) > 0.5 && u > v)
        return Tfun(u, 0, text) - Tfun(0, v, "set");
    else
        return 0.0;
}

double U1(double x) { return atan(asin(sin(3 * x))); }
double T1(double x) { return atan(acos(sin(2 * x))); }

double Wnr1(double x, double y)
{
    if (x > y)
        return T1(x) - 0.9 * U1(x) * U1(y);
    else
        return 0.9 * T1(x) * T1(y) - U1(x);
}

double U(double x)
{
    ifstream inputFile("dat1.dat");
    if (!inputFile.is_open()) return 1.0;

    map<double, double> table;
    double xi, yi;
    while (inputFile >> xi >> yi)
        table[xi] = yi;

    if (table.find(x) == table.end())
        return 1.0;

    return table[x];
}

double T(double x)
{
    ifstream inputFile("dat2.dat");
    if (!inputFile.is_open()) return 1.0;

    map<double, double> table;
    double xi, yi;
    while (inputFile >> xi >> yi)
        table[xi] = yi;

    if (table.find(x) == table.end())
        return 1.0;

    return table[x];
}

double Wnr(double x, double y)
{
    if (x > y)
        return T(x) - U(x) * U(y);
    else
        return T(x) * T(y) - U(x);
}

double Qnk(double x, double y)
{
    return 10.5 * Qnr1(2 * x, y) - 3.75 * Qnr1(x, 2 * y);
}

double Rnk(double x, double y, double z)
{
    return x * Qnk(x, y) + y * Qnk(y, x) + z * Qnk(z, x);
}

double Qnr1(double x, double y)
{
    if (y == 0) return 1.0;

    else if (x > y && 10 * pow(y, 4) - x >= 0)
        return x * x * sqrt(10 * pow(y, 4) - x);

    else if (x <= y && 3 * x > y && 10 * pow(x, 4) - y >= 0)
        return pow(x, 3) * log(10 * pow(x, 4) - y);

    else if (x <= y && 3 * x <= y && pow(y, 4) - 2 * x >= 0)
        return y * y * sqrt(pow(y, 4) - 2 * x);

    else if (10 * y * y - x < 0)
        return Rnk(x, y, 1.25);

    else if (y * y - 2 * x < 0)
        return Rnk(x, y, 1.5);

    else if (10 * x * x - y < 0)
        return Qnk(x, 0);

    else
        throw InvalidArgumentException("Invalid arguments");
}

int main()
{
    double x, y, z;
    cout << "Enter x, y, z: ";
    cin >> x >> y >> z;

    string text;
    cout << "Enter text: ";
    cin >> text;

    cout << "Result: " << func(x, y, text) << endl;
    return 0;
}
