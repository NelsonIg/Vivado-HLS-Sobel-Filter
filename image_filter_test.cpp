#include "image_filter.h"
#include "hls_opencv.h"

#include <iostream>
using namespace std;

int main (int argc, char** argv) {

IplImage* src;
IplImage* dst;

// AXI stream version
AXI_STREAM src_axi, dst_axi;




    src = cvLoadImage(INPUT_IMAGE);
    dst = cvCreateImage(cvGetSize(src), src->depth, src->nChannels);

    IplImage2AXIvideo(src, src_axi);

    //______________________________________________________________________________
    // DUT:
    image_filter(src_axi, dst_axi);
    //______________________________________________________________________________

    // Convert the AXI4 Stream data to OpenCV format
    AXIvideo2IplImage(dst_axi, dst);



cvSaveImage(OUTPUT_IMAGE, dst);
cvReleaseImage(&src);
cvReleaseImage(&dst);
}
