#include "cellCsv.hpp"


int main()
{
    ccsv::cellCsv csvWriter;
    
    csvWriter.setCell(3,5, "hid");
    csvWriter.setCell(3,2, "hisa");
    csvWriter.setCell(34,13, "hsi");
    csvWriter.setCellReal(0,3, 4.545);
    csvWriter.setCellInt(7,3, 136);
    csvWriter.setCell(2,5, std::string("I AM A BANNANNA"));
    csvWriter.dump("testcsv.csv");
}