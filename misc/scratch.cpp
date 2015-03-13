#include <iostream>
#include <math.h>

class Point
{
	public:
		int x, y;

		Point()
		{
			x = 0; y = 0;
		}
		Point(int xCor, int yCor)
		{
			x = xCor;
			y = yCor;
		}

		friend std::iostream& operator<<(std::iostream& strm, Point& pt);
};

std::ostream& operator<<(std::ostream& strm, Point& pt)
{
	strm << pt.x << ", " << pt.y;
	return strm;
}

class Rectangle
{
	public:
		int width;
		int height;
		Point topLeft;

		int diagonal()
		{
			return sqrt(pow(2, height) + pow(2, width));
		}

		Rectangle()
		{
			width = 0; height = 0; topLeft = Point();
		}
		Rectangle(Point tpL, int wdt, int hgt)
		{
			topLeft = tpL;
			width = wdt;
			height = hgt;
		}

		friend std::fstream operator<<(std::fstream strm, Rectangle rect);
};

std::ostream& operator<<(std::ostream& strm, Rectangle& rect)
{
	strm << "{(" << rect.topLeft << "), w:" 
		<< rect.width << " h:" << rect.height << "}";
	return strm;
}

int main(int argc, char** argv)
{

	Rectangle testRect(Point(5, 6), 11, 33);
	std::cout << testRect << "\n";

}
