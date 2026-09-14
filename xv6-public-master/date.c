#include "types.h"
#include "user.h"
#include "date.h"
int
main(int argc, char *argv[])
{
struct rtcdate r;
if (date(&r)) {
printf(2, "date failed\n");
exit();
}
// your code to print the date-time
printf(1, "%d:%d:%d UTC %d/%d/%d\n", 
        r.hour, r.minute, r.second, r.month, r.day, r.year
);
exit();
}