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

private:
    int _height{0}, _artist_id{0}, _width{0};
    std::string _uri{""}, _type{""};
    bool cachedheight{false}, cachedartist_id{false}, cachedwidth{false}, cached_uri{false}, cachedtype{false};
};

#endif
