#ifndef FUNCTIONS_CLASSES_H
#define FUNCTIONS_CLASSES_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// prototype
void submenu();
void displayMenu();

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
        cout << "\t\t\t  | " << "FOOTBALL SCOREBOARD " << "|" << endl;
        cout << "====================================================" << endl;
        cout << "      HOME                           VISITOR        " << endl;
        cout << setw(8 + home.getHomeCity().length()/2) << home.getHomeCity() << setw((33 - home.getHomeCity().length()/2) + visitors.getHomeCity().length()/2) << visitors.getHomeCity() << endl;
        cout << setw(8 + home.getName().length()/2) << home.getName() << setw((33 - home.getName().length()/2) + visitors.getName().length()/2) << visitors.getName() << endl;
        cout << "\t\t\t\t\t   " << minute << ":" << seconds << endl;
        cout << "\t\t" << home.getScore() << "\t\t     QTR: " << quarter << "\t\t\t    " << visitors.getScore() << endl;
        cout << "\t\t"<< down << " DOWN" << "\t\t\t\t\t" << "  TO GO " << toGo << endl;
        cout << "\nTIMEOUTS LEFT: " << home.getTimeoutCount() << "\t\t\t\t " << "TIMEOUTS LEFT: " << visitors.getTimeoutCount() << endl;
        cout << "COACH: " << home.getCoachName() << setw(33 - home.getCoachName().length()) << "COACH: " << visitors.getCoachName() << endl;
        cout << "====================================================" << endl;
        cout << "              ||                   ||              " << endl;
        cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
      }
  };

void subMenu()
{
  int subChoice;
  
  cout << "\nPick a Team to Update" << endl;
  cout << "---------------------------" << endl;
  cout << "1. Team One" << endl;
  cout << "2. Team Two" << endl;
  cout << "Enter your team: ";

}

void displayMenu()
{
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
}

#endif