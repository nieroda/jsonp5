#ifndef __artists_hpp
#define __artists_hpp

#include "JSONArray.hpp"
#include "Artist.hpp"
#include "ArtistImages.hpp"


class Artists: public JSONArray {
public:
    Artists();
    ~Artists();

    int numArtists();
    void addArtist(Artist *artist);
    Artist *artistWithID(int aID);
    void loadArtistsFromFile(std::string fileName);
    std::string htmlString();
    //std::shared_ptr<JSONDataObject> jsonObjectNode() { return std::make_shared<Track>()  }
    JSONDataObject *jsonObjectNode() { return new Artist(); }
    void setArtistImages(ArtistImages *ai);
    //std::vector<Artist *> *listOfArtists() { return (std::shared_ptr<std::vector<std::shared_ptr<JSONDataObject>>>) _listOfDataObjects; }
    std::vector<Artist *> *listOfArtists() { return (std::vector<Artist *> *) _listOfDataObjects; }
    void runAsserts();  // used for checking the integrity of this class.

};

#endif
