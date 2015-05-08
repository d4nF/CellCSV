#include "cellCsv.hpp"


int main()
{
    ccsv::cellCsv csvWriter;
    
    csvWriter.setCell(3,5, "This is a cell");
    csvWriter.setCell(3,2, "This is an out of order cell");
    csvWriter.setCell(34,13, "Im pretty far away arent I?");
    csvWriter.setCellReal(0,3, 4.545);
    csvWriter.setCell(0,2, "Here\'s a double:");
    csvWriter.setCellInt(7,3, 136);
    csvWriter.setCell(7,2, "Here\'s an int type:");
    csvWriter.setCell(2,5, std::string("I AM A BANNANNA"));
    csvWriter.dump("testcsv.csv");
}