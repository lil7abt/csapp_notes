#ifndef __TVFM__H__
#define __TVFM__H__

//The difference is that just one Remote method—
// instead of all the Remote methods

class Tv; // forward declaration, to avoid cicular dependency

class Remote
{
public:
    enum State{Off, On};
    enum {MinVal, MaxVal=20};
    enum {Antenna, Cable};
    enum {TV, DVD};
private:
    int mode;
public:
    Remote(int m=TV): mode(m) {}
    bool volup(Tv & t);
    bool voldown(Tv & t);
    void onoff(Tv & t);
    void chanup(Tv & t);
    void chandown(Tv & t);
    void set_mode(Tv & t);
    void set_input(Tv & t);
    void set_chan(Tv & t, int c);   
};

class Tv
{
private:
    int state;
    int volume;
    int maxchannel;
    int channel;
    int mode;
    int input;
public:
    //make just this set_chan() from class Tv as a friend.
    friend void Remote::set_chan(Tv & t, int c);
    enum State{Off, On};
    enum {MinVal, MaxVal = 20};
    enum {Tv, DVD};
    Tv(int s=Off, int mc=125): state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {}
    void onoff() {state=(state==On)? Off:On;}
    bool ison() const {return state == On;}
    bool volup();
    bool voldown();
    void setmode(){mode=(mode==Antenna)?Cable:Antenna;}
    void set_input(){input=(input==V)?DVD:TV;}
    void settings() const;
}

// Remote methods as inline functions
// inline functions have internal linkage, which means the function definition
// must be in the file that uses the function.
inline bool Remote::volup(Tv & t) {return t.volup();}
inline bool Remote::voldown(Tv & t) { return t.voldown();}
inline void Remote::onoff(Tv & t) { t.onoff(); }
inline void Remote::chanup(Tv & t) {t.chanup();}
inline void Remote::chandown(Tv & t) {t.chandown();}
inline void Remote::set_mode(Tv & t) {t.set_mode();}
inline void Remote::set_input(Tv & t) {t.set_input();}
inline void Remote::set_chan(Tv & t, int c) {t.channel = c;}


#endif  //!__TVFM__H__