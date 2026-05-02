import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.NoSuchElementException;

interface PlaylistIterator {
    boolean hasNext();
    Object next();
}

class SimplePlaylistIterator implements PlaylistIterator {
    private final Playlist playlist;
    private int index = 0;

    public SimplePlaylistIterator(Playlist playlist) {
        this.playlist = playlist;
        this.index = 0;
    }

    @Override
    public boolean hasNext() {
        return index < playlist.getSongs().length;
    }

    @Override
    public Object next() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
        return playlist.getSongs()[index++];
    }
}

class ShufflePlaylistIterator implements PlaylistIterator {
    private final Playlist playlist;
    private final List<Integer> indices;
    private int currentIndex = 0;

    public ShufflePlaylistIterator(Playlist playlist) {
        this.playlist = playlist;
        this.indices = new ArrayList<>();
        for (int i = 0; i < playlist.getSongs().length; i++) {
            indices.add(i);
        }
        Collections.shuffle(indices);
    }

    @Override
    public boolean hasNext() {
        return currentIndex < indices.size();
    }

    @Override
    public Object next() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
        int songIndex = indices.get(currentIndex++);
        return playlist.getSongs()[songIndex];
    }
}

class FavoritePlaylistIterator implements PlaylistIterator {
    private final Playlist playlist;
    private final List<Integer> favoriteIndices;
    private int currentIndex = 0;

    public FavoritePlaylistIterator(Playlist playlist) {
        this.playlist = playlist;
        this.favoriteIndices = new ArrayList<>();
        for (int i = 0; i < playlist.getSongs().length; i++) {
            if (playlist.getSongs()[i].isFavorite()) {
                favoriteIndices.add(i);
            }
        }
    }

    @Override
    public boolean hasNext() {
        return currentIndex < favoriteIndices.size();
    }

    @Override
    public Object next() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
        int songIndex = favoriteIndices.get(currentIndex++);
        return playlist.getSongs()[songIndex];
    }
}

class Playlist {
    private ArrayList<Song> songs;

    public Playlist() {
        songs = new ArrayList<>();
    }

    public void addSong(Song song) {
        songs.add(song);
    }

    public PlaylistIterator createIterator(String type) {
        switch (type.toLowerCase()) {
            case "simple":
                return new SimplePlaylistIterator(this);
            case "shuffle":
                return new ShufflePlaylistIterator(this);
            case "favorite":
                return new FavoritePlaylistIterator(this);
            default:
                throw new IllegalArgumentException("Unknown iterator type: " + type);
        }
    }
}

public class IteratorMain {
    public static void main(String[] args) {
        Playlist playlist = new Playlist();
        playlist.addSong(new Song("Song 1", "Artist A", true));
        playlist.addSong(new Song("Song 2", "Artist B", false));
        playlist.addSong(new Song("Song 3", "Artist C", true));
        playlist.addSong(new Song("Song 4", "Artist D", false));

        System.out.println("Simple Iterator:");
        PlaylistIterator simpleIterator = playlist.createIterator("simple");
        while (simpleIterator.hasNext()) {
            System.out.println(simpleIterator.next());
        }

        System.out.println("\nShuffle Iterator:");
        PlaylistIterator shuffleIterator = playlist.createIterator("shuffle");
        while (shuffleIterator.hasNext()) {
            System.out.println(shuffleIterator.next());
        }

        System.out.println("\nFavorite Iterator:");
        PlaylistIterator favoriteIterator = playlist.createIterator("favorite");
        while (favoriteIterator.hasNext()) {
            System.out.println(favoriteIterator.next());
        }
    }
}