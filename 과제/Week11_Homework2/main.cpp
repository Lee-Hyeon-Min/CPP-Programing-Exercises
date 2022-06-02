#include <cstdio>
#include <iostream>

using namespace std;
class TimeHMS {
	int hour, min, sec;
public:
	TimeHMS(int h = 0, int m = 0, int s = 0) :hour(h), min(m), sec(s) {}
	void print(const char* msg = "시간 = ") {
		printf("%d시 %d분 %d초 \n", hour, min, sec);
	}

	TimeHMS operator+(TimeHMS t2) { 
		if (sec + t2.sec >= 60) {
			int second;
			min += 1;
			second = sec + t2.sec - 60;
			return TimeHMS(hour + t2.hour, min + t2.min, second);
		}
		if (min + t2.min >= 60)
		{
			int minute;
			hour += 1;
			minute = min + t2.min - 60;
			return TimeHMS(hour + t2.hour, minute, sec + t2.sec);
		}
		return TimeHMS(hour + t2.hour, min + t2.min, sec + t2.sec);
	}
	TimeHMS operator-(TimeHMS t1) {
		return TimeHMS(hour - t1.hour, min - t1.min, sec - t1.sec);
	}
	bool operator==(TimeHMS t2) { return hour == t2.hour && min == t2.min && sec == t2.sec; }
	bool operator!=(TimeHMS t2) { return hour != t2.hour || min != t2.min || sec != t2.sec; }
	TimeHMS& operator++() { hour += 1; return *this; }
	TimeHMS& operator--() { hour -= 1; return *this; }
	TimeHMS operator++(int) { sec += 1; return TimeHMS(hour,min,sec); }
	TimeHMS operator--(int) { sec -= 1; return TimeHMS(hour,min,sec); }
	int& operator[](int num) {
		if (num == 0) return hour;
		else if (num == 1) return min;
		else if (num == 2) return sec;
	}
	 operator int() {
		return (int)(hour * 3600 + min * 60 + sec);
	}
	 operator double() {
		 return (double)(hour + min / 60 + sec / 3600);
	 }
	 TimeHMS operator* (double d) { 
		 if (sec * d >= 60) {
			 int second;
			 second = sec * d - 60;
			 return TimeHMS(hour * d, min* d, second);
		 }
		 if (min * d >= 60) {
			 int minute;
			 minute = min * d - 60;
			 return TimeHMS(hour * d, minute, sec* d);
		 }
		 return  TimeHMS(hour * d, min* d, sec* d);
	 }
};
TimeHMS t1(1, 20, 30), t2(4, 35, 46), t3;

int main()
{
	TimeHMS t1(1, 20, 30), t2(4, 35, 46), t3;
	t3 = t1 + t2;
	t3.print("t1 + t2 = ");
	t3 = t2 - t1;
	t3.print("t2 - t1 = ");
	t3 = ++t1;
	t3.print("t1 = ");
	t3 = --t1;
	t3.print("t1 = ");
	t3 = t1++;
	t3.print("t1 = ");
	t3 = t1--;
	t3.print("t1 = ");
	t3 = t1[0];
	cout << "hour = " << t1[0] << endl;
	t3 = t1[1];
	cout << "minute = " << t1[1] << endl;
	t3 = t1[2];
	cout << "second = " << t1[2] << endl;
	t3 = (int) t1;
	t3.print("int t1 = ");
	t3 = (double)t1;
	t3.print("double t1 = ");
	t3 = t1 * 2.0;
	t3.print("2 * t1 = ");
	
}