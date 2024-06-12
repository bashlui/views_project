# ifndef VIDEO2_H
# define VIDEO2_H
# include <vector>
# include <string>

class Video2 {
protected:
    std::string title;
    std::string genre;
public:
    Video2();
    virtual ~Video2();
    Video2(std::string&, std::string&);
    std::string getTitle2() const;
    std::string getGenre2() const;
};

# endif // VIDEO2_H