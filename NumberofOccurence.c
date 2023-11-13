/*C Code to check the number of occurrences in an integer Array.
The limitations are:
0 < array_size < 100
0 < element < 1000

First, you need to initialize the count array. 
The count array holds occurrences of each element.
count[1000] = {0} this initializes the entire array.

First for loop increments the number of occurrences of each element(from 0 to 1000).
Don't be confused with array_len and 1000. Array_len is the size of the actual given input array(test case).

Second for loop counts the number of occurrences of each element(index, in this case, is the actual element number, for example, count[599] = 3 means the number 599 occurs 3 times in the array).
If the number of occurrence is bigger than the maxCount then maxCount becomes the number of occurrence. The answer becomes index = number of element if the number of occurrence beats maxCount.

Third for loop finds if there are duplicate occurrences. 
If the number of element is not the same as the answer (highest occurring number) and the count of occurence is equal to maxCount then it will return -1.
Basically, it will return -1 if there is more than 1 highest occurring number. For example, if count[3] = 3 and count [4] = 3, maxCount is 3, then it will return -1.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len) {
    int answer = -1;
    int count[1000] = {0};
    int maxCount = 0;
    
    for(int i = 0; i < array_len; i++){
        count[array[i]]++;
    }
    
    for(int i = 0; i < 1000; i++){
        if(count[i] > maxCount){
            answer = i;
            maxCount = count[i];
        }
    }
    
    for(int i = 0; i < 1000; i++){
        if(i != answer && count[i] == maxCount){
            return -1;
        }
    }
    

    return answer;
}
