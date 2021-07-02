#include <bits/stdc++.h>
#include <chrono>
#include <time.h>

using namespace std;
using namespace std::chrono_literals;
using namespace std::this_thread;

//If I knew how to cleanly use Classes I feel like I could've made my life a LOT easier

//global arrays with constant contents
string bedroomActions[6] = {"1. Examine Room",
                            "2. Do Homework",
                            "3. Sleep",
                            "4. Go to Hallway",
                            " ",
                            "Bedroom"};
string hallwayActions[6] = {"1. Examine Room",
                            "2. Go to Kitchen",
                            "3. Go to Bathroom",
                            "4. Go to Living Room",
                            "5. Go to Bedroom",
                            "Hallway"};
string kitchenActions[6] = {"1. Examine Room",
                            "2. Make Food",
                            "3. Go to Hallway",
                            "4. Go to Living Room",
                            " ",
                            "Kitchen"};
string livingRoomActions[6] = {"1. Examine Room",
                               "2. Play Video Games",
                               "3. Socialize with Friends",
                               "4. Go to Kitchen",
                               "5. Go to Hallway",
                               "Living Room"};
string bathroomActions[6] = {"1. Examine Room",
                             "2. Take a Shower",
                             "3. Use the Toilet",
                             "4. Go to Hallway",
                             " ",
                             "Bathroom"};

//global arrays for tasks
string tasks[7] = {"I'm sleepy... I should go to bed", 
                  "I'm hungry... I should get something to eat",
                  "I'm lonely... I should talk to someone",
                  "I have homework to do... I should start that",
                  "...I really need to use the restroom",
                  "I smell horrible... I should take a shower",
                  "I'm bored... video games sound fun right now"};



int main ()
{
    //Function Prototypes
    void printTextSpace50(string);
    void displayIntro();
    void displaySynopsis();
    void displayGameBegin();
    void clearScreen();
    string roomCalc(int, string);
    string randTask();
    void randTaskList();
    string displayMenu(int, string, string, string, string);
    
    
    //functions (testing)
    int userInput;
    string roomName = "Bedroom";
    
    srand(time(NULL));
    string task1, task2, task3;
    task1 = randTask();
    task2 = randTask();
    while(task1 == task2)
    {
        task2 = randTask();
    }
    task3 = randTask();
    while(task3 == task1 || task3 == task2)
    {
        task3 = randTask();
    }    
    roomName = displayMenu(1, task1, task2, task3, roomName);
    while (true)
    {
    cin >> userInput;
    clearScreen();
    roomName = roomCalc(userInput, roomName);
    displayMenu(1, task1, task2, task3, roomName);
    }
    
}

//--------------------------Functions dedicated to improving the quality of output formatting--------------------------//

//times out the printing of a string by it's text (50ms)
void printTextSpace50(string input)
{
    char* hold = &input[0];
    char *output = hold;
    while (*output != false)
    {
        sleep_for(50ms);
        cout << *output;
        output++;
    };
}

//clears the screen
void clearScreen()
{
    //allegedly this is really bad to use, but I honestly do not know why
        //if things stop working, potentially see this?
    if (system("CLS")) system("clear");
}

//--------------------------Functions responsible for computing in-game values--------------------------//

//determines the room of the player
string roomCalc(int userInput, string roomName)
{
    if(roomName == bedroomActions[5])
    {
        if(userInput == 4)
        {
            return hallwayActions[5];
        }
        else
        {
            return roomName;
        }
    }
    else if(roomName == hallwayActions[5])
    {
        if(userInput == 2)
        {
            return kitchenActions[5];
        }
        else if(userInput == 3)
        {
            return bathroomActions[5];
        }
        else if(userInput == 4)
        {
            return livingRoomActions[5];
        }
        else if(userInput == 5)
        {
            return bedroomActions[5];
        }
        else
        {
            return roomName;
        }
    }
    else if(roomName == kitchenActions[5])
    {
        if(userInput == 3)
        {
            return hallwayActions[5];
        }
        else if(userInput == 4)
        {
            return livingRoomActions[5];
        }
        else
        {
            return roomName;
        }
    }
    else if(roomName == livingRoomActions[5])
    {
        if(userInput == 4)
        {
            return kitchenActions[5];
        }
        else if(userInput == 5)
        {
            return hallwayActions[5];
        }
        else
        {
            return roomName;
        }
    }
    else if(roomName == bathroomActions[5])
    {
        if (userInput == 4)
        {
            return hallwayActions[5];
        }
        else
        {
            return roomName;
        }
        
    }
    else
    {
        cout << "Invalid Room: Internal Error\n\n";
        return roomName;
    }
}

//gets a random task for the player
string randTask()
{
    int randVal;
    string randTask;
    randVal = rand() % 6 + 1;
    randTask = tasks[randVal];
    return randTask;
}

//assembles a list of random tasks for the player (PURELY FOR TEST PURPOSES)
void randTaskList()
{
    string task1, task2, task3;
    task1 = randTask();
    task2 = randTask();
    while(task1 == task2)
    {
        task2 = randTask();
    }
    task3 = randTask();
    while(task3 == task1 || task3 == task2)
    {
        task3 = randTask();
    }
    cout << "Task 1: " << task1 << endl << "Task 2: " << task2 << endl << "Task 3: " << task3 << endl;

}

