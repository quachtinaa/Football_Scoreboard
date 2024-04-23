// Tina Quach
// Class: COSC-1437-58002
// Instructor: Dr. T
// Date: 04/20/2024
// Program Description: This program will display a football scoreboard and allow user to change the scoreboard values

#include <iostream>
#include <string>
#include "functions_classes.h"
#include "input_validation.h"

using namespace std;

int main()
{
  // variables
  Scoreboard s;
  Team tOne, tTwo;
  char choice = '\0';
  int localMinutes = 0, localSeconds = 0, localDown = 0, localToGo = 0, localEtc = 0, localChoice, localTeam = 0;
  string localName = "";

  // intialize home and visitors to team one and team two
  s.setHome(tOne);
  s.setVisitors(tTwo);
  tOne.setHomeStatus(true);
  tTwo.setHomeStatus(false);
  
  // do while loop for menu
  do
    {
      // show scoreboard
      s.showScoreboard();

      // show menu
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

      displayMenu();
      choice = validateChr(choice);

      // OPTIONS
      // choice a - change home and visitor status
      if (choice == 'A' || choice == 'a')
      {
        localTeam = 0;
        cout << "\nWhich team is Home? (1 for Team One, 2 for Team Two): ";
        localTeam = validateInt(localTeam);
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

      // choice b - change team names
      if (choice == 'B' || choice == 'b')
      {
        subMenu();
        localChoice = validateInt(localChoice);
        if (localChoice == 1)
        {
          cout << "\nEnter the new name for Team One: ";
          cin.ignore();
          getline (cin, localName);
          tOne.setName(localName);
        }
        if (localChoice == 2)
        {
          cout << "\nEnter the new name for Team Two: ";
          cin.ignore();
          getline (cin, localName);
          tTwo.setName(localName);
        }
        
      }

      // choice c - change team coach names
      if (choice == 'C' || choice == 'c')
      {
        subMenu();
        localChoice = validateInt(localChoice);
        if (localChoice == 1)
        {
          cout << "\nEnter the new coach name for Team One: ";
          cin.ignore();
          getline (cin, localName);
          tOne.setCoachName(localName);
        }
        if (localChoice == 2)
        {
          cout << "\nEnter the new coach name for Team Two: ";
          cin.ignore();
          getline (cin, localName);
          tTwo.setCoachName(localName);
        }
      }

      // choice d - change home city names
      if (choice == 'D' || choice == 'd')
      {
        subMenu();
        localChoice = validateInt(localChoice);
        if (localChoice == 1)
        {
          cout << "\nEnter the home city for Team One: ";
          cin.ignore();
          getline (cin, localName);
          tOne.setHomeCity(localName);
        }
        if (localChoice == 2)
        {
          cout << "\nEnter the home city for Team Two: ";
          cin.ignore();
          getline (cin, localName);
          tTwo.setHomeCity(localName);
        }
      }

      // choice e - change scores
      if (choice == 'E' || choice == 'e')
      {
        subMenu();
        localChoice = validateInt(localChoice);
        if (localChoice == 1)
        {
          cout << "\nTeam One Score: ";
          cin >> localEtc;
          tOne.setScore(localEtc);
        }
        if (localChoice == 2)
        {
          cout << "\nTeam Two Score: ";
          cin >> localEtc;
          tTwo.setScore(localEtc);
        }
      }

      // choice f - change timeout counts
      if (choice == 'F' || choice == 'f')
      {
        subMenu();
        localChoice = validateInt(localChoice);
        if (localChoice == 1)
        {
          cout << "\nTeam One Timeout Count: ";
          cin >> localEtc;
          tOne.setTimeoutCount(localEtc);
        }
        if (localChoice == 2)
        {
          cout << "\nTeam Two Timeout Count: ";
          cin >> localEtc;
          tTwo.setTimeoutCount(localEtc);
        }
      }

      // choice g - change quarter
      if (choice == 'G' || choice == 'g')
      {
        cout << "\nQuarter: ";
        localEtc = validateInt(localEtc);
        s.setQuarter(localEtc);
      }

      // choice h - change down and to go counts
      if (choice == 'H' || choice == 'h')
      {
        cout << "\nDown: ";
        localDown = validateInt(localDown);
        s.setDown(localDown);
        
        cout << "\nTo Go: ";
        cin >> localToGo;
        s.setToGo(localToGo);
      }

      // choice i - change time
      if (choice == 'I' || choice == 'i')
      {
        cout << "\nMinutes: ";
        localMinutes = validateInt(localMinutes);
        s.setMinute(localMinutes);
        cout << "\nSeconds: ";
        localSeconds = validateInt(localSeconds);
        s.setSeconds(localSeconds);
      }

      // refresh the data in s for the new updates
      // if user chose 2 when choosing team one or team two for home status, refresh data regarding that home is team two and visitor is team one
      if (localTeam == 2)
      {
        s.setHome(tTwo); 
        s.setVisitors(tOne);
      }
      else // anything else = keep same
      {
        s.setHome(tOne); 
        s.setVisitors(tTwo); 
      }

    cout << "\033[2J\033[1;1H"; // clear screen when repeating do-while loop

    } while (choice != 'X' && choice != 'x');

  // goodbye message
  cout << "You are exiting the scoreboard menu, goodbye!" << endl;
  
  return 0;
}