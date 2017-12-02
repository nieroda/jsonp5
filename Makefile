CFLAGS=-std=c++11 -ggdb

DATAOBJECTS=JSONDataObject.cpp JSONDataObject.hpp JSONArray.cpp JSONArray.hpp JSONDataItem.cpp JSONDataItem.hpp
ALBUMIMAGES=AlbumImage.hpp AlbumImage.cpp AlbumImages.hpp AlbumImages.cpp
ARTISTIMAGES=ArtistImage.hpp ArtistImage.cpp ArtistImages.hpp ArtistImages.cpp
TRACK=Track.cpp Track.hpp
TRACKS=Tracks.cpp Tracks.hpp
ALBUM=Album.cpp Album.hpp
ALBUMS=Albums.cpp Albums.hpp
ARTIST=Artist.cpp Artist.hpp
ARTISTS=Artists.cpp Artists.hpp
JSONDATAOBJECT=JSONDataObject.cpp JSONDataObject.hpp
JSONARRAY=JSONArray.cpp JSONArray.hpp
JSONDATAITEM=JSONDataItem.cpp JSONDataItem.hpp

OBJECTS=Track.o Tracks.o Album.o Albums.o AlbumImage.o AlbumImages.o Artist.o Artists.o ArtistImage.o ArtistImages.o JSONArray.o JSONDataItem.o JSONDataObject.o main.o

Track.o: $(TRACK) $(JSONDATAOBJECT)
	g++ $(CFLAGS) -c Track.cpp -o Track.o

Tracks.o: $(TRACKS) $(TRACK) $(JSONARRAY)
	g++ $(CFLAGS) -c Tracks.cpp -o Tracks.o

Album.o: $(ALBUM) $(TRACKS) $(JSONDATAOBJECT) $(ALBUMIMAGES)
	g++ $(CFLAGS) -c Album.cpp -o Album.o

Albums.o: $(ALBUMS) $(ALBUM) $(JSONARRAY)
		g++ $(CFLAGS) -c Albums.cpp -o Albums.o

AlbumImage.o: $(ALBUMIMAGES) $(JSONDATAOBJECT)
	g++ $(CFLAGS) -c AlbumImage.cpp -o AlbumImage.o

AlbumImages.o: $(ALBUMIMAGES) $(JSONARRAY)
	g++ $(CFLAGS) -c AlbumImages.cpp -o AlbumImages.o

Artist.o: $(ARTIST) $(ALBUM) $(ARTISTIMAGES) $(JSONDATAOBJECT) $(ALBUMS)
	g++ $(CFLAGS) -c Artist.cpp -o Artist.o

Artists.o: $(ARTISTS) $(ARTIST) $(JSONARRAY) $(ARTISTIMAGES)
	g++ $(CFLAGS) -c Artists.cpp -o Artists.o

ArtistImage.o: $(ARTISTIMAGES) $(JSONDATAOBJECT)
	g++ $(CFLAGS) -c ArtistImage.cpp -o ArtistImage.o

ArtistImages.o: $(ARTISTIMAGES) $(JSONARRAY)
	g++ $(CFLAGS) -c ArtistImages.cpp -o ArtistImages.o

JSONArray.o: $(JSONARRAY) $(JSONDATAOBJECT)
	g++ $(CFLAGS) -c JSONArray.cpp -o JSONArray.o

JSONDataItem.o: $(JSONDATAITEM)
	g++ $(CFLAGS) -c JSONDataItem.cpp -o JSONDataItem.o

JSONDataObject.o: $(JSONDATAOBJECT) $(JSONDATAITEM)
	g++ $(CFLAGS) -c JSONDataObject.cpp -o JSONDataObject.o

main.o: main.cpp $(ALBUMS) $(ALBUMIMAGES) $(ARTISTIMAGES) $(ARTISTS) $(TRACKS)
	g++ $(CFLAGS) -c main.cpp -o main.o

main.x: $(OBJECTS)
	g++ $(CFLAGS) $(OBJECTS) -o main.x


clean:
	rm -fr *~ $(OBJECTS) main.x
