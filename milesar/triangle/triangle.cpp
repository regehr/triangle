/** triangle.cpp
* single spaces
* x1 y1 x2 y2 x3 y3
* coordinates are integers in [0...100]
* read from standard input stream (stdin), write to standard output (stdout)
* input is zero or more lines, each containing a triangle
* behavior is undefined if input is malformed

* assignment: write a triangle classifier in c++
* write 7 test cases, try for at least one each
*
* Author: Adam Miles
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <assert.h>

#define PI 3.14159265

using namespace std;

/** takes the input string, parses it by the ' ' space character, and returns a vector of doubles
 * representing each token. It is presumed that error checking has already been performed, and that
 * all found tokens are of the appropriate type (representing integers) for the points of a triangle.
 *
 * @param triangleInput a string expected to be 6 integers separated by spaces.
 * @return points, a vector of 6 doubles.
 */
vector<double> getTriangle (string triangleInput) {
    vector<double> points;

    string token;
    istringstream tokenStream(triangleInput);
    while (getline(tokenStream, token, ' '))
    {
        points.push_back(stoi(token));
    }

    return points;
}

/** finds the index of the longest side of a triangle, the largest value in a vector of 3 doubles representing
 * the lengths of the sides of a triangle.
 *
 * @param lengths, a vector of 3 doubles representing the lengths of the sides of a triangle.
 * @return longestSide, and integer representing the index of the the longestSide length stored in lengths
 */
int findLongestSide (vector<double> lengths) {
    int longestSide = 0;
    double length = 0.0;

    for (int i = 0; i < lengths.size(); i++) {
        if (lengths[i] > length) {
            longestSide = i;
            length = lengths[i];
        }
    }

    return longestSide;
}

/** calculates the lengths of the sides of a triangle, using an input vector with 6 doubles describing
 * the vertices of a triangle.
 *
 * @param pts a vector of 6 doubles describing the 3 vertices of a triangle (ax, ay, bx, by, cx, cy).
 * @return
 */
vector<double> getLengths (vector<double> pts) {
    vector<double> getLengths;

    getLengths.push_back(sqrt(pow(pts[0] - pts[2], 2) + pow(pts[3] - pts[1], 2)));
    getLengths.push_back(sqrt(pow(pts[2] - pts[4], 2) + pow(pts[3] - pts[5], 2)));
    getLengths.push_back(sqrt(pow(pts[0] - pts[4], 2) + pow(pts[1] - pts[5], 2)));

    return getLengths;
}

/** calculates the angles of a triangle using the lengths of the sides and the law of cosines.
 *
 * @param sides, a vector of 3 doubles describing the lengths of the sides of a triangle (ab, bc, ca).
 * @return
 */
vector<double> getAngles (vector<double> sides) {
    vector<double> angles = {0, 0, 0};

    int longestSide = findLongestSide(sides);
    double A = 0.0;
    double B = 0.0;

    B = acos((pow(sides[0], 2) + pow(sides[2], 2) - pow(sides[1], 2)) / (2 * sides[0] * sides[2]));

    A = asin(sides[0] * sin(B) / sides[1]);

    angles[0] = A * 180.0 / PI;
    angles[1] = B * 180.0 / PI;
    angles[2] = 180 - (A + B) * 180.0 / PI;

    return angles;

}

/** determines if the 3 vertices constitute a valid triangle by calculating the area. if the area
 * is greater than zero, than the points form a triangle.
 *
 * @param points vector of 6 doubles defining the points of a triangle (ax, ay, bx, by, cx, cy).
 * @return true if the points describe a valid triangle.
 */
bool degenerate (vector<double> pts) {

    double area = (pts[0] * (pts[3] - pts[5]) + pts[2] * (pts[5] - pts[1]) + pts[4] * (pts[1] - pts[3])) / 2;

    return area >= 0.0;
}

/** helper function, prints the contents of a vector to the commandline, seperated by spaces.
 *
 * @param items, a vector of items to print out to the console.
 */
void printVector (vector<double> items) {
    for (double item : items) {
        cout << item << " ";
    }
    cout << endl;
}

/** classifies the type of triangle described by the 3 angles (angles) and side lengths (lengths).
 *
 * @param angles vector holding the 3 interior angles of the triangle.
 * @param lengths vector holding the 3 side lengths of the triangle.
 */
