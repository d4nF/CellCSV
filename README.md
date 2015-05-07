# CellCSV
CellCSV is a simple to use c++ cell based csv library writer/generator.
You don't have to worry about filling the csv in a linear fashion. you can fill it up by each cell in any order you want. 
Best of all, you don't even have to worry about the cells you skip. cellCSV will take care of that for you

see example.cpp for a working example.

In short, all you need is to call cellCSv::putCell(coord1, coord2, "some str") a bunch of times and finally a cellCSV::dump("myfile.csv"); and you're done! 