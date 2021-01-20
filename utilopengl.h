#pragma once

#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

//setting 3d stuff

void setObjectT(GLfloat* aF0, GLfloat aF1, GLfloat aF2, GLfloat aF3){
  aF0[3] = aF1;
  aF0[7] = aF2;
  aF0[11] = aF3;
}

void setObjectRx(GLfloat* aF0, GLfloat aF1){
  aF0[5] = cos(aF1);
  aF0[6] = -sin(aF1);
  aF0[9] = sin(aF1);
  aF0[10] = cos(aF1);
}

void setObjectRy(GLfloat* aF0, GLfloat aF1){
  aF0[0] = cos(aF1);
  aF0[2] = sin(aF1);
  aF0[8] = -sin(aF1);
  aF0[10] = cos(aF1);
}

void setObjectRz(GLfloat* aF0, GLfloat aF1){
  aF0[0] = cos(aF1);
  aF0[1] = -sin(aF1);
  aF0[4] = sin(aF1);
  aF0[5] = cos(aF1);
}

void scaleObject(GLfloat* aF0, GLfloat aF1){
  aF0[0] *= aF1;
  aF0[5] *= aF1;
  aF0[10] *= aF1;
}

void setObjectS(GLfloat* aF0, GLfloat aF1){
  aF0[0] = aF1;
  aF0[5] = aF1;
  aF0[10] = aF1;
}

//create zero matrix
GLfloat* ugl_Z(int aI0){
  GLfloat* ret = malloc(sizeof(GLfloat)*aI0);
  for(int it0 = 0; it0 < aI0; it0++) ret[it0] = 0;
  return ret;
}

//create identity matrix
GLfloat* ugl_I(int aI0){
  GLfloat* ret = malloc(sizeof(GLfloat)*aI0*aI0);
  for(int it0 = 0; it0 < aI0*aI0; it0++){
    if(it0%(aI0 + 1) == 0) ret[it0] = 1;
    else ret[it0] = 0;
  }
  return ret;
}

//create duplicate
GLfloat* ugl_duplicate(GLfloat* aF0, int aI0){
  GLfloat* ret = malloc(sizeof(GLfloat)*aI0);
  for(int it0 = 0; it0 < aI0; it0++) ret[it0] = aF0[it0];
  return ret;
}

//some arithmetics
GLfloat* ugl_mult(GLfloat* aF0, GLfloat* aF1, int aI0, int aI1, int aI2){
  //input array 0, input array 1, row 0, col 0/row1, col 1
  GLfloat* ret = ugl_Z(aI0*aI2);
  for(int it0 = 0; it0 < aI0*aI2; it0++){
    for(int it1 = 0; it1 < aI1; it1++) ret[it0] += aF0[(it0/4)*aI1 + it1]*aF1[it1*aI2 + (it0%4)];
  }
  return ret;
}

//create a single transformation matrix from a list of transformation
//matrices
GLfloat* ugl_T(GLfloat** aF0){
  GLfloat* ret = ugl_mult(aF0[1], aF0[0], 4, 4, 4);
  for(int it0 = 2; it0 < 5; it0++){
    GLfloat* temp = ugl_mult(aF0[it0], ret, 4, 4, 4);
    free(ret);
    ret = ugl_duplicate(temp, 16);
    free(temp);
  }
  return ret;
}