string classify (vector<double> points) {
    string result = ""; // classification response.
    string triangleInput = "";

    /** first test degenerate case, by checking the area inscribed by the 3 vertices. if the area == 0,
     * then the points do not describe a triangle (colinear, or multiple points are the same).
     *
     */
    if (degenerate(points)) {
        return "not a triangle";
    }

    vector<double> sides = getLengths(points);
    vector<double> angles = getAngles(sides);

    /** once the input vertices have been validated to describe a triangle withing the specified coordinate space,
     * classify the constituent angles.
     *
     */
    for (double angle : angles) {
        if (floor(angle) > 90.0) {
            result += "obtuse ";
            break;
        } else if (floor(angle) == 90.0) {
            result += "right ";
            break;
        }
    }

    if (!((floor(sides[0]) == floor(sides[1])) && (floor(sides[1]) == floor(sides[2])) &&
            (floor(sides[0]) == floor(sides[2]))) && result == ""){
        result += "acute ";
    }

    /** next select the correct descriptor based on the number of congruent sides, and append to the angular
     * descriptor. the special case 'equilateral' is handled at the very end of the sequence, having already
     * verified that a combination of equal angles above (60 60 60) has not been classified.
     *
     */
    int congruentSides = 0;

    if ((sides[0]) == (sides[2]) || sides[1] == (sides[2])) {
        congruentSides = 2;
    }
    else if ((sides[0]) == (sides[2]) && sides[1] == (sides[2])) {
        congruentSides = 3;
    }

    if (congruentSides == 0) {
        result += "scalene ";
    } else if (congruentSides == 2) {
        result += "isosceles ";
    } else if (congruentSides == 3){
        result += "equilateral ";
    }

    /** debugging print statements
     *
     */
    cout << "\n" << result + "triangle:" << endl;
    cout << "points: ";
    printVector(points);
    cout << "sides: ";
    printVector(sides);
    cout << "angles: ";
    printVector(angles);
    cout << "congruent sides:" << congruentSides;


    /** append 'triangle' to the end of the descriptors, after navigating the table of 7 combinations.
     *
     */
    return result + "triangle";
}

vector<vector<double>> getTriangles () {
    string triangleInput = "";
    vector<vector<double>> triangles;

    cout << "Enter a triangle, defined by 3 points, or six integers separated by spaces (ax ay bx by cx cy):"
            "\nEnter 'q!' to quit entering coordinate series." << endl;

    while (triangleInput != "q!") {
        vector<double> points;

        getline (cin, triangleInput);
        if (triangleInput == "q!") {
            continue;
        }

        points = getTriangle(triangleInput);

        if (points.size() != 6) {
            cout << "Invalid input.\nInput must be 6 integers separated by spaces (ax ay bx by cx cy)." << endl;
            continue;
        }

        for (double point : points) {
            if (point > 100 || point < 0) {
                cout << "Invalid input.\n Coordinates must be integers within the range 0-100." << endl;
            }
        }

        triangles.push_back(points);
        triangleInput = "";
    }

    return triangles;

}

/** performs a series of tests, to validate the performance of the triangle classification and related
 * functionality.
 *
 */
void classificationTests () {
    /** degenerate triangle test
     *
     */
    vector<vector<double>> degenerateTriangles;
    degenerateTriangles.push_back(vector<double> {0,0,90,90,0,0});
    degenerateTriangles.push_back(vector<double> {10,0,10,70,10,5});

    for (vector<double> triangle : degenerateTriangles) {
        assert(classify(triangle) == "not a triangle");
    }

    /** accute scalene triangle test
     *
     */
    vector<vector<double>> accuteScaleneTriangles;
    accuteScaleneTriangles.push_back(vector<double> {5,85,90,90,40,15});
    accuteScaleneTriangles.push_back(vector<double> {10,0,50,70,80,5});

    for (vector<double> triangle : accuteScaleneTriangles) {
        assert(classify(triangle) == "acute scalene triangle");
    }

    /** right scalene triangle test
     *
     */
    vector<vector<double>> rightScaleneTriangles;
    rightScaleneTriangles.push_back(vector<double> {0,0,0,3,4,0});
    rightScaleneTriangles.push_back(vector<double> {0,0,0,1,2,0});

    for (vector<double> triangle : rightScaleneTriangles) {
        assert(classify(triangle) == "right scalene triangle");
    }

    /** obtuse scalene triangle test
     *
     */
    vector<vector<double>> obtuseScaleneTriangles;
    obtuseScaleneTriangles.push_back(vector<double> {2,0,0,3,7,0});
    obtuseScaleneTriangles.push_back(vector<double> {5,5,20,80,20,20});

    for (vector<double> triangle : obtuseScaleneTriangles) {
        assert(classify(triangle) == "obtuse scalene triangle");
    }

    /** acute isosceles triangle test
     *
     */
    vector<vector<double>> acuteIsoscelesTriangles;
    acuteIsoscelesTriangles.push_back(vector<double> {0,8,2,8,1,0});

    for (vector<double> triangle : acuteIsoscelesTriangles) {
        assert(classify(triangle) == "acute isosceles triangle");
    }

    /** right isosceles triangle test
     *
     */
    vector<vector<double>> rightIsoscelesTriangles;
    rightIsoscelesTriangles.push_back(vector<double> {0,0,0,1,1,0});
    rightIsoscelesTriangles.push_back(vector<double> {0,100,100,100,100,0});

    for (vector<double> triangle : rightIsoscelesTriangles) {
        assert(classify(triangle) == "right isosceles triangle");
    }

    /** right isosceles triangle test
     *
     */
    vector<vector<double>> obtuseIsoscelesTriangles;
    obtuseIsoscelesTriangles.push_back(vector<double> {0,0,50,0,25,10});
    obtuseIsoscelesTriangles.push_back(vector<double> {0,100,100,100,50,90});

    for (vector<double> triangle : obtuseIsoscelesTriangles) {
        assert(classify(triangle) == "obtuse isosceles triangle");
    }
}

/** prompts the user to enter a series of coordinates, one set of 6 per line. classifies the sets of coordinates
 * by type of triangle they describe.
 *
 * @return
 */
int main() {

    vector<vector<double>> triangles = getTriangles();

    for (vector<double> triangle : triangles) {
        cout << classify(triangle) << endl;
    }

    classificationTests();

    return 0;
}

