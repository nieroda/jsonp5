#ifndef __tracks_hpp__
#define __tracks_hpp__

#include "JSONArray.hpp"
#include "Track.hpp"
#include "memory"
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

class Tracks: public JSONArray {
public:
    Tracks();
    ~Tracks();

    int numTracks();
    void addTrack(Track *track);

    //std::shared_ptr<Tracks> trackswithAlbumID(int aID);
    Tracks *trackswithAlbumID(int aID);
    Track *trackwithAlbumID(int aID);
    void loadTracksFromFile(std::string fileName);
    std::string htmlString();
    //std::shared_ptr<JSONDataObject> jsonObjectNode() { return std::make_shared<Track>();  }
    JSONDataObject *jsonObjectNode() { return new Track(); }
    JSONDataObject *trackwithAlbumIDs(int aID);
    //std::shared_ptr<std::vector<std::shared_ptr<JSONDataObject>>> listOfTracks() { return  _listOfDataObjects; }
    std::vector<Track *> *listOfTracks() { return (std::vector<Track *> *) _listOfDataObjects; }
    //std::vector<JSONDataObject *>* listOfArtists() { return _listOfDataObjects; }
    //std::shared_ptr<std::vector<std::shared_ptr<Track>>> listOfTracks() {
    //  return _listOfDataObjects;
    //}
    void runAsserts();
};

#endif
