#include <unordered_map>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstdlib>
#include <string>

#include "timsort.hpp" // timsort has 
/*
 * 
 * 0,0 1,0 2,0		1,2,3
 * 0,1 1,1 1,2		
 * 0,2 1,2 2,2
 * 
 */

namespace ccsv 
{
    typedef unsigned long long numType;
    const numType COLUMN_LIMIT = 16777216; //(2^24) That leaves us with 2^40 rows 
    enum class dattype : int
    {
	INT,
	UINT,
	DOUBLE,
	FLOAT,
	STRING
    };
    struct key
    {
	numType x;
	numType y;
	key(numType _x, numType _y): x(_x), y(_y) {}
	
	bool operator==(const key &rhs) const
	{ 
	    return (x == rhs.x && y == rhs.y);
	}
	    
    };
    
    struct keyHasher
    {
    std::size_t operator()(const key& k) const
    {
	
    }
};
    
    
    struct value
    {
	std::string 	str;
	dattype 	dtype;
	value(std::string _str, dattype _dtype) :str(_str), dtype(_dtype) {}
    };
    
    typedef std::pair<key,value> mapEntry;
    bool compareKeys(const key &lhs, const key& rhs)
    {
	return lhs.x+(COLUMN_LIMIT*lhs.y) > rhs.x+(COLUMN_LIMIT*rhs.y);
    }
    
    
    /*!
     * This is a class/library csv reader/writer.
     * unlike many other csv writers, cellCsv is capable of 
     * adding contents to any "cell" in one go regardless if your data 
     * is being processed in different loops/times
     * @example
     * you can call
     * csvHandle handler;
     * handler.cell(3,5,"im bob");
     * handler.cell(6,6,6.7345);
     * handler.cell(0,3,3);
     * handler.dump("testcsv.csv");
     * 
     * It should be noted that this convience comes with a penalty of 
     * 	a) Using a hash table implementation, so this library is not completely memory efficient
     *  b) Using a vector to store keys so that the bounds (for wri)
     */
    class csvHandle 
    {
    public:
	csvHandle()
	{
	    
	    
	}
	virtual ~csvHandle();
    public:
	void cell(numType x, numType y, std::string str)
	{
	    if (str.empty())
	    key k(x,y);
	    value val(str, dattype::STRING);
	    insertToCell(k ,val);
	}
	void cell(numType x, numType y, double dnum)
	{
	    key k(x,y);
	    value val(std::to_string(dnum), dattype::DOUBLE);
	    insertToCell(k ,val);

	}
	
	void cell(numType x, numType y, float fnum)
	{
	    key k(x,y);
	    value val(std::to_string(fnum), dattype::FLOAT);
	    insertToCell(k ,val);
	}
	
	void cell(numType x, numType y, long long int num)
	{
	    key k(x,y);
	    value val(std::to_string(num), dattype::INT);
	    insertToCell(k ,val);
	}
	
	void cell(numType x, numType y, unsigned long long int num)
	{
	    key k(x,y);
	    value val(std::to_string(num), dattype::UINT);
	    insertToCell(k ,val);

	}	
	value getVal(numType x, numType y)
	{
	    const auto cIt = csvData_.find(key(x,y));
	    if (!cIt == csvData_.end()) // if false, then key not found!
	    {
		return cIt->second;
	    }
	    return "";
	}
	std::string at(numType x, numType y)
	{
	    const auto cIt = csvData_.find(key(x,y));
	    if (!cIt == csvData_.end()) // if false, then key not found!
	    {
		return cIt->second.str;
	    }
	    return "";
	}
	void dump(std::string)
	{
	   for (key akey : boundVec_)
	   {
	       
	       
	   }
	    
	}
	
    private:
	void addToBoundVec(const key & k)
	{
	    boundVec_.push_back(k);
// 	    std::sort(boundVec_.begin(), boundVec_.end(), compareKeys);
	    gfx::TimSort(boundVec_.begin(),boundVec_.end(), compareKeys);

	}
	void removeFromBoundVec(const key & k)
	{
	   // presorted, since we sorted at add
	   auto it = std::lower_bound(boundVec_.begin(),boundVec_.end(),k,compareKeys);
	   boundVec_.erase(it);
	}
	
	/*! This is a mere procedure to shorten code for the cell() methods
	 * 
	 */
	inline void insertToCell(const key & k ,const value & val)
	{
	    const auto cIt = csvData_.find(k);
	    bool needToAddKeyToRefArr = true;
	    if (!cIt == csvData_.end()) // if false, then key not found!
	    {
		csvData_.erase(cIt);
		needToAddKeyToRefArr =false;
	    }
		
	    csvData_.insert(mapEntry(k,val));
	    if (needToAddKeyToRefArr){
		addToBoundVec(k);
	    }
	}
    private:

	std::unordered_map<key,value> csvData_;
	/*! the boundVec_ exists in order to keep track and find keys in order */
	std::vector<key>		boundVec_; 
	
    };
}