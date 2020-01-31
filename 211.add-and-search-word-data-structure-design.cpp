/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Add and Search Word - Data structure design
 */

// @lc code=start
class Node
{
public:
    bool terminate = false;
    map<char, Node *> next;
};

class Step
{
public:
    map<char, Node *>::iterator it;
    Node *s;
    int i;
    Step(map<char, Node *>::iterator it, Node *s, int i)
    {
        this->it = it;
        this->s = s;
        this->i = i;
    }
};

class WordDictionary
{
private:
    Node *root;

public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
        root = new Node();
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        Node *s = root;
        for (char c : word)
        {
            if (s->next[c] == NULL)
            {
                s->next[c] = new Node();
            }
            s = s->next[c];
        }
        s->terminate = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        stack<Step> back({Step(root->next.begin(), root, 0)});
        map<char, Node *>::iterator it;
        Node *s;
        int i;
        int mi = 1;
        pair<map<char, Node *>::iterator, Node *> next;
        while (!back.empty())
        {
            Step step = back.top();
            back.pop();
            it = step.it;
            s = step.s;
            i = step.i;
            if (i < word.size())
            {
                if (word[i] == '.')
                {
                    while (it != s->next.end())
                    {
                        if (it->second != NULL)
                        {
                            Step next(it->second->next.begin(), it->second, i + 1);
                            back.push(Step(++it, s, i));
                            back.push(next);
                            break;
                        }
                        it++;
                    }
                }
                else if (s->next[word[i]] != NULL)
                {
                    back.push(Step(s->next[word[i]]->next.begin(), s->next[word[i]], i + 1));
                }
            }
            else if (s->terminate)
            {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
