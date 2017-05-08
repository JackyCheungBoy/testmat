#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;
/*********************  
计时函数 PrintMs 
************************/
void PrintMs(const char *text = " ")
{
	static long long last = 0;
	long long cur = getTickCount();
	if (last == 0)
	{
		last = cur;
		return;
	}
	long long ms = 0;
	ms = ((double)(cur - last) / getTickFrequency()) * 1000;
	if (*text != 0)
	{
		printf("%s =  %dms\n", text, ms);
	}
	last = getTickCount();

}

int main(int argc, char *argv)
{
	Mat mat(3000, 4000, CV_8UC3);
	//mat.create(3000, 4000, CV_8UC3); // 另外一种创建的方法
	int  mat_size = mat.elemSize();
	int  size = mat.rows * mat.cols *mat_size;
	PrintMs();

	for (int i = 0; i < size; i += mat_size)
	{
		mat.data[i] = 255; //blue
		mat.data[i + 1] = 0; //green
		mat.data[i + 2] = 0; //red

	}

	PrintMs("mat.data ms");
	namedWindow(" mat");  //创建一个窗口，
	imshow("mat", mat);   // 显示这个窗口
	waitKey(0);

	return 0;
}
