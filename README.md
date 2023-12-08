# DataProcessingEnterprises Ananya Kakaveti
C++ Program, written in CLion
main.cpp : testing code based on the code from Figure 2 in the assignment
InMemoryDB.cpp : class that represents the table

How to Run the Code
-------------------
If you have CLion, you can open this directly in that application. You just have to add _#include "InMemoryDB.cpp"_ at the top of the testing file. Alternatively, you can use the main.cpp that I committed (based on the code from Figure 2 in the assignment), but note that lines 17, 45 and 48 will throw exceptions because they are invalid calls.

If you don't have CLion, you can download both files, and run **g++ main.cpp** inside the folder that contains them, and then run **./a.out** , which will simply run the file in the command line. Again, note that lines 17, 45, and 48 will cause exceptions based on the guidelines, so be sure to comment them out if you want to see all of the functinality.


Adapting to an Assignment
-------------------------
I think this could be adapted to an assigment if there were more functions added to the class. Perhaps there could be a boolean attached to the inserted key-value that represents whether that row in the table can be adjusted. This could be interpreted as: if "true" was passed in, that row is "locked" and I can not change the value. Additionally, methods like deleteRow or changeKey (keep the value but change the key) could be added to add some straight forward but applicable functionality to the database.
