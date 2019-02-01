//flight.c
// #include "staf.c"
// #include "Passengers.c"
// #include "FMS.c"

typedef struct Flight Flight;

struct Flight
{
    char flightName[20];
    char destination[20];
    char from[20];
    int duration;
    time_t timeDeparture;
    time_t timeArrival;

};

