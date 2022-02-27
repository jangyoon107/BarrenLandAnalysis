#include "Farm.h"

/*
 * Farm() 
 * Default Constructor. By default, width and height of farm will be 400 and 600.
 */
Farm::Farm()
{
    landWidth = 400;
    landHeight = 600;
    validFarmFlag = true;

    // Resize visited matrix to default width and height
    landVisited.resize(landHeight, vector<int>(landWidth, 0));
}

/*
 * Farm(int w, int h): 
 * Constructor. Define farm using user provided width and height.
 */
Farm::Farm(int w, int h)
{
    // Check if width or height is valid
    if(w < 1 || h < 1)
    {
        cout<<"Initialization error, ";

        if(w < 1)
            cout<<"Width ";
        
        if(h < 1)
            cout<<"Height ";

        cout<< "must be bigger than 0"<<endl;

        validFarmFlag = false;
        return;
    }
    
    landWidth = w;
    landHeight = h;
    validFarmFlag = true;

    // Resize visited matrix to default width and height
    landVisited.resize(landHeight, vector<int>(landWidth, 0));
}

/*
 * void SetWidthHeight(int w, int h)
 * This function will set farm's width and height to new user defined width and height.
 * It is used when you already created farm and only want to resize the farm.
 */
void Farm::SetWidthHeight(int w, int h)
{
    // Check if width or height is valid
    if(w < 1 || h < 1)
    {
        cout<<"Initialization error, ";

        if(w < 1)
            cout<<"Width ";
        
        if(h < 1)
            cout<<"Height ";

        cout<< "must be bigger than 0"<<endl;

        validFarmFlag = false;
        return;
    }

    landWidth = w;
    landHeight = h;

    // Resize visited matrix to default width and height
    landVisited.resize(landHeight, vector<int>(landWidth, 0));
}

/*
 * void SetBarrenAreas(vector<string> barrenString): 
 * This function loops through string coordinates of barren lands and convert them to land object and save it internally.
 */
void Farm::SetBarrenAreas(vector<string> barrenString)
{
    vector<int> coordinates;
    for (size_t i = 0; i < barrenString.size(); i++)
    {
        // Read line of string coordinates (or one barren coordinates)
        istringstream iss(barrenString[i]);
        string numString;

        // Read numbers that are seperated by white space. And convert string to int and save to vector
        while(iss >> numString)
        {
            int number = stoi(numString);
            coordinates.push_back(number);
        }
        
        // Initialize land object from barren coordinates
        Land land(coordinates);

        // Check if the land object is valid and only include barren lands that is valid.
        if(land.IsValid())
            barrenLands.push_back(land);
        
        // clear vector for next batch of string coordinates
        coordinates.clear();
    }

    // Once new barren coordinates are received, update internal land matrix to reflect the locations of barren lands
    UpdateLandMatrix();
}

/*
 * void UpdateLandMatrix(): 
 * This function loops through each barren lands and marks any internal barren land with -1 on the internal land matrix.
 */
void Farm::UpdateLandMatrix()
{
    for (size_t i = 0; i < barrenLands.size(); i++)
    {
        Land land = barrenLands[i];

        for (int y = land.GetBottomLeft().y; y < land.GetBottomLeft().y + land.GetHeight(); y++)
        {
            for (int x = land.GetBottomLeft().x; x < land.GetBottomLeft().x + land.GetWidth(); x++)
            {
                // Convert Y here since input barren coordinates starts from bottom left (0, 0) while internal land matrix uses top left (0, 0) coordinate system. 
                int convY = abs(y - landHeight + 1);

                // By any chance barren land coordinates exceed the farm land size, we only mark barren land within the farm area
                if(convY < landHeight && x < landWidth)
                    landVisited[convY][x] = -1;
            }
        }
    }
}

/*
 * void DisplayFarm(): 
 * For testing small cases, visualize internal land matrix (x for barren and - for fertile)
 */
