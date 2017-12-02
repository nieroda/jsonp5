#include "ArtistImages.hpp"

ArtistImages::ArtistImages() {}

ArtistImages::~ArtistImages() {
  for (auto i : *listofArtistImages())
    delete i;
}

int ArtistImages::numArtistImages() {
  return _listOfDataObjects->size();
}

void ArtistImages::addArtistImage(ArtistImage *aimage) {
  _listOfDataObjects->push_back(aimage);
}

ArtistImages* ArtistImages::imageswithID(int aID) {
  ArtistImages *artist = new ArtistImages();
  for (auto i : *listofArtistImages()) {
    if (i->artistID() == aID)
      artist->addArtistImage(i);
  }
  return artist;
}

void ArtistImages::loadArtistImagesFromFile(std::string fileName) {
  std::fstream aiStream;
  aiStream.open(fileName.c_str(), std::fstream::in);
  parseJSONArray(aiStream);
  aiStream.close();
}

std::string ArtistImages::htmlString() {
  std::cout << "unused" << std::endl;
  return "foobaz";
}

void ArtistImages::runAsserts() {
  std::cout << "asserts called in artist image" << std::endl;
  for (auto i: *_listOfDataObjects) {
    i->print();
  }
}
