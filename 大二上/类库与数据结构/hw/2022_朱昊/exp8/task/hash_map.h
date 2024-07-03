#ifndef HASH_MAP
#define HASH_MAP

#include <list>

using namespace std;

template<class Key, class T>
struct key_value_pair
{
    key_value_pair(const key_value_pair& p) : first(p.first)
    {
        second = p.second;
    }

    key_value_pair(const Key& key, const T& t) : first(key)
    {
        second = t;
    }

    bool operator== (const key_value_pair& x)
    {
        return first == x.first;
    }

    const Key first;
    T second;
}; // struct key_value_pair

template<class Key, class T, class HashFunc>
class hash_map
{
    typedef typename list<key_value_pair<const Key, T> >::iterator hash_list_itr;

protected:

    const static int DEFAULT_SIZE; 
    const static float MAX_RATIO; //load factor

    list <key_value_pair<const Key, T> > *buckets;
    int count,   // number of items in hash_map
        length;  // number of buckets in hash_map
    
    HashFunc hash;

    void check_for_expansion()
    {
        hash_list_itr list_itr;
        int address;

        if (count > int(MAX_RATIO * length))
        {
            list< key_value_pair<const Key, T> >* temp_buckets = buckets;

            length = 2 * length + 1;
            buckets = new list< key_value_pair< const Key, T> >[length];
            Key new_key;
            for (int i = 0; i < length / 2; i++)
                if (!temp_buckets[i].empty())
                    for (list_itr = temp_buckets[i].begin();
                        list_itr != temp_buckets[i].end();
                        list_itr++)
                    {
                        new_key = (*list_itr).first;
                        address = hash(new_key) % length;
                        buckets[address].push_back(*list_itr);
                    } // posting temp_buckets [i] back into buckets

            delete[] temp_buckets;

        } // doubling buckets size
    } // method check_for_expansion

public:

    // Postcondition: this hash_map has been intialized.
    hash_map()
    {
        count = 0;
        length = DEFAULT_SIZE;
        buckets = new list<key_value_pair<const Key, T> >[DEFAULT_SIZE];
    } // default constructor

    bool operator== (const hash_map<Key, T, HashFunc>& other)
    {
        return (buckets == other.buckets) &&
            (count == other.count) &&
            (length == other.length);
    }

    // Postcondition: the number of items in this hash_map has been returned.
    int size()
    {
        return count;
    } // method size

    //innner iterator class
    class iterator
    {
        friend class hash_map<Key, T, HashFunc>;

    protected:

        unsigned index, length;
        hash_list_itr list_itr;
        list<key_value_pair<const Key, T> > *buckets;

    public:

        bool operator== (const iterator& other) const
        {
            return (index == other.index) &&
                (list_itr == other.list_itr) &&
                (buckets == other.buckets) &&
                (length == other.length);
        } // ==

        bool operator!= (const iterator& other) const
        {
            return !(*this == other);
        } // operator!=

        iterator operator++ (int)
        {
            iterator old_itr = *this;
            if (++list_itr != buckets[index].end())
                return old_itr;
            while (index < length - 1)
            {
                index++;
                if (!buckets[index].empty())
                {
                    list_itr = buckets[index].begin();
                    return old_itr;
                } // bucket entry not empty
            }// while
            list_itr = buckets[index].end();
            return old_itr;
        } // postincrement operator++

        key_value_pair<const Key, T>& operator* ()
        {
            return *list_itr;
        } // operator*
    }; // iterator


    // Postcondition: an iterator positioned at the beginning
    //                of this hash_map has been returned.
    iterator begin()
    {
        int i = 0;
        iterator itr;

        itr.buckets = buckets; //friend class
        while (i < length - 1)
        {
            if (!buckets[i].empty())
            {
                itr.list_itr = buckets[i].begin();
                itr.index = i;
                itr.length = length;
                return itr;
            } // buckets [i] not empty
            i++;
        } // while
        itr.list_itr = buckets[i].end();
        itr.index = i;
        itr.length = length;
        return itr;
    } // begin


    // Postcondition: an iterator has been returned that can be used
    //                in comparisons to terminate iterating through
    //                this hash_map.
    iterator end()
    {
        int i = length - 1;
        iterator itr;

        itr.buckets = buckets;
        itr.list_itr = buckets[i].end();
        itr.index = i;
        itr.length = length;
        return itr;
    } // end


    // Postcondition: If an item with x's key had already been inserted
    //                into this hash_map, the pair returned consists of an
    //                iterator positioned at the previously inserted item,
    //                and false. Otherwise, the pair returned consists of
    //                an iterator positioned at the newly inserted item,
    //                and true. The averageTime (n) is constant, and
    //                worstTime (n) is O (n).
    pair<iterator, bool> insert(const key_value_pair<const Key, T>& x)
    {
        iterator old_itr;
        Key key = x.first;

        old_itr = find(key);
        if (old_itr != end())
            return pair <iterator, bool>(old_itr, false);
        int address = hash(key) % length;
        buckets[address].push_back(x);
        count++;
        check_for_expansion();
        return pair<iterator, bool>(find(key), true);
    } // insert


    // Postcondition: if this hash_map already contains a value whose
    //                key part is key, a reference to that value's
    //                second component has been returned.  Otherwise,
    //                a new value, <key, T()>, is inserted into this
    //                map and a reference to that value's second
    //                component has been returned. The averageTime (n)
    //                is constant, and worstTime (n) is O (n).
    T& operator[] (const Key& key)
    {
        return (*((insert(key_value_pair<const Key, T>(key, T()))).first)).second;
    } // operator[ ]


    // Postcondition: if this hash_map contains a value whose key
    //                component is key, an iterator positioned at that
    //                value has been returned. Otherwise, an iterator
    //                with the same value as end() has been returned.
    //                The averageTime (n) is constant, and the
    //                worstTime (n) is O (n). What is n?
    iterator find(const Key& key)
    {
        int address = hash(key) % length;
        iterator itr;
        itr.list_itr = std::find(buckets[address].begin(),
            buckets[address].end(),
            key_value_pair<const Key, T>(key, T()));
        if (itr.list_itr == buckets[address].end())
            return end();
        itr.buckets = buckets;
        itr.index = address;
        itr.length = length;
        return itr;
    } // find


    // Precondition: itr is positioned at value in this hash_map.
    // Postcondition: the value that itr is positioned at has been
    //                deleted from this hash_map. The averageTime (n)
    //                is constant. The worstTime (n) is O (n).
    void erase(iterator itr)
    {
        buckets[itr.index].erase(itr.list_itr);
        count--;
    } // erase

    // Postcondition: the space allocated for this hash_map
    //                object has been deallocated.
    ~hash_map()
    {
        delete[] buckets;
    } // destructor
}; // hash_map

template<class Key, class T, class HashFunc>
const int hash_map<Key, T, HashFunc>::DEFAULT_SIZE = 211;

template<class Key, class T, class HashFunc>
const float hash_map<Key, T, HashFunc>::MAX_RATIO = 0.75;

#endif
