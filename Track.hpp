#ifndef __track_hpp
#define __track_hpp

#include "JSONDataObject.hpp"
#include <string>


class Track: public JSONDataObject {
public:
    Track();
    ~Track();

    std::string artistName();
    std::string title();
    std::string albumName();
    std::string duration();
    std::string position();
    int albumID();
    
    bool getA() { return cached_artistName; }

    std::string htmlString();
    void print();

private:
    std::string _artistName{""}, _title{""}, _albumName{""}, _duration{""}, _position{""};
    bool cached_artistName{false}, cached_title{false}, cached_albumName{false}, cached_duration{false}, cached_position{false}, cached_albumID{false};
    int _albumID{0};
};

#endif
