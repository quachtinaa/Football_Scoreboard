// Tina Quach
// Class: COSC-1437-58002
// Instructor: Dr. T
// Date: 04/20/2024
// Program Description: This program will display a football scoreboard and allow user to change the scoreboard values
// Skills: Classes and objects, input validation, menu style, loops

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
  int localMinutes = 0, localSeconds = 0, localDown = 0, localToGo = 0, localEtc = 0, localChoice = 0, localTeam = 0;
  string localName = "";

  // intialize home and visitors to team one and team two
  s.setHome(tOne);
  s.setVisitors(tTwo);
  tOne.setHomeStatus(true);
  tTwo.setHomeStatus(false);
  
  // do while loop for menu
  do
    {
      cout << "\033[2J\033[1;1H";
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
      choice = validateChar(choice);

      // OPTIONS
      if (choice == 'A' || choice == 'a') // choice a - change home and visitor status
      {
        do
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
          else if (localTeam == 2)
          {
            tOne.setHomeStatus(false);
            tTwo.setHomeStatus(true);
            s.setHome(tTwo);
            s.setVisitors(tOne);
          } 
          else
          {
            cout << "\nInvalid input. Please try again." << endl;
          }
        } while (localTeam < 1 || localTeam > 2);
      }
      else if (choice == 'B' || choice == 'b') // choice b - change team names
      {
        do
          {
            subMenu();
            localChoice = validateInt(localChoice);
            if (localChoice == 1)
            {
              cout << "\nEnter the new name for Team One: ";
              getline (cin, localName);
              tOne.setName(localName);
            }
            else if (localChoice == 2)
            {
              cout << "\nEnter the new name for Team Two: ";
              getline (cin, localName);
              tTwo.setName(localName);
            }
            else
            {
              cout << "\nInvalid input. Please try again." << endl;
            }
          } while (localChoice < 1 || localChoice > 2);
      }
      else if (choice == 'C' || choice == 'c') // choice c - change team coach names
      {
        do
          {
            subMenu();
            localChoice = validateInt(localChoice);
            if (localChoice == 1)
            {
              cout << "\nEnter the new coach name for Team One: ";
              getline (cin, localName);
              tOne.setCoachName(localName);
            }
            else if (localChoice == 2)
            {
              cout << "\nEnter the new coach name for Team Two: ";
              getline (cin, localName);
              tTwo.setCoachName(localName);
            }
            else
            {
              cout << "\nInvalid input. Please try again." << endl;
            }
          } while (localChoice < 1 || localChoice > 2);
      }
      else if (choice == 'D' || choice == 'd') // choice d - change home city names
      {
        do
          {
            subMenu();
            localChoice = validateInt(localChoice);
            if (localChoice == 1)
            {
              cout << "\nEnter the home city for Team One: ";
              getline (cin, localName);
              tOne.setHomeCity(localName);
            }
            else if (localChoice == 2)
            {
              cout << "\nEnter the home city for Team Two: ";
              getline (cin, localName);
              tTwo.setHomeCity(localName);
            }
            else
            {
              cout << "\nInvalid input. Please try again." << endl;
            }
          } while (localChoice < 1 || localChoice > 2);
      }
      else if (choice == 'E' || choice == 'e') // choice e - change scores
      {
        do
          {
            subMenu();
            localChoice = validateInt(localChoice);
            if (localChoice == 1)
            {
              cout << "\nTeam One Score: ";
              cin >> localEtc;
              tOne.setScore(localEtc);
            }
            else if (localChoice == 2)
            {
              cout << "\nTeam Two Score: ";
              cin >> localEtc;
              tTwo.setScore(localEtc);
            }
            else
            {
              cout << "\nInvalid input. Please try again." << endl;
            }
          } while (localChoice < 1 || localChoice > 2);
      }
      else if (choice == 'F' || choice == 'f') // choice f - change timeout counts
      {
        do
          {
            subMenu();
            localChoice = validateInt(localChoice);
            if (localChoice == 1)
            {
              cout << "\nTeam One Timeout Count: ";
              cin >> localEtc;
              tOne.setTimeoutCount(localEtc);
            }
            else if (localChoice == 2)
            {
              cout << "\nTeam Two Timeout Count: ";
              cin >> localEtc;
              tTwo.setTimeoutCount(localEtc);
            }
            else
            {
              cout << "\nInvalid input. Please try again." << endl;
            }
          } while (localChoice < 1 || localChoice > 2);
      }
      else if (choice == 'G' || choice == 'g') // choice g - change quarter
      {
        do
          {
            cout << "\nQuarter (1-4): ";
            localEtc = validateInt(localEtc);
            s.setQuarter(localEtc);
            if (localEtc < 1 || localEtc > 4)
              cout << "\nInvalid input. Please try again." << endl;
          } while (localEtc < 1 || localEtc > 4);
      }
      else if (choice == 'H' || choice == 'h') // choice h - change down and to go counts
      {
        do
          {
            cout << "\nDown: ";
            localDown = validateInt(localDown);
            s.setDown(localDown);
            if (localEtc < 1 || localEtc > 4)
            {
              cout << "\nInvalid input. Please try again." << endl;
            }
          } while (localDown < 1 || localDown > 4);
        do
          {
            cout << "\nTo Go: ";
            localToGo = validateInt(localToGo);
            s.setToGo(localToGo);
            if (localToGo < 0 || localToGo > 10)
            {
              cout << "\nInvalid input. Please try again." << endl;
            }
          } while (localToGo < 0 || localToGo > 10);
      }
      else if (choice == 'I' || choice == 'i') // choice i - change time
      {
        do
          {
            cout << "\nMinutes: ";
            localMinutes = validateInt(localMinutes);
            s.setMinute(localMinutes);
            if (localMinutes < 0 || localMinutes > 59)
            {
              cout << "\nInvalid input. Please try again." << endl;
            }
          } while (localMinutes < 0 || localMinutes > 59);
        do
          {
            cout << "\nSeconds: ";
            localSeconds = validateInt(localSeconds);
            s.setSeconds(localSeconds);
            if (localSeconds < 0 || localSeconds > 59)
            {
              cout << "\nInvalid input. Please try again." << endl;
            }
          } while (localSeconds < 0 || localSeconds > 59);
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

    // cout << "\033[2J\033[1;1H"; // clear screen when repeating do-while loop

    } while (choice != 'X' && choice != 'x');

  // goodbye message
  cout << "You are exiting the scoreboard menu, goodbye!" << endl;
  
  return 0;
}