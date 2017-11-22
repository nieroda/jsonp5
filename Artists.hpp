#ifndef __artists_hpp
#define __artists_hpp

#include "JSONArray.hpp";
#include "memory";

class Artists: public JSONArray
{
public:
    Artists();
    ~Artists();

    int numArtists();
    void addArtist(Artist *artist);
    Artist *artistWithID(int aID);
    void loadArtistsFromFile(std::string fileName);
    std::string htmlString();
    std::shared_ptr<JSONDataObject> jsonObjectNode() { return std::make_shared<Track>()  }
    void setAlbumsForArtists(Albums *albums);
    void setImagesForArtists(ArtistImages *);
    std::vector<Artist *> *listOfArtists() { return (std::shared_ptr<std::vector<std::shared_ptr<JSONDataObject>>>) _listOfDataObjects; }
    void runAsserts();  // used for checking the integrity of this class.

};

#endif
