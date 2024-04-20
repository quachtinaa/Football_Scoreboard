#include <iostream>
#include <string>

using namespace std;

  class Team
    {
      private:
        string name, coach_name, home_city;
        bool home_status;
        int score, timeout_count;
      public:
        Team(){name = "Default"; coach_name = "Default"; home_city = "Default", home_status = true, score = 0, timeout_count = 0;} // default constructor
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
          cout << home.getName() << "\t\t  " << minute << ":" << seconds << "\t\t " << visitors.getName() << endl;
          cout << "\t" << home.getScore() << "\t\t" << "QTR: " << quarter << "\t\t\t" << visitors.getScore() << endl;
          cout << down << " DOWN" << "\t\t\t\t\t" << "TO GO " << toGo << endl;
          cout << "TIMEOUTS LEFT: " << home.getTimeoutCount() << "\t" << "TIMEOUTS LEFT: " << visitors.getTimeoutCount() << endl;
          cout << "Coaches: " << home.getCoachName() << "\t\t" << visitors.getCoachName() << endl;
        }
    };

int main()
{
  // variables
  Scoreboard s;
  Team tOne, tTwo;
  char choice = '\0';

  // do while loop for menu
  do
    {
      s.showScoreboard();

      cout << "\n \t\t\tMENU" << endl;
      cout << "---------------------------------" << endl;
      cout << "A. Update Home and Visitor Teams" << endl;
      cout << "B. Update Team One's Name" << endl;
      cout << "C. Update Team Two's Name" << endl;
      cout << "D. Update Team One's Coach Name" << endl;
      cout << "E. Update Team Two's Coach Name" << endl;
      cout << "F. Update Team One's Home City" << endl;
      cout << "G. Update Team Two's Home City" << endl;
      cout << "H. Update Team One's Score" << endl;
      cout << "I. Update Team Two's Score" << endl;
      cout << "J. Update Team One's Timeout Count";
      cout << "Enter your choice: ";
    
    } while (choice == 'X' || choice == 'x');

  return 0;
}