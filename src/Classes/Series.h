# ifndef SERIES_H
# define SERIES_H

# include "Video.h"
# include <vector>

class Series : public Video {
private:
    int numSeasons;
public:
    Series(int &id, std::string &title, std::string &genre, std::string &duration, float &rating, int &numSeasons)
    : Video(id, title, genre, duration, rating), numSeasons(numSeasons) {}

    void setVideoId() override;
    void setVideoTitle() override;
    void setVideoLength() override;
    void setVideoGenre() override;
    void setVideoRating() override;
    double rateVideo() override;
    void showSeries(std::vector<Series> &series);
};

# endif SERIES_H
