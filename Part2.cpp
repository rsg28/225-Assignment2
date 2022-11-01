#include <iostream>
#include "BinarySearchTree.h"
#include "AvlTree.h"
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
    cout << setprecision(6);
    srand(time(0));
    cout << "=====================================" << endl;
    cout << "Start of Part2" << endl;
    cout << "=====================================" << endl;
    cout << "Objectives: Calculate average Insertion Time, Depth, Membership Time and Height on both trees." << endl;
    // To avoid unnecesary complications, the trees will be of ints
    // Then, we define 2 trees, where one is an Avl
    BinarySearchTree<int> T1;
    AvlTree<int> T2;

    // Declarations...

    // Result 1
    double averageInsertionT1 = 0;
    double averageInsertionT2 = 0;

    // Result 2
    int averageDepthT1 = 0;
    int averageDepthT2 = 0;

    // Result 3
    int heightT1 = 0;
    int heightT2 = 0;

    // Result 4
    double averageMembershipT1 = 0;
    double averageMembershipT2 = 0;

    int insertVal;
    clock_t start, finish;
    cout << "------------------------Executing Insertion Phase------------------------" << endl;
    cout << "Specifications:" << endl;
    cout << "- Inserting 1000000 random numbers [0, 999999] into T2 (AVL Tree) " << endl;
    cout << "- Inserting 1000000 random numbers [0, 999999] into T1 (Binary Search Tree) " << endl;
    cout << "- Note that the insert time on each T1 and T2 is recorded and stored" << endl;
    for (int i = 0; i < 2000000; i++)
    {
        insertVal = rand() % 1000000;

        start = clock();
        T2.insert(insertVal);
        finish = clock();
        averageInsertionT2 += elapsed_time(start, finish);

        start = clock();
        T1.insert(insertVal);
        finish = clock();
        averageInsertionT1 += elapsed_time(start, finish);
    }

    // Average Insertion time Results
    averageInsertionT1 = averageInsertionT1 / 2000000;
    averageInsertionT2 = averageInsertionT2 / 2000000;
    cout << "...Results obtained and stored" << endl;

    cout << "------------------------Executing Depth/Height Testing Phase------------------------" << endl;
    cout << "Specifications:" << endl;
    cout << "- The average Depth will be done with random values between [0, 999999] for 10000 times." << endl;
    cout << "- The Height of each Tree is obtained using a class method." << endl;

    for (int i = 0; i < 10000; i++)
    {
        insertVal = rand() % 1000000;
        T2.depth(insertVal);
        averageDepthT2 += T2.depth(insertVal);
        T1.depth(insertVal);
        averageDepthT1 += T1.depth(insertVal);
    }
    //Depth
    averageDepthT1 = averageDepthT1/10000;
    averageDepthT2 = averageDepthT2/10000;

    // Heights
    heightT1 = T1.height();
    heightT2 = T2.height(); // The professor has defined its own version of height

    cout << "...Results obtained and stored" << endl;

    cout << "------------------------Executing Membership Testing Phase------------------------" << endl;
    cout << "Specifications:" << endl;
    cout << "- The membership test will use values between [0, 999999] for 10000 times." << endl;

    double minMembershipT1 = 100;
    double maxMembershipT1 = 0;
    double minMembershipT2 = 100;
    double maxMembershipT2 = 0;
    double temp;

    for (int i = 0; i < 10000; i++)
    {
        insertVal = rand() % 1000000;
        start = clock();
        T2.contains(insertVal);
        finish = clock();
        temp = elapsed_time(start, finish);
        averageMembershipT2 += temp;
        if(temp > maxMembershipT2){
            maxMembershipT2 =temp;
        }
        else if(temp < minMembershipT2){
            minMembershipT2 =temp;
        }

        start = clock();
        T1.contains(insertVal);
        finish = clock();
        temp = elapsed_time(start, finish);
        averageMembershipT1 += temp;
        if(temp > maxMembershipT1){
            maxMembershipT1 =temp;
        }
        else if(temp < minMembershipT1){
            minMembershipT1 =temp;
        }
    }
    averageMembershipT1 = averageMembershipT1/10000;
    averageMembershipT2 = averageMembershipT2/10000;

    // Findings report
    // Instead of diving averageMemberships and averageInsertion by the number of executed times, we write them in a cientific notation form
    // to avoid confusion and printing 0 (Highly innaccurate)
    cout << "------------------------Test Results------------------------ " << endl;
    cout << "Average Insertion time for: T1 = " << averageInsertionT1
         << ", T2 = " << averageInsertionT2 << endl;
    cout << "Average Depth for: T1 = " << averageDepthT1 << ", T2 = " << averageDepthT2 << endl;
    cout << "Height for: T1 = " << heightT1 << ", T2 = " << heightT2 << endl;
    cout << "Min Membership Time T1: " << minMembershipT1 
         << ", T2 = " << minMembershipT2 << endl;
    cout << "Average Membership Time T1: " << averageMembershipT1 
         << ", T2 = " << averageMembershipT2 << endl;
    cout << "Max Membership Time T1: " << maxMembershipT1 
         << ", T2 = " << maxMembershipT2 << endl;

    cout << endl
         << "End of Part2" << endl;
    cout << "For further analysis, refer to Part2.pdf report" << endl;
}
