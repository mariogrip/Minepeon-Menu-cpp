#include <iostream>
#include <stdlib.h>
#include <minepeonuiupdate.h>

using namespace std;
char yourch;
int system(const char *command);

int main()
{
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
        system("/usr/bin/sudo /usr/bin/systemctl stop miner");
        break;
    case 'd':
        system("/usr/bin/sudo /usr/bin/systemctl start miner");
        break;
    case 'e':
        system("/usr/bin/sudo /usr/bin/systemctl restart miner");
        break;
    case 'f':
                   //Own Header file
        break;
    case 'g':
                   //Own Header file
        break;
    case 'h':
                   //Own Header file
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
        main();
        break;
    }
    return 0;
}

