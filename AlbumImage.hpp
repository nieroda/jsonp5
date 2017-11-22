#ifndef __albumimage__hpp
#define __albumimage_hpp

#include "JSONDataObject.hpp"
#include <string>
#include <iostream>

class AlbumImage: public JSONDataObject {
public:
    AlbumImage();
    ~AlbumImage();

    std::string height();
    std::string type();
    std::string uri();
    int width();
    int album_id();

private:
    std::string _height{""}, _type{""}, _uri{""};
    int _width{0}, _albumID{0};
    bool cachedheight{false}, cachedtype{false}, cacheduri{false}, cachedwidth{false}, cachedalbumid{false};
};

#endif
