#pragma once
#include <iostream>
using namespace std;

#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
using namespace cv;


const int PATH_NAME = 100;
const int PIC_MAXNUM = 12;
const int FEATURE_NUMS = 20;
const string PIC_PATH = "E:\\project_code/experiment_data/";

void load_pic_resource(char(*pic_list)[PATH_NAME]);
void get_pics_sift_feature(char(*pic_list)[PATH_NAME]);
void get_feature_points_matching();
