#ifndef EPISODES_H
#define EPISODES_H
# include "Video.h"

class Episodes : public Video {
private:
    std::string season;
    std::string episode;
public:
    Episodes(int&, std::string&, std::string&, std::string&, float&, std::string&, std::string&);
    virtual std::string getSeason();
    virtual std::string getEpisode();

};



#endif EPISODES_H