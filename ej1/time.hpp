#ifndef TIME_HPP
#define TIME_HPP

enum class Meridiano {
    AM,
    PM
};

class Time {
    private:
        int hours;
        int minutes;
        int seconds;
        Meridiano meridiano;
    public:
        Time(int hours, int minutes, int seconds, Meridiano meridiano);
        Time(int hours, int minutes, int seconds);
        Time(int hours, int minutes);
        Time(int hours);
        Time();
        int GetHours() const;
        int GetMinutes() const;
        int GetSeconds() const;
        Meridiano GetMeridiano() const;
        void SetHours(int hours);
        void SetMinutes(int minutes);
        void SetSeconds(int seconds);
        void SetMeridiano(Meridiano meridiano);
        void PrintTime() const;
        void PrintTime24() const;
};

#endif