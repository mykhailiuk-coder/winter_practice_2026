#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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
float Tfun(float u, float v, string text)
{
	cout << "Tfun called" << endl;
    ifstream inputFile("dat3.dat");
    float r = 1.0;

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

float func(float u, float v, string text)
{
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

float u = 1.5;
float v = 2.5;
string text = "bet hey get";

float rezult = func(u, v, text);

float U(float x) 
{
    ifstream inputFile("dat1.txt");
    float r = 1.0;

    if (!inputFile.is_open())
    {
        cerr << "Error: Could not open the file." << endl;
        r = 0.0;
        return r;
    }
}

int main()
{
    Tfun(1.5, 2.5, "bet hey get");
    return 0;
}
