#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

namespace Generator {

    int getRand(int max_rand);

    string generatePassword(int len, bool nums, bool specialchars, bool rcap) {
        
        srand(time(NULL))

        // lists of random chars for better generating
        // std_chars dosent go all the way to z beacuse i was lazy
        char std_chars[16] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'};
        char spc_chars[4] = {'!', '@', '#', '$'};

        string pass;

        int loop;

        while (loop < len) {

            int randChoice = getRand(3);
            bool actionPerfomed = false;

            if (randChoice == 1) {

                if (rcap) {
                    pass = pass + std_chars[toupper(getRand(sizeof(std_chars)))];

                } else {
                    pass = pass + std_chars[getRand(sizeof(std_chars))];

                }

                actionPerfomed = true;

            } else if (randChoice == 2 && nums) {
                pass = pass + to_string(getRand(9));
                actionPerfomed = true;

            } else if (randChoice == 3 && specialchars) {
                pass = pass + spc_chars[getRand(sizeof(spc_chars))];

            }

            if (actionPerfomed) {
                loop++;
            }

        }

        return pass;

    }

    int getRand(int max_rand) {

        int prev_output = NULL;

        // Filters reapeating ints
        while (rand() % max_rand + 1 == prev_output) {
            // wait
        }

        prev_output = rand() % max_rand + 1;
        return rand() % max_rand + 1;

    }

}
