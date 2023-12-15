#include <iostream>
#include <stack>
#include <set>
#include <cfloat>
#include <cstring>
#include <cmath>
#define ROW 10
#define COL 10

typedef std::pair<int,int> Pair;
typedef std::pair<double,Pair> pPair;


struct cell{
    int parent_i, parent_j;

    double f, g, h;
};

// Used to check whether the cell has valid coordinates
bool isValid(int row, int column){
    return (row >= 0 && row < ROW && column >= 0 && column< COL);
}

// Used to check whether the selected cell is blocked

 
//Function to check whether the cell is blocked or not
bool isUnblocked(int grid[][COL], int row, int column)
{

    if (grid[row][column] == 1)
        return true;
    else
        return false;
}
 
// A Utility Function to check whether destination cell has
// been reached or not
bool isDestination(int row, int column, Pair destination)
{
    if (row == destination.first && column == destination.second)
        return (true);
    else
        return (false);
}
 
// A Utility Function to calculate the 'h' heuristics.
double calculateHValue(int row, int column, Pair dest)
{
    // Return using the distance formula
    return ((double)sqrt(
        (row - dest.first) * (row - dest.first)
        + (column - dest.second) * (column - dest.second)));
}
 
// A Utility Function to trace the path from the source
// to destination
void tracePath(cell cellDetails[][COL], Pair dest)
{
    printf("\nThe Path is ");
    int row = dest.first;
    int column = dest.second;
 
    std::stack<Pair> Path;
 
    while (!(cellDetails[row][column].parent_i == row
             && cellDetails[row][column].parent_j == column)) {
        Path.push(std::make_pair(row, column));
        int temp_row = cellDetails[row][column].parent_i;
        int temp_column = cellDetails[row][column].parent_j;
        row = temp_row;
        column = temp_column;
    }
 
    Path.push(std::make_pair(row, column));
    while (!Path.empty()) {
        std::pair<int, int> p = Path.top();
        Path.pop();
        printf("-> (%d,%d) ", p.first, p.second);
    }
 
    return;
}
 
