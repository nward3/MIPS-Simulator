// associativeCache.h

#ifndef ASSOCIATIVE_CACHE_H
#define ASSOCIATIVE_CACHE_H

class associativeCache {
  public:
  	associativeCache(unsigned logBlockSize_, unsigned logDepth_, unsigned associativity_);
  	bool checkHit(unsigned addr);
  	void printStats();
  	unsigned getAccesses() { return accesses; }
  	unsigned getHits() { return hits; }
  	virtual ~associativeCache();

  private:
  	unsigned logBlockSize;
	unsigned logDepth;
	unsigned associativity;		// n-way associative cache
	unsigned accesses;			// total number of memory accesses
	unsigned hits;				// total number of cache hits
	unsigned **tagArray;		// array containing the cache's tags
	bool **validArray;			// array containing the cache's valid bits
	unsigned **lastAccessArray;	// array containing the cache's last accesses
};

#endif