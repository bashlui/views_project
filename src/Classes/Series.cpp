# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>
# include <string>
# include <algorithm>

# include "Series.h"
using namespace std;

string red2 = "\033[31m";
string reset2 = "\033[0m";

Series::Series() : Video2() {
    numSeasons = 0;
}

Series::Series(std::string &_title, std::string &_genre, int &_numSeasons) :
Video2(_title, _genre) {
    numSeasons = _numSeasons;
}

void Series::setNumSeasons(int num) {
    numSeasons = num;
}

int Series::getNumSeasons() const {
    return numSeasons;
}

string Series::trim(const string &str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
        return "";
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

void Series::loadSeries(vector<Video2*> &series) {
    ifstream file("Data/Series.txt");
    if (!file.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string ignore, title, genre, seasons;
        int numSeasons;

        if (getline(ss, ignore, ',') &&
            getline(ss, title, ',') &&
            getline(ss, genre, ',') &&
            getline(ss, seasons, ',')) {
            numSeasons = stoi(seasons);
            auto* serie = new Series(title, genre, numSeasons);
            series.push_back(serie);

        }
    }
    file.close();
}

void Series::showSeriesList(vector<Video2*> &series) {
    for (const auto &serie : series) {
       Series *s = dynamic_cast<Series*>(serie);
       if (s) {
           cout << "Title: " << s->getTitle2() << endl;
           cout << "Genre: " << s->getGenre2() << endl;
           cout << "Number of seasons: " << s->getNumSeasons() << endl;
           cout << "------------------------" << endl;
       }
    }
}

void Series::showSeriesByGenre(vector<string> &genres, vector<Video2*> &series) {
    for(const auto &serie : series) {
        if (find(genres.begin(), genres.end(), serie->getGenre2()) != genres.end()) {
            Series *s = dynamic_cast<Series*>(serie);
            if (s) {
                cout << "Title: " << s->getTitle2() << endl;
                cout << "Genre: " << red2 << s->getGenre2() << reset2 << endl;
                cout << "Number of seasons: " << s->getNumSeasons() << endl;
                cout << "------------------------" << endl;
            }
        }
    }
}