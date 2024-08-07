#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>

int main()
{
    //Measuring program runtime.
    struct timeval before;
    gettimeofday(&before, NULL);
    long long before_millis = before.tv_sec*1000LL + before.tv_usec/1000;

    printf("Hello");

    struct timeval after;
    gettimeofday(&after, NULL);
    long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000;

    printf(" print ran in: %llu milli seconds \n", after_millis-before_millis);


    //Generate Random numbers.
    srand(time(NULL)); // Seed. Only one time for the life of program.
    //for(int i =0;i<3;i++){
    //printf("%d\n", rand());
    //}
    return 0;
}
