#include <iostream>
#include "cellCsv.hpp"

int main()
{
    ccsv::cellCsv csvwriter;
    csvwriter.setCell(1,4,"b33ob");
    csvwriter.setCell(21,4,"b1ob");
    csvwriter.setCell(456,222,4.56);
    csvwriter.setCell(3,3,"boba");
    csvwriter.dump("b.csv");
    
    return 0;
}