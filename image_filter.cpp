/*
#include "image_filter.h"

//______________________________________________________________________________

void image_filter(AXI_STREAM& INPUT_STREAM, AXI_STREAM& OUTPUT_STREAM) {

#pragma HLS INTERFACE axis port=INPUT_STREAM bundle=VIDEO_IN
#pragma HLS INTERFACE axis port=OUTPUT_STREAM bundle=VIDEO_OUT
//#pragma HLS INTERFACE s_axilite port=return   bundle=CONTROL_BUS

//#pragma HLS INTERFACE s_axilite port=rows     bundle=CONTROL_BUS //offset=0x14
//#pragma HLS INTERFACE s_axilite port=cols     bundle=CONTROL_BUS //offset=0x1C
//#pragma HLS INTERFACE ap_stable port=rows
//#pragma HLS INTERFACE ap_stable port=cols



//assert(rows <= MAX_HEIGHT);
//assert(cols <= MAX_WIDTH);
const int rows = MAX_HEIGHT;
const int cols = MAX_WIDTH;

RGB_IMAGE  img_0  (MAX_HEIGHT, MAX_WIDTH);
GRAY_IMAGE img_1 (MAX_HEIGHT, MAX_WIDTH);
GRAY_IMAGE img_1a (MAX_HEIGHT, MAX_WIDTH);
GRAY_IMAGE img_1b (MAX_HEIGHT, MAX_WIDTH);
GRAY_IMAGE img_2 (MAX_HEIGHT, MAX_WIDTH);
GRAY_IMAGE img_3 (MAX_HEIGHT, MAX_WIDTH);
GRAY_IMAGE img_4 (MAX_HEIGHT, MAX_WIDTH);
RGB_IMAGE  img_5 (MAX_HEIGHT, MAX_WIDTH);

/*
RGB_IMAGE  img_0  (rows, cols);
RGB_IMAGE img_1 (rows, cols);
RGB_IMAGE img_0a (rows, cols);
RGB_IMAGE img_0b (rows, cols);
RGB_IMAGE img_2 (rows, cols);
RGB_IMAGE img_3 (rows, cols);
RGB_IMAGE img_4 (rows, cols);
*//*

#pragma HLS dataflow
//#pragma HLS pipeline
// Convert AXI4 Stream data to hls::mat format
hls::AXIvideo2Mat(INPUT_STREAM, img_0);
hls::CvtColor<HLS_RGB2GRAY>(img_0, img_1);
//hls::GaussianBlur<5,5>(img_1, img_2);
hls::Duplicate(img_1,img_1a,img_1b);
hls::Sobel<1,0,3>(img_1a, img_2);
hls::Sobel<0,1,3>(img_1b, img_3);
hls:AddWeighted(img_2,0.5,img_3,0.5,0.0,img_4);
hls::CvtColor<HLS_GRAY2RGB>(img_4, img_5);
hls::Mat2AXIvideo(img_5, OUTPUT_STREAM);
/*
hls::AXIvideo2Mat(INPUT_STREAM, img_0);
hls::Duplicate(img_0,img_0a,img_0b);
hls::Sobel<1,0,3>(img_0a, img_1);
hls::Sobel<0,1,3>(img_0b, img_2);
hls:AddWeighted(img_1,0.5,img_2,0.5,0.0,img_3);
hls::Mat2AXIvideo(img_3, OUTPUT_STREAM);
*//*
}*/

#include "image_filter.h"

void image_filter(AXI_STREAM& INPUT_STREAM, AXI_STREAM& OUTPUT_STREAM) {

//------------------------------- Soecifying the Axistream  ---------------------
#pragma HLS INTERFACE axis port=INPUT_STREAM bundle=VIDEO_IN
#pragma HLS INTERFACE axis port=OUTPUT_STREAM bundle=VIDEO_OUT

//------------------------------- Setup for Algorithm ---------------------------
const int rows = MAX_HEIGHT;
const int cols = MAX_WIDTH;
RGB_IMAGE  img_0  (MAX_HEIGHT, MAX_WIDTH);
GRAY_IMAGE img_1 (MAX_HEIGHT, MAX_WIDTH);
GRAY_IMAGE img_1a (MAX_HEIGHT, MAX_WIDTH);
GRAY_IMAGE img_1b (MAX_HEIGHT, MAX_WIDTH);
GRAY_IMAGE img_2 (MAX_HEIGHT, MAX_WIDTH);
GRAY_IMAGE img_3 (MAX_HEIGHT, MAX_WIDTH);
GRAY_IMAGE img_4 (MAX_HEIGHT, MAX_WIDTH);
RGB_IMAGE  img_5 (MAX_HEIGHT, MAX_WIDTH);

#pragma HLS dataflow // enable Pipelining

// Convert AXI4 Stream data to hls::mat format
hls::AXIvideo2Mat(INPUT_STREAM, img_0);

//---------------------------- Implemented filter ------------------------------
hls::CvtColor<HLS_RGB2GRAY>(img_0, img_1);
hls::Duplicate(img_1,img_1a,img_1b);
hls::Sobel<1,0,5>(img_1a, img_2);
hls::Sobel<0,1,5>(img_1b, img_3);
hls:AddWeighted(img_2,0.5,img_3,0.5,0.0,img_4);
hls::CvtColor<HLS_GRAY2RGB>(img_4, img_5);
//--------------------------------------------------------------------------------
hls::Mat2AXIvideo(img_5, OUTPUT_STREAM);
}

