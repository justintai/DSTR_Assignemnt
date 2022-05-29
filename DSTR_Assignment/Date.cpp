//#include <string>
//#include <time.h>
//#include <ctime>
//#include <chrono>
//#define _CRT_SECURE_NO_WARNINGS
//using namespace std;
//
//time_t toTimeStamp(string date) {
//    struct tm t;
//    time_t t_of_day;
//
//    t.tm_year = stoi(date.substr(0, 4)) - 1900;  // Year - 1900
//    t.tm_mon = stoi(date.substr(5, 7)) - 1;           // Month, where 0 = jan
//    t.tm_mday = stoi(date.substr(8, 10));          // Day of the month
//    t.tm_hour = 0;
//    t.tm_min = 0;
//    t.tm_sec = 0;
//    t.tm_isdst = 0;        // Is DST on? 1 = yes, 0 = no, -1 = unknown
//    t_of_day = mktime(&t);
//
//    return t_of_day;
//}
//
//int main()
//{
//    string date = "2022-04-28";
//    time_t t = toTimeStamp(date);
//    cout << "The timestamp of "<<date<<" is " << t << endl;
//    auto end = std::chrono::system_clock::now();
//    time_t end_time = std::chrono::system_clock::to_time_t(end);
//    cout << "finished computation at " << ctime(&end_time) << endl;
//
//
//    tm* tm = localtime(&t);
//    cout << "The year is " << tm->tm_year + 1900
//        << " The month is " << tm->tm_mon + 1
//        << " The date is " << tm->tm_mday
//        << " The hour is " << tm->tm_hour
//        << " The minute is " << tm->tm_min
//        << " The sec is " << tm->tm_sec << endl;
//    return 0;
//}