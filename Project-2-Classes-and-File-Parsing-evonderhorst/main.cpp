// Author: Erich Vonderhorst
// Creation Date: 11/2/2023
// Last Update: 11/3/2023
// Description: reads in the personal data of NBA and NFL players from two csv files. The data is stored into
//              an instance of a type corresponding to which sport the player in question is associated with
//              which is then placed into a vector of pointers to the base type Person and then displayed. The
//              vector is then sorted by the players' names and displayed a second time as sorted. Lastly, the
//              players above 6'11" and 350 lbs. and the oldest and youngest players are determined and
//              displayed.

#include "Person.h" // base type for NBA and NFL players
#include "NBAPlayer.h" // for storing NBA players' data
#include "NFLPlayer.h" // for storing NFL players' data
#include <fstream>  // for reading the csv files
#include <vector> // for storing the data of all players

using namespace std;

// Prototypes
void loadNBADataFile(string, vector<Person*>&);
void loadNFLDataFile(string, vector<Person*>&);
void print(vector<Person*>&);
void sortByName(vector<Person*>&);
void sortByHeight(vector<Person*>&);
void sortByWeight(vector<Person*>&);
void sortByAge(vector<Person*>&);

//=============================================================================================================
// Main
//=============================================================================================================
int main() {

    vector<Person*> PlayerInfo; // holds all instances of NFLPlayer and NBAPlayer made for each player listed in the files

    // Parse both files and add player instances to vector
    loadNBADataFile("NBA.csv", PlayerInfo);
    loadNFLDataFile("NFL.csv", PlayerInfo);
    // loadNFLDataFile("BONUS.csv", PlayerInfo); <- Just for fun.

    // Output unsorted data
    cout << "Number of players in files: " << to_string(PlayerInfo.size()) << endl << endl;
    print(PlayerInfo);

    // Output sorted data
    sortByName(PlayerInfo);
    cout << endl << "-------------------------------------------------------------------------------" << endl;
    cout << "Sorted Player List" << endl;
    cout << "-------------------------------------------------------------------------------"  << endl << endl;
    print(PlayerInfo);

    // Find and display players with height values above 6'11"
    vector<Person*> TallPlayers;
    for (int i = 0; i < PlayerInfo.size(); i++) {
        if (PlayerInfo[i]->getHeight() > FeetInches(7) || PlayerInfo[i]->getHeight() == FeetInches(7))
            TallPlayers.push_back(PlayerInfo[i]);
    }
    sortByHeight(TallPlayers);
    print(TallPlayers);
    cout << endl << "Number of players over 6 feet, 11 inches = " << to_string(TallPlayers.size()) << endl << endl;

    // Find and display players with weight values above 350 lbs.
    vector<Person*> BigPlayers;
    for (int i = 0; i < PlayerInfo.size(); i++) {
        if (PlayerInfo[i]->getWeight() > 350)
            BigPlayers.push_back(PlayerInfo[i]);
    }
    sortByWeight(BigPlayers);
    print(BigPlayers);
    cout << endl << "Number of players over 350 lbs. = " << to_string(BigPlayers.size()) << endl << endl;

    // Find and display the player(s) with the greatest height value
    vector<Person*> TallestPlayers;
    sortByHeight(PlayerInfo);
    for (int i = 0; i < PlayerInfo.size(); i++) {
        if (PlayerInfo[i]->getHeight() == PlayerInfo[PlayerInfo.size() - 1]->getHeight())
            TallestPlayers.push_back(PlayerInfo[i]);
    }
    cout << endl << "Tallest Player List" << endl;
    sortByName(TallestPlayers);
    print(TallestPlayers);

    // Find and display the player(s) with the earliest date of birth
    vector<Person*> OldestPlayers;
    sortByAge(PlayerInfo);
    // Disregard all of the dates with default values (missing date in the csv file)
    int invalidDOBs = 0;
    for (int i = 0; i < PlayerInfo.size(); i++) {
        if (PlayerInfo[i]->getDOB() == Date(0,0,0))
            invalidDOBs++;
    }
    for (int i = 0; i < PlayerInfo.size(); i++) {
        if (PlayerInfo[i]->getDOB() == PlayerInfo[PlayerInfo.size() - invalidDOBs - 1]->getDOB())
            OldestPlayers.push_back(PlayerInfo[i]);
    }
    cout << endl << "Oldest Player List" << endl;
    sortByName(OldestPlayers);
    print(OldestPlayers);

    // Find and display the player(s) with the latest date of birth
    vector<Person*> YoungestPlayers;
    sortByAge(PlayerInfo);
    for (int i = 0; i < PlayerInfo.size(); i++) {
        if (PlayerInfo[i]->getDOB() == PlayerInfo[0]->getDOB())
            YoungestPlayers.push_back(PlayerInfo[i]);
    }
    cout << endl << "Youngest Player List" << endl;
    sortByName(YoungestPlayers);
    print(YoungestPlayers);

    // Deallocate all used memory
    for (int i = 0; i < PlayerInfo.size(); i++)
        delete PlayerInfo[i];

    return 0;
}

//=============================================================================================================
// Free Functions
//=============================================================================================================

