// associativeCache.cpp

#include "associativeCache.h"
#include "global.h"

// class constructor
associativeCache::associativeCache(unsigned logBlockSize_, unsigned logDepth_, unsigned associativity_)
: logBlockSize(logBlockSize_),
  logDepth(logDepth_),
  associativity(associativity_),
  accesses(0),
  hits(0)
{
	tagArray = new unsigned* [1 << logDepth];
	validArray = new bool* [1 << logDepth];
	lastAccessArray = new unsigned* [1 << logDepth];
	for (int i = 0; i < 1 << logDepth; i++) {
		tagArray[i] = new unsigned [associativity];
		validArray[i] = new bool [associativity];
		lastAccessArray[i] = new unsigned [associativity];
	}
}

// class destructor
associativeCache::~associativeCache() {
	delete tagArray;
	delete validArray;
	delete lastAccessArray;
}

// checks the cache for a hit
bool associativeCache::checkHit(unsigned addr) {
	unsigned mask = (1 << logDepth) - 1;
	unsigned index = (addr >> logBlockSize) & mask;
	unsigned tag = addr >> (logBlockSize + logDepth);
	++accesses;
	// printf("addr = %08x  index = %02x  tag = %06x\n", addr, index, tag);

	// check for hits
	for (int set = 0; set < associativity; set++) {
		if (tagArray[index][set] == tag && validArray[index][set]) {
			++hits;
			lastAccessArray[index][set] = accesses;
			// printf("hit:  set = %d\n", set);
			return true;
		}
	}

	// process miss and update cache
	int lru;	// least recently used set in cache
	unsigned min = accesses;
	for (int set = 0; set < associativity; set++) {
		if (!validArray[index][set]) {
			lru = set;
			break;
		} else {
			if (lastAccessArray[index][set] < min) {
				min = lastAccessArray[index][set];
				lru = set;
			}
		}
	}
	// printf("miss:  set = %d\n", lru);

	tagArray[index][lru] = tag;
	validArray[index][lru] = true;
	lastAccessArray[index][lru] = accesses;
	return false;
}

// prints the stats on cache hits and accesses
void associativeCache::printStats() {
	// printf("accesses = %u  hits = %u  hit rate = %f\n", accesses, hits, (float) hits/accesses);
}