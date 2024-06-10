#ifndef EPISODES_H
#define EPISODES_H

# include "Video.h"

class Episodes : public Video {
    private:
        int seasonEpisode;
        std::string airDate;
    public:
        Episodes();
        Episodes(int&, std::string&, std::string&, std::string&, double&, int&, std::string&);
        int getSeasonEpisode();
        std::string getAirDate();
};



#endif EPISODES_H