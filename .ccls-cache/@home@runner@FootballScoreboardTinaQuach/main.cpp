#include <iostream>
#include <string>

using namespace std;

int main() 
{
  class Team
    {
      private:
        string name, coach_name, home_city;
        bool home_status;
        int score, timeout_count;
      public:
        Team(){name = "Default"; coach_name = "Default"; home_city = "Default"; home_status = true;} // default constructor
        void setName(string n){name = n;}
        void setCoachName(string cn){coach_name = cn;}
        void setHomeCity(string hc){home_city = hc;}
        void setHomeStatus(bool hs){home_status = hs;}
        void setScore(int s){score = s;}
        void setTimeoutCount(int tc){timeout_count = tc;}
        string getName() const {return name;}
        string getCoachName() const {return coach_name;}
        string getHomeCity() const {return home_city;}
        bool getHomeStatus()const {return home_status;}
        int getScore() const {return score;}
        int getTimeoutCount() const {return timeout_count;}
    };

  class Scoreboard
    {
      private:
        int minute, seconds, quarter, down, toGo;
        Team home, visitors;
      public:
        Scoreboard(){minute = 0, seconds = 0, quarter = 0, down = 0, toGo = 0, home = Team(), visitors = Team();} // default constructor
        void setMinute(int min){minute = min;}
        void setSeconds(int sec){seconds = sec;}
        void setQuarter(int q){quarter = q;}
        void setDown(int d){down = d;}
        void setToGo(int tg){toGo = tg;}
        void setHome(Team h){home = h;}
        void setVisitors(Team v){visitors = v;}
        int getMinute() const {return minute;}
        int getSeconds() const {return seconds;}
        int getQuarter() const {return quarter;}
        int getDown() const {return down;}
        int getToGo() const {return toGo;}
        Team getHome() const {return home;}
        Team getVisitors() const {return visitors;}
        void showScoreboard()
        {
          
        }
    };
}