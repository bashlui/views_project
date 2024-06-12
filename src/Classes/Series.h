# ifndef SERIES_H
# define SERIES_H

# include "Video2.h"
# include <vector>

class Series : public Video2 {
private:
    int numSeasons;
public:
    Series();
    Series(std::string&, std::string&, int&);
    int getNumSeasons() const;
    virtual void showSeriesList(std::vector<Video2*> &series);
    virtual void showSeriesByGenre(std::vector<std::string> &genres, std::vector<Video2*> &series);
    static void loadSeries(std::vector<Video2*> &videos);
    static std::string trim(const std::string &str);
    void setNumSeasons(int num);
};

# endif // SERIES_H
