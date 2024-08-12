#ifndef USA_H
#define USA_H

#include <array>
    using std::array;

#include <string>
    using std::string;

struct USA {
    static array<string,56> stateCodes;
    static array<string,56> stateNames;
    static array<string, 56> stateClosingTimes;
    static array<char, 56> statePreviousWinners;
    static array<int, 56> stateEvs;
    static array<int, 56> stateProjNums;
    static array<int, 56> statePopulations;
    static array<bool, 56> stateKennedys;
    
    static string nameFromCode(string code);
    static string codeFromName(string state_name);
    static string closingTimeFromCode(string code);
    static char previousWinnerFromCode(string code);
    static int evFromCode(string code);
    static int projNumFromCode(string code);
    static int populationFromCode(string code);
    static bool kennedyFromCode(string code);

};

#endif