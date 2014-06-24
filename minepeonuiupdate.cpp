#include "minepeonuiupdate.h"
#include <stdlib.h>
#include <unistd.h>


MinePeonUIUpdate::MinePeonUIUpdate()
{
    chdir("/opt/minepeon");
    system("git pull");

}
