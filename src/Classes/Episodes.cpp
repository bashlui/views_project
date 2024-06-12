# include "Episodes.h"
# include <iostream>
# include <string>
#include <utility>
# include <vector>
# include <fstream>
# include <sstream>

using namespace std;

Episodes::Episodes() {
    this->episodeDuration = "";
    this->episodeSeason = 0;
}

Episodes::~Episodes() = default;

Episodes::Episodes(int &id, string &title, string &genre, int &idSeries, int &numSeasons, string &episodeDuration, int &episodeSeason)
: Series(id, title, genre, numSeasons) {
    this->episodeDuration = episodeDuration;
    this->episodeSeason = episodeSeason;
}

string Episodes::getEpisodeDuration() const {
    return this->episodeDuration;
}

int Episodes::getEpisodeSeason() const {
    return this->episodeSeason;
}

void Episodes::setEpisodeDuration(string duration) {
    this->episodeDuration = duration;
}

void Episodes::setEpisodeSeason(int season) {
    this->episodeSeason = season;
}

string Episodes::trim(const string &str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
        return "";
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

void Episodes::loadEpisodes(std::vector<Video2 *> &episodes) {
    ifstream file("Data/Episodios.txt");
    if (!file.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, title, genre, seasons, duration, season;
        int idSeries, numSeasons, episodeSeason;

        if (getline(ss, id, ',') &&
            getline(ss, title, ',') &&
            getline(ss, genre, ',') &&
            getline(ss, seasons, ',') &&
            getline(ss, duration, ',') &&
            getline(ss, season, ',')) {
            idSeries = stoi(id);
            numSeasons = stoi(seasons);
            episodeSeason = stoi(season);
            auto* episode = new Episodes(idSeries, title, genre, idSeries, numSeasons, duration, episodeSeason);
            episodes.push_back(episode);
        }
    }
    file.close();
}

void Episodes::showEpisodesListBySeriesId(std::vector<Video2 *> &episodes, const string &id) {
    for (auto &episode : episodes) {
        if (episode->getId2() == stoi(id)) {
            cout << "ID: " << episode->getId2() << endl;
            cout << "Title: " << episode->getTitle2() << endl;
            cout << "Duration: " << dynamic_cast<Episodes*>(episode)->getEpisodeDuration() << endl;
            cout << "Season: " << dynamic_cast<Episodes*>(episode)->getEpisodeSeason() << endl;
            cout << "--------------------------------" << endl;
        }
    }
}


