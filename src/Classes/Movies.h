# ifndef MOVIES_H
# define MOVIES_H

# include "Video.h"
# include <vector>

class Movies : public Video {
private:
    static void loadMovies(std::vector<Video> &videos);
    static std::string trim(const std::string &str);
    std::string releaseDate;
public:
    Movies();
    Movies(std::string &_title, std::string &_genre, std::string &_duration, int &_rating, std::string &_releaseDate);
    std::string getMovieReleaseDate();
    virtual void showMovieList(std::vector<Video> &movies);
    virtual void showMovieByRating(std::vector<Video> &movies, int rating);
    void setMovieReleaseDate(std::string date);

};

# endif // MOVIES_H