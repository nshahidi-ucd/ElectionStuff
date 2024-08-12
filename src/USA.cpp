#include "USA.h"
#include <string>
    using std::string;
#include <array>
    using std::array;

array<string, 56> USA::stateCodes = {"AL", "AK", "AZ", "AR", "CA", "CO", "CT", "DE", "DC", "FL", "GA", "HI", "ID", "IL", "IN", "IA", "KS", "KY", "LA", "ME", "M1", "M2", "MD", "MA", "MI", "MN", "MS", "MO", "MT", "NE", "N1", "N2", "N3", "NV", "NH", "NJ", "NM", "NY", "NC", "ND", "OH", "OK", "OR", "PA", "RI", "SC", "SD", "TN", "TX", "UT", "VT", "VA", "WA", "WV", "WI", "WY"};
array<string, 56> USA::stateNames = {"Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "District of Columbia", "Florida", "Georgia", "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maine\'s 1st", "Maine\'s 2nd", "Maryland", "Massachussetts", "Michigan", "Minnesota", "Mississippi", "Missouri", "Montana", "Nebraska", "Nebraska\'s 1st", "Nebraska\'s 2nd", "Nebraska\'s 3rd", "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York", "North Carolina", "North Dakota", "Ohio", "Oklahoma", "Oregon", "Pennsylvania", "Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah", "Vermont", "Virgina", "Washington", "West Virginia", "Wisconsin", "Wyoming"};
array<string, 56> USA::stateClosingTimes = {"6:00 PM", "11:00 PM", "7:00 PM", "6:30 PM", "9:00 PM", "7:00 PM", "6:00 PM", "6:00 PM", "6:00 PM", "6:00 PM", "5:00 PM", "9:00 PM", "9:00 PM", "6:00 PM", "5:00 PM", "8:00 PM", "7:00 PM", "5:00 PM", "7:00 PM", "6:00 PM", "6:00 PM", "6:00 PM", "6:00 PM", "6:00 PM", "7:00 PM", "7:00 PM", "6:00 PM", "6:00 PM", "8:00 PM", "7:00 PM", "7:00 PM", "7:00 PM", "7:00 PM", "8:00 PM", "6:00 PM", "6:00 PM", "7:00 PM", "7:00 PM", "5:30 PM", "7:00 PM", "5:30 PM", "6:00 PM", "9:00 PM", "6:00 PM", "6:00 PM", "5:00 PM", "7:00 PM", "6:00 PM", "7:00 PM", "8:00 PM", "5:00 PM", "5:00 PM", "9:00 PM", "5:30 PM", "7:00 PM", "7:00 PM"};
array<char, 56> USA::statePreviousWinners = {'R', 'R', 'D', 'R', 'D', 'D', 'D', 'D', 'D', 'R', 'D', 'D', 'R', 'D', 'R', 'R', 'R', 'R', 'R', 'D', 'D', 'R', 'D', 'D', 'D', 'D', 'R', 'R', 'R', 'R', 'R', 'D', 'R', 'D', 'D', 'D', 'D', 'D', 'R', 'R', 'R', 'R', 'D', 'D', 'D', 'R', 'R', 'R', 'R', 'R', 'D', 'D', 'D', 'R', 'D', 'R'};
array<int, 56> USA::stateEvs = {9, 3, 11, 6, 54, 10, 7, 3, 3, 30, 16, 4, 4, 19, 11, 6, 6, 8, 8, 2, 1, 1, 10, 11, 15, 10, 6, 10, 4, 2, 1, 1, 1, 6, 4, 14, 5, 28, 16, 3, 17, 7, 8, 19, 4, 9, 3, 11, 40, 6, 3, 13, 12, 4, 10, 3};
array<int, 56> USA::stateProjNums = {99, 75, 50, 99, 1, 29, 17, 14, 0, 77, 53, 8, 99, 11, 97, 91, 95, 99, 99, 38, 9, 80, 1, 1, 49, 47, 98, 92, 90, 93, 82, 44, 99, 52, 45, 79, 38, 19, 56, 99, 70, 99, 28, 50, 14, 83, 99, 96, 82, 91, 1, 40, 20, 99, 50, 99};
array<int, 56> USA::statePopulations = {5143033, 733536, 7497004, 3089060, 38889770, 5914181, 3625646, 1044321, 678972, 22975931, 11145304, 1430877, 1990456, 12516863, 6892124, 3214315, 2944376, 4540745, 4559475, 0, 701052, 701053, 6196525, 7020058, 10041241, 5761530, 2940452, 6215144, 1142746, 0, 662374, 663083, 662611, 3210931, 1405105, 9320865, 2115266, 19469232, 10975017, 788940, 11812173, 4088377, 4227337, 12951275, 1098082, 5464155, 928767, 7204002, 30976754, 3454232, 647818, 8752297, 7841283, 1766107, 5931367, 586485};
array<bool, 56> USA::stateKennedys = {false, true, false, false, true, true, false, true, false, true, false, true, true, true, false, true, false, false, false, false, false, false, false, false, true, true, true, false, false, true, true, true, true, true, true, true, true, true, true, false, true, true, false, true, false, true, false, true, true, true, false, false, true, false, false, false};

string USA::nameFromCode(string code) {
    for(size_t i = 0; i < 56; ++i)
        if(stateCodes[i] == code)return stateNames[i];
    return " ";
}

string USA::codeFromName(string state_name) {
    for(size_t i = 0; i < 56; ++i)
        if(stateNames[i] == state_name)return stateCodes[i];
    return " ";
}

string USA::closingTimeFromCode(string code) {
    for(size_t i = 0; i < 56; ++i)
        if(stateCodes[i] == code)return stateClosingTimes[i];
    return " ";
}

char USA::previousWinnerFromCode(string code) {
    for(size_t i = 0; i < 56; ++i)
        if(stateCodes[i] == code)return statePreviousWinners[i];
    return ' ';
}

int USA::evFromCode(string code) {
    for(size_t i = 0; i < 56; ++i)
        if(stateCodes[i] == code)return stateEvs[i];
    return -1;
}

int USA::projNumFromCode(string code) {
    for(size_t i = 0; i < 56; ++i)
        if(stateCodes[i] == code)return stateProjNums[i];
    return -1;
}

int USA::populationFromCode(string code) {
    for(size_t i = 0; i < 56; ++i)
        if(stateCodes[i] == code)return statePopulations[i];
    return -1;
}

bool USA::kennedyFromCode(string code) {
    for(size_t i = 0; i < 56; ++i)
        if(stateCodes[i] == code)return stateKennedys[i];
    return false;
}