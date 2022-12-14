class MyHashSet
{
public:
    MyHashSet()
    {
    }
    vector<int> v;
    void add(int key)
    {
        for (auto it : v)
        {
            if (it == key)
                return;
        }
        v.push_back(key);
    }

    void remove(int key)
    {
        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i] == key)
                v.erase(v.begin() + i);
        }
    }

    bool contains(int key)
    {
        for (auto it : v)
        {
            if (it == key)
                return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */