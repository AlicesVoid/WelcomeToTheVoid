//Amelia Rotondo
//Started: 4/17/2021
//Last Edited: 5/14/2021

#include <bits/stdc++.h>
#include <chrono>
#include <time.h>

using namespace std;
using namespace std::chrono_literals;
using namespace std::this_thread;

class goingNowhere
{
private:

    //constant variables for data formatting 
    const int LASTDAY = 10;

    //arrays for Menu Actions
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

    //Parallel Arrays for Prompts
    string bedroomPrompt[21] =          {"The bed is half-made...",                                                           //1          
                                         "Shelves contain collectible figures thinly-veiled in dust... ",
                                         "Your computer's whirring is the most notable noise in the room...",
                                         "The wall looks like a maze of thorns with it's spray-on dry wall...",                //2        
                                         "Other than your monitor's glare, the room is pitch-black... ",
                                         "There are no windows...",
                                         "The room looks... more confusing than usual... ",                                            
                                         "You have a tough time figuring out which wall has a door on it...",
                                         "Corners feel strangely illuminated, the montior feels dimmer than you remember...",
                                         "For some reason, everything appears colorless...",                                           
                                         "The floor is more littered than usual, you honestly doubt you own some of these things...",
                                         "The room has a threatening aura...",
                                         "Walls appear more distant from you than ever, making the room feel larger it is...",
                                         "Actually..., you can't find any devices in your room whatsoever...",
                                         "For some reason the lit-up bricks in your room feel, ubiquitous...",
                                         "You see a bug crawl into the light fixed on the ceiling... not that you wanted to...",
                                         "Walls appear more distant from you than ever, making the room feel larger it is...",
                                         "The room feels ambiently-lit...",
                                         "???? ???????? ????? ?? ??????... ???? ??? ??? ?????? ??? ?????",
                                         "?????? ??? ??????? ???? ???????... ??? ?????? ???? ?????? ??? ?? ?? ????? ??",
                                         "The room appears endless..."};
    string hallwayPrompt[21] = {"The tight corridor is monochrome...",                                                           //1          
                                         "All but for a single painting on the blank white wall...",
                                         "A Still Life of a Red and Green Apple...",
                                         "A short slice of pathway that connects all rooms in the apartment...",                //2        
                                         "There's a mirror at it's dead end... it seems a little out of place...",
                                         "You find yourself talking to your reflection from time to time...",
                                         "Lighting across the hall appears more uneven then usual...,",                                            
                                         "As if there were shadows you've never seen before...",
                                         "Yet when you glance behind yourself you see nothing out of the ordinary...",
                                         "The passage feels longer than you remember it being...",                                           
                                         "Many times walking you've counted the steps,.. this time being no different...",
                                         "Although 10 steps seems like an awfully noticable difference...",
                                         "Somehow the straight hall appears curved... ",
                                         "You know this can't be right and proceed normally...",
                                         "Though the mirror only reflects part of the corridor...",
                                         "The passage appear more lively than usual... colorful...",
                                         "The wall is decorated at random with splashes of paint...",
                                         "Although, the still life is nowhere to be seen...",
                                         "???? ???????? ????? ?? ??????... ???? ??? ??? ?????? ??? ?????",
                                         "?????? ??? ??????? ???? ???????... ??? ?????? ???? ?????? ??? ?? ?? ????? ??",
                                         "The room appears endless..."};
    string kitchenPrompt[21] = {"Utensils are strewn across the countertops...",                                                           //1          
                                         "Though, this is fine, as you usually only use forks and spoons anyways...",
                                         "Your freezer and fridge are filled with instant meals and meal replacements...",
                                         "The oven is busted... it's been like that since you moved in...",                //2        
                                         "Outside from a constant black theme, the kitchen appears tasteless...",
                                         "The small counterspace makes cooking seem impossible... not like you know how to cook...",
                                         "Grease stains decorate the gaslit stovetop...,",                                            
                                         "You find this eery because you've only used the stove twice...",
                                         "The frige appears emptier than you remember leaving it...",
                                         "The kitchen's entrance appears narrower than you remember...,",                                           
                                         "Black walls feel as if they're closing in on you..., constricting the room...",
                                         "Cobwebs organize in cabinet corners..., you like to imagine that you're friends with them sometimes...",
                                         "Some food that you thought was fresh is sporting a dark-green tint..., you swore you bought that yesterday...",
                                         "The water from your fridge tap doesn't tastes more bitter than usual...",
                                         "You notice the microwave's light flicker when you heat up food...",
                                         "The freezer feels warmer than usual, giving you an unsettling fear from the food inside it...",
                                         "Cabinets feel deeper than they usually do..., you struggle to see what items are farthest in them...",
                                         "A strangely-colored liquid drips from the bottom of your dishwasher...",
                                         "???? ???????? ????? ?? ??????... ???? ??? ??? ?????? ??? ?????",
                                         "?????? ??? ??????? ???? ???????... ??? ?????? ???? ?????? ??? ?? ?? ????? ??",
                                         "The room appears endless..."};
    string livingRoomPrompt[21] = {"Random nicknacks fill the room..., it looks more like a closet at this rate....",             //1          
                                         "One lone window shines a piercing beam along the top of a wall...",
                                         "The seating is composed exclusively of beanbags and chairs...",
                                         "A low coffee stable stretches only half the length of the room...",                //2        
                                         "Trash bags wait in the corner of the room..., where the wall meets the kitchen entrance...",
                                         "The carpet features several grotesquely-colored stains...",
                                         "The lighting sports a yellow tint today..., must be something with bulbs or whatever...",                                            
                                         "Today's overcast weather gives you a good opportunity to realize how dim the lights are...",
                                         "Something about this room smells- off...",
                                         "You notice a pixel on the TV die in real time...",                                           
                                         "Game disks are scattered across your room..., you swear you've never opened half of these...",
                                         "One of the beanbags has been dragged out of the room and into the hallway...",
                                         "You notice that the window appears smaller than usual, with the band of light only barely scraping the wall...",
                                         "Further, the blinds on the window appear to have torn again..,",
                                         "Beams of yellow light inconveniently scatter across the room...",
                                         "The beanbags and chairs form a circle in the middle of the room...",
                                         "It seems you forgot to turn off the TV last night..., though now it only blares static...",
                                         "Apparently the lightbulb in your one lamp shattered..., you figure you needed a new one anyways...",
                                         "???? ???????? ????? ?? ??????... ???? ??? ??? ?????? ??? ?????",
                                         "?????? ??? ??????? ???? ???????... ??? ?????? ???? ?????? ??? ?? ?? ????? ??",
                                         "The room appears endless..."};
    string bathroomPrompt[21] = {"Droplets of water dribble from the faucet of the sink...",             //1          
                                         "The toilet bowl is coated in weird stains that definitely weren't from use...",
                                         "White tiles across the walls appear tinted shades of yellow and green...",
                                         "The bathtub is filled with mysterious scratches and stains...",                //2        
                                         "You wonder how they got there..., given that you don't usually take baths...",
                                         "Every once in a while a Silverfish crawls out from inside the medicine cabinet...",
                                         "A plethora of prescription drugs lay on your counter...,",                                            
                                         "Allegedly you take these every morning..., but you can't even remember what half of them do anymore...",
                                         "An out of place chandelier lights up the narrow room...",
                                         "The mirror on the wall appears to be cracked along the edges...,",                                           
                                         "You're scared to imagine what could be behind it...",
                                         "A small rug on the floor has been shoved into the corner of the room...",
                                         "You think you see a cockroach crawl into the light fixture...",
                                         "Moving shadows paint the image that someone's in the room with you...",
                                         "The building's water pressure is more..., dynamic than you'd like it to be today...",
                                         "New dents and scratches line the edge of the bathtub...,",
                                         "You could only imagine what sort of creature could cause that degree of damage...",
                                         "Moving through the room causes the chandelier to shake, despite it's direct fixture to the ceiling...",
                                         "???? ???????? ????? ?? ??????... ???? ??? ??? ?????? ??? ?????",
                                         "?????? ??? ??????? ???? ???????... ??? ?????? ???? ?????? ??? ?? ?? ????? ??",
                                         "The room appears endless..."};

