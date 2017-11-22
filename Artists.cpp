#include "Artists.hpp"
#include "Artist.hpp"
#include "Albums"
#include <string>
#include <fstream>

Artists::Artists() {}
Artists::~Artists() {}

int Artists::numArtists() {
    return _listOfDataObjects->size();
}

void Artists::addArtist(Artist *artist) {
    _listOfDataObjects->push_back(std::make_shared<Artist>(*artist));
}


Artist* Artists::artistWithID(int aID) {
    for (auto i: *_listOfDataObjects) {
        if (i->valueForIntegerAttribute("artist_id") == aID)
            return i;
    }
}

void Artists::loadArtistsFromFile(std::string fileName) {
    std::fstream artStream;
    artStream.open(fileName.c_str(), std::fstream::in);
    parseJSONArray(artStream);
    artStream.close();
}

std::string Artists::htmlString() {
    std::cout << "htmlString in artists is being called " << std::endl;
}


void Artists::setAlbumsForArtists(Album *albums) {
    //
}

void setImagesForArtists(ArtistImages *ai) {
    //
}

std::vector<Artist *>* Artists::listOfArtists() {
    return (std::vector<Artist *> *) _listOfDataObjects;
}

void Artists::runAsserts() {
  std::cout << "Run asserts in artists is being called" << std::endl;
}
