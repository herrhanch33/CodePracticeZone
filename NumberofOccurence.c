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
