#include <iostream>
#include <map>
#include <string>

class stateMap {
public:
    std::string get_input() {
        std::string state;
        std::cout << "Enter a state name: ";
        std::getline(std::cin, state);
        std::cout << '\n';
        for (char c : state)
            c = std::tolower(c);
        return state;
    }

    void find_city(std::string state) {
        auto it = states.find(state);
        if (it != states.end()) {
            std::cout << "The capital of " << state << " is " << it->second << std::endl;
        } else {
            std::cout << "State not found in the map." << std::endl;
        }
    }
private:
    std::map<std::string, std::string> states = {
        { "alabama"       , "Montgomery"     },
        { "alaska"        , "Juneau"         },
        { "arizona"       , "Phoenix"        },
        { "arkansas"      , "Little Rock"    },
        { "california"    , "Sacramento"     },
        { "colorado"      , "Denver"         },
        { "connecticut"   , "Hartford"       },
        { "delaware"      , "Dover"          },
        { "florida"       , "Tallahassee"    },
        { "georgia"       , "Atlanta"        },
        { "hawaii"        , "Honolulu"       },
        { "idaho"         , "Boise"          },
        { "illinois"      , "Springfield"    },
        { "indiana"       , "Indianapolis"   },
        { "iowa"          , "Des Moines"     },
        { "kansas"        , "Topeka"         },
        { "kentucky"      , "Frankfort"      },
        { "louisiana"     , "Baton Rouge"    },
        { "maine"         , "Augusta"        },
        { "maryland"      , "Annapolis"      },
        { "massachusetts" , "Boston"         },
        { "michigan"      , "Lansing"        },
        { "minnesota"     , "Saint Paul"     },
        { "mississippi"   , "Jackson"        },
        { "missouri"      , "Jefferson City" },
        { "montana"       , "Helena"         },
        { "nebraska"      , "Lincoln"        },
        { "nevada"        , "Carson City"    },
        { "new hampshire" , "Concord"        },
        { "new jersey"    , "Trenton"        },
        { "new mexico"    , "Santa Fe"       },
        { "new york"      , "Albany"         },
        { "north carolina", "Raleigh"        },
        { "north dakota"  , "Bismarck"       },
        { "ohio"          , "Columbus"       },
        { "oklahoma"      , "Oklahoma City"  },
        { "oregon"        , "Salem"          },
        { "pennsylvania"  , "Harrisburg"     },
        { "rhode island"  , "Providence"     },
        { "south carolina", "Columbia"       },
        { "south dakota"  , "Pierre"         },
        { "tennessee"     , "Nashville"      },
        { "texas"         , "Austin"         },
        { "utah"          , "Salt Lake City" },
        { "vermont"       , "Montpelier"     },
        { "virginia"      , "Richmond"       },
        { "washington"    , "Olympia"        },
        { "west virginia" , "Charleston"     },
        { "wisconsin"     , "Madison"        },
        { "wyoming"       , "Cheyenne"       }
    };
};
int main() {
    stateMap city_finder;
    std::string state;
    do {
        state = city_finder.get_input();
        city_finder.find_city(state);
    } while (state != "-1");
}

