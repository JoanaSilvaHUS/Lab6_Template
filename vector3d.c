#include "vector3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/* TODO: -- define data structure here -- */ 
    typedef struct vector3d
    {
        double x, y, z;
    }Vector3d;


    PtVector3d  vector3dCreate(double x, double y, double z) {
    PtVector3d p = (PtVector3d) malloc(sizeof(Vector3d));


    if (p == NULL) return NULL;

    p->x = x;
    p->y=y;
    p->z=z;

    return p;
}


void vector3dPrint(PtVector3d vec, bool lineBreakAfter) {
    
    if(vec == NULL)
    {
        printf("NULL");
    }

    else
    {
        printf("<%.21f, %.21f, %.21f>", vec->x, vec->y, vec->z);
    }

    if(lineBreakAfter)
    {
        printf("\n");
    }
}

int vector3dDestroy(PtVector3d *pVec)
{
    PtVector3d vec = *pVec;
 
    if (vec == NULL) return VECTOR3D_NULL;

    free(vec);
    *pVec = NULL;

    return VECTOR3D_OK;
}

PtVector3d vector3dMultiplyByScalar(PtVector3d vec, double scalar)
{
    if (vec == NULL) return NULL;

    PtVector3d c = vector3dCreate(vec->x * scalar, vec->y * scalar, vec-> z * scalar);

    return c;
}

PtVector3d vector3dAss(PtVector3d vec1, PtVector3d vec2)
{
    if (vec1 == NULL || vec2 == NULL) return NULL;

    PtVector3d c = vector3dCreate(vec1->x + vec2->x, vec1->y + vec2->y, vec1->y + vec2->z);

    return c;
}

int vector3dMagnitude(PtVector3d vec, double *magnitude)
{
    if (vec == NULL) return VECTOR3D_NULL;

    *magnitude = sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);

    return VECTOR3D_OK;
}

int vector3dX(PtVector3d vec, double *x) {
    
  if (vec == NULL) return VECTOR3D_NULL;

  *x = vec -> x;

  return VECTOR3D_OK;


}

int vector3dY(PtVector3d vec, double *y) {
    
  if (vec == NULL) return VECTOR3D_NULL;

  *y = vec -> y;

  return VECTOR3D_OK;
}

int vector3dZ(PtVector3d vec, double *z) {
    
   if (vec == NULL) return VECTOR3D_NULL;

  *z = vec -> z;

  return VECTOR3D_OK;
}

PtVector3d vector3dNormalize(PtVector3d vec)
{
    if(vec == NULL)
    {
        return NULL;
    }
    double magnitude = 0;
    vector3dMagnitude(vec, &magnitude);

    if(magnitude == 0)
    {
        return vector3dCreate(0,0,0);
    }
    else
    {
    PtVector3d c = vector3dCreate(vec->x, vec->y, vec->z);
    PtVector3d more = vector3dMultiplyByScalar(c, 1/magnitude);
    }

    free(c);
    return more;
}

PtVector3d vector3dMultiplyByScalar(PtVector3d vec, double scalar) {
    return NULL;
}

PtVector3d vector3dAdd(PtVector3d vec1, PtVector3d vec2) {
    return NULL;
}

int vector3dMagnitude(PtVector3d vec, double *magnitude) {
   
    return VECTOR3D_OK;
}

PtVector3d vector3dNormalize(PtVector3d vec) {
    return NULL;
}

