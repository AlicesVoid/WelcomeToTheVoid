// LOOT CRATE ROLLING APPLICATION!

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <thread>
#include <string>
#include <vector>
using namespace std;
using namespace std::chrono_literals;
using namespace std::this_thread;

class Rarities 
{
    private: // com = 18, rare = 9, legendary = 9
        vector<string> com{ "XingYun Fanfic", "Incel's Teeth", "Sykkuno Maid Fit", "Vanilla M/F Hentai and it's B o r i n g", "Kokichi Kinnie",
         "Jimmy Neutron Sock", "Fuckboy Snapback", "Glow In The Dark Nail Polish", "Razer Huntsman Pro Tournament Edition", "Ketamine Addiction", "Meth Addiction", 
         "Shitty Chain-Mail Email", "Captain Morgan Spiced Cum", "Used Condom", "Pack of Newport Cigarettes", "Bottle of Mountain Dew: Code Piss", "Bad Dragon Unflared Stallion Packer",
         "Front Row Seat to see The MKULTRA Experiments Live"};

        vector<string> rar{ "League of Legends Funko Pop", "Pink Print VHS", "ot8 VALEANEN nsfw 18+ comic mlm yaoi don't like don't read", "Long Furby", "Venti Tiddy Mousepad", 
        "Andrew Kreiss Tiddy Mousepad", "Dead Frog with it's Eyeballs Removed", "A Magazine containing Nothing But Tentacle Porn and One Direction One Shots", 
        "Chair That Tazes You When You Least Expect It"};

        vector<string> leg{ "Mail-Order Twink",  "Gucci Flip Flop", "Luchino Egg", "BTS Jungkook", "Dommy Daddy Corpse Husband", "Kermit The Frog Plushie", "Lio Fotia Tiddy Mousepad", 
        "Moby Huge", "Dildo of Queen Elizabeth's Tongue", "Vial of Pure, Distilled Homosexual Tension"};

    public:
        string get_common(int a)
        {
            string A = com[(a-1)];
            return A;
        }
        string get_rare(int a)
        {
            string B = rar[(a-1)];
            return B;
        }
        string get_legendary(int a)
        {
            string C = leg[(a-1)];
            return C;
        }
};

int main ()
{
    int box_amount, loot_crate, common_roll, rare_roll, legend_roll;
    string common_item, rare_item, legend_item;
    int bias = 0;
    int value = 9;
    //creates variables for the loot_crate roll, amount of boxes, and bias
    
    cout << "\n\n...Welcome to the Loot Crate Simulator (patent pending 2021*)\nHow many do you wanna roll chief?: ";
    cin >> box_amount;
    Rarities loot;

    for (int i = 0; i < box_amount; i++)
    {
        srand (time(NULL));
        loot_crate = bias + (rand() % 100 + 1);
        common_roll = rand() % (2*value) + 1;
        rare_roll = rand() % value + 1;
        legend_roll = rand() % value + 1;

        for (int j = 0; j < 3; j++)
        {
            sleep_for(1500ms);
            cout << "." << endl;            
        }
        

        if (0 < loot_crate && loot_crate < 65)
        {
            bias += 1;
            sleep_for(900ms);
            string comms = "...you got a: "+ loot.get_common(common_roll);
            char* common = &comms[0];
            char *p=common;
            while (*p != NULL)
            {
                sleep_for(110ms);
                cout << *p;
                p++;
            }
            cout << endl;
        }
        else if (64 < loot_crate && loot_crate < 85)
        {
            sleep_for(2000ms);
            string rars = "...you got a: " + loot.get_rare(rare_roll);
            char* rare = &rars[0];
            char *q=rare;
            while (*q != NULL)
            {
                sleep_for(110ms);
                cout << *q;
                q++;
            }
            cout << endl;
        }
        else
        {
            bias = 0;
            sleep_for(2000ms);
            string legs = "...you got a: " + loot.get_legendary(legend_roll);
            char* legend = &legs[0];
            char *r=legend;
            while (*r != NULL)
            {
                sleep_for(110ms);
                cout << *r;
                r++;
            }
            cout << endl;           
        }
    //cout << loot_crate << endl;
    }
    //cout << bias << endl;
    sleep_for(10s);

    return 0;
}