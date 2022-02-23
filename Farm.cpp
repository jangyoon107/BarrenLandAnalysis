#include "Farm.h"


Farm::Farm()
{
    landWidth = 400;
    landHeight = 600;

    landVisited.resize(landHeight, vector<int>(landWidth, 0));
}

Farm::Farm(int w, int h)
{
    assert(("Width must be positive", w >= 0));
    assert(("Height must be positive", h >= 0));

    landWidth = w;
    landHeight = h;

    landVisited.resize(landHeight, vector<int>(landWidth, 0));
}

void Farm::SetWidthHeight(int w, int h)
{
    assert(("Width must be positive", w >= 0));
    assert(("Height must be positive", h >= 0));

    landWidth = w;
    landHeight = h;

    landVisited.resize(landHeight, vector<int>(landWidth, 0));
}

bool Farm::SetBarrenAreas(vector<string> barrenString)
{
    vector<int> coordinates;
    for (size_t i = 0; i < barrenString.size(); i++)
    {
        istringstream iss(barrenString[i]);

        string numString;
        while(iss>>numString)
        {
            int number = stoi(numString);
            coordinates.push_back(number);
        }

        if(coordinates.size() != 4)
        {
            cout<<"Invalid format of coodinates, " <<coordinates.size() << " of numbers found on a input... Excluding from the barren list."<<endl;
            coordinates.clear();
            continue;
        }
        
        Land land(coordinates[0], coordinates[1], coordinates[2], coordinates[3]);
        if(land.IsValid())
            barrenLands.push_back(land);
        else{
            cout<<"Invalid Barren Coordinates received... Excluding it from the barren list."<<endl;
        }
        
        coordinates.clear();
    }

    if (barrenLands.size() > 0)
    {
        UpdateLandMatrix();
        return true;
    }
    else
    {
        cout<<"Insufficient number of barren inputs.. Unable to contine. Exiting..."<<endl;
        //exit(EXIT_FAILURE);
        return false;
    }
}

void Farm::UpdateLandMatrix()
{
    for (size_t i = 0; i < barrenLands.size(); i++)
    {
        Land land = barrenLands[i];

        for (int y = land.GetBottomLeft().y; y < land.GetBottomLeft().y + land.GetHeight(); y++)
        {
            for (int x = land.GetBottomLeft().x; x < land.GetBottomLeft().x + land.GetWidth(); x++)
            {
                int convY = abs(y - landHeight + 1);
                if(convY < landHeight && x < landWidth)
                    landVisited[convY][x] = -1;
            }
        }
    }
}

void Farm::DisplayFarm()
{
    //only for small cases
    if(landWidth > 20 && landHeight > 20)
        return;

    cout<<"Land:"<<endl;
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

/* Algorith summary: 
 * To calculate the fertile land, we will go through each coordinate of the farm and check if we have visited before.
 * If we havent visited, then we will start BFS search and visit all positions reachable from current location.
 * Once propagation is done, we have found one plot of land that is fertile. Add to vector and move to next location we havent visited. 
 */
vector<int> Farm::CalculateFertileLand()
{
    vector<int> areas;
  
    for (int y = 0; y < landHeight; y++)
    {
        for (int x = 0; x < landWidth; x++)
        {
            if(landVisited[y][x] == 0)
            {
                int area = BFSHelper(y, x);
                areas.push_back(area);
            }
        }
        
    }

    sort(areas.begin(), areas.end());

    return areas;
}

/* Algorith summary:
 * Standary BFS algorithm with queue. Adds 1 to area every time it finds unvisited fertile land. 
 * Keep propagating to left, right, up, down lands until all nodes are visited or barren.
 */
int Farm::BFSHelper(int y, int x)
{
    int area = 0;

    queue<Point> queuePoint;
    queuePoint.push(Point{x, y});

    while (!queuePoint.empty())
    {
        Point coord = queuePoint.front();
        queuePoint.pop();

        if(landVisited[coord.y][coord.x] == 0)
        {
            landVisited[coord.y][coord.x] = 1;
            area++;

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