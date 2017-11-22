#include "Album.hpp"

Album::Album() {
  std::cout << "Album created.." << std::endl;
  _primaryAlbumImage = new AlbumImage();
  _secondaryAlbumImage = new AlbumImage();
  _tracks = new Tracks();
  _artist = new Artist();
}
Album::~Album() { /*std::cout << "Called Destructor~ " << std::endl;*/ }

void Album::setTracks(Tracks *tracks) {
  std::cout << "running asserts" << std::endl;
  tracks->runAsserts();
    _tracks = tracks;
}

void Album::setArtist(Artist *artist) {
  _artist = artist;
}


std::string Album::title() {
    if ( cachedtitle )
        return _title;
    cachedtitle = true;
    return _title = valueForStringAttribute("title");
}

std::string Album::genres() {
    if ( cachedgenre )
        return _genres;
    cachedgenre = true;
    return _genres = valueForStringAttribute("genres");
}

std::string Album::year() {
  if ( cachedyear )
    return _year;
    cachedyear = true;
    return _year = valueForStringAttribute("year");
}

int Album::albumID() {
    if ( cachedalbumid )
        return _albumID;
    cachedalbumid = true;
    return _albumID = valueForIntegerAttribute("album_id");
}

int Album::artistID() {
    if ( cachedartistid )
        return _artistID;
    cachedartistid = true;
    return _artistID = valueForIntegerAttribute("artist_id");
}

int Album::numImages() {
    if ( cachednumimages )
        return _numImages;
    cachednumimages = true;
    return _numImages = valueForIntegerAttribute("num_images");
}

int Album::numTracks() {
    if ( cachednumtracks )
        return _numTracks;
    cachednumtracks = true;
    return _numTracks = valueForIntegerAttribute("num_tracks");
}

void Album::print() {
    std::cout << "Print in album is being called" << std::endl;
    std::cout << "Title: " << title() << std::endl;
    std::cout << "Genres: " << genres() << std::endl;
    std::cout << "albumID: " << albumID() << std::endl;
    std::cout << "artistID: " << artistID() << std::endl;
    std::cout << "numImage: " << numImages() << std::endl;
    std::cout << "numTracks: " << numTracks() << std::endl;
    std::cout << "year: " << year() << std::endl;

    if (_tracks) {
      std::cout << "Tracks is running asserts " << std::endl;
      _tracks->runAsserts();
    }
}

std::string Album::htmlString() {
    std::string baz = "Foo";
    return baz;
}
