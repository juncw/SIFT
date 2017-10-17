#include "SIFT.h"

vector<KeyPoint> keyPoints[PIC_MAXNUM];
Mat images[PIC_MAXNUM], descriptiors[PIC_MAXNUM];


void load_pic_resource(char(*pic_list)[PATH_NAME])
{
	cout << "start load pictures.." << endl;
	for (int i = 1; i <= PIC_MAXNUM; ++i) {
		sprintf_s(pic_list[i - 1], "%sMETAL_%d.jpg", PIC_PATH.c_str(), i);
	}
	cout << "load pictures resource finish..." << endl;
}

void get_pics_sift_feature(char(*pic_list)[PATH_NAME])
{
	Ptr<Feature2D> f2d = xfeatures2d::SIFT::create();

	int i = 0;
	for (; i < PIC_MAXNUM; ++i) {
		images[i] = imread(pic_list[i]);
		Mat featureImage;
		f2d->detect(images[i], keyPoints[i]);

		f2d->compute(images[i], keyPoints[i], descriptiors[i]);
		/*drawKeypoints(images[i], keyPoints[i], featureImage, Scalar(-1));
		imshow("keyPoints of image", featureImage);
		waitKey(200);*/
	}
}

void get_feature_points_matching()
{
	BFMatcher matcher;
	vector<DMatch> matches[PIC_MAXNUM-1];
	int i = 0;
	for (; i < PIC_MAXNUM-1; ++i) {
		matcher.match(descriptiors[i], descriptiors[i+1], matches[i]);
		std::nth_element(matches[i].begin(), matches[i].begin() + FEATURE_NUMS - 1, matches[i].end());
		matches[i].erase(matches[i].begin() + FEATURE_NUMS, matches[i].end());
	}
	

	i = 0;
	for(; i < PIC_MAXNUM-1; ++i){
		cv::Mat imageMatches;
		cv::drawMatches(images[i], keyPoints[i],
			images[i + 1], keyPoints[i + 1],
			matches[i],
			imageMatches,
			cv::Scalar(128, 128, 128));
		cv::imshow("matches", imageMatches);
		cv::waitKey(0);
	}
}