# include "Episodes.h"
# include <iostream>
#include <utility>
# include <vector>
# include <string>
# include <algorithm>
# include <fstream>
# include <sstream>

using namespace std;

Episodes::Episodes() {
    episodeID = 0;
    episodeIdSeason = "";
    episodeTitle = "";
    episodeDuration = "";
    episodeRating = 0;
    episodeSeasonNumber = 0;

}

Episodes::Episodes(int id, string idSeason, string title, string duration, float rating, int seasonNumber) {
    episodeID = id;
    episodeIdSeason = std::move(idSeason);
    episodeTitle = std::move(title);
    episodeDuration = std::move(duration);
    episodeRating = rating;
    episodeSeasonNumber = seasonNumber;
}

Episodes::~Episodes() = default;

int Episodes::getEpisodeId() const {
    return episodeID;
}

string Episodes::getEpisodeIdSeason() {
    return episodeIdSeason;
}

string Episodes::getEpisodeTitle() {
    return episodeTitle;
}

string Episodes::getEpisodeDuration() {
    return episodeDuration;
}

float Episodes::getEpisodeRating() const {
    return episodeRating;
}

int Episodes::getEpisodeSeason() const {
    return episodeSeasonNumber;
}

string Episodes::trim(const string &str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
        return "";
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

void Episodes::loadEpisodes(vector<Episodes *> &episodes) {
    ifstream file("Data/Episodios.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id;
        string idSeason;
        string title;
        string duration;
        string rating;
        string seasonNumber;
        getline(ss, id, ',');
        getline(ss, idSeason, ',');
        getline(ss, title, ',');
        getline(ss, duration, ',');
        getline(ss, rating, ',');
        getline(ss, seasonNumber, ',');
        episodes.push_back(new Episodes(stoi(id), idSeason, title, duration, stof(rating), stoi(seasonNumber)));
    }
    file.close();
}


void Episodes::showEpisodesListBySeriesId(std::vector<Episodes *> &episodes, int &id) {
    for (auto &episode : episodes) {
        if (episode->getEpisodeId() == id) {
            cout << "Episode ID: " << episode->getEpisodeId() << endl;
            cout << "Episode ID Season: " << episode->getEpisodeIdSeason() << endl;
            cout << "Episode Title: " << episode->getEpisodeTitle() << endl;
            cout << "Episode Duration: " << episode->getEpisodeDuration() << " min" << endl;
            cout << "Episode Rating: " << episode->getEpisodeRating() << endl;
            cout << "Episode Season Number: " << "Season " << episode->getEpisodeSeason() << endl;
            cout << "--------------------------------" << endl;
        }
    }
}


