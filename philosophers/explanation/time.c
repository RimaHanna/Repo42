#include <stdio.h> // printf
#include <sys/time.h> // time
#include <stdint.h> // uint64_t
#include <unistd.h> // usleep microseconds

// struct timeval {
//     time_t      tv_sec;     // seconds
//     suseconds_t tv_usec;    // microseconds
// };
// 1 second = 1 000 000 microseconds.
// 1 second = 1 000 milliseconds ms
// usleep used microseconds

// int gettimeofday(struct timeval *tv, struct timezone *tz);

/* 
    gettimeofday bring the time of the day since 1/1/1970 in seconds and the 
    rest in microseconds
*/


uint64_t	get_time(void) // returns time in milliseconds
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0) // not false
		return (0);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

void    example_1()
{
    struct timeval time;

    gettimeofday(&time, NULL);
    printf("%ld seconds\n", time.tv_sec);
    printf("%ld microseconds\n", time.tv_usec);
/*
    time.tv_sec is the number of seconds since 1/1/1970 at midnight until now,
    the number of years is seconds / 60 (minutes) / 60 (hours) / 24 (days) / 365 (years) 
*/
    printf("\n%ld years passed since 1970\n", time.tv_sec / 60 / 60 / 24 / 365); 
}

void    example_2()
{
    uint64_t    start_time;
    uint64_t    now;

    start_time = get_time();
    usleep(10000); // accepts microseconds
    now = get_time();
    printf("%ld milliseconds passed since the start\n", now - start_time);
}

int main()
{
    example_1();
    example_2();

    return (0);
}