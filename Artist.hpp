#ifndef __artist_hpp
#define __artist_hpp

#include<fstream>
#include<cstring>
#include <vector>
#include <string>

#include "JSONDataObject.hpp"

class Artist: public JSONDataObject {
public:
    Artist();
    ~Artist();

    std::string profile();
    std::string artistName();
    std::string realName();
    std::string numImages();  // since it's a string in the JSON file
    int    artistID();

    //virtual void print();
    std::string htmlString();

    // the following 4 function-prototypes are new to this project.
    //void setAlbums(Albums *albums) { _albums = albums; }
    //Albums *albums() { return _albums; }
    //ArtistImage *&primaryImage()       { return _primaryImage;   }
    //ArtistImage *&secondaryImage()     { return _secondaryImage; }

private:
    int _artistID{0};
    bool cachedName{false}, cachedRealName{false}, cachedProfile{false}, cachedNumImages{false}, cachedArtistID{false};
    std::string _name{""}, _realName{""}, _profile{""}, _numImages{""};


    // the following 3 variables are new to this project.
    //ArtistImage *_primaryImage, *_secondaryImage;
    //Albums *_albums;
};

#endif
