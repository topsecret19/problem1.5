//Marawan El Sharkawi
//CSCI 301-Section 1
//#cs301175
//Project 3

/*
    Recursion is a technique in programming which allows a function to call itself. It is one of the ways to make repeated
computations. A recursive function passes a smaller version of the problem to a new function of itself then it uses the results
returned from all the functions it has called to determine the solution of the main problem. This program reads a maze from a
file displays it then find paths from its start to its end using recursion.

    The program uses three data structures:
•Two integers variables called “r” and “c”, these two integers hold the numbers of rows and columns of the maze respectively
being read from the file contains the maze.

•Three char variables, one called “lineEnd” to hold the character at the end of the line to start reading a new line.
The second called “space “which the program uses to print a blank space whenever there is no walls in the maze. And the third one
is called “path” the program uses it to print a dot whenever there is a path that solves the maze.

•A two-dimensional array called “maze”, this array holds very character read from the file, rows of the maze in one of its
 dimensions and columns in the other dimension. A program constant sets the maximum value of the numbers of rows and columns of
 the maze the program can read and find a path through.

    The program uses four functions:
•openFile() , it takes ifstream which is a stream class to read from the file contains the maze as a parameter and its being
passed by reference. The function asks the user to input the name of the file contains the maze to open it, if the name of the
file does not exist or the user entered a false file name the function keep asking the user to enter the name of the file until
the users enters a correct file name.

•readFile(),  it takes ifstream parameter, maze two dimensional array, and two integer variables passed by reference to refer
to the number of rows and columns of the maze. The function reads the number of rows and columns of the maze from the opened file,
 saves the characters of each row and column of the maze into the two-dimensional array.

•display(), it takes maze two dimensional array, and two integer variables to refer to the number of rows and columns of the
maze, the functions prints out the characters saved into the two dimensional array which are the maze read from the file.

•pathFinder(), it takes maze two dimensional array, two integer variables to refer to the dimensions of the start position of
the maze and two integer variables to refer to the number of rows and columns of the maze. The function finds all the possible
paths from the start position of the maze till the end position, prints a space whenever there are no walls and prints a dot
wherever there is a path that will lead to the end of the maze, the function find the paths using recursion technique.

    The program creates an ifstream variable for the file the user will input, two integer variables one to hold the number of the
rows of the maze and the other to hold the number of columns of the maze, and a maze two-dimensional array. The program then calls
the openFile() function and passes the ifstream variable as its parameters then calls readFile() function and passes the ifstream
variable, the maze variable and the two integer variables as its parameters. Next, the program closes the file contains the maze
after the readFile() function is done with its work, after that it calls display() function and passes the maze variable and
the two integer variables as its parameters. The final step is to assign the dimension of the start position of the maze
through the two-dimensional array then to call the pathFinder() function which will find the paths through the maze and
print out the maze with the paths found.

*/


#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const char space = ' '; //char variable used by the program to print blank spaces.
const char path = '.'; //char variable used by the program to print dots.
const int max_rows = 22; // Maximum number of rows in a maze is 22.
const int max_cols=76;   //Maximum number of columns in a maze is 76.


typedef char maze[max_rows][max_cols]; //maze two dimensional array that gets big as the maze.

void openFile (ifstream &File) //File represents a file that contains the maze will be opened to get ready to be read.
                                // Post-condition: A file named by the used has been opened and ready to be read.
{
string file; //prepare a string to save the name of the file the user will input.
  do
  { cout << "Enter the name of the file contains the maze: ";
    cin >> file; //Take the user input.
    File.open(file.c_str()); //open the file the user has entered its name.
  } while (File.fail()); //Ask the user to enter the name of the file if there is no such file found.
}

