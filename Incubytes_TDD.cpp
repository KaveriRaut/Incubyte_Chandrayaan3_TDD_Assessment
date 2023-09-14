#include <iostream>
#include<vector>
using namespace std;

// Class SpaceCraft having position (x,y,z) and direction (N, S, E, W, Up, Down)
class Spacecraft
{

    private:
        // position co-ordinates(x,y,z), direction of spaceCraft in space
        int x;
        int y;
        int z;
        char direction;

    public:
        // Constructor to initialize the spacecraft's position co-ordinates and direction
        Spacecraft(int startX, int startY, int startZ, char startDirection)
        {
            x = startX;
            y = startY;
            z = startZ;
            direction = startDirection;
        }

        // NOTE: During movement in position co-ordinate
        // x co-ordinates changes => for East , West direction
        // y co-ordinates changes => for North , South direction
        // z co-ordinates changes => for Up , Down turn

        // Function to move the spacecraft forward
        void moveForward()
        {
            if (direction == 'N')
            {
                y++;
            }
            else if (direction == 'S')
            {
                y--;
            }
            else if (direction == 'E')
            {
                x++;
            }
            else if (direction == 'W')
            {
                x--;
            }
            else if (direction == 'U')
            {
                z++;
            }
            else if (direction == 'D')
            {
                z--;
            }
        }

        // Function to move the spacecraft backward
        void moveBackward()
        {
            // Implement backward movement similar to forward movement but in the opposite direction
            if (direction == 'N')
            {
                y--;
            }
            else if (direction == 'S')
            {
                y++;
            }
            else if (direction == 'E')
            {
                x--;
            }
            else if (direction == 'W')
            {
                x++;
            }
            else if (direction == 'U')
            {
                z--;
            }
            else if (direction == 'D')
            {
                z++;
            }
        }

        // Function to turn the spacecraft left (based on spaceCraft's left hand)
        void turnLeft()
        {
            if (direction == 'N')
            {
                direction = 'W';
            }
            else if (direction == 'S')
            {
                direction = 'E';
            }
            else if (direction == 'E')
            {
                direction = 'N';
            }
            else if (direction == 'W')
            {
                direction = 'S';
            }
            else if (direction == 'U')
            {
                direction = 'N'; // Left turn while facing up becomes North
            }
            else if (direction == 'D')
            {
                direction = 'S'; // Left turn while facing down becomes South
            }
        }

        // Function to get the current position and direction
        void getCurrentPositionAndDirection()
        {
            cout << "Position: (" << x << ", " << y << ", " << z << ") , ";
            cout << "Direction: " << direction << "\n";
            cout<<endl;
        }

};


// Function to run tests for the Spacecraft class
void runTests()
{
    // Initialize the spacecraft with a starting position and direction
    Spacecraft chandrayaan3(0, 0, 0, 'N'); 
    cout<<"Start Position: ";
    chandrayaan3.getCurrentPositionAndDirection(); // Input: Start Position: (0,0,0), Direction: N

    // Tests for MoveForward operation ----------------------------------------------------------
    
    // Test 1: Move forward when facing North
    chandrayaan3.moveForward();
    cout<<"moveForward: ";
    chandrayaan3.getCurrentPositionAndDirection(); // Expected: Position: (0, 1, 0), Direction: N

    // Test 2: Move forward again when facing North 
    chandrayaan3.moveForward();
    cout<<"moveForward: ";
    chandrayaan3.getCurrentPositionAndDirection(); // Expected: Position: (0, 2, 0), Direction: N
    
    // Tests for MoveBackword operation ----------------------------------------------------------

    // Test 1: Move backward when facing North
    chandrayaan3.moveBackward();
    cout<<"moveBackward: ";
    chandrayaan3.getCurrentPositionAndDirection(); // Expected: Position: (0, 1, 0), Direction: N

    // Test 2: Move backward again when facing North 
    chandrayaan3.moveBackward();
    cout<<"moveBackward: ";
    chandrayaan3.getCurrentPositionAndDirection(); // Expected: Position: (0, 0, 0), Direction: N
    
    // Tests for TurnLeft operation ----------------------------------------------------------

    // Test 1: Turn Left when facing North
    chandrayaan3.turnLeft();
    cout<<"turnLeft: ";
    chandrayaan3.getCurrentPositionAndDirection(); // Expected: Position: (0, 0, 0), Direction: W

    // Test 2: Turn Left again when facing North 
    chandrayaan3.turnLeft();
    cout<<"turnLeft: ";
    chandrayaan3.getCurrentPositionAndDirection(); // Expected: Position: (0, 0, 0), Direction: S
}

int main()
{
    runTests();
    return 0;
}