    //Parallel Arrays for Tasks
    string tasks[7] = {"I'm sleepy... I should go to bed", 
                    "I'm hungry... I should get something to eat",
                    "I'm lonely... I should talk to someone",
                    "I have homework to do... I should start that",
                    "...I really need to use the restroom",
                    "I smell horrible... I should take a shower",
                    "I'm bored... video games sound fun right now"};
    string taskComplete[7] = {"You go to bed, it takes a while but you manage to fall asleep...", 
                              "You watch the microwave spin for a whole 60 seconds... you proceed to eat straight out of the microwave",
                              "You call a couple friends just for the sake of talking to someone, it's nice to talk to people every once in a while...",
                              "You spend a couple of hours tinkering away at a program for class... at some point you figure the work will add up to something...",
                              "You- use the restroom... I don't think you want to hear the details...",
                              "You shower for a while, finding some comfort under the extremely hot water",
                              "You play Minecraft on your Xbox for the next Eight Hours... at least your house looks really cool"};   
    string day10Tasks[7] = {"??? ?????... ? ????? ?? ?? ???", 
                    "??? ??????... ? ??????? ??? ????????? ?? ???",
                    "??? ??????... ? ?????? ???? ?? ???????",
                    "? ??? ???????? ?? ??... ? ?????? ????? ????",
                    "...? ????? ???? ?? ??? ??? ????????",
                    "? ????? ????????... ? ?????? ???? ? ??????",
                    "??? ?????... ????? ????? ????? ??? ????? ???"};

