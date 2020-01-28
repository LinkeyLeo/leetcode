/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start
class Block
{
public:
    int key;
    int data;
    int frequency;
    Block *prev = NULL;
    Block *next = NULL;
    Block(int key, int data)
    {
        this->key = key;
        this->data = data;
        this->frequency = 0;
    }
};

class LFUCache
{
private:
    int capacity;
    map<int, Block *> cache;
    map<int, vector<Block *>> evict;

public:
    LFUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (cache[key] == NULL)
        {
            return -1;
        }
        Block *t = cache[key];
        if (evict[t->frequency][0] == t)
        {
            if (t->next == NULL)
            {
                evict.erase(t->frequency);
            }
            else
            {
                evict[t->frequency][0] = t->next;
            }
        }
        else if (evict[t->frequency][1] == t)
        {
            evict[t->frequency][1] = t->prev;
            t->prev->next = NULL;
        }
        else
        {
            t->next->prev = t->prev;
            t->prev->next = t->next;
        }
        t->frequency++;
        t->next = NULL;
        if (evict[t->frequency].empty())
        {
            evict[t->frequency].push_back(t);
            evict[t->frequency].push_back(t);
            t->prev = NULL;
        }
        else
        {
            evict[t->frequency][1]->next = t;
            t->prev = evict[t->frequency][1];
            evict[t->frequency][1] = t;
        }
        return t->data;
    }

    void put(int key, int value)
    {
        if (cache[key] == NULL)
        {
            Block *t = new Block(key, value);
            if (capacity == 0)
            {
                if (evict.empty())
                {
                    return;
                }
                Block *e = evict.begin()->second[0];
                if (e == evict.begin()->second[1])
                {
                    evict.erase(evict.begin());
                }
                else
                {
                    evict.begin()->second[0] = e->next;
                    evict.begin()->second[0]->prev = NULL;
                }
                cache.erase(e->key);
                delete e;
            }
            else
            {
                capacity--;
            }
            cache[key] = t;
            if (evict[0].empty())
            {
                evict[0].push_back(t);
                evict[0].push_back(t);
            }
            else
            {
                evict[0][1]->next = t;
                t->prev = evict[0][1];
                evict[0][1] = t;
            }
        }
        else
        {
            Block *t = cache[key];
            t->data = value;
            if (evict[t->frequency][0] == t)
            {
                if (t->next == NULL)
                {
                    evict.erase(t->frequency);
                }
                else
                {
                    evict[t->frequency][0] = t->next;
                }
            }
            else if (evict[t->frequency][1] == t)
            {
                evict[t->frequency][1] = t->prev;
                t->prev->next = NULL;
            }
            else
            {
                t->next->prev = t->prev;
                t->prev->next = t->next;
            }
            t->frequency++;
            t->next = NULL;
            if (evict[t->frequency].empty())
            {
                evict[t->frequency].push_back(t);
                evict[t->frequency].push_back(t);
                t->prev = NULL;
            }
            else
            {
                evict[t->frequency][1]->next = t;
                t->prev = evict[t->frequency][1];
                evict[t->frequency][1] = t;
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
