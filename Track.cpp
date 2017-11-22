#include "Track.hpp"

Track::Track() { /*std::cout << "New track created" << std::endl;*/ }

Track::~Track() { /*std::cout << "Track destroyed" << std::endl;*/}

std::string Track::htmlString() {
    std::cout << "Called" << std::endl;
    std::string holder;
    holder += "\t<li><p>" + title() + "</p>\n";
    std::cout << "Finished " << std::endl;
    holder += "\t\t<ul>\n";
    holder += "\t\t\t<li><p>Artist Name: " + artistName() + "</p></li>\n";
    holder += "\t\t\t<li><p>Album Name: " + albumName() + "</p></li>\n";
    holder += "\t\t\t<li><p>Album ID: " + std::to_string(albumID()) + "</p></li>\n";
    holder += "\t\t\t<li><p>Duration: " + duration() + "</p></li>\n";
    holder += "\t\t\t<li><p>Position: " + position() + "</p></li>\n";
    holder += "\t\t</ul>\n";
    holder += "\t</li>\n";

    return holder;
}

void Track::print() {
  std::cout << "Print in track is being called " << std::endl;
    std::cout << artistName() << std::endl;
    std::cout << title() << std::endl;
    std::cout << albumName() << std::endl;
    std::cout << duration() << std::endl;
    std::cout << position() << std::endl;
    std::cout << albumID() << std::endl;

}

std::string Track::artistName() {
    if (cached_artistName) {
        return _artistName;
    }
    cached_artistName = true;
    return _artistName = valueForStringAttribute("artist_name");
}

std::string Track::title() {
    if (cached_title)
        return _title;
    cached_title = true;
    return _title = valueForStringAttribute("title");
}

std::string Track::albumName() {
    if (cached_albumName)
        return _albumName;
    cached_albumName = true;
    return _albumName = valueForStringAttribute("album_name");
}

std::string Track::duration() {
    if (cached_duration)
        return _duration;
    cached_duration = true;
    return _duration = valueForStringAttribute("duration");
}

std::string Track::position() {
    if (cached_position)
        return _position;
    cached_position = true;
    return _position = valueForStringAttribute("position");
}

int Track::albumID() {
    if (cached_albumID)
        return _albumID;
    cached_albumID = true;
    return _albumID = valueForIntegerAttribute("album_id");
}
