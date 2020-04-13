#define IMAGE_FILTER_H


//#define MAX_WIDTH  1920
//#define MAX_HEIGHT 1080
#define MAX_WIDTH  1280
#define MAX_HEIGHT 720
#define MAX_MEMORY 2047
#include  "hls_video.h"
#include <ap_fixed.h>

typedef hls::stream<ap_axiu<24,1,1,1> >           AXI_STREAM;


// check include/hls/hls_video_types.h for detail on pixel type
typedef hls::Mat<MAX_MEMORY,   MAX_MEMORY,   HLS_8UC3> RGB_IMAGE;
typedef hls::Mat<MAX_MEMORY/2, MAX_MEMORY/2, HLS_8UC3> RGB_IMAGE_HALF;
typedef hls::Scalar<3, unsigned char>                 RGB_PIXEL;


typedef hls::Mat<MAX_MEMORY,   MAX_MEMORY,   HLS_8UC1> GRAY_IMAGE;
typedef hls::Mat<MAX_MEMORY/2, MAX_MEMORY/2, HLS_8UC1> GRAY_IMAGE_HALF;

typedef hls::Scalar<1, unsigned char>  GRAY_PIXEL;

typedef ap_fixed<8,4>        GAIN_T;
typedef ap_fixed<8,4,AP_RND> COEF_T;
typedef ap_int<16>           INDEX_T;
typedef ap_fixed<8,4>        RATIO_T;

// kernel size
const int KS = 5;


#define INPUT_IMAGE          "Lena.bmp"
#define OUTPUT_IMAGE         "output.bmp"
#define OUTPUT_IMAGE_GOLDEN  "golden_output.bmp"



void image_filter(
	AXI_STREAM& INPUT_STREAM,
	AXI_STREAM& OUTPUT_STREAM );
	//int rows,
	//int cols);

