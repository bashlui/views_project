# ifndef MOVIES_H
# define MOVIES_H

# include "Video.h"
# include <vector>

class Movies : public Video {
private:
    std::string releaseDate;
    int movieRating;
public:
    Movies();
    Movies(std::string &_title, std::string &_genre, std::string &_duration, int &_rating, std::string &_releaseDate);
    std::string getMovieReleaseDate();
    virtual void showMovieList(std::vector<Video> &movies);
    virtual void showMovieByRating(std::vector<Video> &movies, int rating);
    virtual void showMovieByGenre(std::vector<std::string> &genres ,std::vector<Video> &movies);
    virtual void rateMovie(std::vector<Video> &movies, const std::string &title, int &rate);
    static void loadMovies(std::vector<Video> &videos);
    static std::string trim(const std::string &str);
    void setMovieReleaseDate(std::string date);
    void setMovieRating(int rating);
    int getMovieUserRating() const;

};

# endif // MOVIES_H