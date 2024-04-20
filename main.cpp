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
        Scoreboard(){minute = 0, seconds = 0, quarter = 1, down = 0, toGo = 0, home = Team(), visitors = Team();} // default constructor
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
  int localMinutes = 0, localSeconds = 0, localDown = 0, localToGo = 0, localEtc = 0;

  s.setHome(tOne);
  s.setVisitors(tTwo);
  
  // do while loop for menu
  do
    {
      s.showScoreboard();
      cout << "\n\n \t\t\t\t\t\t\t\t\tMENU" << endl;
      cout << "-----------------------------------------------------------------------" << endl;
      cout << "Note: Team One is Home and Team Two is Visitor unless changed otherwise" << endl;
      cout << "-----------------------------------------------------------------------" << endl;
      cout << "A. Update Home and Visitor Teams" << endl;
      cout << "B. Update Team Names" << endl;
      cout << "C. Update Team Coach Names" << endl;
      cout << "D. Update Home City Names" << endl;
      cout << "E. Update Scores" << endl;
      cout << "F. Update Timeout Counts" << endl;
      cout << "G. Update Quarter" << endl;
      cout << "H. Update Down and To Go Count" << endl;
      cout << "I. Update Time" << endl;
      cout << "X. Exit" << endl;
      cout << "\nEnter your choice: ";
      cin >> choice;

      if (choice == 'A' || choice == 'a')
      {
      }
      if (choice == 'B' || choice == 'b')
      {
      }
      if (choice == 'C' || choice == 'c')
      {
      }
      if (choice == 'D' || choice == 'd')
      {
      }
      if (choice == 'E' || choice == 'e')
      {
      }
      if (choice == 'F' || choice == 'f')
      {
      }
      if (choice == 'G' || choice == 'g')
      {
        cout << "\nQuarter: ";
        cin >> localEtc;
        s.setQuarter(localEtc);
      }
      if (choice == 'H' || choice == 'h')
      {
        cout << "\nDown: ";
        cin >> localDown;
        s.setDown(localDown);
        cout << "\nTo Go: ";
        cin >> localToGo;
        s.setToGo(localToGo);
      }
      if (choice == 'I' || choice == 'i')
      {
        cout << "\nMinutes: ";
        cin >> localMinutes;
        s.setMinute(localMinutes);
        cout << "\nSeconds: ";
        cin >> localSeconds;
        s.setSeconds(localSeconds);
      }

      s.setHome(tOne); // refresh the data in s for the new updates
      s.setVisitors(tTwo);
      cout << "\033[2J\033[1;1H"; // clear screen
    } while (choice != 'X' || choice != 'x');

  return 0;
}