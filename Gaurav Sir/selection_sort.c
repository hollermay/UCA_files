#include<stdio.h>
#include <assert.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>


void exch(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

}

void selection_sort(int arr[], int n)
{
    for(int i =0;i<n;i++)
    {
        int min =i; // to keep index of minimum element
        for(int j =i+1;j<n;j++)
        {
            if(arr[j]<arr[min]) min = j;
        }
        exch(arr,i,min);
    }
}

void test_simple_input(){
    int input[] = {5,3,1,9,7};
    int expected_output[] = {1,3,5,7,9};
    
    selection_sort(input,5);

    for(int i =0;i<5;i++){
        assert(input[i]==expected_output[i]);
    }
}

long long time_elapsed(int n)
{
    int * arr = (int *)malloc(n*sizeof(int)); //malloc comes from stdlib.h
    srand(time(NULL));
    for(int i =0;i<n;i++){
        arr[i] = rand();
    }
    struct timeval before;
    gettimeofday(&before, NULL);
    long long before_millis = before.tv_sec*1000LL + before.tv_usec/1000;

    selection_sort(arr,n);

    struct timeval after;
    gettimeofday(&after, NULL);
    long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000;

    free(arr);
    return after_millis-before_millis;
}

int main(){
    
    test_simple_input();

    long long t1 = time_elapsed(5000);
    long long t2 = time_elapsed(10000);
    
    printf("%lf\n",t2*1.0 / t1);
    return 0;
}