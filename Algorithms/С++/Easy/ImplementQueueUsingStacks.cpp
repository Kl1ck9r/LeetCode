


class MyQueue {
private:
	stack<int> st1, st2;

	/* Push element x onto myQueue */
	void push(int x) {
		while (!empty()) {
			st2.push(st1.top());
			st1.pop();
		}

		st1.push(x);

		while (!st2.empty()) {
			st1.push(st2.top());
			st2.pop();
		}
	}

	/** Removes the element on front of the myQueue and returns that element. */
	int pop() {
		int var = st1.top();
		st1.pop();
		return var;
	}

	/* Get the front element. */
	int peek() { return st1.top(); }

	/* Returns whether the stack is empty. */
	bool empty() {
		return st1.empty();
	}

};