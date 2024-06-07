#ifndef EPISODES_H
#define EPISODES_H

# include "Video.h"

class Episodes : public Video {
    private:
        std::string seasonEpisode;
        std::string airDate;
    public:
        Episodes();
        Episodes(int &_id, std::string &_title, std::string &_genre, std::string &_duration, double &_rating, std::string &_seasonEpisode, std::string &_airDate);
        std::string getSeasonEpisode();
};



#endif EPISODES_H