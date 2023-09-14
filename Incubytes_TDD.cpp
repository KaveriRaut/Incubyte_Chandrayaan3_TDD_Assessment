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

        // Function to move the spacecraft forward (position co-ordinates changes)
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

        // Function to move the spacecraft backward (position co-ordinates changes)
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

        // Function to turn the spacecraft right  (based on spaceCraft's right hand)
        void turnRight()
        {
            if (direction == 'N')
            {
                direction = 'E';
            }
            else if (direction == 'S')
            {
                direction = 'W';
            }
            else if (direction == 'E')
            {
                direction = 'S';
            }
            else if (direction == 'W')
            {
                direction = 'N';
            }
            else if (direction == 'U')
            {
                direction = 'S'; // Right turn while facing up becomes South
            }
            else if (direction == 'D')
            {
                direction = 'N'; // Right turn while facing down becomes North
            }
        }

        // Function to turn the spacecraft up (only direction changes)
        void turnUp()
        {
            // Implement upward turn logic to change the direction
            if (direction == 'N' || direction == 'S' || direction == 'E' || direction == 'W')
            {
                direction = 'U';
            }
            else if (direction == 'U')
            {
                // The spacecraft is already facing up
                // You can choose to handle this differently if needed
            }
            else if (direction == 'D')
            {
                direction = 'N'; // Assume facing North after turning up from down
            }
        }

        // Function to turn the spacecraft down
        void turnDown()
        {
            // Implement downward turn logic to change the direction
            if (direction == 'N' || direction == 'S' || direction == 'E' || direction == 'W')
            {
                direction = 'D';
            }
            else if (direction == 'D')
            {
                // The spacecraft is already facing down
                // You can choose to handle this differently if needed
            }
            else if (direction == 'U')
            {
                direction = 'N'; // Assume facing North after turning down from up
            }
        }

        // Function to get the current position and direction
        void getCurrentPositionAndDirection()
        {
            cout << "Position: (" << x << ", " << y << ", " << z << ") , ";
            cout << "Direction: " << direction << "\n";
            cout<<endl;
        }

        //stores the mapping of operation char to actual operation function
        void callOperations(vector<char>vec)
        {
            for(int i=0;i<vec.size();i++)
            {
                if(vec[i]=='f') 
                { 
                    this->moveForward();
                    this->getCurrentPositionAndDirection();
                }
                else if(vec[i]=='b') 
                { 
                    this->moveBackward();
                    this->getCurrentPositionAndDirection();
                }
                else if(vec[i]=='l') 
                {
                    this->turnLeft();
                    this->getCurrentPositionAndDirection();
                }
                else if(vec[i]=='r') 
                {
                    this->turnRight();
                    this->getCurrentPositionAndDirection();
                }
                else if(vec[i]=='u') 
                {
                    this->turnUp();
                    this->getCurrentPositionAndDirection();
                }
                else if(vec[i]=='d') 
                {
                    this->turnDown();
                    this->getCurrentPositionAndDirection();
                }
            }
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
    
    // // Tests for TurnLeft operation ----------------------------------------------------------

    // // Test 1: Turn Left when facing North
    chandrayaan3.turnLeft();
    cout<<"turnLeft: ";
    chandrayaan3.getCurrentPositionAndDirection(); // Expected: Position: (0, 0, 0), Direction: W

    // // Test 2: Turn Left again when facing West 
    chandrayaan3.turnLeft();
    cout<<"turnLeft: ";
    chandrayaan3.getCurrentPositionAndDirection(); // Expected: Position: (0, 0, 0), Direction: S
    
    // Tests for TurnRight operation ----------------------------------------------------------

    // // Test 1: Turn Right when facing North
    chandrayaan3.turnRight();
    cout<<"turnRight: ";
    chandrayaan3.getCurrentPositionAndDirection(); // Expected: Position: (0, 0, 0), Direction: E

    // // Test 2: Turn Right again when facing East 
    chandrayaan3.turnRight();
    cout<<"turnRight: ";
    chandrayaan3.getCurrentPositionAndDirection(); // Expected: Position: (0, 0, 0), Direction: S
    
    // Tests for TurnUp operation ----------------------------------------------------------

    // Test 1: Turn Up when facing North
    chandrayaan3.turnUp();
    cout<<"turnUp: ";
    chandrayaan3.getCurrentPositionAndDirection(); // Expected: Position: (0, 0, 0), Direction: U
    
    // Tests for TurnDown operation ----------------------------------------------------------

    // Test 1: Turn Down when facing North
    chandrayaan3.turnDown();
    cout<<"turnDown: ";
    chandrayaan3.getCurrentPositionAndDirection(); // Expected: Position: (0, 0, 0), Direction: D
}

