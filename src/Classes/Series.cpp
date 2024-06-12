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
    idSeries = 0;
    numSeasons = 0;
}

Series::Series(int& _id,std::string &_title, std::string &_genre, int &_numSeasons) :
Video2(_id, _title, _genre) {
    idSeries = _id;
    numSeasons = _numSeasons;
}

int Series::getSeriesId() const {
    return idSeries;
}

void Series::setSeriesId(int id) {
    idSeries = id;
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
        string id, title, genre, seasons;
        int numSeasons, serieId;

        if (getline(ss, id, ',') &&
            getline(ss, title, ',') &&
            getline(ss, genre, ',') &&
            getline(ss, seasons, ',')) {
            serieId = stoi(id);
            numSeasons = stoi(seasons);
            auto* serie = new Series(serieId, title, genre, numSeasons);
            series.push_back(serie);

        }
    }
    file.close();
}

void Series::showSeriesList(vector<Video2*> &series) {
    for (const auto &serie : series) {
       Series *s = dynamic_cast<Series*>(serie);
       if (s) {
           cout << "ID: " << s->getId2() << endl;
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
                cout << "ID: " << s->getId2() << endl;
                cout << "Title: " << s->getTitle2() << endl;
                cout << "Genre: " << red2 << s->getGenre2() << reset2 << endl;
                cout << "Number of seasons: " << s->getNumSeasons() << endl;
                cout << "------------------------" << endl;
            }
        }
    }
}