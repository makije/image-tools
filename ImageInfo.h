#ifndef IMAGEINFO_H_
#define IMAGEINFO_H_

#include <opencv2/highgui/highgui.hpp>

class ImageInfo {

private:
	cv::Mat_<ushort> image;

public:
	ImageInfo(char*);
	virtual ~ImageInfo();

	int getImageHeight();
	int getImageWidth();

	void printPixelValuesPatch(int, int, int, int);
	void printPixelValuesPatch(int, int, int, int, int);
};

#endif /* IMAGEINFO_H_ */