void Farm::DisplayFarm()
{
    //only for small cases
    if(landWidth > 20 && landHeight > 20)
        return;

    cout<<"Farm:"<<endl;
    for (int y = 0; y < landHeight; y++)
    {
        for (int x = 0; x < landWidth; x++)
        {
            if(landVisited[y][x] < 0)
                cout<<" x ";
            else
                cout<<" - ";
        }
        cout<<endl;
    }
    cout<<endl;
}

/*
 * bool IsValid(): 
 * Getter for validity of current farm.
 */
bool Farm::IsValid() const
{
    return validFarmFlag;
}

/*
 * vector<int> CalculateFertileLand(): 
 * Main function for finding areas of all fertile land. Uses internal land matrix to keep track of visited coordinates.
 * 
 * Algorith summary: 
 * To calculate the fertile land, we will go through each coordinate of the farm and check if we have visited before.
 * If we havent visited, then we will start BFS search and visit all positions reachable from current location.
 * Once propagation is done, we have found one plot of land that is fertile. Add to vector and move to next location we havent visited. 
 */
vector<int> Farm::CalculateFertileLand()
{
    vector<int> areas;
    
    // Loop through each coordinates of the farm and see if we visited it. 
    for (int y = 0; y < landHeight; y++)
    {
        for (int x = 0; x < landWidth; x++)
        {
            //If this position is not visited before, call AreaDetectorBFS to visit all connected fertile land.
            if(landVisited[y][x] == 0)
            {
                int area = AreaDetectorBFS(y, x);
                areas.push_back(area);
            }
        }
        
    }
    
    // Sort the area from smallest to largest befor returning the result. If we found no fertile land, return 0;
    if(areas.size() > 0)
    {
        sort(areas.begin(), areas.end());
    }
    else
    {
        areas.push_back(0);
    }

    // Reset Land matrix
    ResetLandMatrix();

    return areas;
}
/*
 * int AreaDetectorBFS(int y, int x): 
 * From given position, visit all connected fertile lands and calculate the area of this particular fertile land.
 * 
 * Algorith summary:
 * Standard BFS algorithm with queue. Adds 1 to area every time it finds unvisited fertile land. 
 * Keep propagating to left, right, up, down lands until all connected nodes are visited.
 */
int Farm::AreaDetectorBFS(int y, int x)
{
    int area = 0;

    // Use queue so first discovered node gets processed first
    queue<Point> queuePoint;
    queuePoint.push(Point{x, y});

    while (!queuePoint.empty())
    {
        Point coord = queuePoint.front();
        queuePoint.pop();

        // If current node hasnt been visited and not a barren land
        if(landVisited[coord.y][coord.x] == 0)
        {
            // Add to area and mark as visited land
            landVisited[coord.y][coord.x] = 1;
            area++;

            // Propagate to left, right, up, down and add to queue
            if(coord.x - 1 >= 0 && coord.x - 1 < landWidth)
                queuePoint.push(Point{coord.x - 1, coord.y});
            if(coord.x + 1 >= 0 && coord.x + 1 < landWidth)
                queuePoint.push(Point{coord.x + 1, coord.y});

            if(coord.y - 1 >= 0 && coord.y - 1 < landHeight)
                queuePoint.push(Point{coord.x, coord.y - 1});
            if(coord.y + 1 >= 0 && coord.y + 1 < landHeight)
                queuePoint.push(Point{coord.x, coord.y + 1});
        }
    }

    return area;
}

/*
 * void ResetLandMatrix(): 
 * Reset Land matrix to unvisited so future calculations can be performed again.
 */
void Farm::ResetLandMatrix()
{
    for (int y = 0; y < landHeight; y++)
    {
        for (int x = 0; x < landWidth; x++)
        {
            if(landVisited[y][x] == 1)
                landVisited[y][x] = 0;
        }
    }
}