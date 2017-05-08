#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;
/*********************  
��ʱ���� PrintMs 
************************/
void PrintMs(const char *text = " ")
{
	static long long last = 0;      //
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
	//mat.create(3000, 4000, CV_8UC3); // ����һ�ִ����ķ���
	int  mat_size = mat.elemSize();
	int  size = mat.rows * mat.cols *mat_size;
	PrintMs();
	//����������mat�ռ�
	for (int i = 0; i < size; i += mat_size)
	{
		mat.data[i] = 255; //blue
		mat.data[i + 1] = 0; //green
		mat.data[i + 2] = 0; //red

	}

	PrintMs("mat.data ms");

	// ֱ�ӵ�ַ������һ�������Ŀռ�
	for (int row = 0; row < mat.rows; row++)
	{
		for (int col = 0; col < mat.cols; col++)
		{
			(&mat.data[row*mat.step])[col*mat_size] = 0; //B
			(&mat.data[row*mat.step])[col*mat_size+1] = 0;
			(&mat.data[row*mat.step])[col*mat_size+2] = 255;

		}
	}
	PrintMs("mat.step ms");

	// ͨ��mat.ptr �ӿڱ���mat
	for (int row = 0; row < mat.rows; row++)
	{
		for (int col = 0; col < mat.cols; col++)
		{
			Vec3b *c = mat.ptr<Vec3b>(row, col);
			c->val[0] = 0;
			c->val[1] = 255;
			c->val[2] = 0;


		}
	}
	PrintMs("mat.ptr ms");

	namedWindow(" mat");  //����һ�����ڣ�
	imshow("mat", mat);   // ��ʾ�������
	waitKey(0);

	return 0;
}
