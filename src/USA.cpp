#include "USA.h"
#include <string>
    using std::string;
#include <array>
    using std::array;

array<string, 56> USA::stateCodes = {"AL", "AK", "AZ", "AR", "CA", "CO", "CT", "DE", "DC", "FL", "GA", "HI", "ID", "IL", "IN", "IA", "KS", "KY", "LA", "ME", "M1", "M2", "MD", "MA", "MI", "MN", "MS", "MO", "MT", "NE", "N1", "N2", "N3", "NV", "NH", "NJ", "NM", "NY", "NC", "ND", "OH", "OK", "OR", "PA", "RI", "SC", "SD", "TN", "TX", "UT", "VT", "VA", "WA", "WV", "WI", "WY"};
array<string, 56> USA::stateNames = {"Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "District of Columbia", "Florida", "Georgia", "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maine\'s 1st", "Maine\'s 2nd", "Maryland", "Massachussetts", "Michigan", "Minnesota", "Mississippi", "Missouri", "Montana", "Nebraska", "Nebraska\'s 1st", "Nebraska\'s 2nd", "Nebraska\'s 3rd", "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York", "North Carolina", "North Dakota", "Ohio", "Oklahoma", "Oregon", "Pennsylvania", "Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah", "Vermont", "Virgina", "Washington", "West Virginia", "Wisconsin", "Wyoming"};
array<string, 56> USA::stateClosingTimes = {"6:00 PM", "11:00 PM", "7:00 PM", "6:30 PM", "9:00 PM", "7:00 PM", "6:00 PM", "6:00 PM", "6:00 PM", "6:00 PM", "5:00 PM", "9:00 PM", "9:00 PM", "6:00 PM", "5:00 PM", "8:00 PM", "7:00 PM", "5:00 PM", "7:00 PM", "6:00 PM", "6:00 PM", "6:00 PM", "6:00 PM", "6:00 PM", "7:00 PM", "7:00 PM", "6:00 PM", "6:00 PM", "8:00 PM", "7:00 PM", "7:00 PM", "7:00 PM", "7:00 PM", "8:00 PM", "6:00 PM", "6:00 PM", "7:00 PM", "7:00 PM", "5:30 PM", "7:00 PM", "5:30 PM", "6:00 PM", "9:00 PM", "6:00 PM", "6:00 PM", "5:00 PM", "7:00 PM", "6:00 PM", "7:00 PM", "8:00 PM", "5:00 PM", "5:00 PM", "9:00 PM", "5:30 PM", "7:00 PM", "7:00 PM"};

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