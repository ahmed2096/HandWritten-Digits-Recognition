#ifndef CONVBACKPROB_H_INCLUDED
#define CONVBACKPROB_H_INCLUDED
#include "NeuralNetwork.h"
#include "ConvFeedForward.h"

typedef matrix<float> Matrix;
//////////////////////////////////////////////////////////*********************************\////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////|******POOL BACKPROPAGATION*******|////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////\*********************************/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Matrix* create_mask_from_window(Matrix* x);
Matrix* distribute_value(float dz, int nh, int nw);

//////////////////////////////////////////////////////////*********************************\////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////|***CONVOLUTION BACKPROPAGATION***|////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////\*********************************/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* For calculating dW */
VectVolume FilterGrades(VectVolume ACprev, VectVolume dAC);
/* For calculating dA */
VectVolume FullConvolution(VectVolume RotatedFilters, VectVolume dAC);
/* For calculating db*/
Matrix* biasGrades(VectVolume dZC);
/* Helping functions */
VectVolume Calc_dZC(VectVolume ZC, VectVolume dAC, ActivationType activation);      // For calculating dZC
VectVolume RearrangeFilters(VectVolume filter);                                     // For rearranging the vector of volumes to make it suitable for convolution
VectVolume PadAllVolumes(VectVolume Original, int pad, int value);                  // For padding the vector volumes to make it suitable for convolution
Volume PadVolume(Volume Original, int pad, int value);
VectVolume RotateAllVolumes(VectVolume filters);                                    // For rotating the vector of volumes 180 degrees
Volume RotateVolume(Volume filter);


#endif // CONVBACKPROB_H_INCLUDED