    //arrays for Text Display Purposes
    string intro[10]         {"||||||||||||||||||||||||||||||||||||||||", 
                            "|                                      |",
                            "|            Going Nowhere:            |",
                            "|        A Text-Based Horror Game      |",
                            "|                                      |",
                            "|                                      |",
                            "|          By: Amelia Rotondo          |",
                            "|                                      |",
                            "|                                      |",
                            "||||||||||||||||||||||||||||||||||||||||"};
    string synopsis[6]       {"You are a College Student who has been working from home for the past year.", 
                            "Despite the freedoms granted by working at home, you begin to realize that ",
                            "sometimes you can grow too comfortable to your environment.",
                            "In your comfort, you will fail to realize that your environment has been ",
                            "altered beyond your control.",
                            "What do you do now?",};
    string rules[6]          {"Welcome! this is a text-based horror game played by entering values into the terminal.", 
                            "You will be presented with a menu containing several values, including: ",
                            "a list of tasks for the day, a room type, and actions you can do within that room. ",
                            "To complete tasks for the day, enter the number listed next to actions within a room; ",
                            "For some tasks, you may have to go to different rooms to access new actions.",
                            "I hope you enjoy Going Nowhere.",};
    string menu[33]          {"||||||||||||||||||||||||||||||||||||||||||||||||||\n", 
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
    string ending[5]         {"As you wander around your house, you begin to realize that",
                              "you truly have no idea where you are anymore...",
                              "The past ten days feel like a blur to you, in a weird way,",
                              "you fear that you've gone nowhere, and have nowhere to go.",
                              "In all aspects, you truly feel like you are going nowhere."};

    //variables for storing game-relative values
    int dayVal = 0;
    int promptDayVal;
    string task1, task2, task3, taskMsg;
    string roomName = "Bedroom";
    int userInput, sleepIterator;
    string blankSpace = " ";
    bool programRun = true;

public:

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
    
    //times out the printing of, in specific, a prompt
    void printPrompt(string arrayPrompt[])
    {
        if(dayVal < 3)
        {
            promptDayVal = 0;
        }
        else if(dayVal < 5)
        {
            promptDayVal = 3;
        }
        else if(dayVal < 6)
        {
            promptDayVal = 6;
        }
        else if(dayVal < 7)
        {
            promptDayVal = 9;
        }
        else if(dayVal < 8)
        {
            promptDayVal = 12;
        }
        else if(dayVal < 9)
        {
            promptDayVal = 15;
        }
        else if(dayVal < 10)
        {
            promptDayVal = 18;
        }
        else 
        {
            promptDayVal = 21;
        }

        for(int i = 0; i < 3; i++)
        {
            printTextSpace50(arrayPrompt[promptDayVal]);
            cout << endl;
            promptDayVal++;
        }
    }

    //gets enter
    void getEnter()
    {
        cin.ignore();
        cout << "\nPress Enter to Contine: ";
        cin.get();
    }

    //clears the screen
    void clearScreen()
    {
        //allegedly this is really bad to use, but I honestly do not know why
            //if things stop working, potentially see this?
        
        if (system("CLS")) system("clear");
    }
    
    //displays 'footstep-like' output to signify movement by the player
    void footsteps()
    {
        int a = 5;
        for(int i; i<a; i++)
        {
            cout << "^\n";
            sleep_for(200ms);
            cout << " ^\n";
            sleep_for(200ms);
        }
        cout << "^\n\n";
    }

    //changes strings to random question marks for day 10
    string day10String(string input)
    {
        string day10String;
        char* hold = &input[0];
        char *output = hold;
        while (*output != false)
        {
            if(*output != ' ')
            {
                day10String = day10String + "?";
            }
            else
            {
                day10String = day10String + " ";
            }
            output++;
        };

        return day10String;
    }

    //--------------------------Functions responsible for computing in-game values--------------------------//

    //Increments the Day Value by 1
    void dayIncrement()
    {
        dayVal += 1;
    }

    //Checks if the user is on day 10 or not
    bool lastDayCheck()
    {
        if (dayVal == LASTDAY)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //determines the room of the player
    void roomCalc(int userInput, string whatRoom)
    {
        if(whatRoom == bedroomActions[5])
        {
            if(userInput == 4)
            {
                footsteps();
                roomName = hallwayActions[5];
            }
            else
            {
                roomName = whatRoom;
            }
        }
        else if(whatRoom == hallwayActions[5])
        {
            if(userInput == 2)
            {
                footsteps();
                roomName = kitchenActions[5];
            }
            else if(userInput == 3)
            {
                footsteps();
                roomName = bathroomActions[5];
            }
            else if(userInput == 4)
            {
                footsteps();
                roomName = livingRoomActions[5];
            }
            else if(userInput == 5)
            {
                footsteps();
                roomName = bedroomActions[5];
            }
            else
            {
                roomName = whatRoom;
            }
        }
        else if(whatRoom == kitchenActions[5])
        {
            if(userInput == 3)
            {
                footsteps();
                roomName = hallwayActions[5];
            }
            else if(userInput == 4)
            {
                footsteps();
                roomName = livingRoomActions[5];
            }
            else
            {
                roomName = whatRoom;
            }
        }
        else if(whatRoom == livingRoomActions[5])
        {
            if(userInput == 4)
            {
                footsteps();
                roomName = kitchenActions[5];
            }
            else if(userInput == 5)
            {
                footsteps();
                roomName = hallwayActions[5];
            }
            else
            {
                roomName = whatRoom;
            }
        }
        else if(whatRoom == bathroomActions[5])
        {
            if (userInput == 4)
            {
                footsteps();
                roomName = hallwayActions[5];
            }
            else
            {
                roomName = whatRoom;
            }
            
        }
        else
        {
            cout << "Invalid Room: Internal Error\n\n";
            roomName = whatRoom;
        }
    }

    //determines if the player completed a task 
    string taskValid(int userInput, string whatRoom)
    {
        if(whatRoom == bedroomActions[5])
        {
            if(userInput == 2)
            {
                taskMsg = taskComplete[3];
                return tasks[3];
            }
            else if(userInput == 3)
            {
                taskMsg = taskComplete[0];
                return tasks[0];
            }
            else
            {
                return "yeehaw";
            }
        }
        else if(whatRoom == kitchenActions[5])
        {
            if(userInput == 2)
            {
                taskMsg = taskComplete[1];
                return tasks[1];
            }
            
            else
            {
                return "yeehaw";
            }
        }
        else if(whatRoom == livingRoomActions[5])
        {
            if(userInput == 2)
            {
                taskMsg = taskComplete[6];
                return tasks[6];
            }
            else if(userInput == 3)
            {
                taskMsg = taskComplete[2];
                return tasks[2];
            }
            else
            {
                return "yeehaw";
            }
        }
        else if(whatRoom == bathroomActions[5])
        {
            if (userInput == 2)
            {
                taskMsg = taskComplete[5];
                return tasks[5];
            }
            else if(userInput == 3)
            {
                taskMsg = taskComplete[4];
                return tasks[4];
            }
            else
            {
                return "yeehaw";
            }
            
        }
        else
        {
            cout << "Invalid Task Command: Internal Error\n\n";
            return "yeehaw";
        }
    }

    //adjusts tasks list if a user completed a task
    void taskCalc(string task)
    {
        
        if (task == task1)
        {
            printTextSpace50(taskMsg);
            task1 = blankSpace;
            getEnter();
        }
        else if (task == task2)
        {
            printTextSpace50(taskMsg);
            task2 = blankSpace;
            getEnter();
        }
        else if (task == task3)
        {
            printTextSpace50(taskMsg);
            task3 = blankSpace;
            getEnter();
        }

        if (task2 == blankSpace && task3 != blankSpace)
        {
            task2 = task3;
            task3 = blankSpace;
        }
        else if (task1 == blankSpace && task2 != blankSpace)
        {
            task1 = task2;
            task2 = task3; 
            task3 = blankSpace;
        }
    }

    //determines if the player examined a room
    void examCalc(int userInput, string whatRoom)
    {
        if(userInput == 1)
        {
            if(whatRoom == bedroomActions[5])
            {
                printPrompt(bedroomPrompt);
                getEnter();
            }
            else if(whatRoom == hallwayActions[5])
            {
                printPrompt(hallwayPrompt);
                getEnter();
            }
            else if(whatRoom == kitchenActions[5])
            {
                printPrompt(kitchenPrompt);
                getEnter();
            }
            else if(whatRoom == livingRoomActions[5])
            {
                printPrompt(livingRoomPrompt);
                getEnter();
            }
            else if (whatRoom == bathroomActions[5])
            {
                printPrompt(bathroomPrompt);
                getEnter();
            }            
        }
    }

    //checks to see if all tasks are complete, and if so, appends sleeping to the list of tasks 
    void sleepCheck()
    {
        if (task1 == blankSpace && sleepIterator == 1)
        {
            sleepIterator = 0;
            dayIncrement();
            randTaskList();
            roomName = bedroomActions[5];
        }
        else if (task1 == blankSpace)
        {
            sleepIterator = 1;
            task1 = tasks[0];
        }
    }

    //conducts holistic assessment of user input from the menu
    void inputCalc(int userInput, string whatRoom)
    {
        examCalc(userInput, whatRoom);
        roomCalc(userInput, whatRoom);
        taskCalc(taskValid(userInput, whatRoom));
        sleepCheck();
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

    //assembles a list of random tasks for the player 
    void randTaskList()
    {
        srand (time(NULL));
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
    }

    //gets a random day 10 task for the player
    string day10RandTask()
    {
        int randVal;
        string randTask;
        randVal = rand() % 6 + 1;
        randTask = day10Tasks[randVal];
        return randTask;
    }

    //assembles a list of random tasks designed around day 10
    void day10RandTaskList()
    {
        task1 = day10RandTask();
        task2 = day10RandTask();
        while(task1 == task2)
        {
            task2 = day10RandTask();
        }
        task3 = day10RandTask();
        while(task3 == task1 || task3 == task2)
        {
            task3 = day10RandTask();
        } 
    }

    //--------------------------Functions responsible for the display and calibration of the games' menu--------------------------//

    //displays the introduction to the game
    void displayIntro()
    {
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

    ///displays all introductory elements of the game
    void displayGameBegin()
    {
        cout << endl;
        displaySynopsis();
        cout << endl;
        displayIntro();
        cout << endl;
        displayRules();
        
        // I don't use the modular form here so that I can preserve the output formatting
        cout << "\nPress Enter to Contine: ";
        cin.get();
        clearScreen();
    }

    //prints the ending of the game
    void displayEnding()
    {
        int i = 0;
        while(i < 5)
        {
            string getLine = ending[i];
            printTextSpace50(getLine);
            cout << endl;
            if(i==1 || i==3)
            {
                cout << endl;
            }
            i++;
            sleep_for(20ms);
        }
        sleep_for(500ms);
    }

    //displays all concluding elements of the game
    void displayGameEnd()
    {
        cout << endl;
        displayEnding();
        cin.ignore();     
        cout << "\n\nPress Enter to End the Game: ";
        cin.get();
    }

    //displays the core menu of the game
    string displayMenu(int dayNumber, string firstTask, string secondTask, string thirdTask, string whatRoom)
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
        if (whatRoom == bedroomActions[5])
        {
            roomVal = bedroomActions;
        }
        else if (whatRoom == hallwayActions[5])
        {
            roomVal = hallwayActions;
        }
        else if (whatRoom == kitchenActions[5])
        {
            roomVal = kitchenActions;
        }
        else if (whatRoom == livingRoomActions[5])
        {
            roomVal = livingRoomActions;
        }
        else if (whatRoom == bathroomActions[5])
        {
            roomVal = bathroomActions;
        }
        
        //displays the menu
        cout << setiosflags(ios::left);
        if (lastDayCheck())
        {
            for(int i = 0; i < 33; i++)
            {
                cout << menu[i];

                switch (i)
                {
                    case 2:
                        cout << setfill(' ') << setw(47) << dayNumber;
                        break;
                    case 6:
                        cout << setfill(' ') << setw(47)  << firstTask;
                        break;
                    case 8:
                        cout << setfill(' ') << setw(47)  << secondTask;
                        break;
                    case 10:
                        cout << setfill(' ') << setw(47)  << thirdTask;
                        break;
                    case 15:
                        cout << setfill(' ') << setw(47)  << day10String(*(roomVal + 5));
                        break;
                    case 20:
                        cout << setfill(' ') << setw(47) << day10String(*(roomVal + 0));
                        break;
                    case 22:
                        cout << setfill(' ') << setw(47)  << day10String(*(roomVal + 1));
                        break;
                    case 24:
                        cout << setfill(' ') << setw(47) << day10String(*(roomVal + 2));
                        break;
                    case 26:
                        cout << setfill(' ') << setw(47) << day10String(*(roomVal + 3));
                        break;
                    case 28:
                        cout << setfill(' ') << setw(47) << day10String(*(roomVal + 4));
                        break;
                    default:
                        break;
                }
            }
        }
        else
        {
            for(int i = 0; i < 33; i++)
            {
                cout << menu[i];

                switch (i)
                {
                    case 2:
                        cout << setfill(' ') << setw(47) << dayNumber;
                        break;
                    case 6:
                        cout << setfill(' ') << setw(47)  << firstTask;
                        break;
                    case 8:
                        cout << setfill(' ') << setw(47)  << secondTask;
                        break;
                    case 10:
                        cout << setfill(' ') << setw(47)  << thirdTask;
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
        }
        cout << "Please Enter an Action (By Number): ";
        return *(roomVal + 5);
    };

    //drives the entire game 
    void gameDriver()
    {
        displayGameBegin();
        randTaskList();
        dayIncrement();

        while(programRun)
        {
            
            if (!lastDayCheck())
            {
                //displays the menu continuously
                displayMenu(dayVal, task1, task2, task3, roomName);
                cin >> userInput;
                inputCalc(userInput, roomName);
                clearScreen();
                
            }
            else
            {
                //displays the menu for the last day 
                day10RandTaskList();
                for (int i = 0; i < 6; i++)
                {
                    clearScreen();
                    displayMenu(dayVal, task1, task2, task3, roomName);
                    cin >> userInput;
                    inputCalc(userInput, roomName);
                } 
                displayGameEnd();     
                programRun = false;
            }            
        }
         
    }

};

int main()
{
    goingNowhere gN;
    gN.gameDriver();
    return 0;
}

