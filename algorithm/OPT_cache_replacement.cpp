/*
一个简单的OPT算法实现。输入为类似[1,3,2,3,1,4,5,2,7]这样的数字序列。
*/
#include <stdio.h>
#include <stdint.h>
#include <cassert>
#include <unordered_map>
#include <set>

const static int CacheSize = 4;
const static int container_sequence[] = {4, 3, 2, 1, 4, 3, 5, 4, 3, 2, 1, 5};
const static int record_sequence[] = {10, 20, 30, 40, 50};
const static int seq_num = sizeof(container_sequence) / sizeof(int);

class ChunkCache {
public:

    ChunkCache(const int* arr, const int cache_size) {
        for (int i = 0; i < CacheSize; i ++) {
            cache[i] = {-1, -1};
        }

        // 预处理
        for (int i = 0; i < seq_num; i ++) {
            container_position[container_sequence[i]].insert(i);
        }
    }

    int getRecord(int cid) {
        for (int i = 0; i < CacheSize; i ++) {
            if (cache[i].cid == cid) {
                cur_position ++;
                return cache[i].record;
            }
        }

        return -1;
    }

    void prefetchContainer(int cid) {
        int free_idx = -1;

        // just for check
        for (int i = 0; i < CacheSize; i ++) {
            if (cache[i].cid == cid) {
                return ;
            }

            if (cache[i].cid == -1) {
                free_idx = i;
            }
        }

        if (free_idx == -1) {
            // should do evict if the cache is full
            free_idx = evict();
            assert(free_idx != -1);
        }

        // prefetch
        int record = record_sequence[cid -1]; // actually a complex IO operation here
        cache[free_idx] = {cid, record};
        return ;
    }

    void printCache() {
        for (int i = 0; i < CacheSize; i ++) {
            if (cache[i].cid != -1) {
                printf("%d\t", cache[i].cid);
            }
        }

        printf("\n");
    }

private:

    int getNextPosition(int cid) {
        auto it = container_position[cid].upper_bound(cur_position);
        if (it == container_position[cid].end()) {
            return INT32_MAX;
        } else {
            printf("cid = %d, posi = %d, next_pos = %d\n", cid, cur_position, *it);
            return *it;
        }
    }

    int evict() {
        int max = -1;
        int max_idx = -1;
        for (int i = 0; i < CacheSize; i ++) {
            assert(cache[i].cid != -1);
            int next_pos = getNextPosition(cache[i].cid);
            if (next_pos > max) {
                max = next_pos;
                max_idx = i;
            }
        }

        return max_idx;
    }

    struct CacheBlock {
        int cid;
        int record;
    };

    std::unordered_map<int, std::set<int>> container_position; // <cid, positions>
    CacheBlock cache[CacheSize];
    int cur_position = 0;
};

int main() {
    ChunkCache chunkCache(container_sequence, CacheSize);
    int hit_cnt = 0;

    for (int i = 0; i < seq_num; i ++) {
        int c = chunkCache.getRecord(container_sequence[i]);
        if (c != -1) {
            hit_cnt ++;
            goto Next;
        }
        chunkCache.prefetchContainer(container_sequence[i]);
        c = chunkCache.getRecord(container_sequence[i]);

Next:
        assert(c == record_sequence[container_sequence[i] - 1]);

        printf("======================**%d**======================\n", i);
        chunkCache.printCache();
    }

    printf("hit rate: %.3lf\n", (double)hit_cnt / seq_num);
    return 0;
}