#ifndef EPISODES_H
#define EPISODES_H

# include <vector>
# include <string>
# include "Series.h"

class Episodes : public Series {
private:
    // id, title, genre X, idSeries, numSeasons X
    // EPISODIO: id, titulo, duración, rating, numero de temporada
    std::string episodeDuration;
    int episodeSeason;
public:
    Episodes();
    ~Episodes() override;
    Episodes(int&, std::string&, std::string&, int&, int&, std::string&, int&);
    std::string getEpisodeDuration() const;
    int getEpisodeSeason() const;
    void setEpisodeDuration(std::string duration);
    void setEpisodeSeason(int season);
    virtual void showEpisodesListBySeriesId(std::vector<Video2*> &episodes, const std::string &id);
    static void loadEpisodes(std::vector<Video2*> &episodes);
    static std::string trim(const std::string &str);

};

#endif // EPISODES_H