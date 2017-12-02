#ifndef _album_hpp
#define _album_hpp


//class Tracks;
class Artist;
#include "JSONDataObject.hpp"
#include "AlbumImage.hpp"
#include "AlbumImages.hpp"
#include "Tracks.hpp"
//#include "Artist.hpp"
#include <iostream>
#include <memory>
#include <fstream>
#include <algorithm>




class Album: public JSONDataObject {
public:
    Album();
    ~Album();

    std::string title();
    std::string genres();
    int albumID();
    int artistID();
    int numImages();
    int numTracks();
    std::string year();

    void setTracks(Tracks *tracks);
    void setArtist(Artist *artist);
    Artist *artist()  { return _artist; }
    Tracks *tracks()  { return _tracks; }

    void setAlbumImages(AlbumImages *ai);
    AlbumImage *&primaryImage() { return _primaryAlbumImage;   }
    AlbumImage *&secondaryImage()  { return _secondaryAlbumImage; }

    void print();
    std::string htmlString();
    void createFile();

private:
    std::string _title{""}, _genres{""}, _year{""};
    int _albumID{0}, _artistID{0}, _numImages{0}, _numTracks{0};

    bool cachedtitle{false}, cachedgenre{false}, cachedyear{false}, cachedalbumid{false}, cachedartistid{false}, cachednumimages{false}, cachednumtracks{false};

    AlbumImage *_primaryAlbumImage{nullptr}, *_secondaryAlbumImage{nullptr};  //unused
    Tracks *_tracks{nullptr};
    Artist *_artist{nullptr};
};


#endif
