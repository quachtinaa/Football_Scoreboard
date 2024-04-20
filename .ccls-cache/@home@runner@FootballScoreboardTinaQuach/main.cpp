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
        Team(){name = "DefaultTeamName"; coach_name = "DefaultCoach"; home_city = "DefaultHomeCity", home_status = true, score = 0, timeout_count = 0;} // default constructor
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
        string color, reset = "\x1b[0m";
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
          color = "\x1b[" + to_string(32) + ";"+to_string(33)+"m";
          cout << color << "\t\t\t  | " << reset << "FOOTBALL SCOREBOARD " << color << "|" << endl;
          cout << "---------------------------------------------------" << reset << endl;
          cout << home.getHomeCity() << "\t\t\t\t\t " << visitors.getHomeCity() << endl;
          cout << home.getName() << "\t\t  " << minute << ":" << seconds << "\t\t " << visitors.getName() << endl;
          cout << "\t\t" << home.getScore() << "\t\t     QTR: " << quarter << "\t\t\t    " << visitors.getScore() << endl;
          cout << "\t\t"<< down << " DOWN" << "\t\t\t\t\t" << "  TO GO " << toGo << endl;
          cout << "TIMEOUTS LEFT: " << home.getTimeoutCount() << "\t\t\t\t " << "TIMEOUTS LEFT: " << visitors.getTimeoutCount() << endl;
          cout << "Coaches: " << home.getCoachName() << "\t\t\t " << visitors.getCoachName() << endl;
          cout << color << "---------------------------------------------------" << endl;
          cout << "              ||                   ||              " << reset << endl;
          color = "\x1b[" + to_string(32) + ";"+to_string(32)+"m";
          cout << color << "- - - - - - - - - - - - - - - - - - - - - - - - - -" << reset << endl;
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

      cout << "-----------------------------------------------------------------------" << endl;
      cout << "\n \t\t\t\t\t\t\t\t\tMENU" << endl;
      cout << "-----------------------------------------------------------------------" << endl;
      cout << "Note: Team One is Home and Team Two is Visitor unless changed otherwise" << endl;
      cout << "-----------------------------------------------------------------------" << endl;
      cout << "A. Update Home and Visitor Teams" << endl;
      cout << "B. Update Team Names" << endl;
      cout << "C. Update Team Coach Names" << endl;
      cout << "D. Update Home City Names" << endl;
      cout << "E. Update Scores" << endl;
      cout << "J. Update Timeout Counts" << endl;
      cout << "F. Update Quarter" << endl;
      cout << "G. Update Down" << endl;
      cout << "H. Update To Go" << endl;
      cout << "I. Update Time" << endl;
      cout << "\nEnter your choice: ";
      cin >> choice;
    
    } while (choice == 'X' || choice == 'x');

  return 0;
}