// Description: parses the data for all of the NBA players listed in the csv file with the passed name, creates
//              NBAPlayer objects using the parsed data, and places them into the passed vector
void loadNBADataFile(string filename, vector<Person*>& players) {
    string line = ""; // holds each line read in from the file for parsing

    // Variables for all the data to be acquired per line
    string firstName;
    string lastName;
    FeetInches height;
    double weight;
    Date dob;
    int number;
    string position;

    int seperator = 0; // location of the comma's seperating values in the file: used for parsing

    // Open the file, read in and ignore the header line
    ifstream read;
    read.open(filename);
    getline(read, line);

    // While the file still has lines with data...
    while (!read.eof()) {
        // Read in a line
        getline(read, line);

        // Find the location of the first comma, create a substring from the start if the line to it,
        // assign the substring to the relevant variable
        seperator = line.find(',');
        lastName = line.substr(0, seperator);

        // Delete what has already been parsed to help simplify the rest of the process,
        line.erase(0, seperator + 1);
        // Repeat for all pieces of data
        seperator = line.find(',');
        firstName = line.substr(0, seperator);

        line.erase(0, seperator + 1);
        seperator = line.find(',');
        try {
            number = stoi(line.substr(0, seperator));
        } catch (exception& e) {
            number = 0;
        }

        line.erase(0, seperator + 1);
        seperator = line.find(',');
        position = line.substr(0, seperator);

        line.erase(0, seperator + 1);
        seperator = line.find(',');
        height.setLength(line.substr(0, seperator));

        line.erase(0, seperator + 1);
        seperator = line.find(',');
        try {
            weight = stod(line.substr(0, seperator));
        } catch (exception& e) {
            weight = 0.0;
        }

        dob.setMDY(line.substr(seperator + 1));

        // Initialize a new instance of NBAPlayer using all of the variables that data was just parsed for,
        // push it to the back of the passed vector
        players.push_back(new NBAPlayer(firstName, lastName, height, weight, dob, number, position));
    }

    // Delete and pop the last element because an instance composed entirely of default values made instances
    // way onto the end somehow
    delete players.back();
    players.pop_back();
}

// Description: parses the data for all of the NFL players listed in the csv file with the passed name, creates
//              NFLPlayer objects using the parsed data, and places them into the passed vector
// Notes: functions nearly identical to the parsing function for NBA players but the data is parsed in a
//        different order and one more piece of data is included (team)
void loadNFLDataFile(string filename, vector<Person*>& players) {
    string line = "";

    string firstName;
    string lastName;
    FeetInches height;
    double weight;
    Date dob;
    int number;
    string position;
    string team;

    int seperator = 0;
    ifstream read;
    read.open(filename);
    getline(read, line);

    while (!read.eof()) {
        getline(read, line);

        seperator = line.find(',');
        try {
            number = stoi(line.substr(0, seperator));
        } catch (exception& e) {
            number = 0;
        }

        line.erase(0, seperator + 2);
        seperator = line.find(',');
        lastName = line.substr(0, seperator);

        line.erase(0, seperator + 1);
        seperator = line.find('"');
        firstName = line.substr(0, seperator);

        line.erase(0, seperator + 2);
        seperator = line.find(',');
        position = line.substr(0, seperator);

        line.erase(0, seperator + 1);
        seperator = line.find(',');
        height.setLength("'" + line.substr(0, seperator) + '"');

        line.erase(0, seperator + 1);
        seperator = line.find(',');
        try {
            weight = stod(line.substr(0, seperator));
        } catch (exception& e) {
            weight = 0.0;
        }

        line.erase(0, seperator + 1);
        seperator = line.find(',');
        dob.setMDY(line.substr(0, seperator));

        team = line.substr(seperator + 1);

        players.push_back(new NFLPlayer(firstName, lastName, height, weight, dob, number, position, team));
    }
}

// Description: prints the data for each Person in the passed vector
void print(vector<Person*>& players) {
    for (int i = 0; i < players.size(); i++)
        cout << players[i]->toString() << endl;
}

// Description: sorts the Persons in the passed vector by their names in lexicographical order
// Notes: uses selection sort
void sortByName(vector<Person*>& players) {
    int min;

    for (int i = 0; i < players.size() - 1; i++) {

        min = i;
        for (int j = i + 1; j < players.size(); j++) {
            if (players[j]->getFormalName() < players[min]->getFormalName())
                min = j;
        }

        if (min != i) {
            Person* temp = players[i];
            players[i] = players[min];
            players[min] = temp;
        }
    }
}

// Description: sorts the Person in the passed vector by their height values in ascending order
// Notes: uses selection sort// Notes: uses selection sort
void sortByHeight(vector<Person*>& players) {
    int min;

    for (int i = 0; i < players.size() - 1; i++) {

        min = i;
        for (int j = i + 1; j < players.size(); j++) {
            if (players[j]->getHeight() < players[min]->getHeight())
                min = j;
        }

        if (min != i) {
            Person* temp = players[i];
            players[i] = players[min];
            players[min] = temp;
        }
    }
}

// Description: sorts the Persons in the passed vector by their weight values in ascending order
// Notes: uses selection sort
void sortByWeight(vector<Person*>& players) {
    int min;

    for (int i = 0; i < players.size() - 1; i++) {

        min = i;
        for (int j = i + 1; j < players.size(); j++) {
            if (players[j]->getWeight() < players[min]->getWeight())
                min = j;
        }

        if (min != i) {
            Person* temp = players[i];
            players[i] = players[min];
            players[min] = temp;
        }
    }
}

// Description: sorts the Persons in the passed vector by their dates of birth in descending order
// Notes: uses selection sort
void sortByAge(vector<Person*>& players) {
    int min;

    for (int i = 0; i < players.size() - 1; i++) {

        min = i;
        for (int j = i + 1; j < players.size(); j++) {
            if (players[j]->getDOB() > players[min]->getDOB())
                min = j;
        }

        if (min != i) {
            Person* temp = players[i];
            players[i] = players[min];
            players[min] = temp;
        }
    }
}
