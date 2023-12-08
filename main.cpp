#include <iostream>

#include "InMemoryDB.cpp"

int main() {
    // std::cout << "Hello, World!" << std::endl;

    InMemoryDB inmemoryDB;
    cout << "Make database" << endl;

    // should return null, because A doesn’t exist in the DB yet
    inmemoryDB.get("A");
    cout << "A: " << inmemoryDB.get("A") << endl;


    // should throw an error because a transaction is not in progress
    inmemoryDB.put("A", 5);


    // starts a new transaction
    inmemoryDB.begin_transaction();
    cout << "beginning transaction" << endl;

    // set’s value of A to 5, but its not committed yet
    inmemoryDB.put("A", 5);
    cout << "setting A to 5" << endl;

    // should return null, because updates to A are not committed yet
    inmemoryDB.get("A");
    cout << "A: " << inmemoryDB.get("A") << endl;

    // update A’s value to 6 within the transaction
    inmemoryDB.put("A", 6);
    cout << "setting A to 6" << endl;

    // commits the open transaction
    inmemoryDB.commit();
    cout << "moving changes into main table" << endl;

    // should return 6, that was the last value of A to be committed
    inmemoryDB.get("A");
    cout << "A: " << inmemoryDB.get("A") << endl;

    // throws an error, because there is no open transaction
    inmemoryDB.commit();

    // throws an error because there is no ongoing transaction
    inmemoryDB.rollback();

    // should return null because B does not exist in the database
    inmemoryDB.get("B");
    cout << "B: " << inmemoryDB.get("B") << endl;

    // starts a new transaction
    inmemoryDB.begin_transaction();
    cout << "beginning transaction" << endl;

    // Set key B’s value to 10 within the transaction
    inmemoryDB.put("B", 10);
    cout << "setting B to 10" << endl;

    // Rollback the transaction - revert any changes made to B
    inmemoryDB.rollback();
    cout << "reverting changes" << endl;

    // Should return null because changes to B were rolled back
    inmemoryDB.get("B");
    cout << "B: " << inmemoryDB.get("B") << endl;

    return 0;
}
