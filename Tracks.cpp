#include "Tracks.hpp"

Tracks::Tracks() {}
Tracks::~Tracks() {}

int Tracks::numTracks() {
  return _listOfDataObjects->size();
}

void Tracks::addTrack(Track *track) {
  //std::cout << "adding track" << std::endl;
    _listOfDataObjects->push_back(std::make_shared<Track>(*track));
}

Track* Tracks::trackwithAlbumID(int aID) {
    for (auto i : *_listOfDataObjects) {
      if (i->valueForIntegerAttribute("album_id") == aID)
        return reinterpret_cast<Track *>(i.get());
  }
}

std::shared_ptr<Tracks> Tracks::trackswithAlbumID(int aID) {
    std::shared_ptr<Tracks> track = std::make_shared<Tracks>();
    for (auto i : *_listOfDataObjects) {
      if (i->valueForIntegerAttribute("album_id") == aID) {
        track->addTrack(reinterpret_cast<Track*>(i.get()));
      }
    }
    return track;
}

void Tracks::loadTracksFromFile(std::string fileName) {
  std::fstream trackStream;
  trackStream.open(fileName.c_str(), std::fstream::in);
  parseJSONArray(trackStream);
  trackStream.close();
}

std::string Tracks::htmlString() {
  std::cout << "Bleh :: Blah" << std::endl;
}

void Tracks::runAsserts() {
  std::cout << "Run asserts in track is being called " << std::endl;
  for (auto i: *_listOfDataObjects) {
    std::cout << "Inside for loop" << std::endl;
    i->print();
  }
}
