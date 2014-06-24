#include "archupdate.h"
#include <stdlib.h>

ArchUpdate::ArchUpdate()
{
    system("/usr/bin/sudo /usr/bin/pacman -Syu");
}
