#ifndef TV_H_
#define TV_H_


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
    friend class Remote;
    enum {Off, On};
    enum {MinVal, MaxVal = 20};
    enum {Antenna, Cable};
    enum {TV, DVD};

    Tv(int s=Off, int mc=125): state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {}
    void onoff() {state = (state == On)? Off : On;}
    //void onoff() {state ^=1;}
    bool ison() const {return state == On;}
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() {mode=(mode==Antenna)? Cable:Antenna;}
    void set_input() {input = (input==TV)?DVD:TV;}
    void settings() const;//display all settings
};
class Remote// to control the TV or DVD
{
private:
    int mode;
public:
    Remote(int m=Tv::TV): mode(m){}
    //each Remote Constructor and method takes a reference of a Tv object as an argument
    //which refects that a remote has to be aimed at a particular TV

    //following member funcions have just used the public interface of the class Tv
    bool volup(Tv & t)          {return t.volup();}
    bool voldown(Tv & t)        {return t.voldown();}
    void onoff(Tv & t)          {t.onoff();}
    void chanup(Tv & t)         {t.chanup();}
    void chandown(Tv & t)       {t.chandown();}    
    void set_mode(Tv & t)       {t.set_mode();}
    void set_input(Tv & t)      {t.set_input();}

    void set_chan(Tv & t, int c){t.channel=c;}
};


#endif // !TV_H_