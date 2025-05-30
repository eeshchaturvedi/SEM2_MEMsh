#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Painting {
protected:
    string title;
    string artist;
    double price;

public:
    Painting(string title = "None", string artist = "None") {
        this->title = title;
        this->artist = artist;
        this->price = 400;
    }

    virtual void get_data() {
        cout << "Enter title: ";
        cin >> ws; // to ignore newline before getline
        getline(cin, title);
        cout << "Enter artist's name: ";
        getline(cin, artist);
    }

    virtual void display() const {
        cout << "Painting: " << title << " by " << artist << " | Price: $" << price << endl;
    }

    string get_artist() const {
        return artist;
    }

    string get_title() const {
        return title;
    }

    virtual ~Painting() {}
};

class FamousPainting : public Painting {
public:
    FamousPainting(string title = "None", string artist = "None") {
        this->title = title;
        this->artist = artist;
        this->price = 25000;
    }

    void display() const override {
        cout << "FAMOUS Painting: " << title << " by " << artist << " | Price: $" << price << endl;
    }
};

// Helper function to check if artist is famous
bool is_famous_artist(const string& name) {
    return (name == "Degas" || name == "Monet" || name == "Picasso" || name == "Rembrandt");
}

int main() {
    vector<Painting*> paintings;

    for (int i = 0; i < 10; i++) {
        cout << "\nPainting #" << i + 1 << endl;

        string title, artist;
        cout << "Enter title: ";
        cin >> ws;
        getline(cin, title);
        cout << "Enter artist's name: ";
        getline(cin, artist);

        if (is_famous_artist(artist)) {
            paintings.push_back(new FamousPainting(title, artist));
        } else {
            paintings.push_back(new Painting(title, artist));
        }
    }

    cout << "\nAll Paintings:\n";
    for (int i = 0; i < 10; i++) {
        paintings[i]->display();
    }

    // Clean up memory
    for (auto p : paintings) {
        delete p;
    }

    return 0;
}
