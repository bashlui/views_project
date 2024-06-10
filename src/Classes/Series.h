# ifndef SERIES_H
# define SERIES_H

# include "Video.h"
# include <vector>

class Series : public Video {
private:
    int numSeasons;
public:
    Series();
    Series(int&, std::string&, std::string&, std::string&, double&, int&);
    virtual void setNumSeasons() = 0;
    int getNumSeasons();
};

# endif SERIES_H
