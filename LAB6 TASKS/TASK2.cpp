#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MediaFile {
protected:
    string filePath;
    double size;

public:
    MediaFile(const string& path, double s) : filePath(path), size(s) {}
    virtual void play() const {
        cout << "Playing media from: " << filePath << endl;
    }
    virtual void stop() const {
        cout << "Stopping media from: " << filePath << endl;
    }
    virtual ~MediaFile() {}
};

class VisualMedia : virtual public MediaFile {
protected:
    string resolution;

public:
    VisualMedia(const string& path, double s, const string& res)
        : MediaFile(path, s), resolution(res) {}
};

class AudioMedia : virtual public MediaFile {
protected:
    int sampleRate;

public:
    AudioMedia(const string& path, double s, int rate)
        : MediaFile(path, s), sampleRate(rate) {}
};

class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(const string& path, double s, const string& res, int rate)
        : MediaFile(path, s), VisualMedia(path, s, res), AudioMedia(path, s, rate) {}

    void play() const override {
        cout << "Playing video from: " << filePath << " with resolution: " << resolution
             << " and sample rate: " << sampleRate << "Hz" << endl;
    }

    void stop() const override {
        cout << "Stopping video from: " << filePath << endl;
    }
};

class ImageFile : public VisualMedia {
public:
    ImageFile(const string& path, double s, const string& res)
        : MediaFile(path, s), VisualMedia(path, s, res) {}

    void play() const override {
        cout << "Displaying image from: " << filePath << " with resolution: " << resolution << endl;
    }

    void stop() const override {
        cout << "Closing image: " << filePath << endl;
    }
};

class AudioFile : public AudioMedia {
public:
    AudioFile(const string& path, double s, int rate)
        : MediaFile(path, s), AudioMedia(path, s, rate) {}

    void play() const override {
        cout << "Playing audio from: " << filePath << " with sample rate: " << sampleRate << "Hz" << endl;
    }

    void stop() const override {
        cout << "Stopping audio: " << filePath << endl;
    }
};

int main() {
    vector<MediaFile*> mediaFiles;

    mediaFiles.push_back(new VideoFile("video.mp4", 500.0, "1920x1080", 44100));
    mediaFiles.push_back(new ImageFile("photo.jpg", 5.0, "1080x720"));
    mediaFiles.push_back(new AudioFile("song.mp3", 10.0, 48000));

    for (MediaFile* media : mediaFiles) {
        media->play();
        media->stop();
        cout << "---" << endl;
    }

    for (MediaFile* media : mediaFiles) {
        delete media;
    }

    return 0;
}

