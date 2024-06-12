# ifndef SERIES_H
# define SERIES_H

# include "Video2.h"
# include <vector>

class Series : public Video2 {
private:
    int idSeries;
    int numSeasons;
public:
    Series();
    Series(int&, std::string&, std::string&, int&);
    int getNumSeasons() const;
    int getSeriesId() const;
    virtual void showSeriesList(std::vector<Video2*> &series);
    virtual void showSeriesByGenre(std::vector<std::string> &genres, std::vector<Video2*> &series);
    static void loadSeries(std::vector<Video2*> &videos);
    static std::string trim(const std::string &str);
    void setNumSeasons(int num);
    void setSeriesId(int id);
};

# endif // SERIES_H
