#include "Track.hpp"

Track::Track() { /*std::cout << "New track created" << std::endl;*/ }

Track::~Track() { /*std::cout << "Track destroyed" << std::endl;*/}

std::string Track::htmlString() {
    std::string html;
    html += "\t<tr class=\"tracks\">\n";
    html += "\t\t<td class=\"trackName\">" + title() +"</td>\n";
    html += "\t\t<td>" + duration() + "</td>\n";
    html += "\t</tr>\n";
    return html;
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
