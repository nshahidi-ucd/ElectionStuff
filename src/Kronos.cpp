#include <string>
    using std::string;
    using std::to_string;
    using std::stoi;

#include <vector>
    using std::vector;

#include <array>
    using std::array;

#include <cmath>

#include "Kronos.h"

Kronos::Kronos(){
    this->setListsAndObjs();
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

void Kronos::setListsAndObjs(){
    if(this->propsSet)return;
    vector<int> base_hours {4, 5, 6, 7, 8, 9, 10, 11, -12, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, 12, 1, 2, 3};
    vector<string> base_hour_strs {"4", "5", "6", "7", "8", "9", "10", "11", "12", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "1", "2", "3"};
    vector<char> base_minute_deciles {'0','1','2','3','4','5'};
    vector<char> base_minute_uniles {'0','1','2','3','4','5','6','7','8','9'};
    for(size_t i = 0; i < base_hours.size(); ++i){
        int cur_int_hour = base_hours[i];
        string cur_meridian = cur_int_hour < 0 ? "AM" : "PM";
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

array<string,3> Kronos::parseTimeStr(string time_str) const {
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

string Kronos::buildTimeStr(array<string, 3> parsed_time) const {
    return parsed_time.at(0) + ":" + parsed_time.at(1) + " " + parsed_time.at(2);
}

double Kronos::timeStrToIndex(string time_str) const {
    array<string, 3> parsed_time = this->parseTimeStr(time_str);
    string ten_minute = string(1, parsed_time.at(1).at(0)) + "0";
    parsed_time.at(1) = ten_minute;
    string decile_str = this->buildTimeStr(parsed_time);
    double index = 0;
    for(size_t i = 0; i < this->tenMinuteList.size(); ++ i)
        if(this->tenMinuteList.at(i) == decile_str){
            index += i;
            break;
        }
    for(size_t j = 0; j < this->oneMinuteLists[index].size(); ++ j){
        if(this->oneMinuteLists[index].at(j) == time_str){
            index += j / 10;
            break;
        }
    }
    return index;
}

string Kronos::dtStrFromIndex(double index) const {
    if(index > 1152)return "";
    double index_floor = floor(index);
    double day_number_ = floor(index_floor / 144);
    int day_number = 0 + day_number_;
    string weekday_name = this->weekdays.at(day_number);
    int date_number = 5 + day_number;
    double index_left_ = remainder(index_floor, 144);
    int index_left = 0 + index_left_;
    double decimal_ = (index - index_floor) * 10;
    int decimal = 0 + decimal_;
    string the_time = this->oneMinuteLists.at(index_left).at(decimal);
    return weekday_name + ", November " + to_string(date_number) + "th; " + the_time;
}

string Kronos::getWeekday(string dt_str) const {
    size_t comma_place = dt_str.find_first_of(',');
    return dt_str.substr(0, comma_place);
}

string Kronos::getDate(string dt_str) const {
    size_t comma_p1 = dt_str.find_first_of(',') + 1;
    string after_comma = dt_str.substr(comma_p1, dt_str.length() - comma_p1);
    size_t nonspace_p1 = after_comma.find_first_not_of(' ');
    string trimmed_left = after_comma.substr(nonspace_p1, after_comma.length() - nonspace_p1);
    size_t semicolon_place = trimmed_left.find_first_of(';');
    return trimmed_left.substr(0, semicolon_place);
}

string Kronos::getDateNum(string dt_str) const {
    string date_str = this->getDate(dt_str);
    size_t r_p1 = date_str.find_first_of('r') + 1;
    string after_r = dt_str.substr(r_p1, date_str.length() - r_p1);
    size_t nonspace_p1 = after_r.find_first_not_of(' ') + 1;
    string trimmed_left = after_r.substr(nonspace_p1, after_r.length() - nonspace_p1);
    size_t t_place = trimmed_left.find_first_of('t');
    return trimmed_left.substr(0, t_place);
}

int Kronos::getDateNum(string dt_str, bool ret_int) const {
    string date_str = this->getDate(dt_str);
    size_t r_p1 = date_str.find_first_of('r') + 1;
    string after_r = date_str.substr(r_p1, date_str.length() - r_p1);
    size_t nonspace_p1 = after_r.find_first_not_of(' ') + 1;
    string trimmed_left = after_r.substr(nonspace_p1, after_r.length() - nonspace_p1);
    size_t t_place = trimmed_left.find_first_of('t');
    string date_num = trimmed_left.substr(0, t_place);
    return ret_int ? stoi(date_num) : 0;
}

string Kronos::getClockTime(string dt_str) const {
    size_t semicolon_p1 = dt_str.find_first_of(';') + 1;
    string after_semicolon = dt_str.substr(semicolon_p1, dt_str.length() - semicolon_p1);
    size_t nonspace_p1 = after_semicolon.find_first_not_of(' ') + 1;
    return after_semicolon.substr(nonspace_p1, after_semicolon.length() - nonspace_p1);
}

array<string, 4> Kronos::parseDtStr(string dt_str) const {
    string weekday = this->getWeekday(dt_str),
    date = this->getDate(dt_str),
    date_num = this->getDateNum(dt_str),
    clock_time = this->getClockTime(dt_str);
    array<string,4> parsed_dt_str = {weekday, date, date_num, clock_time};
    return parsed_dt_str;
}

double Kronos::dtStrToIndex(string dt_str) const {
    int date_num = this->getDateNum(dt_str, true);
    int parsed_144s = (date_num - 5) * 144;
    return this->timeStrToIndex(this->getClockTime(dt_str)) + parsed_144s;
}

int Kronos::dtStrCmp(string dt_str_1, string dt_str_2) const {
    double dt_str_1_index = this->dtStrToIndex(dt_str_1),
    dt_str_2_index = this->dtStrToIndex(dt_str_2);
    if(dt_str_1_index > dt_str_2_index)return 1;
    else if(dt_str_1_index > dt_str_2_index)return -1;
    else return 0;
}

string Kronos::timeStrToDtStr(string time_str) const {
    double time_str_index = this->timeStrToIndex(time_str);
    return this->dtStrFromIndex(time_str_index);
}

string Kronos::timeStrToDtStr(string time_str, int date) const {
    double time_str_index = this->timeStrToIndex(time_str);
    int parsed_144s = (date - 5) * 144;
    return this->dtStrFromIndex(time_str_index + parsed_144s);
}