void runGivenTest()
{
    // Initialize the spacecraft with a starting position and direction
    Spacecraft chandrayaan3(0, 0, 0, 'N'); 
    cout<<"Start Position: ";
    chandrayaan3.getCurrentPositionAndDirection(); // Input: Start Position: (0,0,0), Direction: N

    //Commands = {'f', 'r', 'u', 'b', 'l'};

    // Test 1: Move forward when facing Position: (0,0,0), Direction: N
    chandrayaan3.moveForward();
    cout<<"moveForward: ";
    chandrayaan3.getCurrentPositionAndDirection(); // Expected: Position: (0, 1, 0), Direction: N

    // Test 2: Turn Right when facing with Position: (0, 1, 0), Direction: N
    chandrayaan3.turnRight();
    cout<<"turnRight: ";
    chandrayaan3.getCurrentPositionAndDirection(); // Expected: Position: (0, 1, 0), Direction: E

    // Test 3: Turn Up when facing Position: (0, 1, 0), Direction: E
    chandrayaan3.turnUp();
    cout<<"turnUp: ";
    chandrayaan3.getCurrentPositionAndDirection(); // Expected: Position: (0, 1, 0), Direction: U
    
    // Test 4: Move backward when facing North
    chandrayaan3.moveBackward();
    cout<<"moveBackward: ";
    chandrayaan3.getCurrentPositionAndDirection(); // Expected: Position: (0, 1, -1), Direction: U

    // Test 5: Turn Left when facing North
    chandrayaan3.turnLeft();
    cout<<"turnLeft: ";
    chandrayaan3.getCurrentPositionAndDirection(); // Expected: Position: (0, 1, -1), Direction: N

    // Required Final Position: (0, 1, -1) , Direction: N
}

int main()
{
    // cout<<"runTests for each individual function testing: "<<endl;
    // runTests();
    // cout<<"//---------------------//"<<endl;
    // cout<<"runGivenTest for entire commands for spacecraft movements testing: "<<endl;
    // runGivenTest();
    //---------------------------------------------------------------------------//

    //----------------Complete Running Program with input/output from User------------//
    // Initialize the spacecraft with a starting position and direction
    int x,y,z;
    char dir;
    cout<<"Enter the current position co-ordinates and direction: ";
    cin>>x>>y>>z>>dir;
    Spacecraft chandrayaan3(x, y, z, dir); //0 0 0 N
    // Spacecraft chandrayaan3(0, 0, 0, 'N');

    // print current position and direction
    cout << "Current Position and Direction: " << endl;
    chandrayaan3.getCurrentPositionAndDirection();
    //---------------------------------------------------------------------------//


    //---------------------------------------------------------------------------//
    // Execute commands : Commands: ['f', 'r', 'u', 'b', 'l']
    int num_of_operations;
    cout<<"Enter number of operations want to perform: ";
    cin>>num_of_operations;
    cout<<"Enter the sequence of commands you want to execute on spacecraft: "; //f,b,l,r,u,d
    vector<char> operation_vec;
    char op;
    for(int i=0;i<num_of_operations;i++)
    {
        cin>>op;
        operation_vec.push_back(op);
    }
    chandrayaan3.callOperations(operation_vec);
    //---------------------------------------------------------------------------//
    
    // Get the final position and direction
    cout << "Final Position and Direction: " << endl;
    chandrayaan3.getCurrentPositionAndDirection();
    //---------------------------------------------------------------------------//
    return 0;
}
