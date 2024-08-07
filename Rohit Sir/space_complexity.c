#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

int main() {
// Record the start memory usage
struct rusage usage_start;
getrusage(RUSAGE_SELF, &usage_start);


// Place your code to measure memory usage here
// For example, let's allocate some memory
int *array = (int *)malloc(10000000* sizeof(int));

for(int i =0;i<10000000;i++){
    array[i] = i;

}


// Record the end memory usage
struct rusage usage_end;
getrusage(RUSAGE_SELF, &usage_end);


// Calculate memory usage in kilobytes
long memory_used = usage_end.ru_maxrss - usage_start.ru_maxrss;

printf("Memory Used: %ld kilobytes\n", memory_used);

return 0;
}