#include <iostream>
#include <string>
using namespace std;

/***********************************************/
/* Bitte die folgenden Makros einkommentieren, */
/* so bald die entsprechende Unteraufgabe      */
/* gelöst ist !!!                              */
/***********************************************/
#define A1_a
#define A1_b
#define A1_c
#define A1_d
//#define A1_e

class Audioformat {
public:

    virtual string titel() = 0;
    virtual string info()  = 0;
};

int mp3_counter = 0;

class MP3_Format : public Audioformat {
public:
    MP3_Format(const string s) :song(s){mp3_counter++;}
    MP3_Format(const char *s) :song(s){mp3_counter++;}
    MP3_Format(MP3_Format& f) :song(f.song){mp3_counter++;}
    MP3_Format() :song(""){mp3_counter++;}
    ~MP3_Format(){mp3_counter--;}

    virtual string titel() { return  song; }
    virtual string info()  { return "MP3"; }
    operator std::string () const { return song;}

    bool operator!=(MP3_Format &other) { return song!=other.song; }
    bool operator==(MP3_Format &other) { return song==other.song; }
    MP3_Format &operator=(const char *s){ song=s; return *this;}
private:
    string song;
};
