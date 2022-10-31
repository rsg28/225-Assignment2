/*
    The present program requires the utilization of really small numbers. However, this is very complicated to formulate. I managed to get through it but it exists the possibility to obtain an inaccurate 0. In this case, please re run the program.
*/


#include <iostream>
#include "BinarySearchTree.h"
#include <vector>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;

/*
   returns elapsed time in milliseconds
*/
double elapsed_time(clock_t start, clock_t finish)
{
    return (finish - start) / (double)(CLOCKS_PER_SEC / 1000);
}

int main()
{
    cout << setprecision(32);
    srand(time(0));
    cout << "====================================" << endl;
    cout << "Part1" << endl;
    cout << "=====================================" << endl;
    cout << "Objectives: Calculate average Depth, and Membership Time for both trees." << endl;

    // To avoid unnecesary complications, the trees will be of ints
    BinarySearchTree<int> T1;
    BinarySearchTree<int> T2;

    double averageTimeT1 = 0;
    double averageTimeT2 = 0;
    int averageDepthT1 = 0;
    int averageDepthT2 = 0;
    vector<int> nums; // Will store numbers the numbers inserted in T2.
    int insertVal;
    clock_t start, finish;
    cout << "------------------------Executing Insertion Phase------------------------" << endl;
    cout << "Specifications:" << endl;
    cout << "- Inserting 100000 random numbers [0, 999999] into T2" << endl;
    for (int i = 0; i < 1000000; i++)
    {
        insertVal = rand() % 1000000;
        T2.insert(insertVal);
        nums.push_back(insertVal);
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    // cout << "Printing T2..." << endl;
    // cout << "Keys:" << endl;
    // T2.printTree();
    // cout << "Tree:" << endl;
    // T2.displayTree();
    cout << "...Results obtained and stored" << endl;
    cout << endl;
    cout << "Inserting the same elements into T1, but in an ordered fashion so we have a tall and skinny tree" << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        T1.insert(nums[i]);
    }
    // Thus T2 is a naturally made tree while T1 will be tall and skinny


    // cout << "Printing T1..." << endl;
    // cout << "Keys:" << endl;
    // T1.printTree();
    // cout << "Tree:" << endl;
    // T1.displayTree();
    cout << "...Results obtained and stored" << endl;
    cout << endl;

    cout << "------------------------Executing Membership Test Phase------------------------" << endl;
    cout << "Specifications:" << endl;
    cout << "- Membership tests and find average Depth will be done with random values between [0, 999999] for 2000 times." << endl;
    cout << "- Note that as this interval increases, so does the average depth." << endl;
    // Hereby, we start the tests
    for (int i = 0; i < 2000; i++)
    {
        insertVal = rand() % 1000000;
        // membership test for T1
        start = clock();
        T1.contains(insertVal);
        finish = clock();
        averageTimeT1 += elapsed_time(start, finish);
        averageDepthT1 += T1.depth(insertVal);

        // membership test for T2
        start = clock();
        T2.contains(insertVal);
        finish = clock();
        averageTimeT2 += elapsed_time(start, finish);
        averageDepthT2 += T2.depth(insertVal);
    }

    // Average time for membership checks
    averageTimeT1 = averageTimeT1 / 2000;
    averageTimeT2 = averageTimeT2 / 2000;

    // Average depth
    averageDepthT1 = averageDepthT1 / 2000;
    averageDepthT2 = averageDepthT2 / 2000;
    cout << "...Results obtained and stored" << endl;
    cout << endl;
    cout << "------------------------Test Results------------------------ " << endl;
    cout << "Average time for: T1 = " << averageTimeT1 << ", T2 = " << averageTimeT2 << endl;
    cout << "Average Depth for: T1 = " << averageDepthT1 << ", T2 = " << averageDepthT2 << endl;
    cout << endl << "End of Part1" << endl;
    cout << "For further analysis, refer to Part1.pdf report" << endl;
}
