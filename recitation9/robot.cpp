#include <iostream>
using namespace std;

class Robot {
    public:
        Robot(int start_x, int start_y, char start_heading) {
            x = start_x;
            y = start_y;
            heading = start_heading;
        }

        int getX() {
            return x;
        }

        int getY() {
            return y;
        }

        char getHeading() {
            return heading;
        }

        void setX(int new_x) {
            x = new_x;
        }

        void setY(int new_y) {
            y = new_y;
        }

        void setHeading(char new_heading) {
            heading = new_heading;
        }

        void turnLeft() {
            if (heading == 'N') {
                heading = 'W';
            }
        }

        void turnRight() {
            if (heading == 'N') {
                heading = 'E';
            }
            else if (heading == 'E') {
                heading = 'S';
            }
        }

        void moveForward() {
            if (heading == 'N') {
                y++;
            }
            else if (heading == 'S') {
                y--;
            }
        }

        int x;
        int y;
        char heading;
};
