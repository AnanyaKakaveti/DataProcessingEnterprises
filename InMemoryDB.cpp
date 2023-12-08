//
// Created by Annie Kakaveti on 12/8/23.
//
#include <string>
#include <unordered_map>
using namespace std;


class InMemoryDB {

    unordered_map<string, int> table;
    bool transactionStarted = false;
    unordered_map<string, int> tempTable;

public:
    InMemoryDB () {

    }

    int get(string key) {
        // can be called even if transaction is not happening
        if (!table.count(key))
            return NULL;
        return table[key];

    }

    void put(string key, int val) {
        if (!transactionStarted)
            throw invalid_argument("Transaction not started, parameters in put() invalid.");

        // create a new key with the provided value if a key doesn’t exist
        // Otherwise it will update the value of an existing key.
        tempTable[key] = val;
    }

    void begin_transaction() {
        // can only have 1 transaction at a time
        if (transactionStarted)
            return;
        transactionStarted = true;
    }

    void commit() {
        if (!transactionStarted)
            throw invalid_argument("Transaction not started, cannot commit any changes.");

        // add changes to table
        for (auto i : tempTable) {
            table[i.first] = i.second;
        }

        tempTable.clear();
        rollback();

    }

    void rollback() {
        if (!transactionStarted)
            throw invalid_argument("Transaction not started, cannot rollback any changes.");

        // reset transaction
        transactionStarted = false;
        tempTable.clear();
    }

};