// A Function to find the shortest path between
// a given source cell to a destination cell according
// to A* Search Algorithm
void AStarAlgorithm(int grid[][COL], Pair src, Pair dest)
{
    // If the source is out of range
    if (isValid(src.first, src.second) == false) {
        printf("Source is invalid\n");
        return;
    }
 
    // If the destination is out of range
    if (isValid(dest.first, dest.second) == false) {
        printf("Destination is invalid\n");
        return;
    }
 
    // Either the source or the destination is blocked
    if (isUnblocked(grid, src.first, src.second) == false
        || isUnblocked(grid, dest.first, dest.second)
               == false) {
        printf("Source or the destination is blocked\n");
        return;
    }
 
    // If the destination cell is the same as source cell
    if (isDestination(src.first, src.second, dest)
        == true) {
        printf("We are already at the destination\n");
        return;
    }
 
    // Closed list tells us which cells are already included
    bool closedList[ROW][COL];
    memset(closedList, false, sizeof(closedList));
 
    // Declare a 2D array of structure to hold the details
    // of that cell
    cell cellInfo[ROW][COL];
 
    int i, j;
 
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            cellInfo[i][j].f = FLT_MAX;
            cellInfo[i][j].g = FLT_MAX;
            cellInfo[i][j].h = FLT_MAX;
            cellInfo[i][j].parent_i = -1;
            cellInfo[i][j].parent_j = -1;
        }
    }
 
    // Initialising the parameters of the starting node
    i = src.first, j = src.second;
    cellInfo[i][j].f = 0.0;
    cellInfo[i][j].g = 0.0;
    cellInfo[i][j].h = 0.0;
    cellInfo[i][j].parent_i = i;
    cellInfo[i][j].parent_j = j;
 
    
     //Create an open list having information as <f, <i, j>>
     // f = g + h, i = row, j = column of the selected cell
    std::set<pPair> openList;
 
    //put starting cell into open list and initialize f as 0.0
    openList.insert(std::make_pair(0.0, std::make_pair(i, j)));
 
    //boolean value for checking whether we reached destination
    bool foundDest = false;
 
    while (!openList.empty()) {
        pPair p = *openList.begin();
 
        // Remove this vertex from the open list
        openList.erase(openList.begin());
 
        // Add this vertex to the closed list
        i = p.second.first;
        j = p.second.second;
        closedList[i][j] = true;
 
        
        // To store the 'g', 'h' and 'f' of the 8 successors
        double gNew, hNew, fNew;
 
        //----------- North ------------
 
        // Only process this cell if this is a valid one
        if (isValid(i - 1, j) == true) {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i - 1, j, dest) == true) {
                // Set the Parent of the destination cell
                cellInfo[i - 1][j].parent_i = i;
                cellInfo[i - 1][j].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellInfo, dest);
                foundDest = true;
                return;
            }
            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (closedList[i - 1][j] == false
                     && isUnblocked(grid, i - 1, j)
                            == true) {
                gNew = cellInfo[i][j].g + 1.0;
                hNew = calculateHValue(i - 1, j, dest);
                fNew = gNew + hNew;
 
                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellInfo[i - 1][j].f == FLT_MAX
                    || cellInfo[i - 1][j].f > fNew) {
                    openList.insert(std::make_pair(
                        fNew, std::make_pair(i - 1, j)));
 
                    // Update the details of this cell
                    cellInfo[i - 1][j].f = fNew;
                    cellInfo[i - 1][j].g = gNew;
                    cellInfo[i - 1][j].h = hNew;
                    cellInfo[i - 1][j].parent_i = i;
                    cellInfo[i - 1][j].parent_j = j;
                }
            }
        }
 
        //----------- South ------------
 
        if (isValid(i + 1, j) == true) {
            if (isDestination(i + 1, j, dest) == true) {
                cellInfo[i + 1][j].parent_i = i;
                cellInfo[i + 1][j].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellInfo, dest);
                foundDest = true;
                return;
            }

            else if (closedList[i + 1][j] == false
                     && isUnblocked(grid, i + 1, j)
                            == true) {
                gNew = cellInfo[i][j].g + 1.0;
                hNew = calculateHValue(i + 1, j, dest);
                fNew = gNew + hNew;
 
                if (cellInfo[i + 1][j].f == FLT_MAX
                    || cellInfo[i + 1][j].f > fNew) {
                    openList.insert(std::make_pair(
                        fNew, std::make_pair(i + 1, j)));

                    cellInfo[i + 1][j].f = fNew;
                    cellInfo[i + 1][j].g = gNew;
                    cellInfo[i + 1][j].h = hNew;
                    cellInfo[i + 1][j].parent_i = i;
                    cellInfo[i + 1][j].parent_j = j;
                }
            }
        }
 
        //----------- East ------------
 
        if (isValid(i, j + 1) == true) {
            if (isDestination(i, j + 1, dest) == true) {
                cellInfo[i][j + 1].parent_i = i;
                cellInfo[i][j + 1].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellInfo, dest);
                foundDest = true;
                return;
            }
 
            else if (closedList[i][j + 1] == false
                     && isUnblocked(grid, i, j + 1)
                            == true) {
                gNew = cellInfo[i][j].g + 1.0;
                hNew = calculateHValue(i, j + 1, dest);
                fNew = gNew + hNew;
 
                if (cellInfo[i][j + 1].f == FLT_MAX
                    || cellInfo[i][j + 1].f > fNew) {
                    openList.insert(std::make_pair(
                        fNew, std::make_pair(i, j + 1)));
 
                    cellInfo[i][j + 1].f = fNew;
                    cellInfo[i][j + 1].g = gNew;
                    cellInfo[i][j + 1].h = hNew;
                    cellInfo[i][j + 1].parent_i = i;
                    cellInfo[i][j + 1].parent_j = j;
                }
            }
        }
 
        //----------- West ------------
 
        if (isValid(i, j - 1) == true) {
            if (isDestination(i, j - 1, dest) == true) {
                cellInfo[i][j - 1].parent_i = i;
                cellInfo[i][j - 1].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellInfo, dest);
                foundDest = true;
                return;
            }
 
            else if (closedList[i][j - 1] == false
                     && isUnblocked(grid, i, j - 1)
                            == true) {
                gNew = cellInfo[i][j].g + 1.0;
                hNew = calculateHValue(i, j - 1, dest);
                fNew = gNew + hNew;
 
                if (cellInfo[i][j - 1].f == FLT_MAX
                    || cellInfo[i][j - 1].f > fNew) {
                    openList.insert(std::make_pair(
                        fNew, std::make_pair(i, j - 1)));
 
                    cellInfo[i][j - 1].f = fNew;
                    cellInfo[i][j - 1].g = gNew;
                    cellInfo[i][j - 1].h = hNew;
                    cellInfo[i][j - 1].parent_i = i;
                    cellInfo[i][j - 1].parent_j = j;
                }
            }
        }
 
        //----------- Nort-East -----------
 
        if (isValid(i - 1, j + 1) == true) {
            if (isDestination(i - 1, j + 1, dest) == true) {
                cellInfo[i - 1][j + 1].parent_i = i;
                cellInfo[i - 1][j + 1].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellInfo, dest);
                foundDest = true;
                return;
            }
 
            else if (closedList[i - 1][j + 1] == false
                     && isUnblocked(grid, i - 1, j + 1)
                            == true) {
                gNew = cellInfo[i][j].g + 1.414;
                hNew = calculateHValue(i - 1, j + 1, dest);
                fNew = gNew + hNew;
 
                if (cellInfo[i - 1][j + 1].f == FLT_MAX
                    || cellInfo[i - 1][j + 1].f > fNew) {
                    openList.insert(std::make_pair(
                        fNew, std::make_pair(i - 1, j + 1)));
 
                    cellInfo[i - 1][j + 1].f = fNew;
                    cellInfo[i - 1][j + 1].g = gNew;
                    cellInfo[i - 1][j + 1].h = hNew;
                    cellInfo[i - 1][j + 1].parent_i = i;
                    cellInfo[i - 1][j + 1].parent_j = j;
                }
            }
        }
 
        //----------- North-West ------------

        if (isValid(i - 1, j - 1) == true) {
            if (isDestination(i - 1, j - 1, dest) == true) {
                cellInfo[i - 1][j - 1].parent_i = i;
                cellInfo[i - 1][j - 1].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellInfo, dest);
                foundDest = true;
                return;
            }
 
            else if (closedList[i - 1][j - 1] == false
                     && isUnblocked(grid, i - 1, j - 1)
                            == true) {
                gNew = cellInfo[i][j].g + 1.414;
                hNew = calculateHValue(i - 1, j - 1, dest);
                fNew = gNew + hNew;
 
                if (cellInfo[i - 1][j - 1].f == FLT_MAX
                    || cellInfo[i - 1][j - 1].f > fNew) {
                    openList.insert(std::make_pair(
                        fNew, std::make_pair(i - 1, j - 1)));

                    cellInfo[i - 1][j - 1].f = fNew;
                    cellInfo[i - 1][j - 1].g = gNew;
                    cellInfo[i - 1][j - 1].h = hNew;
                    cellInfo[i - 1][j - 1].parent_i = i;
                    cellInfo[i - 1][j - 1].parent_j = j;
                }
            }
        }
 
        //----------- South-East ------------
 
        if (isValid(i + 1, j + 1) == true) {
            if (isDestination(i + 1, j + 1, dest) == true) {
                cellInfo[i + 1][j + 1].parent_i = i;
                cellInfo[i + 1][j + 1].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellInfo, dest);
                foundDest = true;
                return;
            }

            else if (closedList[i + 1][j + 1] == false
                     && isUnblocked(grid, i + 1, j + 1)
                            == true) {
                gNew = cellInfo[i][j].g + 1.414;
                hNew = calculateHValue(i + 1, j + 1, dest);
                fNew = gNew + hNew;
 
                if (cellInfo[i + 1][j + 1].f == FLT_MAX
                    || cellInfo[i + 1][j + 1].f > fNew) {
                    openList.insert(std::make_pair(
                        fNew, std::make_pair(i + 1, j + 1)));
 
                    cellInfo[i + 1][j + 1].f = fNew;
                    cellInfo[i + 1][j + 1].g = gNew;
                    cellInfo[i + 1][j + 1].h = hNew;
                    cellInfo[i + 1][j + 1].parent_i = i;
                    cellInfo[i + 1][j + 1].parent_j = j;
                }
            }
        }
 
        //----------- South West ------------

        if (isValid(i + 1, j - 1) == true) {
            if (isDestination(i + 1, j - 1, dest) == true) {
                cellInfo[i + 1][j - 1].parent_i = i;
                cellInfo[i + 1][j - 1].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellInfo, dest);
                foundDest = true;
                return;
            }
 
            else if (closedList[i + 1][j - 1] == false
                     && isUnblocked(grid, i + 1, j - 1)
                            == true) {
                gNew = cellInfo[i][j].g + 1.414;
                hNew = calculateHValue(i + 1, j - 1, dest);
                fNew = gNew + hNew;
 
  
                if (cellInfo[i + 1][j - 1].f == FLT_MAX
                    || cellInfo[i + 1][j - 1].f > fNew) {
                    openList.insert(std::make_pair(
                        fNew, std::make_pair(i + 1, j - 1)));

                    cellInfo[i + 1][j - 1].f = fNew;
                    cellInfo[i + 1][j - 1].g = gNew;
                    cellInfo[i + 1][j - 1].h = hNew;
                    cellInfo[i + 1][j - 1].parent_i = i;
                    cellInfo[i + 1][j - 1].parent_j = j;
                }
            }
        }
    }
 
    if (foundDest == false)
        printf("Failed to find the Destination Cell\n");
 
    return;
}
 


int main(){

int grid[ROW][COL]
        = { { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
            { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
            { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
            { 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
            { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
            { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
            { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
            { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
            { 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 },
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }};

Pair start = std::make_pair(9,9);
Pair destination = std::make_pair(0,0);

AStarAlgorithm(grid,start,destination);

}

