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
        int GetHours();
        int GetMinutes();
        int GetSeconds();
        Meridiano GetMeridiano();
        void SetHours(int hours);
        void SetMinutes(int minutes);
        void SetSeconds(int seconds);
        void SetMeridiano(Meridiano meridiano);
        void PrintTime();
        void PrintTime24();
};