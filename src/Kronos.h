#ifndef KRONOS_H
#define KRONOS_H

#include <string>
    using std::string;

#include <vector>
    using std::vector;

#include <array>
    using std::array;

class Kronos {
    
    
    private:
        
        vector<string> tenMinuteList;
        vector<vector<string>> oneMinuteLists;
        vector<string> daysTracker;
        vector<string> weekdays {"Tuesday", "Wednesday","Thursday","Friday","Saturday","Sunday","Monday"};
        bool propsSet {false};
    
    public:
        
        Kronos();
        ~Kronos() = default;
        
        vector<string> getTenMinuteList() const;
        vector<vector<string>> getOneMinuteLists() const;
        vector<string> getDaysTracker() const;
        vector<string> getWeekdays() const;
        bool getPropsSet() const;
        
        void setTenMinuteList(vector<string> theTenMinuteList);
        void setOneMinuteLists(vector<vector<string>> theOneMinuteLists);
        void setDaysTracker(vector<string> theDaysTracker);
        void setWeekdays(vector<string> theWeekdays);
        void setPropsSet(bool thePropsSet);
        
        void setListsAndObjs();
        
        array<string,3> parseTimeStr(string time_str) const;
        string buildTimeStr(array<string,3> parsed_time) const;
        double timeStrToIndex(string time_str) const;
        string dtStrFromIndex(double index) const;
        string getWeekday(string dt_str) const;
        string getDate(string dt_str) const;
        string getDateNum(string dt_str) const;
        int getDateNum(string dt_str, bool ret_int) const;
        string getClockTime(string dt_str) const;
        array<string,4> parseDtStr(string dt_str) const;
        double dtStrToIndex(string dt_str) const;
        int dtStrCmp(string dt_str_1, string dt_str_2) const;
        string timeStrToDtStr(string time_str) const;
        string timeStrToDtStr(string time_str, int date) const;

};

#endif