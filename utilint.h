/*
Utility functions pertaining to integers and integer arrays
Mao Yamanaka
Because there are no namespaces in C, all functions have the prefix" ui_".
*/

#pragma once

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//PART 1: Integer array utilities

int ui_findpeak(int* aI0, int aI1, int aI2, int aI3){
  //ARGS: input array, length of array, lowest/highest [0/1], threshfold
  //RESULT: location of peak
  int tVal = aI3;
  int tIdx = 0;
  for(int it0 = 0; it0 < aI1; it0++){
    if((aI2 == 1 && tVal < aI0[it0]) || (aI2 == 0 && tVal > aI0[it0])){
      tVal = aI0[it0];
      tIdx = it0;
    }
  }
  return tIdx;
}

int ui_sum(int* aI0, int aI1){
  //ARGS: input array, length of array
  //RESULT: sum of array
  int ret = 0;
  for(int it0 = 0; it0 < aI1; it0++) ret += aI0[it0];
  return ret;
}

int ui_search(int* aI0, int aI1, int aI2){
  //ARGS: input array, length of array, target value
  //RESULT: location of first instance of value. -1 if not found
  int ret = -1;
  for(int it0 = 0; it0 < aI1; it0++){
    if(aI0[it0] == aI2){
      ret = it0;
      break;
    }
  }
  return ret;
}

void ui_print(int* aI0, int aI1){
  //ARGS: input array, length of array
  //RESULT: array printed to stdout
  for(int it0 = 0; it0 < aI1; it0++){
    printf("%d", aI0[it0]);
    if(it0 == aI1 - 1) printf("\n");
    else printf(", ");
  }
}

void ui_printrect(int* aI0, int aI1, int aI2){
  //ARGS: input array, length of array, rectangle length
  //RESULT: array printed in rectangular format to stdout
  for(int it0 = 0; it0 < aI1; it0++){
    printf("%d", aI0[it0]);
    if(it0 == aI1 - 1 || it0%aI2 == aI2 - 1) printf("\n");
    else printf(", ");
  }
}

int* ui_array(int aI0, int aI1){
  //ARGS: length of array, default value
  //RESULT: integer array with constant values
  int* ret = malloc(sizeof(int)*aI0);
  for(int it0 = 0; it0 < aI0; it0++) ret[it0] = aI1;
  return ret;
}

int* ui_duplicate(int* aI0, int aI1){
  //ARGS: input array, length of array
  //RESULT: another instance of input array
  int* ret = malloc(sizeof(int)*aI1);
  for(int it0 = 0; it0 < aI1; it0++) ret[it0] = aI0[it0];
  return ret;
}

int ui_nInst(int* aI0, int aI1, int aI2){
  //ARGS: input array, length of array, value of interest
  //RESULT: number of instances of said value
  int ret = 0;
  for(int i = 0; i < aI1; i++){
    if(aI0[i] == aI2) ret++;
  }
  return ret;
}

int* ui_uniform(int aI0, int aI1, int aI2){
  //ARGS: number of elements, lowest value, highest value
  //RESULT: array of uniformly divided array given a range
  int* ret = malloc(sizeof(int)*aI0);
  float ddx = ((float)(aI2 - aI1))/aI0;
  for(int i = 0; i < aI0; i++) ret[i] = aI1 + i*ddx;
  return ret;
}

float ui_error(int* aI0, int* aI1, int aI2){
  //ARGS: first array, second array, length of arrays
  float ret = 0;
  for(int i = 0; i < aI2; i++) ret += pow(aI0[i] - aI1[i], 2);
  return sqrt(ret);
}

//PART 2: Discrete math utilities

int ui_egcd(int aI0, int aI1){
  //ARGS: any positive integer, another positive integer
  //RESULT: the common divisor
  if(aI1 > aI0) return ui_egcd(aI1, aI0);
  else if(aI1 == 0) return aI0;
  else return ui_egcd(aI1, aI0%aI1);
}

int* ui_factors(int aI0){
  //ARGS: input positive integer
  //RESULT: list of all factors
  int* ret;
  return ret;
}
