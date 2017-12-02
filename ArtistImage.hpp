#ifndef __artist_image_hpp
#define __artist_image_hpp

#include "JSONDataObject.hpp"
#include <string>

class ArtistImage: public JSONDataObject {
public:
    ArtistImage();
    ~ArtistImage();
    int height();
    int artistID();
    int width();
    std::string uri();
    std::string type();

    void print();
    std::string htmlString();

private:
    int _height{0}, _artist_id{0}, _width{0};
    std::string _uri{""}, _type{""};
    bool cachedheight{false}, cachedartist_id{false}, cachedwidth{false}, cached_uri{false}, cachedtype{false};
};

#endif

/*
{"height": 600, "uri": "http://cWolf.cs.sonoma.edu/~cs315/projects/project5/images/A-82730-1419714988-9675.jpeg", "artist_id": 82730, "width": 600, "type": "primary"}
*/
