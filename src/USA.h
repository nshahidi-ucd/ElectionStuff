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
    constexpr static array<char, 56> statePreviousWinners =  {'R', 'R', 'D', 'R', 'D', 'D', 'D', 'D', 'D', 'R', 'D', 'D', 'R', 'D', 'R', 'R', 'R', 'R', 'R', 'D', 'D', 'R', 'D', 'D', 'D', 'D', 'R', 'R', 'R', 'R', 'R', 'D', 'R', 'D', 'D', 'D', 'D', 'D', 'R', 'R', 'R', 'R', 'D', 'D', 'D', 'R', 'R', 'R', 'R', 'R', 'D', 'D', 'D', 'R', 'D', 'R'};
    constexpr static array<int, 56> stateEvs = {9, 3, 11, 6, 54, 10, 7, 3, 3, 30, 16, 4, 4, 19, 11, 6, 6, 8, 8, 2, 1, 1, 10, 11, 15, 10, 6, 10, 4, 2, 1, 1, 1, 6, 4, 14, 5, 28, 16, 3, 17, 7, 8, 19, 4, 9, 3, 11, 40, 6, 3, 13, 12, 4, 10, 3};
    constexpr static array<int, 56> stateProjNums = {99, 75, 50, 99, 1, 29, 17, 14, 0, 77, 53, 8, 99, 11, 97, 91, 95, 99, 99, 38, 9, 80, 1, 1, 49, 47, 98, 92, 90, 93, 82, 44, 99, 52, 45, 79, 38, 19, 56, 99, 70, 99, 28, 50, 14, 83, 99, 96, 82, 91, 1, 40, 20, 99, 50, 99};
    constexpr static array<int, 56> statePopulations = {5143033, 733536, 7497004, 3089060, 38889770, 5914181, 3625646, 1044321, 678972, 22975931, 11145304, 1430877, 1990456, 12516863, 6892124, 3214315, 2944376, 4540745, 4559475, 0, 701052, 701053, 6196525, 7020058, 10041241, 5761530, 2940452, 6215144, 1142746, 0, 662374, 663083, 662611, 3210931, 1405105, 9320865, 2115266, 19469232, 10975017, 788940, 11812173, 4088377, 4227337, 12951275, 1098082, 5464155, 928767, 7204002, 30976754, 3454232, 647818, 8752297, 7841283, 1766107, 5931367, 586485};
    constexpr static array<bool, 56> stateKennedys = {false, true, false, false, true, true, false, true, false, true, false, true, true, true, false, true, false, false, false, false, false, false, false, false, true, true, true, false, false, true, true, true, true, true, true, true, true, true, true, false, true, true, false, true, false, true, false, true, true, true, false, false, true, false, false, false};
    
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