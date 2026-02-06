#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
    ifstream inputFile("dat3.dat");
    float r = 1.0;

    if (!inputFile.is_open())
    {
        cerr << "Error: Could not open the file." << endl;
        r = 0.0;
    }

    vector <string> dat3_words;

    string word;
    while (inputFile >> word)
    {
        dat3_words.push_back(word);
    }
    inputFile.close();

    vector<string> text_words = split(text, ' ');

    for (int j = 0; j < text_words.size(); j++)
    {
        bool found = false;

        for (int i = 0; i < dat3_words.size(); i++)
        {
            if (dat3_words[i] == text_words[j])
            {
                cout << text_words[j] << " found at index " << i/2 << endl;
                r = stof(dat3_words[i+1]);
				cout << "r = " << r << endl;
                found = true;
                break; 
            }
            if (dat3_words[i] == "")
            {
				r = 0.0;
            }
            if (i % 2 == 1 && dat3_words[i] == "")
            {
                r = 1.0;
            }
        }

        if (!found)
        {
            cout << text_words[j] << " was not found" << endl;
			r = 0.0;
			cout << "r = " << r << endl;
        }
    }

	r = u * u + v * v - r * (u + v) + r * r;

	return r;
}

int main()
{
    Tfun(1.5, 2.5, "bet hey get");
    return 0;
}
