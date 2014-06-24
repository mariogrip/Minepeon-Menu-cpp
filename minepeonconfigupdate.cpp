#include "minepeonconfigupdate.h"
#include <stdlib.h>
#include <unistd.h>

MinePeonConfigUpdate::MinePeonConfigUpdate()
{
    chdir("/");
    system("/usr/bin/sudo git pull");
}
