#include "ImageInfo.h"

#include <opencv2/highgui/highgui.hpp>

#include <stdio.h>

ImageInfo::ImageInfo(char* imagePath) {
	this->image = cv::imread(imagePath, CV_LOAD_IMAGE_GRAYSCALE);
}

ImageInfo::~ImageInfo() {

}

int ImageInfo::getImageHeight()
{
	return image.rows;
}

int ImageInfo::getImageWidth()
{
	return image.cols;
}

void ImageInfo::printPixelValuesPatch(int x, int y, int height, int width)
{
	this->printPixelValuesPatch(255, x, y, height, width);
}

void ImageInfo::printPixelValuesPatch(int threshold, int x, int y, int height, int width)
{
	int i, j;

	printf("      ");

	for(i = x; i < (x + width); i++)
		printf("%4d ", i);

	printf("\n");

	for(i = x; i < x + height; i++)
	{
		printf("%4d: ", y + (i - x));
		for(j = y; j < y + width; j++)
		{
			int pixel = image(i, j);
			if(pixel <= threshold)
				printf("%4d ", pixel);
			else
				printf("     ");
		}
		printf("\n");
	}
}
