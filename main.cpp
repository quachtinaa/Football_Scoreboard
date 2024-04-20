#include <iostream>
#include <string>
#include "functions_classes.h"

using namespace std;

int main()
{
  // variables
  Scoreboard s;
  Team tOne, tTwo;
  char choice = '\0';
  int localMinutes = 0, localSeconds = 0, localDown = 0, localToGo = 0, localEtc = 0, localChoice, localTeam = 0;
  string localName = "";

  s.setHome(tOne);
  s.setVisitors(tTwo);
  tOne.setHomeStatus(true);
  tTwo.setHomeStatus(false);
  
  // do while loop for menu
  do
    {
      s.showScoreboard();
      cout << "\n\n \t\t\t\t\t\t\t\t\tMENU" << endl;
      cout << "-----------------------------------------------------------------------" << endl;
      cout << "Note: Team One is Home and Team Two is Visitor unless changed otherwise" << endl;
      if (tOne.getHomeStatus() == true)
        cout << "\nCURRENT TEAM ONE STATUS: HOME" << endl;
      else if (tOne.getHomeStatus() == false)
        cout << "\nCURRENT TEAM ONE STATUS: VISITOR" << endl;
      if (tTwo.getHomeStatus() == true)
        cout << "CURRENT TEAM TWO STATUS: HOME" << endl;
      else if (tTwo.getHomeStatus() == false)
        cout << "CURRENT TEAM TWO STATUS: VISITOR" << endl;
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
        cout << "\nWhich team is Home? (1 for Team One, 2 for Team Two): ";
        cin >> localTeam;
        if (localTeam == 1)
        {
          tOne.setHomeStatus(true);
          tTwo.setHomeStatus(false);
          s.setHome(tOne);
          s.setVisitors(tTwo);
        }
        if (localTeam == 2)
        {
          tOne.setHomeStatus(false);
          tTwo.setHomeStatus(true);
          s.setHome(tTwo);
          s.setVisitors(tOne);
        }
      }
      
      if (choice == 'B' || choice == 'b')
      {
        cout << "\nWhich team's name would you like to change? (1 for Team One, 2 for Team Two): ";
        cin >> localChoice;
        if (localChoice == 1)
        {
          cout << "\nEnter the new name for Team One: ";
          cin >> localName;
          tOne.setName(localName);
        }
        if (localChoice == 2)
        {
          cout << "\nEnter the new name for Team Two: ";
          cin >> localName;
          tTwo.setName(localName);
        }
        
      }
      if (choice == 'C' || choice == 'c')
      {
        cout << "Which team's coach name would you like to change? (1 for Team One, 2 for Team Two): ";
        cin >> localChoice;
        if (localChoice == 1)
        {
          cout << "\nEnter the new coach name for Team One: ";
          cin >> localName;
          tOne.setCoachName(localName);
        }
        if (localChoice == 2)
        {
          cout << "\nEnter the new coach name for Team Two: ";
          cin >> localName;
          tTwo.setCoachName(localName);
        }
      }
      if (choice == 'D' || choice == 'd')
      {
        cout << "Which team's home city would you like to change? (1 for Team One, 2 for Team Two): ";
        cin >> localChoice;
        if (localChoice == 1)
        {
          cout << "\nEnter the home city for Team One: ";
          cin >> localName;
          tOne.setHomeCity(localName);
        }
        if (localChoice == 2)
        {
          cout << "\nEnter the home city for Team Two: ";
          cin >> localName;
          tTwo.setHomeCity(localName);
        }
      }
      if (choice == 'E' || choice == 'e')
      {
        cout << "\nTeam One Score: ";
        cin >> localEtc;
        tOne.setScore(localEtc);

        cout << "\nTeam Two Score: ";
        cin >> localEtc;
        tTwo.setScore(localEtc);
      }
      if (choice == 'F' || choice == 'f')
      {
        cout << "\nTeam One Timeout Count: ";
        cin >> localEtc;
        tOne.setTimeoutCount(localEtc);

        cout << "\nTeam Two Timeout Count: ";
        cin >> localEtc;
        tTwo.setTimeoutCount(localEtc);
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

      // refresh the data in s for the new updates
      if (localTeam == 2)
      {
        s.setHome(tTwo); // refresh the data in s for the new updates
        s.setVisitors(tOne);
      }
      else // if localTeam is anything else, refresh the data so that home team is Team One and visitor is Team Two always
      {
        s.setHome(tOne); // refresh the data in s for the new updates
        s.setVisitors(tTwo); 
      }
 
      cout << "\033[2J\033[1;1H"; // clear screen
      
    } while (choice != 'X' && choice != 'x');

  cout << "You are exiting the scoreboard menu, goodbye!" << endl;
  
  return 0;
}