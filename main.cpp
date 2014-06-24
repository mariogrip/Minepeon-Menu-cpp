#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <minepeonuiupdate.h>
#include <archupdate.h>
#include <minepeonconfigupdate.h>
#include<fstream>

using namespace std;
char yourch;
int system(const char *command);

int StartUp(){
    std::ifstream ifile("/etc/MinePeon/MinePeon.conf");
    std::ofstream ofile;
    if (ifile){
    cout << "Starting Minepeon..." << endl;
    }else{
        cout << "Cannot file minepeon file..." << endl << "Making the file then..." << endl << "I need Root to make this file" << endl;
        system("sudo mkdir /etc/MinePeon");
        system("sudo touch /etc/MinePeon/MinePeon.conf");
        ofile.open("/etc/MinePeon/MinePeon.conf");
        ofile << ".";
        ofile.close();
    }
    return 0;
}

int MinePeonMenu(){
    cout << "########################################" << endl;
    cout << "# MinePeon Console Menu (c++ version)  #" << endl;
    cout << "########################################" << endl;
    cout << "# [a] Miner Screen (CTRL-A-D to exit)  #" << endl;
    cout << "# [b] Change console password          #" << endl;
    cout << "# [c] Stop Miner                       #" << endl;
    cout << "# [d] Start Miner                      #" << endl;
    cout << "# [e] Retart Miner                     #" << endl;
    cout << "# [f] Update MinePeon                  #" << endl;
    cout << "# [g] Update MinePeon Configuration    #" << endl;
    cout << "# [h] Update ArchLinux                 #" << endl;
    cout << "# [z] Reboot MinePeon                  #" << endl;
    cout << "# [0] Exit to shell                    #" << endl;
    cout << "########################################" << endl;
    cout << "# [Some options require your password] #" << endl;
    cout << "# [ Exit to shell and type logout to ] #" << endl;
    cout << "# [           Exit System            ] #" << endl;
    cout << "########################################" << endl;
    cout << "Enter your menu choice [a-0]: " << endl;
    cin >> yourch;
    switch (yourch) {
    case 'a':
       system("/usr/bin/screen -r");
        break;
    case 'b':
        system("/usr/bin/passwd");
        break;
    case 'c':
        cout << string(50, '\n') << endl << "Stoping miner..." << endl;
        system("/usr/bin/sudo /usr/bin/systemctl stop miner");
        cout << "Stoping miner.. Done!" << endl;
        sleep(1);
        break;
    case 'd':
        cout << string(50, '\n') << endl << "Starting miner..." << endl;
        system("/usr/bin/sudo /usr/bin/systemctl start miner");
        cout << "Starting miner.. Done!" << endl;
        sleep(1);
        break;
    case 'e':
        cout << string(50, '\n') << endl << "Restarting miner..." << endl;
        system("/usr/bin/sudo /usr/bin/systemctl restart miner");
        cout << "Restarting miner.. Done!" << endl;
        sleep(1);
        break;
    case 'f':
        MinePeonUIUpdate();       //Own Header file
        break;
    case 'g':
        MinePeonConfigUpdate();        //Own Header file
        break;
    case 'h':
        ArchUpdate();      //Own Header file
        break;
    case 'z':
        system("/usr/bin/sudo /usr/bin/reboot");
        break;
    case '0':
        return 0;
        break;
    default:
        cout << string(50, '\n');
        cout << "Oopps!!! Please select a valid menu choice..." << endl;
        cout << "Try agian, press Enter to continue" << endl;
        cin.get();
        cin.ignore();
        MinePeonMenu();
        break;
    }
    MinePeonMenu();
    return 0;
}

int main()
{
    StartUp();
    MinePeonMenu();
    return 0;
}

