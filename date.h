#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>

namespace date {
    class Date {
    private:
        int _year;
        int _month;
        int _day;
    public:
        Date(int year, int month, int day);
        Date() = default;
        ~Date();
        int year() const;
        int month() const;
        int day() const;
        //meme que checkDate mais sans parametre et elle utilise les variables membres
        bool checkDate2();
        bool checkDate(int year, int month, int day);
        //fonction fait le meme que setDay mais sans assert ce qui evite l'arret du programme 
        void setdaywithoutassert(int day);
        void setYear(int year);
        void setMonth(int month);
        void setDay(int day);
        void nextDay();
        std::string toString() const;
        friend std::istream& operator>>(std::istream&,Date&);
    };

    bool operator == (const Date&, const Date&); // comparison operators bool operator != (const date&, const date&);
    bool operator < (const Date&, const Date&);
    bool operator > (const Date&, const Date&);
    bool operator <= (const Date&, const Date&);
    bool operator >= (const Date&, const Date&);
    int  operator - (const Date&, const Date&);
    

}
#endif // DATE_H
