# include "Episodes.h"

Episodes::Episodes() : Video() {
    seasonEpisode = "";
    airDate = "";
}

Episodes::Episodes(int &_id, std::string &_title, std::string &_genre, std::string &_duration, double &_rating, std::string &_seasonEpisode, std::string &_airDate) : Video(_id, _title, _genre, _duration, _rating) {
    this->seasonEpisode = _seasonEpisode;
    this->airDate = _airDate;
}

std::string Episodes::getSeasonEpisode() {
    return seasonEpisode;
}