//--------------------------Functions responsible for the display and calibration of the games' menu--------------------------//

//displays the introduction to the game
void displayIntro()
{
    string intro[10]     {"||||||||||||||||||||||||||||||||||||||||", 
                          "|                                      |",
                          "|            Going Nowhere:            |",
                          "|        A Text-Based Horror Game      |",
                          "|                                      |",
                          "|                                      |",
                          "|          By: Amelia Rotondo          |",
                          "|                                      |",
                          "|                                      |",
                          "||||||||||||||||||||||||||||||||||||||||"};
    int i = 0;
    while(i < 10)
    {
        cout << intro[i] << endl;
        i++;
        sleep_for(50ms);
    }
    sleep_for(500ms);
}

//displays the synopsis of the game
void displaySynopsis()
{
    string synopsis[6]   {"You are a College Student who has been working from home for the past year.", 
                          "Despite the freedoms granted by working at home, you begin to realize that ",
                          "sometimes you can grow too comfortable to your environment.",
                          "In your comfort, you will fail to realize that your environment has been ",
                          "altered beyond your control.",
                          "What do you do now?",};
    int i = 0;
    while(i < 6)
    {
        string getLine = synopsis[i];
        printTextSpace50(getLine);
        cout << endl;
        if(i==0 || i==2 || i==4 || i==5)
        {
            cout << endl;
        }
        i++;
        sleep_for(20ms);
    }
    sleep_for(500ms);
}

//displays the rules of the game
void displayRules()
{
    string rules[6]      {"Welcome! this is a text-based horror game played by entering values into the terminal.", 
                          "You will be presented with a menu containing several values, including: ",
                          "a list of tasks for the day, a room type, and actions you can do within that room. ",
                          "To complete tasks for the day, enter the number listed next to actions within a room; ",
                          "For some tasks, you may have to go to different rooms to access new actions.",
                          "I hope you enjoy Going Nowhere.",};
    int i = 0;
    while(i < 6)
    {
        string getLine = rules[i];
        printTextSpace50(getLine);
        cout << endl;
        if(i==0 || i==2 || i==4 || i==5)
        {
            cout << endl;
        }
        i++;
        sleep_for(20ms);
    }
    sleep_for(250ms);
}

//displays all introductory elements in order
void displayGameBegin()
{
    cout << endl;
    displaySynopsis();
    cout << endl;
    displayIntro();
    cout << endl;
    displayRules();
    cout << "Press Enter to begin the game: \n";
    cin.get();
    clearScreen();
}

//displays the core menu of the game
string displayMenu(int dayNumber, string task1, string task2, string task3, string roomName)
{
    string *roomVal;
    string menu[33]      {"||||||||||||||||||||||||||||||||||||||||||||||||||\n", 
                          "| Day:                                           |\n",
                          "| ","|\n", //Day Value
                          "|------------------------------------------------|\n",
                          "| Tasks:                                         |\n",
                          "| ","|\n", //Task 1
                          "| ","|\n", //Task 2
                          "| ","|\n", //Task 3
                          "|                                                |\n",
                          "|------------------------------------------------|\n",
                          "| Room:                                          |\n",
                          "| ","|\n", //Room Name
                          "|                                                |\n",
                          "|------------------------------------------------|\n",
                          "| Actions Available:                             |\n",
                          "| ","|\n", //Room Action 1
                          "| ","|\n", //Room Action 2
                          "| ","|\n", //Room Action 3
                          "| ","|\n", //Room Action 4
                          "| ","|\n", //Room Action 5
                          "|                                                |\n",
                          "|                                                |\n",
                          "||||||||||||||||||||||||||||||||||||||||||||||||||\n"};
    
    //determines the room of the player
    if (roomName == bedroomActions[5])
    {
        roomVal = bedroomActions;
    }
    else if (roomName == hallwayActions[5])
    {
        roomVal = hallwayActions;
    }
    else if (roomName == kitchenActions[5])
    {
        roomVal = kitchenActions;
    }
    else if (roomName == livingRoomActions[5])
    {
        roomVal = livingRoomActions;
    }
    else if (roomName == bathroomActions[5])
    {
        roomVal = bathroomActions;
    }
    //displays the menu
    cout << setiosflags(ios::left);
    for(int i = 0; i < 33; i++)
    {
        cout << menu[i];

        switch (i)
        {
            case 2:
                cout << setfill(' ') << setw(47) << dayNumber;
                break;
            case 6:
                cout << setfill(' ') << setw(47)  << task1;
                break;
            case 8:
                cout << setfill(' ') << setw(47)  << task2;
                break;
            case 10:
                cout << setfill(' ') << setw(47)  << task3;
                break;
            case 15:
                cout << setfill(' ') << setw(47)  << *(roomVal + 5);
                break;
            case 20:
                cout << setfill(' ') << setw(47) << *(roomVal + 0);
                break;
            case 22:
                cout << setfill(' ') << setw(47)  << *(roomVal + 1);
                break;
            case 24:
                cout << setfill(' ') << setw(47) << *(roomVal + 2);
                break;
            case 26:
                cout << setfill(' ') << setw(47) << *(roomVal + 3);
                break;
            case 28:
                cout << setfill(' ') << setw(47) << *(roomVal + 4);
                break;
            default:
                break;
        }
    }

    cout << "Please Enter an Action (By Number): ";
    return *(roomVal + 5);
}


