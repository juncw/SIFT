
#include "SIFT.h"


int main(void)
{
	char pic_list[PIC_MAXNUM][PATH_NAME];
	load_pic_resource(pic_list);
	get_pics_sift_feature(pic_list);
	get_feature_points_matching();

	waitKey();
	return 0;
}