void readFile(ifstream &file, maze m, int &rows, int &cols) //file represents a file opened that contains the maze.
    // Post-condition: The two-dimensional array m[][] contains the maze rows and columns including the walls the spaces. And the
    //maze rows and columns have been returned in the parameters rows and cols.
{
  int r, c;
  char lineEnd;

  file >> r; //read the number of rows of the maze from the file.
  file >> c; //read the number of columns of the maze from the file.
  file.get(lineEnd); //Get the end of the line to start reading a new line.

  for ( int i=0; i<r; ++i )
  {
    for ( int j=0; j<c; ++j )
      file.get(m[i][j]); //get the characters in the line and save them in the two dimensional array accordingly
    file.get(lineEnd); //get the end of the line and start reading a new line.
  }
  rows = r; //rows of the maze equal the number the program read at the beginning of the file.
  cols = c; //columns of the maze equal the number the program read at the beginning of the file.
}

void display (maze m, int rows, int cols) //The two-dimensional array m[][] holds the representation of a maze.
                                        //Post-condition: The maze representation printed out.
{
  for (int i=0; i<rows; ++i)
  {
    for (int j=0; j<cols; ++j)
      cout << m[i][j];
    cout << endl;
  }
  cout << endl;
}

bool pathFinder(maze m, int r, int c, int rows, int cols) //The two-dimensional array m[][] holds the representation of a maze.
//The path has reached position (r,c) which is the start position of the maze and printed dot.

// Post-condition: All the paths to get out of the maze and maze itself have been printed out.
{
  if (r == rows - 1) //if the path reached point where r equals the number of rows minus one, display the maze and path found
                    //It is is base condition.
    {
    display(m, rows, cols);
    return true;
  }
  else {
    if (r > 0 && m[r - 1][c] == space) //Move upwards,If r bigger than zero and the character found in the
                                //dimension of the point in the two dimensional array m[r-1][c] is a space print a dot there.
    {
      m[r - 1][c] = path;
      if(pathFinder(m, r - 1, c, rows, cols)){ //apply recursion to the function with the new dimensions.
        return true;
      }
      m[r - 1][c] = path; //if the same condition met again print a dot in the blank space.
    }
    if (m[r + 1][c] == space) //Move downwards,If r bigger than zero and the character found in the
                                //dimension of the point in the two dimensional array m[r+1][c] is a space print a dot there.
    {
      m[r + 1][c] = path;
      if(pathFinder(m, r + 1, c, rows, cols)) { //apply recursion to the function with the new dimensions.
        return true;
      }
      m[r + 1][c] = path; //if the same condition met again print a dot in the blank space.
    }
    if (m[r][c - 1] == space) //Move left,If the character found in the dimension of the point in the two dimensional
                            //array m[r][c-1] is a space print a dot there.
    {
      m[r][c - 1] = path;
      if(pathFinder(m, r, c - 1, rows, cols)) { //apply recursion to the function with the new dimensions.
        return true;
      }
      m[r][c - 1] = path; //if the same condition met again print a dot in the blank space.
    }
    if (m[r][c + 1] == space) //Move right,If the character found in the dimension of the point in the two dimensional
                            //array m[r][c+1] is a space print a dot there.
    {
      m[r][c + 1] = path;
      if(pathFinder(m, r, c + 1, rows, cols)) { //apply recursion to the function with the new dimensions.
        return true;
      }
      m[r][c + 1] = path; //if the same condition met again print a dot in the blank space.
    }
  }
  return false; //if anything else other than the above conditions happened return false.
}

int main(){


 ifstream File; //prepare a variable to be the file the program will read.
  int rows, cols; //The number of rows and columns of the maze.
  maze m; //prepare a two dimensional array to hold the maze characters.

  openFile(File); //open the file contains the maze.
  readFile(File, m, rows, cols); //read the file contains the maze
  File.close(); //close the file contains the maze after finishing reading it.
  cout<<"Maze display: "<<endl;
  display(m,rows,cols); //print out the maze.

  cout<<"Maze path found: "<<endl;
    m[0][1] = path; //set the start position of the maze.
  pathFinder(m,0,1,rows,cols); //find all the possible paths from the start to the end position of the maze and print them out.

return 0;
}

