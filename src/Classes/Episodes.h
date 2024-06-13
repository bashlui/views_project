#ifndef EPISODES_H
#define EPISODES_H

# include <vector>
# include <string>
# include "Series.h"

class Episodes {
private:
    int episodeID;
    std::string episodeIdSeason;
    std::string episodeTitle;
    std::string episodeDuration;
    float episodeRating;
    int episodeSeasonNumber;
public:
    Episodes();
    Episodes(int, std::string, std::string, std::string, float, int);
    ~Episodes();
    int getEpisodeId() const;
    std::string getEpisodeIdSeason();
    std::string getEpisodeTitle();
    std::string getEpisodeDuration();
    float getEpisodeRating() const;
    int getEpisodeSeason() const;
    static std::string trim(const std::string &str);
    virtual void showEpisodesListBySeriesId(std::vector<Episodes *> &episodes, int &id);
    static void loadEpisodes(std::vector<Episodes *> &episodes);
};

#endif // EPISODES_H