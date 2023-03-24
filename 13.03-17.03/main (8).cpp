#include <iostream>
#include <ctime>

using namespace std;

bool isLeap(int year) {
 if(year%4==0)
 {
     return true;
 }
 return false;
}

int monthLength(int year, int month) {
    if(isLeap(year)){
        int arr[]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return arr[month-1];
    }
    else{
        int arr[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return arr[month-1];
    }
 }

struct Date {
    int year;
    int month;
    int day;
 };
 
 
 Date today(void) {
  time_t t = time(NULL);
  tm tl = *localtime(&t);
  int year = tl.tm_year + 1900;
  int month = tl.tm_mon + 1;
  int day = tl.tm_mday;
  Date todayDate = {year, month, day};
  return todayDate;
}



int main(void) {
  int myYear=2003;  //дата моего рождения
  int myMonth=9;
  int myDay=10;
  int daysCounter;
  int leapDays=0;
  int MonthDays=0;
  
  cout<<"My date of birth: "<<myYear<< "-" <<myMonth<< "-" <<myDay<< endl;
  
  Date t = today();
  cout << t.year << "-" << t.month << "-" << t.day << endl;
  
  for(int i=myYear;i<t.year;i++){
      if(isLeap(i)){
          leapDays++;
      }
  }
  if(t.month<myMonth){
  for(int i=t.month;i<myMonth;i++){
     MonthDays += monthLength(t.year,i);
  }
  daysCounter=(t.year-myYear)*365+leapDays-MonthDays+(t.day-myDay);
  }
  if(t.month>myMonth){
      for(int i=myMonth;i<t.month;i++){
     MonthDays += monthLength(t.year,i);
  }
  daysCounter=(t.year-myYear)*365+leapDays+MonthDays+(t.day-myDay);
  }
  if(t.month==myMonth){
  daysCounter=(t.year-myYear)*365+leapDays+MonthDays+(t.day-myDay);
  }
  
  
  cout<<daysCounter<<endl;
  
  return 0;
}
