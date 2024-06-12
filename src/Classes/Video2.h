# ifndef VIDEO2_H
# define VIDEO2_H
# include <vector>
# include <string>

class Video2 {
protected:
    int id;
    std::string title;
    std::string genre;
public:
    Video2();
    virtual ~Video2();
    Video2(int&, std::string&, std::string&);
    int getId2() const;
    std::string getTitle2() const;
    std::string getGenre2() const;
};

# endif // VIDEO2_H