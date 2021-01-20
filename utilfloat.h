#include <stdlib.h>

void prntFlArr(float* a0, int a1){
  for(int i = 0; i < a1; i++){
    if(i < a1 - 1) printf("%f, ", a0[i]);
    else printf("%f\n", a0[i]);
  }
}

float* flArr(int a0){
  float* ret = malloc(sizeof(float)*a0);
  for(int i = 0; i < a0; i++) ret[i] = 0;
  return ret;
}

float* flRnd(int a0){
  float* ret = malloc(sizeof(float)*a0);
  for(int i = 0; i < a0; i++) ret[i] = 2*((float)rand())/RAND_MAX - 1;
  return ret;
}

float** wFlArr(int a0, int a1){
  float** ret = malloc(sizeof(float*)*a0);
  for(int i = 0; i < a0; i++) ret[i] = flArr(a1);
  return ret;
}

float** wFlRnd(int a0, int a1){
  float** ret = malloc(sizeof(float*)*a0);
  for(int i = 0; i < a0; i++) ret[i] = flRnd(a1);
  return ret;
}

float* cpFlArr(float* a0, int a1){
  float* ret = malloc(sizeof(float)*a1);
  for(int i = 0; i < a1; i++) ret[i] = a0[i];
  return ret;
}

void pluseqFlArr(float* a0, float* a1, int a2){
  for(int i = 0; i < a2; i++) a0[i] = a0[i] + a1[i];
}

float* uf_arith(float* aF0, float* aF1, int aI0, int aI1, int aI2){
  //array 0, array 1, n rows, n cols, operation
  float* ret = malloc(sizeof(float)*aI0*aI1);
  for(int it0 = 0; it0 < aI0*aI1; it0++){
    if(aI2 == 0) ret[it0] = aF0[it0] + aF1[it0];
    else if(aI2 == 1) ret[it0] = aF0[it0] - aF1[it0];
    else if(aI2 == 2) ret[it0] = aF0[it0]*aF1[it0];
    else ret[it0] = aF0[it0]/aF1[it0];
  }
  return ret;
}

float* uf_mult(float* aF0, float* aF1, int aI0, int aI1, int aI2){
  //array 0, array 1, n row 0, n col 0 = n row 1, n col 1
  float* ret = malloc(sizeof(float)*aI0*aI2);
  return ret;
}
