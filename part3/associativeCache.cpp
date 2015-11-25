// associativeCache.h

#ifndef ASSOCIATIVE_CACHE_H
#define ASSOCIATIVE_CACHE_H

class associativeCache {
  public:
  	associativeCache(unsigned logBlockSize_, unsigned logDepth_, unsigned associativity_);
  	bool checkHit(unsigned addr);
  	unsigned getAccesses() { return accesses; }
  	unsigned getHits() { return hits; }
  	virtual ~associativeCache();

  private:
  	unsigned logBlockSize;
	unsigned logDepth;
	unsigned associativity;
	unsigned accesses;
	unsigned hits;
	unsigned **tagArray;
	bool **validArray;
	unsigned **lastAccessArray;
};

#endif