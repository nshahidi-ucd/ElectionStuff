#include <string>
    using std::string;

#include <vector>
    using std::vector;

#include <array>
    using std::array;

#include "Kronos.h"

Kronos::Kronos(){
    this->setListsAndObjs();
}

void Kronos::setListsAndObjs(){
    if(this->propsSet)return;
    vector<int> base_hours {4, 5, 6, 7, 8, 9, 10, 11, -12, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, 12, 1, 2, 3};
    vector<string> base_hour_strs {"4", "5", "6", "7", "8", "9", "10", "11", "12", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "1", "2", "3"};
    vector<char> base_minute_deciles {'0','1','2','3','4','5'}
    vector<char> base_minute_uniles {'0','1','2','3','4','5','6','7','8','9'}
    for(size_t i = 0; i < base_hours.size(); ++i){
        int cur_int_hour = base_hours[i];
        string cur_meridian = cur_nude_hour < 0 ? "AM" : "PM";
        string cur_str_hour = base_hour_strs[i];
        for(char cur_base_minute_decile : base_minute_deciles){
            string cur_ten_minute = cur_str_hour + ':';
            cur_ten_minute += cur_base_minute_decile;
            string cur_decile_string = cur_ten_minute + "0 ";
            cur_decile_string += cur_meridian;
            this->tenMinuteList.push_back(cur_decile_string);
            vector<string> cur_one_minute_list;
            for(char cur_base_minute_unile : base_minute_uniles)
                cur_one_minute_list.push_back(cur_ten_minute + cur_base_minute_unile);
            this->oneMinuteLists.push_back(cur_one_minute_list);
        }
    }
    this->propsSet = true;
}

vector<string> Kronos::getTenMinuteList() const {
    return this->tenMinuteList;
}

vector<vector<string>> Kronos::getOneMinuteLists() const {
    return this->oneMinuteLists;
}

vector<string> Kronos::getDaysTracker() const {
    return this->daysTracker;
}

vector<string> Kronos::getWeekdays() const {
    return this->weekdays;
}

bool Kronos::getPropsSet() const {
    return this->propsSet;
}

void Kronos::setTenMinuteList(vector<string> theTenMinuteList) {
    this->tenMinuteList = theTenMinuteList;
}

void Kronos::setOneMinuteLists(vector<vector<string>> theOneMinuteLists) {
    this->oneMinuteLists = theOneMinuteLists;
}

void Kronos::setDaysTracker(vector<string> theDaysTracker) {
    this->daysTracker = theDaysTracker;
}

void Kronos::setWeekdays(vector<string> theWeekdays) {
    this->weekdays = theWeekdays;
}

void Kronos::setPropsSet(bool thePropsSet) {
    this->propsSet = thePropsSet;
}

array<string,3> Kronos::parseTimeStr(string& time_str) const {
    size_t colon_place = time_str.find_first_of(':'),
    colon_p1 = colon_place + 1;
    string before_colon = time_str.substr(0, colon_place),
    after_colon = time_str.substr(colon_p1, time_str.length() - colon_p1);
    size_t space_place = after_colon.find_first_of(' '),
    space_p1 = space_place + 1;
    string before_space = after_colon.substr(0, space_place),
    after_space = after_colon.substr(space_p1, after_colon.length() - space_p1);
    array<string,3> parsed_time = {before_colon, before_space, after_space};
    return parsed_time;
}

string Kronos::buildTimeStr(array<string, 3>& parsed_time) const {
    return parsed_time.at(0) + ":" + parsed_time.at(1) + " " + parsed_time.at(2);
}

double Kronos::timeStrToIndex(string& time_str) const {
    array<string, 3> parsed_time = this->parseTimeStr(time_str);
    string ten_minute = string(1, parsed_time.at(1).at(0)) + "0";
}