#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>

#include "ImageInfo.h"

int main(int argc, char* argv[])
{
	char* imagePath;
	int x, y, width, height, threshold;

	x = y = threshold = 0;

	ImageInfo* image = 0;

	int c;

	while (1)
	{
		static struct option long_options[] =
		{
				{"image",		required_argument,	0,	'i'},
				{"x",			required_argument,	0,	'x'},
				{"y",			required_argument,	0,	'y'},
				{"width",		required_argument,	0,	'w'},
				{"height",		required_argument,	0,	'h'},
				{"threshold",	required_argument,	0,	't'},
				{0, 0, 0, 0}
		};
		/* getopt_long stores the option index here. */
		int option_index = 0;

		c = getopt_long (argc, argv, "i:x:y:w:h:t:", long_options, &option_index);

		/* Detect the end of the options. */
		if (c == -1)
			break;

		switch (c)
		{
		case 0:
			/* If this option set a flag, do nothing else now. */
			if (long_options[option_index].flag != 0)
				break;
			printf ("option %s", long_options[option_index].name);
			if (optarg)
				printf (" with arg %s", optarg);
			printf ("\n");
			break;

		case 'i':
			imagePath = optarg;
			if(access(imagePath, F_OK ) == -1)
			{
				printf("%s does not exist\n", imagePath);
				exit(-1);
			}

			image = new ImageInfo(imagePath);
			width = image->getImageWidth();
			height = image->getImageHeight();
			break;

		case 'x':
			x = atoi(optarg);
			break;

		case 'y':
			y = atoi(optarg);
			break;

		case 'w':
			width = atoi(optarg);
			break;

		case 'h':
			height = atoi(optarg);
			break;

		case 't':
			threshold = atoi(optarg);
			break;

		case '?':
			/* getopt_long already printed an error message. */
			break;

		default:
			abort();
		}
	}

	/* Print any remaining command line arguments (not options). */
	if (optind < argc)
	{
		printf ("non-option ARGV-elements: ");
		while (optind < argc)
			printf ("%s ", argv[optind++]);
		putchar ('\n');
	}

	if(image)
	{
		if(!threshold)
			image->printPixelValuesPatch(x, y, height, width);
		else
			image->printPixelValuesPatch(threshold, x, y, height, width);
	}
	else
	{
		printf("Please provide me with an image\n");
	}

	return 0;
}



