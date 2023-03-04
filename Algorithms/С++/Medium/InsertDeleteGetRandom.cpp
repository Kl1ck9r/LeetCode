
/*

Implement the RandomizedSet class:
RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.

*/

// O(1)
class RandomizedSet {
public:
	RandomizedSet() {

	}

	bool insert(int val) {
		if (st.find(val) == st.end()) {
			st.insert(val);
			return true;
		}
		return false;
	}

	bool remove(int val) {
		if (st.find(val) != st.end()) {
			st.erase(st.find(val));
			return true;
		}
		return false;
	}

	int getRandom() {
		srand(time(nullptr));
		int sz = st.size();
		int randNumber = rand() % sz;
		auto it = st.begin();
		for (int i = 0; i < randNumber; i++) {
			it++;
		}

		// also as an option
		/* auto it = st.begin();
		 advance(it, rand() % st.size());
		 return *it;
		 */
	}

private:
	unordered_set<int> st;
};
