# ifndef MOVIES_H
# define MOVIES_H

# include "Video.h"
# include <vector>

class Movies : public Video {
private:
    Movies();
    std::string releaseDate;
public:
    Movies(int&, std::string&, std::string&, std::string&, double&, std::string&);
    virtual void setMovieReleaseDate() = 0;
    std::string getMovieReleaseDate();
    void display() override;
};

# endif // MOVIES_H