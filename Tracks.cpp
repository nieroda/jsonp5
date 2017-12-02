#include "Tracks.hpp"

Tracks::Tracks() {}
Tracks::~Tracks() {
    for (auto i : *listOfTracks())
      delete i;
}

int Tracks::numTracks() {
  return _listOfDataObjects->size();
}

void Tracks::addTrack(Track *track) {
  //std::cout << "adding track" << std::endl;
    //_listOfDataObjects->push_back(std::make_shared<Track>(*track));
    _listOfDataObjects->push_back(track);
}

Track* Tracks::trackwithAlbumID(int aID) {
    for (auto i : *listOfTracks()) {
      if (i->valueForIntegerAttribute("album_id") == aID)
        return i;
  }
}

Tracks* Tracks::trackswithAlbumID(int aID) {
    Tracks *track = new Tracks();
    for (auto i : *listOfTracks()) {
      if (i->valueForIntegerAttribute("album_id") == aID) {
        track->addTrack(i);
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
  std::string html;
  html += "<h2> TrackList </h2>\n";
  html += "<table class=\"tracks\">\n";
  for (auto i : *listOfTracks())
    html += i->htmlString();
  html += "</table>\n";

  return html;
}

void Tracks::runAsserts() {
  std::cout << "Run asserts in track is being called " << std::endl;

  for (auto i : *listOfTracks()) {
    i->print();
  }
}
