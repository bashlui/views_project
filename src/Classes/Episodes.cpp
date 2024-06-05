# include "Episodes.h"

Episodes::Episodes(int& id, std::string& title, std::string& genre, std::string& duration, float& rating, std::string& season, std::string& episode) : Video(id, title, genre, duration, rating) {
    this->season = season;
    this->episode = episode;
}

std::string Episodes::getSeason() {
    return season;
}

std::string Episodes::getEpisode() {
    return episode;
}